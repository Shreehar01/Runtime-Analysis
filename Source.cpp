#include <iostream>
#include "array_runtime.h"
#include "vector_runtime.h"
#include "forwardlist_runtime.h"
#include "list_runtime.h"
#include "output_runtime.h"

int main() {
	
	// Initializing the numbers that will be assigned to different containers
	int numbers[1024];    // An array that stores the unique numbers to assign them to different containers  
	for (int i = 1023; i > 0 ; i--) {
		numbers[i] = i;    // Unique values are assigned to the "numbers" array.
	}
	numbers[0] = numbers[1];    // The first two elements of the numbers are made to be same. 
	// This ensures the total number of repetitions remains constant regardless of the number of elements in a container.
	double data[100];    // An array that stores the runtime of containers for a given number of elements.
	
	// Executing runtimes of different containers and Printing and Saving them.
	int container = 0;   // Variable that determines which container's runtime to be calculated, printed, and saved.
	while (container < 4) {
		switch (container) {
			case 0:
				calculate_runtime_array(data, numbers);  //Calculating runtime for array.
				break;
			case 1:
				calculate_runtime_vector(data, numbers); //Calculating runtime for vector.
				break;
			case 2:
				calculate_runtime_forwardlist(data, numbers);  //Calculating runtime for forward list.
				break;
			case 3:
				calculate_runtime_list(data, numbers);   //Calculating runtime for list.
				break;
		}
		display_runtime(data, container);  // Displaying the runtimes.
		save_runtime(data, container);     // Saving the runtimes in a file.
		container++;
	}
	system("pause");
	return 0;
}