#include "../helper/helper.h"

/** Merges two sorted subarrays into one sorted subarray.
 * @param arr The array containing the two sorted subarrays.
 * @param p The index of the first element of the left subarray.
 * @param q The index of the last element of the left subarray.
 * @param r The index of the last element of the right subarray.
 */
void merge(int* arr, int p, int q, int r) {
	// Length of the left subarray.
	const int leftLen = q - p + 1;

	// Length of the right subarray.
	const int rightLen = r - q;

	// Allocate memory for the left and right subarrays.
	int left[leftLen + 1], right[rightLen + 1];

	// Copy the left subarray into the allocated memory.
	for (int i = 0; i < leftLen; i++) {
		left[i] = arr[p + i];
	}

	// Copy the right subarray into the allocated memory.
	for (int j = 0; j < rightLen; j++) {
		right[j] = arr[q + j + 1];
	}

	// i indexes the smallest remaining element in the left subarray.
	int i = 0;

	// j indexes the smallest remaining element in the right subarray.
	int j = 0;

	// k indexes the next available position in the merged array.
	int k = p;

	// As long as there are elements in both subarrays, copy the smallest element into the merged array.
	while (i < leftLen && j < rightLen) {
		if (left[i] <= right[j]) {
			// If the smallest remaining element in the left subarray is smaller than the smallest remaining element in the right subarray, copy the smallest remaining element in the left subarray into the merged array.
			arr[k] = left[i];
			i++;
		} else {
			// Else, copy the smallest remaining element in the right subarray into the merged array.
			arr[k] = right[j];
			j++;
		}
		// Increment the index of the next available position in the merged array.
		k++;
	}

	// Copy the remaining elements of the left subarray into the merged array.
	while (i < leftLen) {
		arr[k] = left[i];
		i++;
		k++;
	}

	// Copy the remaining elements of the right subarray into the merged array.
	while (j < rightLen) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int* arr, int p, int r) {
	// MERGE-SORT.A; p; r/
	// 1 if p >= r // zero or one element?
	// 2   return
	// 3 q = ⎣(p + r) / 2⎦ // midpoint of A[p:r]
	// 4 MERGE-SORT(A, p, q) // recursively sort A[p:q]
	// 5 MERGE-SORT(A, q+1, r) // recursively sort A[q+1:r]
	// 6 MERGE(A, p, q, r) // Merge A[p:q] and A[q+1:r] into A[p:r].

	// If the subarray has at most one element, it is already sorted.
	if (p >= r) {
		return;
	}

	// If the subarray has more than one element, split the subarray into two subarrays.
	const int q = (p + r) / 2;

	// Sort the left subarray.
	mergeSort(arr, p, q);

	// Sort the right subarray.
	mergeSort(arr, q + 1, r);

	// Merge the sorted subarrays.
	merge(arr, p, q, r);
}

int main() {
	// The array to be sorted.
	int A[] = {5, 2, 15, 13, 4, 6, 1, 3, 9, 12, 11};

	// Number of elements in the array.
	constexpr int lengthOfA = sizeof(A) / sizeof(int);

	// Before sorting.
	print_arr(A, lengthOfA, -1, "Input");

	// Sort the array.
	mergeSort(A, 0, lengthOfA - 1);

	// After sorting.
	print_arr(A, lengthOfA, -1, "Output");

	return 0;
}
