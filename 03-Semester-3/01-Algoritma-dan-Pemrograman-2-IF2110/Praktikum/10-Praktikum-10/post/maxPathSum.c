#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* =======================================================
 * Fungsi Utama: maxPathSum
 * =======================================================
 *
 * Deskripsi:
 *   Mengembalikan nilai maksimum yang bisa dicapai oleh sebuah path
 *   pada binary tree.
 *
 * Spesifikasi:
 *   I.S.  : root terdefinisi (boleh NULL)
 *   F.S.  : Mengembalikan integer berupa maksimum path sum.
 *
 * Catatan:
 *   - Path boleh:
 *       * hanya satu node
 *       * melalui root atau tidak melalui root
 *       * melalui kiri → parent → kanan
 *       * setiap node hanya boleh dilewati satu kali.
 *       * dimulai dan diakhiri di node mana pun,
 *   - Setiap node ∈ [-10^5, 10^5]
 *   - Jumlah node n ∈ [1, 10^4]
 *
 * =======================================================
 */


/* =======================================================
 * ----------------------- CONTOH 1 -----------------------
 * =======================================================
 *
 *           (1)
 *          /   \
 *        (2)   (3)
 *
 * Semua path dan sum-nya:
 *  Path terbaik: 2 → 1 → 3 = 6
 *
 * Output: 6
 * =======================================================
 */


/* =======================================================
 * ----------------------- CONTOH 2 ------------------------
 * =======================================================
 *
 *                 (-10)
 *                 /    \
 *              (9)     (20)
 *                     /    \
 *                   (15)   (7)
 *
 * Path terbaik: 15 → 20 → 7 = 42
 *
 * Output: 42
 * --------------------------------------------------------
 */

int maxPathSumUtil(BinTree node, int *max_val) {
    if (isTreeEmpty(node)) {
        return 0;
    }

    int leftGain = maxPathSumUtil(LEFT(node), max_val);
    if (leftGain < 0) leftGain = 0;

    int rightGain = maxPathSumUtil(RIGHT(node), max_val);
    if (rightGain < 0) rightGain = 0;

    int currentPathSum = leftGain + rightGain + ROOT(node);

    if (currentPathSum > *max_val) {
        *max_val = currentPathSum;
    }

    if (leftGain > rightGain) {
        return ROOT(node) + leftGain;
    } else {
        return ROOT(node) + rightGain;
    }
}

int maxPathSum(BinTree root) {
    int globalMax = -1000000000;
   
    if (isTreeEmpty(root)) {
        return 0;
    }

    maxPathSumUtil(root, &globalMax);
    /*
     * TODO:
     * - Implementasikan logika untuk mencari path sum maksimum.
     * - Boleh menambahkan fungsi rekursif helper bila diperlukan.
     * - Perhatikan kasus node bernilai negatif.
     */
    
    return globalMax;
}

