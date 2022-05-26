#include <iostream>
#include <vector>
/*Overload-Helper to print all elements of a vector using <<*/
template <typename S>
std::ostream& operator<<(std::ostream& os, const std::vector<S>& vector)
{
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

