#include "../helper/helper.h"

/** Merges two sorted subarrays into one sorted subarray.
 * @param arr The array containing the two sorted subarrays.
 * @param p The index of the first element of the left subarray.
 * @param q The index of the last element of the left subarray.
 * @param r The index of the last element of the right subarray.
 * @details Time Complexity: O(n*log(n))
 * @details Input: arr sequence of n numbers arr = {a1, a2, ..., an}.
 * @details Output: arr permutation (reordering) arr' of the input sequence such that arr' is sorted (a1' <= a2' <= ... <= an').
 */
void merge(int* arr, int p, int q, int r) {
	//  1 nL = q - p + 1       // length of A[p:q]
	//  2 nR = r - q           // length of A[q+1:r]
	//  3 let L[0:nL-1] and R[0:nR-1]
	//  4 for i = 0 to nL - 1  // copy A[p:q] to L[0:nL-1]
	//  5   L[i] = A[p+i]
	//  6 for j = 0 to nR - 1  // copy A[q+1:r] to R[0:nR-1]
	//  7   R[j] = A[q+j+1]
	//  8 i = 0                // i is an index of the smallest remaining element in L
	//  9 j = 0                // j is an index of the smallest remaining element in R
	// 10 k = p                // k is an index of the location in A to fill
	// 11 // While each of the arrays L and R have an unmerged element, copy the smallest unmerged element back into A[p:r].
	// 12 while i < nL and j < nR
	// 13   if L[i] <= R[j]
	// 14     A[k] = L[i]
	// 15     i = i + 1
	// 16   else A[k] = R[j]
	// 17     j = j + 1
	// 18   k = k + 1
	// 19 // When we went through one of L or R entirely, copy the remainder of the other to the end of A[p:r].
	// 20 while i < nL
	// 21   A[k] = L[i]
	// 22   i = i + 1
	// 23   k = k + 1
	// 24 while j < nR
	// 25   A[k] = R[j]
	// 26   j = j + 1
	// 27   k = k + 1

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
	// Loop Invariant: At the start of each iteration of the for loop, the subarray A[p:k-1] contains the sorted elements from the merged subarrays L and R.
	// Initialization: Before the loop i=j=0 and k=p, so the subarray A[p:k-1] is empty and trivially sorted.
	// Maintenance: The loop invariant holds before and after each iteration of the loop as the smallest element of the two subarrays is copied into the merged subarray.
	// Termination: The loop terminates when either i >= nL or j >= nR. In either case, all elements of one of the subarrays have been copied into the merged subarray, and the remaining elements of the other subarray are greater than all elements in the merged subarray. Therefore, the merged subarray is sorted.
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
