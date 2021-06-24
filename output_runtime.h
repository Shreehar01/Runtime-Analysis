#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


/**
 * @brief Displays the runtime of different containers with varying elements for different functions.
 *
 * @param A pointer to an array that consists of runtime values and a variable that consists the information of the type of the container.
 */
void display_runtime(double* data, int container);


/**
*@brief Saves the runtime of different containers with varying elements for different functions in different files.
*
* @param A pointer to an array that consists of runtime values and a variable that consists the information of the type of the container.
*/
void save_runtime(double* data, int container);


void display_runtime(double* data, int container) {
	std::string container_name;          // Variable that stores the name of the container whose runtime is being printed.
	// Determining the container's name.
	switch (container) {
		case 0:
			container_name = "Array";
			break;
		case 1:
			container_name = "Vector";
			break;
		case 2:
			container_name = "Forward List";
			break;
		case 3:
			container_name = "List";
			break;
	}
	// Printing the runtimes for different containers for nine functions.
	std::cout << "============================" << container_name << "=============================" << std::endl;
	std::cout << std::setw(11) << "Number" << std::setw(11) << "Append" << std::setw(11) << "RBack" << std::setw(11) << "Prepend" << std::setw(11) << "RFront" << std::setw(11) << "Swap" << std::setw(11) << "Empty" << std::setw(11) << "Insert" << std::setw(11) << "Unique" << std::setw(11) << "Reverse" << std::endl;
	for (int i = 1; i <= 100; i++) {
		std::cout << std::setw(11) << data[i-1] << std::setw(11);
		if (i % 10 == 0) std::cout << std::endl;             // Breaking the line when the size of container increases.
	}
	std::cout << "====================================================================" << std::endl;
}


void save_runtime(double* data, int container) {
	std::string file_name;                  // Variable that stores the name of the file where the runtime data is to be stored.
	// Determining the filename based on the container provided.
	switch (container) {
	case 0:
		file_name = "Array.csv";
		break;
	case 1:
		file_name = "Vector.csv";
		break;
	case 2:
		file_name = "ForwardList.csv";
		break;
	case 3:
		file_name = "List.csv";
		break;
	}
	// Saving the runtimes in a file.
	std::ofstream output;
	output.open(file_name);
	// If file cannot be saved, error is displayed and returned to the "Source.cpp".
	if (!output) {
		std::cout << "File couldn't be created or opened!" << std::endl;
		return;
	}
	output << "Number, Append, RBack, Prepend, RFront, Swap, Empty, Insert, Unique, Reverse" << std::endl;
	for (int i = 1; i <= 100; i++) {
		output << data[i - 1] << ",";
		if (i % 10 == 0) output << std::endl; 
	}
}


#endif