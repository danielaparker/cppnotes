#include <type_traits>
#include <vector>
#include <iostream>
#include "nonstd.hpp"

// primary template
template<class, class = nonstd::void_t<>> // equiv to template<class, class = void>
struct has_value_type : std::false_type {};

// specialization
template< class T >
struct has_value_type<T, nonstd::void_t<typename T::value_type>> : std::true_type { };

int main()
{
    std::cout << "(1) " << has_value_type<std::vector<int>>::value << "\n";
    std::cout << "(2) " << has_value_type<int>::value << "\n";
}
