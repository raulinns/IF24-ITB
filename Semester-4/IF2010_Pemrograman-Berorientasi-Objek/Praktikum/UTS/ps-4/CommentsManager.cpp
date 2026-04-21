#include "CommentsManager.hpp"
#include <algorithm>
using namespace std;

// ======================= YOUR TASK ===========================

/**
 * @brief Menendang/menghapus komentar dari pengguna yang skor reputasinya
 * melebihi batas.
 * @param threshold_score Batas maksimal skor reputasi yang diizinkan sebelum
 * ditendang.
 * @note
 * Hint: apa hayo yang bisa menghapus secara kondisional. kombinasikan remove if
 */
void CommentsManager::kickSpammer(int threshold_score) {
    this->chat_log_.erase(
        std::remove_if(this->chat_log_.begin(), this->chat_log_.end(),
                       [&](auto &e) {
                           return this->reputation_[e.getUsername()] >
                                  threshold_score;
                       }),
        this->chat_log_.end());
}

/**
 * @brief Mencetak semua pelanggaran kata kasar ke layar.
 * * Menelusuri semua chat, dan jika ditemukan kata yang ada di dalam
 * `blacklist_`, program akan mencetak kata tersebut berserta nama pelakunya.
 * Jika tidak ada print "TIDAK ADA PELANGGARAN\n"
 * @note
 * Hint: cuma looping aja kok, tapi sambil cek yak kemunculan elemen setnya. btw
 * loopingnya pake stl yah, jangan pake for/while loop (nanti ngga dianggep
 * bener yah).
 */
void CommentsManager::printViolation() {
    bool kasar = false;
    for_each(this->chat_log_.begin(), this->chat_log_.end(), [&](auto &e) {
        for_each(e.getWords().begin(), e.getWords().end(), [&](auto &f) {
            auto it = this->blacklist_.find(f);
            if (it != this->blacklist_.end()) {
                cout << "kata \"" << *it << "\" oleh akun \"" << e.getUsername()
                     << "\"\n";
                kasar = true;
            }
        });
    });

    if (!kasar) {
        cout << "TIDAK ADA PELANGGARAN\n";
    }
}

/**
 * @brief Mencari pemenang kuis pertama berdasarkan kunci jawaban.
 * @param passwords Set yang berisi kumpulan variasi jawaban yang benar.
 * @return Username dari penonton PERTAMA yang menjawab dengan benar. Jika tidak
 * ada return string "BELUM ADA PEMENANG"
 * * @note
 * HINT: nested searching, manfaatkan algo pencarian dan pengecekan kondisi yang
 * sesuai. Di dalam predicate stl bisa ada algo lain (dikombinasikan) yang
 * memiliki predicate sendiri. pastikan anda memahami cara menggunakan stl
 * beserta predicatenya.
 */
std::string
CommentsManager::quizWinner(const std::set<std::string> &passwords) {
    auto winner_it =
        std::find_if(chat_log_.begin(), chat_log_.end(), [&](const auto &e) {
            return std::any_of(e.getWords().begin(), e.getWords().end(),
                               [&](const auto &f) {
                                   return passwords.find(f) != passwords.end();
                               });
        });

    if (winner_it != chat_log_.end()) {
        return winner_it->getUsername();
    }

    return "BELUM ADA PEMENANG";
}

/**
 * @brief Memprioritaskan komentar pengguna VIP agar mudah dibaca streamer.
 * * Menggeser semua komentar dari pengguna VIP ke bagian paling atas (depan)
 * log chat tanpa merusak urutan waktu masuk dari komentar tersebut.
 * @note
 * HINT: Lakukan partisi pada vector.
 */
void CommentsManager::upVIPComment() {
    std::stable_partition(chat_log_.begin(), chat_log_.end(),
                          [](const auto &e) { return e.isVip(); });
}
