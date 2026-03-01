def coin_exchange_greedy(koin_tersedia, target_uang):
    """
    Menyelesaikan persoalan penukaran uang menggunakan strategi Greedy.
    Strategi: Pilih koin dengan nilai terbesar yang tidak melebihi sisa uang.
    """
    # Langkah 1: Urutkan koin dari nilai terbesar ke terkecil (non-increasing)
    # Kompleksitas pengurutan: O(n log n)
    koin_tersedia.sort(reverse=True)
    
    himpunan_solusi = []
    sisa_uang = target_uang
    
    # Langkah 2: Iterasi melalui setiap koin yang sudah terurut
    for koin in koin_tersedia:
        # Selama koin tersebut masih bisa digunakan (tidak melebihi sisa uang)
        while sisa_uang >= koin:
            himpunan_solusi.append(koin) # Fungsi Seleksi & Kelayakan
            sisa_uang -= koin             # Update sisa uang
            
    # Langkah 3: Periksa apakah target uang berhasil terpenuhi (Fungsi Solusi)
    if sisa_uang == 0:
        return himpunan_solusi
    else:
        return None

# Contoh Penggunaan (Kasus Kanonik: Selalu Optimal)
denominasi = [1, 5, 10, 25]
target = 32
solusi = coin_exchange_greedy(denominasi, target)

if solusi:
    print(f"Target: {target}")
    print(f"Koin yang digunakan: {solusi}")
    print(f"Jumlah koin minimum: {len(solusi)}")
else:
    print("Tidak ada solusi yang tepat untuk target tersebut.")

# Contoh Kasus Non-Kanonik (Greedy mungkin tidak optimal)
# Koin: [5, 4, 3, 1], Target: 7
# Greedy akan menghasilkan [5, 1, 1] (3 koin)
# Optimal seharusnya [4, 3] (2 koin)
