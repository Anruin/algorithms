#include <stdio.h>
#include "../helper/helper.h"

/**
 * @brief Insertion Sort algorithm implementation. Sorts an array of integers in ascending order.
 * @param arr The array to be sorted.
 * @param length The number of elements in the array.
 * @details Time Complexity: O(n^2)
 * @details Input: arr sequence of n numbers arr = {a1, a2, ..., an}.
 * @details Output: arr permutation (reordering) arr' of the input sequence such that arr' is sorted (a1' <= a2' <= ... <= an').
 * @details Loop Invariant: At the start of each iteration of the for loop, the subarray arr[0..j-1] consists of the elements originally in arr[0..j-1], but in sorted order.
 * @details Initialization: arr[0..j-1] is empty and thus trivially sorted.
 * @details Maintenance: Each iteration of the for loop expands the subarray arr[0..j-1] by inserting the correct element into its proper place.
 * @details Termination: The subarray arr[0..j-1] is the entire sorted array arr.
 */
void insertion_sort(int arr[], const int length) {
	// INSERTION-SORT(A,n):
	// for j = 1 to A.length - 1
	//    key = A[j]
	//    i = j - 1
	//    while i >= 0 and A[i] > key
	//       A[i + 1] = A[i]
	//       i = i - 1
	//    A[i + 1] = key

	for (int j = 1; j < length; j++) {
		char msg[50];
		sprintf_s(msg, 50, "Maintenance invariant arr[0:j-1] (j=%d): ", j);
		print_arr(arr, length, j, msg);

		// The key to be inserted into the sorted sequence arr[0..i-1].
		const int key = arr[j];

		// Index of the previous element in the sorted sequence arr[0..i-1].
		int i = j - 1;

		// Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position, going from right to left.
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}

		arr[i + 1] = key;
	}
}

int main() {
	// The array to be sorted.
	int A[] = {5, 2, 15, 13, 4, 6, 1, 3, 9, 12, 11};

	// Number of elements in the array.
	constexpr int lengthOfA = sizeof(A) / sizeof(int);

	// Before sorting.
	print_arr(A, lengthOfA, -1, "Input");

	insertion_sort(A, lengthOfA);

	// After sorting.
	print_arr(A, lengthOfA, -1, "Output");

	return 0;
}
