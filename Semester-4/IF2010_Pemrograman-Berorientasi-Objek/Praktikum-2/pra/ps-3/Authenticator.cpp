#include "Authenticator.hpp"

Authenticator::Authenticator() {
    for (int i = 0; i < MAX_USERS; i++) {
        users[i] = nullptr;
    }

    userCount = 0;
    currentUser = nullptr;
    secretResource = "Ini adalah data rahasia!";
}

void Authenticator::registerUser(const string &username, const string &password,
                                 bool isAdmin) {
    if (userCount >= MAX_USERS) {
        cout << "Gagal: Kapasitas user penuh!" << endl;
        return;
    }

    for (int i = 0; i < userCount; i++) {
        if (username == users[i]->getUsername()) {
            cout << "Gagal: Username sudah digunakan!" << endl;
            return;
        }
    }

    User *newUser;

    if (isAdmin)
        newUser = new AdminUser(username, password);
    else
        newUser = new User(username, password);

    users[userCount++] = newUser;
    cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
}

void Authenticator::login(const string &username, const string &password) {
    for (int i = 0; i < userCount; i++) {
        if (users[i]->getUsername() == username &&
            users[i]->checkPassword(password)) {
            currentUser = users[i];
            cout << "Sukses: Login berhasil! Selamat datang, " << username
                 << "." << endl;
            return;
        }
    }
    cout << "Gagal: Username atau password salah!" << endl;
}

void Authenticator::logout() {
    if (currentUser == nullptr) {
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        string name = currentUser->getUsername();
        cout << "Sukses: User " << name << " telah logout." << endl;
        currentUser = nullptr;
    }
}

void Authenticator::accessResource() const {
    if (currentUser == nullptr) {
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: " << secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource) {
    if (currentUser == nullptr) {
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih "
                "dahulu."
             << endl;
        return; // WAJIB ada return agar tidak crash di bawah
    }

    if (!currentUser->isAdmin()) { // Gunakan negasi '!'
        cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat "
                "melakukan ini."
             << endl;
    } else {
        secretResource = newResource;
        cout << "Sukses: Resource telah diperbarui oleh "
             << currentUser->getUsername() << "." << endl;
    }
}

Authenticator::~Authenticator() {
    for (int i = 0; i < userCount; ++i) {
        delete users[i];
    }
}
