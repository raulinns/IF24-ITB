#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {

  private:
    string name;
    string nim;
    float ipk;
    int total_sks;

  public:
    static int counter;
    Mahasiswa() : Mahasiswa("NPC") {}

    Mahasiswa(string name) : name{name}, nim{"135" + to_string(counter)}, ipk{0.0f}, total_sks{0} {
        counter++;
    }

    void tambahNilai(float nilai, int total_sks) {
        this->ipk = (this->ipk * this->total_sks + nilai * total_sks) /
                    (this->total_sks + total_sks);
        this->total_sks += total_sks;
    }

    void info() const {
        cout << "INFORMASI MAHASISWA" << endl
             << "Nama: " << name << endl
             << "NIM: " << nim << endl;
        printf("IPK: %.2f\n", ipk);
        cout << "SKS: " << total_sks << endl;
    }
};

int Mahasiswa::counter = 0;
