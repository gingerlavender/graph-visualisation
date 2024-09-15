/*!
 * \file
 * Файл с реализацией функций библиотеки graph_dialog.h
*/
#include "input.h"
#include "graph_dialog.h"

void print_menu(void) {
    std::cout << "1. Add vertices\n";
    std::cout << "2. Add edge\n";
    std::cout << "3. Print adjacency lists\n";
    std::cout << "4. Visualise your graph\n\n";
}

void add_vertex_dialog(graph_t& graph) {
	size_t number = 0;
    std::cout << "Enter number of vertices\n\n";
    number = get_num<size_t>();
    std::cout << "\n";
    add_vertex(graph, number);
}

void add_edge_dialog(graph_t& graph) {
	size_t v1 = 0, v2 = 0;
	for (int i = 1; i <= 2; ++i) {
        std::cout << "Enter vertex " << i << ": ";
        if (i == 1) {
			v1 = get_num<size_t>();
		} else {
		    v2 = get_num<size_t>();
	    }
	}
    std::cout << "\n";
    add_edge(graph, v1, v2);
}

void print_adjacency(graph_t& graph) {
    std::cout << "Your graph:\n\n";
	for (size_t i = 0; i < graph.adjacency.size(); ++i) {
        std::cout << i + 1 << ":";
		for (int val : graph.adjacency[i]) {
            std::cout << " " << val;
		}
        std::cout << "\n";
	}
    std::cout << "\n";
}

void visualise_dialog(graph_t& graph) {
    std::string filename, link;
	char answer = 0;
    std::cout << "Do you want to highlight any path in your graph? (Y/n)\n\n";
	do {
        answer = get_char();
        std::cout << "\n";
		if (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
		    std::cout << "Try again\n\n";
		} else {
            std::cout << "Enter name of the new file:\n\n";
            std::cin >> filename;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.eof()) {
                throw std::runtime_error("Have a nice day!");
            }
            std::cout <<"\n";
			if (answer == 'Y' || answer == 'y') {
                int mode = 0;
                size_t length = 0;
                std::cout << "Do you want to work with C-styled arrays or std::vector? (1/2)\n\n";
                mode = get_num<int>();
                std::cout << "\nEnter number of vertices in path:\n\n";
                length = get_num<size_t>(); 
                std::cout << "\n";
				if (mode == 1) {
                    size_t* path = new size_t[length];
                    for (size_t i = 0; i < length; ++i) {
                        std::cout << "Vertex " << i + 1 << ": ";
                        std::cin >> path[i];
                        if (std::cin.eof()) {
                            delete [] path;
                            throw std::runtime_error("Have a nice day!");
                        }
                    }
                    std::cout << "\n";
                    try {
                        link = visualise(graph, filename, path, length);
                    }
                    catch (...) {
                        delete [] path;
                        throw;
                    }
                    std::cout << "Your graph saved in: " << link << "\n\n";
                    delete [] path;
                } else if (mode == 2) {
                    std::vector<size_t> path(length);
                    for (size_t i = 0; i < length; ++i) {
                        std::cout << "Vertex " << i + 1 << ": ";
                        std::cin >> path[i];
                        if (std::cin.eof()) {
                            throw std::runtime_error("Have a nice day!");
                        }
                    }
                    std::cout << "\n";
                    link = visualise(graph, filename, path); 
                    std::cout << "Your graph saved in: " << link << "\n\n";
                } else {
                    std::cout << "There is no such option\n\n";
                }
			} else {
                link = visualise(graph, filename);
                std::cout << "Your graph saved in: " << link << "\n\n";
			} 
		}		
	} while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
}

