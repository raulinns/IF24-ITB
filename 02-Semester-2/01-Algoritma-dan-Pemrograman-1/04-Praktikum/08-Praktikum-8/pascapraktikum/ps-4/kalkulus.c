#include "kalkulus.h"
#include <stdio.h>

Matrix dilate(Matrix v, int scale) {
	Matrix mDilate;
	createMatrix(ROW_EFF(v) * scale, COL_EFF(v) * scale, &mDilate);
	for (int i = 0; i < ROW_EFF(v); i++) {
		for (int j = 0; j < COL_EFF(v); j++) {
			ELMT(mDilate, i * scale, j * scale) = ELMT(v, i, j);
		}
	}
	return mDilate;
}
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy) {
	Matrix mTranslate;
	createMatrix(ROW_EFF(v) + dx, COL_EFF(v) + dy, &mTranslate);
	for (int i = 0; i < ROW_EFF(v); i++) {
		for (int j = 0; j < COL_EFF(v); j++) {
			ELMT(mTranslate, i + dx, j + dy) = ELMT(v, i, j);
		}
	}
	return mTranslate;
}
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis) {
	Matrix mReflect;
	createMatrix(ROW_EFF(v), COL_EFF(v), &mReflect);
	for (int i = 0; i < ROW_EFF(v); i++) {
		for (int j = 0; j < COL_EFF(v); j++) {
			if (axis == 'x') {
				ELMT(mReflect, i, j) = ELMT(v, i, j * -1);
			} else if (axis == 'y') {
				ELMT(mReflect, i, j) = ELMT(v, i * -1, j);
			}
		}
	}
	return mReflect;
}
/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree) {
	Matrix mRotate;
	createMatrix(ROW_EFF(v), COL_EFF(v), &mRotate);
	for (int i = 0; i < ROW_EFF(v); i++) {
		for (int j = 0; j < COL_EFF(v); j++) {	
			if (degree == 0) {
				ELMT(mRotate, i, j) = ELMT(v, i, j);
			} else if (degree == 90) {
				ELMT(mRotate, i, j) = ELMT(v, j * -1, i);
			} else if (degree == 180) {
				ELMT(mRotate, i, j) = ELMT(v, i * -1, j * -1);
			} else if (degree == 270) {
				ELMT(mRotate, i, j) = ELMT(v, j, i * -1);
			}
		}
	}
	return mRotate;
}
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */
