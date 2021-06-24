#ifndef VEcTOR_H
#define VECTOR_H
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>



/**
 * @brief Calculates the runtime of appending in a vector.
 *
 * @param A vector that consists of a number of elements.
 *
 * @returns the runtime of appending in a vector in nanoseconds.
 */
double runtime_append(std::vector<int> vector1);


/**
* @brief Calculates the runtime of removing an element from the end of a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of removing an element from the end of a vector in nanoseconds.
*/
double runtime_remove_back(std::vector<int> vector1);


/**
 * @brief Calculates the runtime of prepending in a vector.
 *
 * @param A vector that consists of a number of elements.
 *
 * @returns the runtime of prepending in a vector in nanoseconds.
 */
double runtime_prepend(std::vector<int> vector1);


/**
* @brief Calculates the runtime of removing an element from the front of a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of removing an element from the front of a vector in nanoseconds.
*/
double runtime_remove_front(std::vector<int> vector1);


/**
* @brief Calculates the runtime of swapping two elements in a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of swapping two elements in a vector in nanoseconds.
*/
double runtime_swap(std::vector<int> vector1);


/**
* @brief Calculates the runtime of removing all the elements from a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of removing all the elements from a vector in nanoseconds.
*/
double runtime_empty(std::vector<int> vector1);


/**
* @brief Calculates the runtime of inserting an element in the front of a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of inserting an element in the front of a vector in nanoseconds.
*/
double runtime_insert(std::vector<int> vector1);


/**
* @brief Calculates the runtime of removing duplicates from a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of removing duplicates from a vector in nanoseconds.
*/
double runtime_remove_duplicates(std::vector<int> vector1);


/**
* @brief Calculates the runtime of reversing elements in a vector.
*
* @param A vector that consists of a number of elements.
*
* @returns the runtime of reversing elements in a vector in nanoseconds.
*/
double runtime_reverse(std::vector<int> vector1);


/**
* @brief Calculates the runtime of executing different functions in a vector and stores it in an array.
*
* @param A pointer to an array that will store the runtimes and a pointer to an array that consists of elements to be assigned to the vector.
*/
void calculate_runtime_vector(double* data, int* numbers);



double runtime_append(std::vector<int> vector1) {
	int value = -1;                            // Value that is to be appended in the vector.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	vector1.push_back(value);                  // Appending the value.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);       // The time duration is converted into nanoseconds.
}


double runtime_remove_back(std::vector<int> vector1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	vector1.pop_back();                         //Removing element from the end of the vector.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);       // The time duration is converted into nanoseconds.
}


double runtime_prepend(std::vector<int> vector1) {
	int value = -1;                        // Value that is to be prepended into the vector.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	vector1.insert(vector1.begin(), value);         // Prepending the value into the vector.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);           // The time duration is converted into nanoseconds.
}


double runtime_remove_front(std::vector<int> vector1) {
	std::chrono::time_point<std	::chrono::steady_clock> start = std::chrono::steady_clock::now();
	vector1.erase(vector1.begin());              // Value is removed from the beginning of the vector.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);         // The time duration is converted into nanoseconds.
}


double runtime_swap(std::vector<int> vector1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	int temp = 0;
	int size = vector1.size();                       // Size of the vector is assigned to the variable.
	// Swapping the first and last elements of the vector.
	temp = vector1[0];
	vector1[0] = vector1[size-1];
	vector1[size-1] = temp;
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);           // The time duration is converted into nanoseconds.
}


double runtime_empty(std::vector<int> vector1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	vector1.clear();                          // Erasing all the elements from the vector
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);       // The time duration is converted into nanoseconds.
}


double runtime_insert(std::vector<int> vector1) {
	int value = -1;                          // Value that is to be inserted at the beginning of the vector.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	vector1.insert(vector1.begin(), value);    // Value is inserted at the beginning of the vector.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);       // The time duration is converted into nanoseconds.
}


double runtime_remove_duplicates(std::vector<int> vector1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::vector<int>::iterator it;
	std::sort(vector1.begin(), vector1.end());                            // Vector is first sorted in the ascending order.
	it = vector1.erase(std::unique(vector1.begin(), vector1.end()), vector1.end());      // The duplicates from the vector are removed.
	vector1.resize(std::distance(vector1.begin(), it));                   // Resizing the vector.
    
	/*
	We could have also used a stl set.
	std::set<int> s;
	unsigned size = vector1.size();
	for (unsigned i = 0; i < size; ++i) s.insert(vector1[i]);
	vector1.assign(s.begin(), s.end());
	*/

	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);               // The time duration is converted into nanoseconds.
}


double runtime_reverse(std::vector<int> vector1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::reverse(vector1.begin(), vector1.end());            // Reversing the vector.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);                    // The time duration is converted into nanoseconds.
}


void calculate_runtime_vector(double* data, int* numbers) {
	std::vector<int> vector1;    // Vector whose runtime for different functions is to be stored as its size increases.
	int elements = 2;            // Variable that determines the number of elements assigned to the vector at any given instance.
	int index = -1;              // Variable that stores the index on which a particular runtime is to be stored.
	bool trial = true;           // Variable that determines if trial run is to be performed.
	int i = 0;
	// Assigning values to the vector and storing the runtimes in "data" array.
	while (i < 10) {
		vector1.assign(numbers, numbers + elements);
		// Trial run is executed for the first time.
		if (trial) {
			runtime_append(vector1);
			runtime_remove_back(vector1);
			runtime_prepend(vector1);
			runtime_remove_front(vector1);
			runtime_swap(vector1);
			runtime_empty(vector1);
			runtime_insert(vector1);
			runtime_remove_duplicates(vector1);
			runtime_reverse(vector1);
			trial = false;
		}
		// Storing the runtimes in "data" array.
		data[++index] = elements;
		data[++index] = runtime_append(vector1);
		data[++index] = runtime_remove_back(vector1);
		data[++index] = runtime_prepend(vector1);
		data[++index] = runtime_remove_front(vector1);
		data[++index] = runtime_swap(vector1);
		data[++index] = runtime_empty(vector1);
		data[++index] = runtime_insert(vector1);
		data[++index] = runtime_remove_duplicates(vector1);
		data[++index] = runtime_reverse(vector1);
		i++;
		elements = elements * 2;            // The number of elements a vector is assigned is doubled by two every single time.
	}
}


#endif