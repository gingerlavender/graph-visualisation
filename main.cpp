#include <iostream>
#include <functional>
#include <vector>
#include "lib/input.h"
#include "lib/graph.h"
#include "lib/graph_dialog.h"

int main() {
	graph_t graph = {};
    std::vector<std::function<void(graph_t&)>> dialog = {add_vertex_dialog, add_edge_dialog, print_adjacency, visualise_dialog};
	int choice = 0; 
	do {  
		print_menu();
        try {
           choice = get_num<int>();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << "\n";
            return 1;
        }
        std::cout << "\n";
		if (choice < CHOICE_MIN || choice > CHOICE_MAX) {
            std::cout << "Oops! No such option\n\n";
			continue;
		} 
		try {
            dialog[choice - 1](graph);
        }
        catch (const std::bad_alloc& ba) {
            std::cerr << "Allocation failed: " << ba.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << "\n\n";
        }
		if (std::cin.eof()) {
			return 1;
		}
	} while (!std::cin.eof());
	return 0;
}
