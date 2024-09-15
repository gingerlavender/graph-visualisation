/*!
 * \file
 * Файл, определяющий структуру и методы для работы с графом.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <string>

/*!
 * \struct graph_t
 * \brief Структура графа.
 * \details Структура графа. Представляет собой вектор списков смежности.
 * \var graph_t::adjacency 
 * Вектор списков смежности
 */
struct graph_t {
    std::vector<std::list<size_t>> adjacency = {};
};

/*!
 * Добавляет number вершин в граф.
 * \param graph Граф
 * \param number Количество добавляемых вершин
 * \throw std::bad_alloc В случае ошибки выделения памяти
*/
void add_vertex(graph_t& graph, size_t number);

/*!
 * Добавляет ребро между двумя вершинами.
 * \param graph Граф
 * \param v1 Номер первой вершины
 * \param v2 Номер второй вершины
 * \throw std::bad_alloc В случае ошибки выделения памяти
 * \throw std::runtime_error В случае, если функция вызывается для несуществующей вершины или ребро уже существует
*/
void add_edge(graph_t& graph, size_t v1, size_t v2);

/*!
 * \brief Визуализация графа.
 * Вариант для визуалиции графа без указания какого-либо пути. Генерирует отрисованный граф в формате .png.
 * \param graph Граф
 * \param filename Имя выходного файла 
 * \return Ссылку на выходной файл (вида file://path-to-file)
 * \throw std::bad_alloc В случае ошибки выделения памяти
*/
std::string visualise(const graph_t& graph, const std::string& filename);

/*!
 * \brief Визуализация графа.
 * Вариант для визуалиции графа с указанием пути. Генерирует отрисованный граф в формате .png.
 * \param graph Граф
 * \param filename Имя выходного файла 
 * \param path Вектор вершин пути
 * \return Ссылку на выходной файл (вида file://path-to-file)
 * \throw std::bad_alloc В случае ошибки выделения памяти
 * \throw std::runtime_error В случае, если пути не существует
*/
std::string visualise(const graph_t& graph, const std::string& filename, const std::vector<size_t>& path);

/*!
 * \brief Визуализация графа.
 * Вариант для визуалиции графа с указанием пути. Генерирует отрисованный граф в формате .png.
 * \param graph Граф
 * \param filename Имя выходного файла 
 * \param path Массив вершин пути (в стиле C)
 * \param length Количество вершин в пути
 * \return Ссылку на выходной файл (вида file://path-to-file)
 * \throw std::bad_alloc В случае ошибки выделения памяти
 * \throw std::runtime_error В случае, если пути не существует
*/
std::string visualise(const graph_t& graph, const std::string& filename, const size_t* path, size_t length);

/*!
 * Проверка существования пути в графе
 * \param graph Граф
 * \param path Массив вершин пути (в стиле C)
 * \param length Количество вершин в пути
 * \return true, если путь существует, false в противном случае
 * \throw std::bad_alloc В случае ошибки выделения памяти
 * \throw std::runtime_error В случае, если пути не существует
*/
bool is_path(const graph_t& graph, const size_t* path, size_t length);

/*!
 * Проверка существования пути в графе
 * \param graph Граф
 * \param path Вектор вершин пути
 * \return true, если путь существует, false в противном случае
 * \throw std::bad_alloc В случае ошибки выделения памяти
 * \throw std::runtime_error В случае, если пути не существует
*/
bool is_path(const graph_t& graph, const std::vector<size_t>& path);

#endif
