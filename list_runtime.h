#ifndef LIST_H
#define LIST_H
#include <list>
#include <cmath>
#include <chrono>



/**
 * @brief Calculates the runtime of appending in a list.
 *
 * @param A list that consists of a number of elements.
 *
 * @returns the runtime of appending in a list in nanoseconds.
 */
double runtime_append(std::list<int> list1);


/**
* @brief Calculates the runtime of removing an element from the end of a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of removing an element from the end of a list in nanoseconds.
*/
double runtime_remove_back(std::list<int> list1);


/**
 * @brief Calculates the runtime of prepending in a list.
 *
 * @param A list that consists of a number of elements.
 *
 * @returns the runtime of prepending in a list in nanoseconds.
 */
double runtime_prepend(std::list<int> list1);


/**
* @brief Calculates the runtime of removing an element from the front of a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of removing an element from the front of a list in nanoseconds.
*/
double runtime_remove_front(std::list<int> list1);


/**
* @brief Calculates the runtime of swapping two nodes in a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of swapping two nodes in a list in nanoseconds.
*/
double runtime_swap(std::list<int> list1);


/**
* @brief Calculates the runtime of removing all the elements from a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of removing all the elements from a list in nanoseconds.
*/
double runtime_empty(std::list<int> list1);


/**
* @brief Calculates the runtime of inserting an element in the middle of a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of inserting an element in the middle of a list in nanoseconds.
*/
double runtime_insert(std::list<int> list1);


/**
* @brief Calculates the runtime of removing duplicates from a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of removing duplicates from a list in nanoseconds.
*/
double runtime_remove_duplicates(std::list<int> list1);


/**
* @brief Calculates the runtime of reversing elements in a list.
*
* @param A list that consists of a number of elements.
*
* @returns the runtime of reversing elements in a list in nanoseconds.
*/
double runtime_reverse(std::list<int> list1);


/**
* @brief Calculates the runtime of executing different functions in a list and stores it in an array.
*
* @param A pointer to an array that will store the runtimes and a pointer to an array that consists of elements to be assigned to the list.
*/
void calculate_runtime_list(double* data, int* numbers);



double runtime_append(std::list<int> list1) {
	int value = -1;                      // Value that is to be appended in the list.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.push_back(value);               // Appending the value.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);         // The time duration is converted into nanoseconds.
}


double runtime_remove_back(std::list<int> list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.pop_back();                  // Removing last element from the list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);     // The time duration is converted into nanoseconds.
}


double runtime_prepend(std::list<int> list1) {
	int value = -1;                        // Value that is to be prepended in the list.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.push_front(value);               // Prepending the list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);       // The time duration is converted into nanoseconds.
}


double runtime_remove_front(std::list<int> list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.pop_front();                        // Removing the value from the front of the list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);      // The time duration is converted into nanoseconds.
}


double runtime_swap(std::list<int> list1) {
	if (list1.size() == 2) {
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
		// Intializing the iterators to point at the beginning position of the list.
		std::list<int>::iterator it1 = list1.begin();
		std::list<int>::iterator it2 = list1.begin();
		std::advance(it2, 1);              // Advancing the second iterator to point to the second element.
		list1.splice(it1, list1, it2);     // Moving second node before the first node.
		std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
		std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
		return duration.count() * pow(10, 9);      // The time duration is converted into nanoseconds.
	// If the size of the list is 4, worst case occurs when swapping is done between nodes at size/2 and end.
	// Trying to swap size/2 with size/2 -1(or size/2 +1) will only be equivalent to one move and not a swap.
	} else if (list1.size() == 4) {
		// Intializing the iterators to point at the beginning position of the list.
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
		std::list<int>::iterator it1 = list1.begin();
		std::list<int>::iterator it2 = list1.begin();
		int size_half = list1.size() / 2;
		std::advance(it1, size_half - 1);           // Advancing the first iterator to point at the node at size/2.
		std::advance(it2, list1.size() - 1);        // Advancing the second iterator to point at the node at end.
		list1.splice(it1, list1, it2);            // Moving the node that was at end to size/2.
		it1 = list1.begin();
		std::advance(it1, size_half);             // Advancing the second iterator to point at the node which was initially at size/2 
		list1.splice(it2, list1, it1);            // Moving the node which was initally at size/2 to end of the list.
		std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
		std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
		return duration.count() * pow(10, 9);      // The time duration is converted into nanoseconds.
	// If the size of the list is greater than 4, worst case occurs when swapping is done between nodes at size/2 - 1 and size /2 + 1.
	// Since we just have even number of elements in our list at any time, the statement mentioned above is always valid.
	} else {
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
		// Intializing the iterators to point at the beginning position of the list.
		std::list<int>::iterator it1 = list1.begin();
		std::list<int>::iterator it2 = list1.begin();
		int size_half = list1.size() / 2;
		std::advance(it1, size_half - 2);         // Advancing the first iterator to point at the node at size/2 -1. 
		std::advance(it2, size_half);             // Advancing the first iterator to point at the node at size/2 +1.
		list1.splice(it1, list1, it2);            // Moving the node at size/2 + 1 to the place which is at size/2 -1.
		it1 = list1.begin();
		advance(it1, size_half + 1);              // Advancing the first iterator to point at position which will be at size/2 +1 after splice. 
		advance(it2, 1);                          // Advancing the second iterator to point at node which was initially at size/2 -1.
		list1.splice(it1, list1, it2);            // Moving the node which was initially at size/2 -1 to the place which is at size/2 +1.
		std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
		std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
		return duration.count() * pow(10, 9);      // The time duration is converted into nanoseconds.
	}
}


double runtime_empty(std::list<int> list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.clear();                // Removing all the elements from the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);           // The time duration is converted into nanoseconds.
}


double runtime_insert(std::list<int> list1) {
	int value = -1;                         // Value that is to be inserted in the middle of the list.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::list<int>::iterator it = list1.begin();     // Initializing the iterator to point at the beginning position.
	std::advance(it, 1);                             // Advancing the iterator to point at first node.
    // Advancing the iterator to the middle of the list if the size of the list is greater than 2.
	if(list1.size() != 2) std::advance(it, list1.size() / 2 - 1);
	list1.insert(it, value);                        // Insertng value at the position(middle) pointed by the iterator.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);           // The time duration is converted into nanoseconds.
}


double runtime_remove_duplicates(std::list<int> list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.sort();              // Sorting the list in ascending order.
	list1.unique();            // Removing duplicates from the list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);          // The time duration is converted into nanoseconds.
}


double runtime_reverse(std::list<int> list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	list1.reverse();                 // Reversing the list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);            // The time duration is converted into nanoseconds.
}


void calculate_runtime_list(double* data, int* numbers) {
	std::list<int> list1;                      // List that stores variable number of elements.
	int elements = 2;                          // Variable that stores the number of elements in the forward list at any given instance.
	int index = -1;                            // Variable that stores the index where runtime of an given function is to be stored.
	bool trial = true;                         // Variable that determines if trial run must be executed.
	int i = 0;

	// Assigning values to the forward list, caculating and storing the runtimes.
	while (i < 10) {
		list1.assign(numbers, numbers + elements);          // Assigning values to the list.
		// The trial run is executed for one time at the beginning so that the initial runtimes are not excessively higher than expected.
		if (trial) {
			runtime_append(list1);
			runtime_remove_back(list1);
			runtime_prepend(list1);
			runtime_remove_front(list1);
			runtime_swap(list1);
			runtime_empty(list1);
			runtime_insert(list1);
			runtime_remove_duplicates(list1);
			runtime_reverse(list1);
			trial = false;
		}
		//Calculating and storing the runtime for different functions in "data" array.
		data[++index] = elements;
		data[++index] = runtime_append(list1);
		data[++index] = runtime_remove_back(list1);
		data[++index] = runtime_prepend(list1);
		data[++index] = runtime_remove_front(list1);
		data[++index] = runtime_swap(list1);
		data[++index] = runtime_empty(list1);
		data[++index] = runtime_insert(list1);
		data[++index] = runtime_remove_duplicates(list1);
		data[++index] = runtime_reverse(list1);
		i++;
		elements = elements * 2;             // The number of elements stored in the list is double every time.
	}
}


#endif 