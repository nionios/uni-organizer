#include <vector>
#ifndef VECTOR_PRINTER_HPP
#define VECTOR_PRINTER_HPP
template <typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vector);
#endif
