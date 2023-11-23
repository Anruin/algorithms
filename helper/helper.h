//
// Created by Hackerman on 18.11.2023.
//

#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>

/** Helper function to print an array.
 * @param A The array to be printed.
 * @param length The number of elements in the array.
 * @param k The number of elements to be printed. If k is less than 0, all elements are printed.
 * @param msg The message to be printed before the array.
 */
static void print_arr(int A[], const int length, const int k, char* msg) {
	printf_s("\n%s: ", msg);
	for (int i = 0; i < length; i++) {
		if (i < k || k < 0) {
			printf_s("%x ", A[i]);
		} else {
			printf_s("_ ");
		}
	}
}

#endif //HELPER_H
