/* =======================================================
 * File: problem.c
 * Deskripsi:
 *   Implementasi fungsi untuk mencari level pada binary tree
 *   yang memiliki jumlah nilai node (sum) terbesar.
 *
 *   Level dari root adalah 1, level anak-anaknya adalah 2, dan seterusnya.
 *   Jika ada lebih dari satu level dengan sum maksimal yang sama,
 *   kembalikan level terkecil (paling atas).
 *
 * ======================================================= */

#include "bintree.h" /* Asumsikan ADT bintree sudah disediakan */
#include <stdio.h>
#include <stdlib.h>

/* =======================================================
 * Fungsi Utama: levelMaxSum
 * =======================================================
 *
 * Deskripsi:
 *   Mengembalikan level dengan jumlah nilai node (sum) terbesar
 *   dari sebuah binary tree.
 *
 * Spesifikasi:
 *   I.S.  : root terdefinisi (mungkin NULL)
 *   F.S.  : Mengembalikan nilai level (integer >= 1)
 *           dengan sum tertinggi.

 * Catatan:
 *   - Jumlah node n ∈ [1, 10^4].
 *   - Nilai node ∈ [-10^5, 10^5].
 *   - Jika ada lebih dari satu level dengan sum maksimal yang sama,
 *     kembalikan level terkecil (paling atas).
 */

/* =======================================================
 * ----------------------- CONTOH 1 ------------------------
 * =========================================================
 * Misal pohon terbentuk:
 *
 *           (1)
 *          /   \
 *        (7)   (0)
 *       /  \
 *     (7)  (-8)
 *
 * Level 1 → sum = 1
 * Level 2 → sum = 7 + 0 = 7
 * Level 3 → sum = 7 + (-8) = -1
 *
 * Hasil: level 2 (7 adalah sum tertinggi)
 * Output : 2
 * ======================================================= */

/*
 * ----------------------- CONTOH 2 ------------------------
 * Misal pohon 2:
 *
 *              (989)
 *                 \
 *                (10250)
 *               /      \
 *           (98693)   (-89388)
 *                      \
 *                      (-32127)
 *
 * Level 1 → sum = 989
 * Level 2 → sum = 10250
 * Level 3 → sum = 98693 + (-89388) = 929305
 * Level 4 → sum = -32127
 *
 * Jadi level dengan jumlah terbesar adalah level 2 (sum = 10250)
 * Output  : 2
 * --------------------------------------------------------
 */

void calculateLevelSums(Address p, int level, long long *sums, int *max_depth) {
  if (isTreeEmpty(p)) {
    return;
  }

  if (level > *max_depth) {
    *max_depth = level;
  }

  sums[level] += ROOT(p);

  calculateLevelSums(LEFT(p), level + 1, sums, max_depth);
  calculateLevelSums(RIGHT(p), level + 1, sums, max_depth);
}

int levelMaxSum(struct TreeNode *root) {
  if (isTreeEmpty(root)) {
    return 0;
  }

  int capacity = 10005;
  long long *sums = (long long *)calloc(capacity, sizeof(long long));

  int max_depth = 0;

  calculateLevelSums(root, 1, sums, &max_depth);

  long long max_sum = sums[1];
  int max_level = 1;

  int i;
  for (i = 2; i <= max_depth; i++) {
    if (sums[i] > max_sum) {
      max_sum = sums[i];
      max_level = i;
    }
  }

  free(sums);

  return max_level;
}
