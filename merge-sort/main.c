#include <stdio.h>
#include "../helper/helper.h"

void merge(int* arr, int p, int q, int r) {
	// Length of the left subarray.
	int nLeft = q - p + 1;

	// Length of the right subarray.
	int nRight = r - q;

	// Allocate memory for the left and right subarrays.
	int left[nLeft + 1], right[nRight + 1];

	// Copy the left subarray into the allocated memory.
	for (int i = 0; i < nLeft; i++) {
		left[i] = arr[p + i];
	}

	// Copy the right subarray into the allocated memory.
	for (int j = 0; j < nRight; j++) {
		right[j] = arr[q + j + 1];
	}

	// i indexes the smallest remaining element in the left subarray.
	int i = 0;

	// j indexes the smallest remaining element in the right subarray.
	int j = 0;

	// k indexes the next available position in the merged array.
	int k = p;

	// As long as there are elements in both subarrays, copy the smallest element into the merged array.
	while (i < nLeft && j < nRight) {
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
	while (i < nLeft) {
		arr[k] = left[i];
		i++;
		k++;
	}

	// Copy the remaining elements of the right subarray into the merged array.
	while (j < nRight) {
		arr[k] = right[j];
		j++;
		k++;
	}
}
