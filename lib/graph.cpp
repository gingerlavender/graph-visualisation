/*!
 * \file
 * Файл с реализацией функций библиотеки graph.h
*/
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "graph.h"

void add_vertex(graph_t& graph, size_t number) {
    graph.adjacency.resize(graph.adjacency.size() + number);
}

void add_edge(graph_t& graph, size_t v1, size_t v2) {
	if (v1 > graph.adjacency.size() || v2 > graph.adjacency.size()) {
		throw std::runtime_error("No vertex");
	}
    if (std::find(graph.adjacency[v1 - 1].begin(), graph.adjacency[v1 - 1].end(), v2) != graph.adjacency[v1 - 1].end()) {
        throw std::runtime_error("Edge already exists");
    }
    graph.adjacency[v1 - 1].push_front(v2);
    graph.adjacency[v2 - 1].push_front(v1);
}

std::string visualise(const graph_t& graph, const std::string& filename, const size_t* path, size_t length) {
    if (path != nullptr && !is_path(graph, path, length)) {
        throw std::runtime_error("This is not a path!");
    }
    std::ofstream out;
    std::string link = "file://";
    out.open(filename);
    out << "strict graph{";
    for (size_t i = 0; i < graph.adjacency.size(); ++i) {        
        out << i + 1 << ";";
        for (int val : graph.adjacency[i]) {
            out << i + 1 << "--" << val << ";";
        }
    }
    for (size_t i = 0; i < length; ++i) {
        if (i != length - 1) {
            out << path[i] << "--";
        } else {
            out << path[i] << "[color=\"red\"]";
        }
    }
    out << "}\n";
    out.close();
    std::string filepath = std::filesystem::canonical(filename);
    link = link + filename + filepath + ".png";
    std::string command = "dot " + filename + " -Tpng -o " + filepath + ".png";
    system(command.c_str());
    return link;
}

std::string visualise(const graph_t& graph, const std::string& filename, const std::vector<size_t>& path) {
    return visualise(graph, filename, path.data(), path.size());
    }

std::string visualise(const graph_t& graph, const std::string& filename) {
    return visualise(graph, filename, nullptr, 0);
    }

bool is_path(const graph_t& graph, const size_t* path, size_t length) {
    if (std::any_of(path, path + length, [=](const size_t i) { return (i <= 0 || i > graph.adjacency.size()); })) {
        return false;
    }
    for (size_t i = 0; i < length - 1; ++i) {
        if (std::none_of(graph.adjacency[path[i] - 1].begin(), graph.adjacency[path[i] - 1].end(), [=, &path](size_t val) { return (val == path[i + 1]); })) {
            return false;
        }
    }
    return true;
}

bool is_path(const graph_t& graph, const std::vector<size_t>& path) {
    return is_path(graph, path.data(), path.size());
}
