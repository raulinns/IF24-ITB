#include "Penganan.hpp"
#include <iostream>

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() {
    SetKeik(0);
    SetPanekuk(0);
}

// ctor dengan parameter
Penganan::Penganan(int keik, int panekuk) {
    SetKeik(keik);
    SetPanekuk(panekuk);
}

// mengembalikan bagian jumlah keik
int Penganan::GetKeik() const { return keik; }

// mengembalikan bagian jumlah panekuk
int Penganan::GetPanekuk() const { return panekuk; }

// mengisi bagian keik
void Penganan::SetKeik(int k) { keik = k; }

// mengisi bagian panekuk
void Penganan::SetPanekuk(int p) { panekuk = p; }

Penganan operator+(const Penganan &a, const Penganan &b) {
    Penganan::n_rumah++;
    return Penganan(a.keik + b.keik, a.panekuk + b.panekuk);
}

Penganan operator-(const Penganan &a, const Penganan &b) {
    int k = (a.keik >= b.keik) ? b.keik : a.keik;
    int p = (a.panekuk >= b.panekuk) ? b.panekuk : a.panekuk;

    Penganan::uang += k * 51 + p * 37;

    return Penganan(a.keik - k, a.panekuk - p);
}

Penganan operator^(const Penganan &p, const int n) {
    int hutangK = (p.keik - n < 0) ? p.keik - n : 0;
    int hutangP = (p.panekuk - n < 0) ? p.panekuk - n : 0;

    int kBaru = (p.keik - n < 0) ? 0 : p.keik - n;
    int pBaru = (p.panekuk - n < 0) ? 0 : p.panekuk - n;

    Penganan::uang += hutangK * 51 + hutangP * 37;
    return Penganan(kBaru, pBaru);
}

Penganan operator^(const int n, const Penganan &p) { return p ^ n; }

// mengembalikan jumlah uang yang diperoleh
int Penganan::JumlahUang() { return uang; }

// mengembalikan jumlah kunjungan ke rumah
int Penganan::HitungNRumah() { return n_rumah; }

void Penganan::Print() {
    std::cout << keik << "keik-" << panekuk << "panekuk" << std::endl;
}
