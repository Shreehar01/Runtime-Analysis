#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <forward_list>
#include <cmath>
#include <chrono>



/**
 * @brief Calculates the runtime of appending in a forward list.
 *
 * @param A forward list that consists of a number of elements.
 *
 * @returns the runtime of appending in a forward list in nanoseconds.
 */
double runtime_append(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of removing an element from the end of a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of removing an element from the end of a forward list in nanoseconds.
*/
double runtime_remove_back(std::forward_list<int> forward_list1);


/**
 * @brief Calculates the runtime of prepending in a forward list.
 *
 * @param A forward list that consists of a number of elements.
 *
 * @returns the runtime of prepending in a forward list in nanoseconds.
 */
double runtime_prepend(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of removing an element from the front of a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of removing an element from the front of a forward list in nanoseconds.
*/
double runtime_remove_front(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of swapping two nodes in a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of swapping two nodes in a forward list in nanoseconds.
*/
double runtime_swap(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of removing all the elements from a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of removing all the elements from a forward list in nanoseconds.
*/
double runtime_empty(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of inserting an element in the end of a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of inserting an element in the end of a forward list in nanoseconds.
*/
double runtime_insert(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of removing duplicates from a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of removing duplicates from a forward list in nanoseconds.
*/
double runtime_remove_duplicates(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of reversing elements in a forward list.
*
* @param A forward list that consists of a number of elements.
*
* @returns the runtime of reversing elements in a forward list in nanoseconds.
*/
double runtime_reverse(std::forward_list<int> forward_list1);


/**
* @brief Calculates the runtime of executing different functions in a forward list and stores it in an array.
*
* @param A pointer to an array that will store the runtimes and a pointer to an array that consists of elements to be assigned to the forward list.
*/
void calculate_runtime_forwardlist(double* data, int* numbers);



double runtime_append(std::forward_list<int> forward_list1) {
	int value = -1;                // Value that is to be appended in the forward list.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::forward_list<int>::iterator it = forward_list1.before_begin();    // Iterator that , at first, points to the "before beginning" location in the forward list.
	// Advancing the iterator till it reaches the last element of the forward list.
	for (int& _ : forward_list1)
		 ++it;
	forward_list1.insert_after(it, value);       // Inserting the value after the last element in the forward list. 
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);         // The time duration is converted into nanoseconds.
}


double runtime_remove_back(std::forward_list<int> forward_list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::forward_list<int>::iterator it = forward_list1.before_begin();  // Iterator that , at first, points to the "before beginning" location in the forward list.
	// Advancing the iterator till it reaches the second last element of the forward list.
	int size = 0;                      // Variable that stores the size of the forward list. Used as a reference for iterator.
	for (int& _ : forward_list1) {
		if (size != 0) {
			++it;                  // Iterator is only allowed to advance after one complete loop so that it points to second last element after the loop completes
		}
		++size;
	}
	it = forward_list1.erase_after(it);     // Removing the last element of the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);     // The time duration is converted into nanoseconds.
}


double runtime_prepend(std::forward_list<int> forward_list1) {
	int value = -1;    // Value that is to be prepended in the forward list.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	forward_list1.push_front(value);             // Prepending the value in the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);      // The time duration is converted into nanoseconds.
}


double runtime_remove_front(std::forward_list<int> forward_list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	forward_list1.pop_front();               // Removing value from the front of the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);         // The time duration is converted into nanoseconds.
}


double runtime_swap(std::forward_list<int> forward_list1) {
		std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
		// Moving the last node before the second last node. (In the case where length = 2, moving the last node before the first node)
		std::forward_list<int>::iterator it1 = forward_list1.before_begin();   // Intializing iterator1.
		std::forward_list<int>::iterator it2 = forward_list1.before_begin();   // Initializig iterator2.
		int length = 0;                                                        // Variable that stores size of the forward list.
		for (int& _ : forward_list1) {
			if (length > 2) ++it2;                                             // Allowing iterator to advance only after 3 loops.       
			if (length > 0) ++it1;                                             // Allowing iterator to advance only after 1 loop.
			++length;
		}
		forward_list1.splice_after(it1, forward_list1, it2);       	           	
		// If the length is two, swapping has been done as only one move is required.
		// If the length is more than two, we need to move the then third last node to the last node.
		if (length > 2) {
			it1 = forward_list1.before_begin();                                // Intializing iterator1.
			it2 = forward_list1.before_begin();                                // Intializing iterator2.
			length = 0;         
			for (int& _ : forward_list1) {
				if (length > 2)  ++it2;                                        // Allowing iterator to advance only after 2 loops.
				if (length > 0)  ++it1;                                        // Allowing iterator to advance only after 1 loop.  
				++length;
			}
			forward_list1.splice_after(it2, forward_list1, it1);
		}

		std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
		std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
		return duration.count() * pow(10, 9);              // The time duration is converted into nanoseconds.
}


double runtime_empty(std::forward_list<int> forward_list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	forward_list1.clear();              //Erasing all the elements of the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);             // The time duration is converted into nanoseconds.
}


double runtime_insert(std::forward_list<int> forward_list1) {
	int value = -1;                // Value that is to be inserted at the end of the forward list.
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	std::forward_list<int>::iterator it = forward_list1.before_begin();    // Iterator that , at first, points to the "before beginning" location in the forward list.
	// Advancing the iterator till it reaches the last element of the forward list.
	for (int& _ : forward_list1)
		++it;
	forward_list1.insert_after(it, value);       // Inserting the value after the last element in the forward list. 
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);         // The time duration is converted into nanoseconds.
}


double runtime_remove_duplicates(std::forward_list<int> forward_list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	forward_list1.sort();                    // Sorting the forward list in ascending order.
	forward_list1.unique();                   // Removing the duplicates from the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);    // The time duration is converted into nanoseconds.     
} 


double runtime_reverse(std::forward_list<int> forward_list1) {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	forward_list1.reverse();                 // Reversing the forward list.
	std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	return duration.count() * pow(10, 9);         // The time duration is converted into nanoseconds.
}


void calculate_runtime_forwardlist(double* data, int* numbers) {
	std::forward_list<int> forward_list1;      // Forward list that stores varying number of elements.
	int elements = 2;                          // Variable that stores the number of elements in the forward list at any given instance.
	int index = -1;                            // Variable that stores the index where runtime of an given function is to be stored.
	bool trial = true;                         // Variable that determines if trial run must be executed.
	int i = 0;

	// Assigning values to the forward list, caculating and storing the runtimes.
	while (i < 10) {
		forward_list1.assign(numbers, numbers + elements);          // Assigning elements to forward list.
		// Trial run is executed for the first time.
		if (trial) {
			runtime_append(forward_list1);
			runtime_remove_back(forward_list1);
			runtime_prepend(forward_list1);
			runtime_remove_front(forward_list1);
			runtime_swap(forward_list1);
			runtime_empty(forward_list1);
			runtime_insert(forward_list1);
			runtime_remove_duplicates(forward_list1);
			runtime_reverse(forward_list1);
			trial = false;
		}
		// Storing the runtime of the different functions in the "data" array.
		data[++index] = elements;
		data[++index] = runtime_append(forward_list1);
		data[++index] = runtime_remove_back(forward_list1);
		data[++index] = runtime_prepend(forward_list1);
		data[++index] = runtime_remove_front(forward_list1);
		data[++index] = runtime_swap(forward_list1);
		data[++index] = runtime_empty(forward_list1);
		data[++index] = runtime_insert(forward_list1);
		data[++index] = runtime_remove_duplicates(forward_list1);
		data[++index] = runtime_reverse(forward_list1);
		i++;
		elements = elements * 2;        // The number of elements to be assigned to forward list is doubled every single time.
	}
}


#endif 