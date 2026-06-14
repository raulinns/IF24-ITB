# Cheatsheet UTS & Praktikum Jaringan Komputer
*Cisco Packet Tracer — Modul 1–4*

---

## Navigasi Cepat
- [Mode CLI Cisco](#mode-cli-cisco)
- [Modul 1: Frame Switching & VLAN](#modul-1-frame-switching--vlan)
- [Modul 2: DHCP & Routing](#modul-2-dhcp--routing)
- [Modul 3: NAT & Port Forwarding](#modul-3-nat--port-forwarding)
- [Modul 4: DNS, SSH, ACL, IPv6](#modul-4-dns-ssh-acl-ipv6)
- [Perintah Diagnostik & Show](#perintah-diagnostik--show)

---

## Mode CLI Cisco

Cisco IOS memiliki hierarki mode. Kamu **harus** berada di mode yang tepat sebelum menjalankan perintah konfigurasi.

```
Router>          ← User EXEC (read-only, sangat terbatas)
Router#          ← Privileged EXEC (show, debug, copy)
Router(config)#  ← Global Configuration (ubah konfigurasi global)
Router(config-if)#  ← Interface Configuration
Router(config-vlan)# ← VLAN Configuration
Router(config-router)# ← Routing Protocol Configuration
Router(config-line)#   ← Line (VTY/Console) Configuration
```

| Perintah | Fungsi |
|----------|--------|
| `enable` / `en` | User EXEC → Privileged EXEC |
| `configure terminal` / `conf t` | Privileged EXEC → Global Config |
| `exit` | Mundur satu level mode |
| `end` / `Ctrl+Z` | Langsung kembali ke Privileged EXEC dari mana saja |
| `do <cmd>` | Jalankan perintah Privileged dari dalam mode config |

### Perintah Dasar Wajib

```
hostname <nama>                      → Ganti nama perangkat
enable secret <password>             → Set password masuk ke enable (encrypted)
no ip domain-lookup                  → Cegah CLI hang saat salah ketik perintah
copy running-config startup-config   → Simpan konfigurasi ke NVRAM (persistent)
write / wr                           → Shortcut copy run start
show running-config                  → Tampilkan konfigurasi aktif saat ini
```

---

## Modul 1: Frame Switching & VLAN

### Konsep Kunci

**MAC Table (CAM Table):** Switch mempelajari MAC Address sumber dari setiap frame yang masuk, lalu menyimpannya di tabel. Ketika ada frame tujuan, switch cari MAC di tabel → kirim ke port spesifik (unicast). Kalau tidak ada → *flood* ke semua port kecuali port asal.

**ARP (Address Resolution Protocol):** Proses resolusi IP → MAC. Host kirim ARP Request (broadcast) → pemilik IP balas dengan ARP Reply (unicast) berisi MAC-nya. Diperlukan sebelum frame Layer 2 bisa dikirim.

**VLAN:** Membagi satu switch fisik menjadi beberapa LAN logis terpisah. Traffic antar-VLAN tidak bisa lewat tanpa router. Setiap VLAN = satu broadcast domain terpisah.

**802.1Q Tagging:** Frame yang lewat trunk port diberi tag 4-byte yang berisi VLAN ID, sehingga switch penerima tahu frame ini milik VLAN berapa.

**Trunk Port:** Port switch yang membawa traffic dari **banyak VLAN** sekaligus, digunakan untuk menghubungkan antar-switch atau ke router.

**Access Port:** Port yang hanya melayani **satu VLAN**, digunakan untuk perangkat end-user (PC, printer, dll).

### Perintah VLAN

```cisco
! === Buat VLAN ===
Switch(config)# vlan 10
Switch(config-vlan)# name Marketing

! === Assign port ke VLAN (Access) ===
Switch(config)# interface f0/1
Switch(config-if)# switchport mode access
Switch(config-if)# switchport access vlan 10

! === Konfigurasi Trunk Port ===
Switch(config)# interface g0/1
Switch(config-if)# switchport mode trunk
! (Opsional) Batasi VLAN yang boleh lewat trunk:
Switch(config-if)# switchport trunk allowed vlan 10,20,30

! === Verifikasi ===
Switch# show vlan brief
Switch# show interfaces trunk
Switch# show mac address-table
```

### Perintah IP Interface Router

```cisco
! Beri IP ke interface router
Router(config)# interface g0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown       ← WAJIB: aktifkan interface (default OFF)
```

---

## Modul 2: DHCP & Routing

### DHCP — Proses DORA

```
Client → Server: DISCOVER  (broadcast, "ada DHCP server ga?")
Server → Client: OFFER     (unicast, "ini IP yang kuberikan: 192.168.1.10")
Client → Server: REQUEST   (broadcast, "oke, aku minta IP itu")
Server → Client: ACK       (unicast, "granted, pakai sampai waktu lease habis")
```

### Perintah DHCP Server (di Router)

```cisco
! Exclude IP yang tidak boleh disewakan (router, server, dll)
Router(config)# ip dhcp excluded-address 192.168.1.1 192.168.1.10

! Buat pool DHCP
Router(config)# ip dhcp pool LAN_POOL
Router(dhcp-config)# network 192.168.1.0 255.255.255.0   ← range subnet
Router(dhcp-config)# default-router 192.168.1.1           ← gateway untuk client
Router(dhcp-config)# dns-server 8.8.8.8                   ← DNS server
Router(dhcp-config)# lease 7                              ← lease 7 hari (opsional)

! Verifikasi
Router# show ip dhcp binding     ← lihat IP yang sudah disewakan ke siapa
Router# show ip dhcp pool        ← statistik pool
```

### Static Routing

**Konsep:** Kamu secara manual memberitahu router: "kalau ada paket untuk jaringan X, kirim ke next-hop Y." Router tidak belajar sendiri — kamu yang mendefinisikan semua jalur.

```cisco
! Sintaks: ip route <network_tujuan> <subnet_mask> <next_hop_IP>
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.2
! Artinya: paket ke 192.168.2.0/24 → kirim ke 10.0.0.2

! Default route (0.0.0.0/0 = semua yang tidak ada di routing table)
Router(config)# ip route 0.0.0.0 0.0.0.0 10.0.0.1

! Verifikasi
Router# show ip route
```

### Inter-VLAN Routing

Karena VLAN memisahkan broadcast domain, diperlukan router untuk komunikasi antar-VLAN.

#### Metode 1: Router on a Stick (Subinterface)

```cisco
! Di router, buat subinterface untuk tiap VLAN
Router(config)# interface g0/0.10
Router(config-subif)# encapsulation dot1q 10           ← tag VLAN 10
Router(config-subif)# ip address 192.168.10.1 255.255.255.0

Router(config)# interface g0/0.20
Router(config-subif)# encapsulation dot1q 20           ← tag VLAN 20
Router(config-subif)# ip address 192.168.20.1 255.255.255.0

! Di switch, port ke router harus trunk
Switch(config)# interface g0/1
Switch(config-if)# switchport mode trunk
```

#### Metode 2: L3 Switch (SVI — Switch Virtual Interface)

```cisco
! Aktifkan routing di multilayer switch
L3Switch(config)# ip routing

! Buat SVI untuk tiap VLAN (berfungsi sebagai gateway)
L3Switch(config)# interface vlan 10
L3Switch(config-if)# ip address 192.168.10.1 255.255.255.0
L3Switch(config-if)# no shutdown

L3Switch(config)# interface vlan 20
L3Switch(config-if)# ip address 192.168.20.1 255.255.255.0
L3Switch(config-if)# no shutdown

! Ubah port fisik menjadi routed port (bukan switchport)
L3Switch(config)# interface g0/1
L3Switch(config-if)# no switchport
L3Switch(config-if)# ip address 10.0.0.1 255.255.255.252
```

### Dynamic Routing — OSPF

**Konsep:** Router saling berbagi informasi topologi (Link State Advertisement/LSA). Setiap router membangun *link-state database* yang sama, lalu menjalankan algoritma Dijkstra (Shortest Path First) untuk menghitung jalur terpendek.

**Administrative Distance (AD):** Nilai kepercayaan sumber routing. Makin kecil = makin dipercaya.
- Connected: 0
- Static: 1
- OSPF: 110
- RIP: 120

```cisco
! Aktifkan OSPF
Router(config)# router ospf 1            ← process-id (lokal, tidak harus sama antar router)

! Iklankan network yang terhubung ke OSPF
! Wildcard mask = kebalikan subnet mask (255.255.255.0 → wildcard: 0.0.0.255)
Router(config-router)# network 192.168.1.0 0.0.0.255 area 0
Router(config-router)# network 10.0.0.0 0.0.0.3 area 0

! Jangan iklankan rute OSPF ke interface yang tidak punya router OSPF lain
Router(config-router)# passive-interface g0/0

! Verifikasi
Router# show ip ospf neighbor    ← lihat router tetangga yang sudah terkoneksi OSPF
Router# show ip route ospf       ← lihat rute yang dipelajari via OSPF
```

### Dynamic Routing — BGP (Konsep)

BGP digunakan antar *Autonomous System* (AS) — jaringan besar milik organisasi berbeda (ISP, perusahaan besar).

```cisco
Router(config)# router bgp 65001              ← AS number lokal
Router(config-router)# neighbor 203.0.113.1 remote-as 65002   ← daftarkan peer
Router(config-router)# network 192.168.0.0 mask 255.255.0.0   ← iklankan prefix

! Route Redistribution: sebarkan rute OSPF ke BGP
Router(config-router)# redistribute ospf 1
```

### Wireless Router

Router wireless berfungsi ganda: router + access point + DHCP server nirkabel. Konfigurasi via GUI (tab Wireless) di Packet Tracer: set SSID dan mode keamanan (WPA2).

---

## Modul 3: NAT & Port Forwarding

### Konsep IP Private vs Public

**IP Private** (tidak bisa diakses internet langsung):
- `10.0.0.0/8`
- `172.16.0.0/12`
- `192.168.0.0/16`

**NAT** menjembatani: mengubah IP Private → IP Public saat paket keluar ke internet, dan sebaliknya saat paket masuk.

### Terminologi NAT

| Istilah | Artinya |
|---------|---------|
| Inside Local | IP Private perangkat internal |
| Inside Global | IP Public yang merepresentasikan perangkat internal |
| Outside Global | IP Public tujuan di internet |
| `ip nat inside` | Interface yang menghadap jaringan lokal |
| `ip nat outside` | Interface yang menghadap internet |

### Static NAT (1 IP Private → 1 IP Public, permanen)

```cisco
! Tandai interface
Router(config)# interface g0/0
Router(config-if)# ip nat inside

Router(config)# interface g0/1
Router(config-if)# ip nat outside

! Buat pemetaan statik
Router(config)# ip nat inside source static 192.168.1.10 203.0.113.10
! Artinya: 192.168.1.10 (private) selalu diterjemahkan ke 203.0.113.10 (public)
```

### Dynamic NAT (Pool IP Public)

```cisco
! Buat pool IP Public yang tersedia
Router(config)# ip nat pool PUBLIC_POOL 203.0.113.10 203.0.113.20 netmask 255.255.255.0

! Buat ACL yang mendefinisikan siapa yang boleh di-NAT
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255

! Hubungkan ACL ke pool NAT
Router(config)# ip nat inside source list 1 pool PUBLIC_POOL
```

### PAT / NAT Overload (Banyak IP Private → 1 IP Public)

PAT membedakan koneksi menggunakan **port number** di Transport Layer. Ini yang paling umum digunakan di rumah/kantor.

```cisco
! Gunakan interface g0/1 (IP Public) sebagai sumber
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255
Router(config)# ip nat inside source list 1 interface g0/1 overload
!                                                            ^^^^^^^^ kunci PAT
```

### Port Forwarding (Akses layanan internal dari internet)

Memungkinkan server internal (web, FTP) diakses dari internet melalui IP Public.

```cisco
! Ekspos web server 192.168.1.100:80 via IP Public port 80
Router(config)# ip nat inside source static tcp 192.168.1.100 80 203.0.113.1 80

! Gunakan port berbeda (misal 8080 di public → 80 di private)
Router(config)# ip nat inside source static tcp 192.168.1.100 80 203.0.113.1 8080
```

### Verifikasi NAT

```cisco
Router# show ip nat translations    ← lihat tabel translasi aktif
Router# show ip nat statistics      ← statistik NAT
Router# clear ip nat translation *  ← hapus semua entri NAT dinamis
```

---

## Modul 4: DNS, SSH, ACL, IPv6

### DNS (Domain Name System)

**Konsep:** DNS mengubah nama domain (google.com) → IP Address. Hierarki: Root → TLD (.com) → Authoritative DNS Server.

**Jenis Record:**
| Record | Fungsi |
|--------|--------|
| A | Hostname → IPv4 |
| AAAA | Hostname → IPv6 |
| CNAME | Alias → hostname lain |
| PTR | IP → hostname (reverse DNS) |

**DNS Poisoning:** Serangan yang mengisi cache DNS dengan record palsu, mengarahkan pengguna ke situs berbahaya. **DoH (DNS over HTTPS)** mengenkripsi query DNS untuk mencegah pemantauan/manipulasi.

### SSH (Secure Shell) — Remote Access Aman

SSH menggantikan Telnet karena menggunakan enkripsi:
- **Fase 1 (Key Exchange):** Asymmetric RSA untuk negosiasi kunci sesi
- **Fase 2 (Data Transfer):** Symmetric AES mengenkripsi semua data

**Prasyarat konfigurasi SSH:** hostname unik + domain name sudah di-set.

```cisco
! 1. Set hostname dan domain (WAJIB untuk generate RSA key)
Router(config)# hostname R1
R1(config)# ip domain-name lab.local

! 2. Buat user lokal
R1(config)# username admin privilege 15 secret P@ssw0rd
!                           ^^^^^^^^^^^ privilege 15 = akses penuh

! 3. Generate RSA key (minimal 1024 bit, rekomendasikan 2048)
R1(config)# crypto key generate rsa
! → ketik 2048 saat diminta modulus

! 4. Konfigurasi VTY lines
R1(config)# line vty 0 15
R1(config-line)# login local          ← autentikasi pakai user lokal
R1(config-line)# transport input ssh  ← hanya terima SSH, tolak Telnet

! 5. (Opsional) Paksa SSH versi 2
R1(config)# ip ssh version 2

! Verifikasi
R1# show ip ssh            ← status SSH
R1# show users             ← siapa yang sedang terkoneksi
```

### ACL (Access Control List)

**Prinsip penting:**
1. Aturan dibaca **dari atas ke bawah** — pertama cocok, langsung dieksekusi
2. Di akhir setiap ACL ada **implicit deny all** (semua yang tidak diizinkan = ditolak)
3. **Standard ACL** (1-99, 1300-1999): filter berdasarkan IP sumber saja → taruh **dekat tujuan**
4. **Extended ACL** (100-199, 2000-2699): filter IP sumber+tujuan+protokol+port → taruh **dekat sumber**

**Wildcard Mask:** Kebalikan subnet mask. `0` = bit harus cocok, `1` = abaikan.
- `255.255.255.0` subnet → `0.0.0.255` wildcard
- `host 192.168.1.1` = shortcut untuk `192.168.1.1 0.0.0.0`
- `any` = shortcut untuk `0.0.0.0 255.255.255.255`

#### Standard ACL

```cisco
! Buat ACL: izinkan 192.168.1.0/24, tolak sisanya
Router(config)# access-list 10 permit 192.168.1.0 0.0.0.255
! (implicit deny any di bawahnya)

! Terapkan ke interface (in = paket masuk ke router, out = paket keluar dari router)
Router(config)# interface g0/1
Router(config-if)# ip access-group 10 out
```

#### Extended ACL

```cisco
! Buat extended ACL bernama (lebih mudah dikelola)
Router(config)# ip access-list extended BLOCK_WEB

! Tolak HTTP dari 192.168.2.0/24 ke server 10.0.0.5
Router(config-ext-nacl)# 10 deny tcp 192.168.2.0 0.0.0.255 host 10.0.0.5 eq 80
! Izinkan semua lainnya
Router(config-ext-nacl)# 20 permit ip any any

! Terapkan ke interface
Router(config)# interface g0/0
Router(config-if)# ip access-group BLOCK_WEB in

! Verifikasi
Router# show ip access-lists          ← lihat semua ACL dan hit counter
Router# show run | include access     ← lihat di interface mana ACL diterapkan
```

### IPv6

**Format:** 128-bit, ditulis dalam 8 grup 4 digit heksadesimal, dipisah `:`.
- Contoh: `2001:0db8:85a3:0000:0000:8a2e:0370:7334`
- Penyederhanaan: hilangkan leading zeros, satu grup `0000` berurutan bisa disingkat `::` (hanya sekali)
- `2001:db8::1` = `2001:0db8:0000:0000:0000:0000:0000:0001`

**Jenis Alamat IPv6:**
| Tipe | Awalan | Keterangan |
|------|--------|------------|
| Global Unicast | `2000::/3` | Setara IP Public, routable di internet |
| Link-Local | `FE80::/10` | Otomatis dikonfigurasi, hanya dalam satu link |
| Loopback | `::1/128` | Setara 127.0.0.1 |
| Multicast | `FF00::/8` | Kirim ke banyak penerima sekaligus |

```cisco
! Aktifkan routing IPv6 global
Router(config)# ipv6 unicast-routing

! Beri IP IPv6 ke interface
Router(config)# interface g0/0
Router(config-if)# ipv6 enable
Router(config-if)# ipv6 address 2001:db8:1::1/64
Router(config-if)# no shutdown

! Static route IPv6
Router(config)# ipv6 route 2001:db8:2::/64 2001:db8:12::2

! Dynamic routing IPv6 dengan RIPng
Router(config)# ipv6 router rip JARINGAN_RIP
Router(config)# interface g0/0
Router(config-if)# ipv6 rip JARINGAN_RIP enable

! Verifikasi
Router# show ipv6 interface brief
Router# show ipv6 route
```

---

## Perintah Diagnostik & Show

Perintah-perintah ini dijalankan dari mode **Privileged EXEC** (`#`).

### General

| Perintah | Fungsi |
|----------|--------|
| `show running-config` | Tampilkan konfigurasi aktif lengkap |
| `show startup-config` | Tampilkan konfigurasi tersimpan di NVRAM |
| `show version` | Info IOS, uptime, hardware |
| `show interfaces` | Status semua interface (up/down, error) |
| `show interfaces <if>` | Detail satu interface tertentu |
| `show ip interface brief` | Ringkasan IP semua interface |

### Routing & VLAN

| Perintah | Fungsi |
|----------|--------|
| `show ip route` | Tabel routing (C=connected, S=static, O=OSPF) |
| `show ip ospf neighbor` | Daftar router OSPF tetangga yang terkoneksi |
| `show vlan brief` | Ringkasan VLAN dan port anggotanya |
| `show interfaces trunk` | Status port trunk |
| `show mac address-table` | Tabel MAC address switch |

### DHCP, NAT, ACL

| Perintah | Fungsi |
|----------|--------|
| `show ip dhcp binding` | Penyewaan IP DHCP yang aktif |
| `show ip nat translations` | Tabel translasi NAT aktif |
| `show ip access-lists` | Semua ACL beserta hit counter |

### IPv6

| Perintah | Fungsi |
|----------|--------|
| `show ipv6 interface brief` | Ringkasan IPv6 semua interface |
| `show ipv6 route` | Tabel routing IPv6 |
| `show ipv6 neighbors` | Tabel neighbor discovery (setara ARP) |

---

## Keterhubungan Konsep — Big Picture

```
[Physical Layer]
    ↓ sinyal listrik/optik/radio
[Data Link Layer] — MAC Address, Frame, Switch, VLAN, 802.1Q
    ↓ frame antar node dalam satu link
[Network Layer] — IP Address, Packet, Router, Routing Table
    |
    ├─ Subnetting (membagi jaringan)
    ├─ ARP (IP → MAC, jembatan L3-L2)
    ├─ ICMP (ping, traceroute, error)
    ├─ NAT (private ↔ public IP)
    ├─ Static Routing (manual)
    └─ Dynamic Routing (OSPF=IGP/link-state, BGP=EGP/path-vector)
    ↓ packet host-to-host
[Transport Layer] — TCP/UDP, Port Number (dipakai ACL extended & PAT)
    ↓
[Application Layer] — DNS (nama→IP), HTTP, SSH, FTP
```

**Alur koneksi PC di LAN berbeda menggunakan router:**
1. PC A (`192.168.1.10`) ping PC B (`192.168.2.10`)
2. PC A cek: B bukan di subnet yang sama → kirim ke **default gateway** (router)
3. PC A ARP untuk MAC gateway → frame dikirim ke router
4. Router terima paket, cek **routing table** → cocok dengan `192.168.2.0/24`
5. Router ARP untuk MAC PC B → forward frame ke PC B
6. Jika melewati NAT: IP source diubah sebelum keluar ke internet

---

## Tips Packet Tracer

- **Interface default OFF** — selalu `no shutdown` setelah setting IP
- **`do` prefix** — jalankan show command dari dalam mode config: `do show ip route`
- **`?`** — autocomplete dan help kontekstual di setiap mode
- **`show run | section <kata>` / `show run | include <kata>`** — filter output show running-config
- **Urutan konfigurasi yang benar:**
  1. Hostname + password dasar
  2. IP address di tiap interface + `no shutdown`
  3. Routing (static / OSPF)
  4. Fitur tambahan (DHCP, NAT, ACL, SSH)
  5. `write` untuk simpan
- **ACL:** Jangan lupa `permit ip any any` di akhir Extended ACL, atau semua traffic lain akan diblokir oleh implicit deny
- **NAT:** Pastikan `ip nat inside` dan `ip nat outside` sudah di-set sebelum tes konektivitas
