#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
	return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q) {
	if (IDX_HEAD(q) == 0) return (IDX_TAIL(q) == CAPACITY - 1);
	else return (IDX_TAIL(q) == IDX_HEAD(q) - 1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q) {
	if ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF)) return 0;
	else if (IDX_HEAD(q) == IDX_TAIL(q)) return 1;
	else if (IDX_HEAD(q) < IDX_TAIL(q)) return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
	else if (IDX_TAIL(q) < IDX_HEAD(q)) return ((CAPACITY - IDX_HEAD(q)) + (IDX_TAIL(q) + 1));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
	if (isFull(*q)) return;
	else if (isEmpty(*q)) {
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
		HEAD(*q) = val;
	}	else {
		if (IDX_TAIL(*q) < (CAPACITY - 1)) {
			IDX_TAIL(*q) = IDX_TAIL(*q) + 1;
			TAIL(*q) = val;
		} else if (IDX_TAIL(*q) == CAPACITY - 1) {
			IDX_TAIL(*q) = 0;
			TAIL(*q) = val;
		}
	}
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh. Jangan lakukan apapun apabila penampung penuh. */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val) {	
	if (isEmpty(*q)) return;

	*val = HEAD(*q);
	if (length(*q) == 1) {
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	} else {
		if (IDX_HEAD(*q) < (CAPACITY - 1)) {
			IDX_HEAD(*q) = IDX_HEAD(*q) + 1;
		} else if (IDX_HEAD(*q) == CAPACITY - 1) {
			IDX_HEAD(*q) = 0;
		}
	}
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, jangan lakukan apa-apa bila kosong*/
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q) {
    printf("[");
    if (!isEmpty(q)) {
        int i = IDX_HEAD(q);
        boolean isFirst = TRUE;
        do {
            if (!isFirst) {
                printf(",");
            }
            printf("%d", q.buffer[i]);
            isFirst = FALSE;
            i = (i + 1) % CAPACITY;
        } while (i != (IDX_TAIL(q) + 1) % CAPACITY);
    }
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang setiap elemen queue, termasuk spasi dan enter */
/* Tambahkan \n ketika Queue sudah selesai di tulis */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */