#include <stdio.h>
#include "../helper/helper.h"

/**
 * @brief Selection Sort algorithm implementation. Sorts an array of integers in ascending order.
 * @param arr The array to be sorted.
 * @param length The number of elements in the array.
 * @details Time complexity: O(n^2)
 * @details Input: arr sequence of n numbers arr = {a1, a2, ..., an}.
 * @details Output: arr permutation (reordering) arr' of the input sequence such that arr' is sorted (a1' <= a2' <= ... <= an').
 * @details Loop invariant: At the each iteration of the loop, the subarray arr[0..i-1] contains the i-1 smallest elements of arr in ascending sorted order. Arter n-1 iterations, the entire array is sorted.
 * @details Initialization: arr[0..0] is empty and thus trivially sorted.
 * @details Maintenance: Each iteration of the loop adds the smallest element of arr[i..n-1] to the subarray arr[0..i-1].
 * @details Termination: The loop terminates when i == n-1. At this point, the subarray arr[0..n-2] contains the n-1 smallest elements of arr in ascending sorted order. The last element is already in its correct position.
 */
void selection_sort(int arr[], const int length) {
	// SELECTION-SORT(A,n):
	// for i = 0 to n
	//   m = i
	//   for j = i + 1 to n
	//     if A[j] < A[m]
	//       m = j
	//   // Exclude the case when A[i] == A[m] to avoid unnecessary swaps.
	//   if A[i] > A[m]
	//     swap A[i] with A[m]

	for (int i = 0; i < length; i++) {
		int m = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[m]) {
				m = j;
			}
		}

		if (arr[i] > arr[m]) {
			printf_s("\nSwap %x [%d] with %x [%d]", arr[i], i, arr[m], m);
			const int t = arr[i];
			arr[i] = arr[m];
			arr[m] = t;

			print_arr(arr, length, i, "");
		}
	}
}

int main() {
	// The array to be sorted.
	int A[] = {5, 2, 15, 13, 4, 6, 1, 3, 9, 12, 11};

	// Number of elements in the array.
	constexpr int lengthOfA = sizeof(A) / sizeof(int);

	// Before sorting.
	print_arr(A, lengthOfA, -1, "Input");

	selection_sort(A, lengthOfA);

	// After sorting.
	print_arr(A, lengthOfA, -1, "Output");

	return 0;
}
