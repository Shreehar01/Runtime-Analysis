#ifndef ARRAY_H
#define ARRAY_H
#include <array>
#include <set>
#include <cmath>
#include <chrono>



/**
 * @brief Calculates the runtime of appending in an array.
 *
 * @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
 *
 * @returns the runtime of appending in an array in nanoseconds.
 */
double runtime_append(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of removing an element from the back of an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of removing an element from the back of an array in nanoseconds.
*/
double runtime_remove_back(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of prepending an element in an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of prepending an element in an array in nanoseconds.
*/
double runtime_prepend(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of removing an element from the front of an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of removing an element from the front of an array in nanoseconds.
*/
double runtime_remove_front(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of swapping two elements in an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of swapping two elements in an array in nanoseconds.
*/
double runtime_swap(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of removing all the elements of an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of removing all the elements of an array in nanoseconds.
*/
double runtime_empty(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of inserting an element in the front of an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of inserting an element in the front of an array in nanoseconds.
*/
double runtime_insert(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of removing duplicates from an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of removing duplicates from an array in nanoseconds.
*/
double runtime_remove_duplicates(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of reversing the elements of an array.
*
* @param A std::array that consists of a number of elements and a variable that stores the length of the number of elements in the array.
*
* @returns the runtime of reversing the elements of an array in nanoseconds.
*/
double runtime_reverse(std::array<int, 1025> array1, int elements);


/**
* @brief Calculates the runtime of executing different functions in an array and stores it in another array.
*
* @param A pointer to an array that will store the runtimes and a pointer to an array that consists of elements to be assigned to std::array.
*/
void calculate_runtime_array(double* data, int* numbers);



double runtime_append(std::array<int, 1025> array1, int elements) {
	int value = -1;                     // Variable that stores value that is to be appended.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	array1[elements] = value;
	elements++;                        // Number of elements in the array is increased by 1.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);             // The time duration is converted to nanoseconds.
}


double runtime_remove_back(std::array<int, 1025> array1, int elements) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	array1[elements] = '\0';                   //The last element is assigned null.
	elements--;								   // Number of elements in the array is decreased by 1.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);       // The time duration is converted to nanoseconds.
}


double runtime_prepend(std::array<int, 1025> array1, int elements) {
	int value = -1;                            // Variable that stores value that is to be prepended.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();                               
	for (int i = elements; i > 0; i--) {
		array1[i] = array1[i - 1];
	}
	array1[0] = value;                         // Value is prepended in the array1.
	elements++;                                // Number of elements in the array is increased by 1.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);     // The time duration is converted to nanoseconds.
}


double runtime_remove_front(std::array<int, 1025> array1, int elements) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	for (int i = 0; i < elements - 1; i++) {
		array1[i] = array1[i + 1];
	}
	array1[elements - 1] = '\0';            // The last value in the array is stored as null.
	elements--;								// Number of elements in the array is decreased by 1.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);   // The time duration is converted to nanoseconds.
}


double runtime_swap(std::array<int, 1025> array1, int elements) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	array1[0] = array1[elements - 1];      // The first and last elements of the array are swapped.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);          // The time duration is converted to nanoseconds.
}


double runtime_empty(std::array<int, 1025> array1, int elements) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	for (int i = 0; i < elements; i++) {
		array1[i] = '\0';                                //All the elements of the array are stored as null.
	}
	elements = 0;                                        // The number of elements in the arrays is 0.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);                // The time duration is converted to nanoseconds.
}


double runtime_insert(std::array<int, 1025> array1, int elements) {
	int value = -1;                            // Variable that stores value that is to be inserted in the beginning.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	for (int i = elements; i > 0; i--) {
		array1[i] = array1[i - 1];
	}
	array1[0] = value;                         // Value is inserted in the beginning in the array1.
	elements++;                                // Number of elements in the array is increased by 1.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);     // The time duration is converted to nanoseconds.
}


double runtime_remove_duplicates(std::array<int, 1025> array1, int elements) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::sort(array1.begin(), array1.begin() + elements);
	int j = 0;
	for (int i = 0; i < elements - 1; i++) {
		if (array1[i] != array1[i + 1]) {
			array1[j++] = array1[i];
		}
	}
	array1[j++] = array1[elements - 1];
	// Filling the values in the end with null to mimic removal of duplicate values. 
	for (int i = j; i < elements; i++) {
		array1[i] = '\0';
	}
	elements = j;            // The number of elements occupying the array is changed(decreased).
	
	// This can also be done by using set from stl
	/*
	std::set<int> set1;                     // A set that stores the unique elements of the array1.
	for (int i = 0; i < elements; i++) {
		set1.insert(array1[i]);             // Inserting the elements of the array into the set.      
	}
	std::set<int>::iterator ptr;
	int initial_size = elements;            // Storing the size of the array1  
	elements = 0;                           // Setting the size of the array1 as 0 so that values can be stored from the beginning.
	for (ptr = set1.begin(); ptr != set1.end(); ++ptr) {
		array1[elements++] = *ptr;           //Storing values from set back into the array1.
	}
	for (int i = elements; i < initial_size; i++) {
		array1[i] = '\0';                    // Storing null in the array1's space which are no longer occupied. 
	}
	*/

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);     // The time duration is converted to nanoseconds.
}


double runtime_reverse(std::array<int, 1025> array1, int elements) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	int temp = 0;
	for (int i = 0, j = elements - 1; i < j; i++, j--) {
		temp = array1[i];
		array1[i] = array1[j];
		array1[j] = temp;
	}
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);   // The time duration is converted to nanoseconds.
}


void calculate_runtime_array(double* data, int* numbers) {
	std::array<int, 1025> array1;   // An array that stores varying number of elements.
	int elements = 0;               // Number of elements the array1.
	int index = -1;                 // A variable that stores the index on which a particular runtime is to be stored.
	array1[0] = numbers[0];         
	bool trial = true;              // A variable that determines if trial run is to be performed.
	
	// Assigning values to array1 and calculating the runtimes to store them in "data" array.
	for (int i = 2; i <= 1024; i = i * 2) {
		for (int j = i / 2; j < i; j++) {
			array1[j] = numbers[j];   
		}
		elements = i;              // array1's length is changed.
		// Trial run so that initial values of runtimes for any given function are not excessively high.
		if (trial) {
			runtime_append(array1, elements);
			runtime_remove_back(array1, elements);
			runtime_prepend(array1, elements);
			runtime_remove_front(array1, elements);
			runtime_swap(array1, elements);
			runtime_empty(array1, elements);
			runtime_insert(array1, elements);
			runtime_remove_duplicates(array1, elements);
			runtime_reverse(array1, elements);
			trial = false;
		}
		data[++index] = elements;
		data[++index] = runtime_append(array1, elements);
		data[++index] = runtime_remove_back(array1, elements);
		data[++index] = runtime_prepend(array1, elements);
		data[++index] = runtime_remove_front(array1, elements);
		data[++index] = runtime_swap(array1, elements);
		data[++index] = runtime_empty(array1, elements);
		data[++index] = runtime_insert(array1, elements);
		data[++index] = runtime_remove_duplicates(array1, elements);
		data[++index] = runtime_reverse(array1, elements);
	}
}


#endif