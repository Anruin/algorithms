#include <stdio.h>
#include "helper.h"
// #include <SDL3/SDL.h>
// #if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
// #define SDL_MAIN_HANDLED
// #endif
#include <math.h>
//#define SDL_MAIN_NOIMPL
#include <SDL3/SDL_main.h>

//#include <SDL3_ttf/SDL_ttf.h>

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

// static SDL_bool bQuit = SDL_FALSE;

// void MainLoop() {
// 	SDL_Event event;
// 	while (SDL_PollEvent(&event)) {
// 		if (event.type == SDL_EVENT_QUIT) {
// 			bQuit = SDL_TRUE;
// 		}
// 		if (event.type == SDL_EVENT_KEY_DOWN) {
// 			if (event.key.keysym.sym == SDLK_ESCAPE) {
// 				bQuit = SDL_TRUE;
// 			} else if (event.key.keysym.sym == SDLK_SPACE) {
// 				// Advance one step.
// 			}
// 		}
// 		break;
// 	}
//
// 	auto time = SDL_GetTicks() / 1000.0;
// 	auto red = (sin(time) + 1.0) / 2.0;
// 	auto green = (cos(time) + 1.0) / 2.0;
// 	auto blue = (sin(time + 1.0) + 1.0) / 2.0;
//
// 	SDL_SetRenderDrawColor(Renderer, red * 255, green * 255, blue * 255, 255);
// 	SDL_RenderClear(Renderer);
// 	SDL_RenderPresent(Renderer);
// }
//
// void drawText(SDL_Surface* screen, char* string, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB) {
// 	TTF_Font* font = TTF_OpenFont("ARIAL.TTF", size);
//
// 	SDL_Color foregroundColor = {fR, fG, fB};
// 	SDL_Color backgroundColor = {bR, bG, bB};
//
// 	SDL_Surface* textSurface
// 			= TTF_RenderText_Shaded
// 			(font, string, foregroundColor, backgroundColor);
//
// 	SDL_Rect textLocation = {x, y, 0, 0};
//
// 	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
//
// 	SDL_DestroySurface(textSurface);
//
// 	TTF_CloseFont(font);
// }

int main(int argc, char* argv[]) {
	// SDL_Log("Hello World!\n");
	//
	// if (SDL_Init(SDL_INIT_EVERYTHING)) {
	// 	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init failed: %s\n", SDL_GetError());
	// 	return 1;
	// }
	//
	// SDL_Window* Window = SDL_CreateWindow("Window", 640, 480, SDL_WINDOW_RESIZABLE);
	// if (!Window) {
	// 	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindow failed: %s\n", SDL_GetError());
	// 	return 1;
	// }
	//
	// SDL_Renderer* Renderer = nullptr;
	//
	// Renderer = SDL_CreateRenderer(Window, nullptr, 0);
	// if (!Renderer) {
	// 	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
	// 	return 1;
	// }
	//
	// SDL_ShowWindow(Window); {
	// 	int w, h, backbufferW, backbufferH;
	// 	SDL_GetWindowSize(Window, &w, &h);
	// 	SDL_GetWindowSizeInPixels(Window, &backbufferW, &backbufferH);
	// 	SDL_Log("Window size: %d x %d\n", w, h);
	// 	SDL_Log("Window backbuffer size: %d x %d\n", backbufferW, backbufferH);
	// 	if (backbufferW != w || backbufferH != h) {
	// 		SDL_Log("Renderer uses scaled backbuffer!\n");
	// 	}
	// }
	//
	// SDL_Log("Press ESC or close window to exit.\n");

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
