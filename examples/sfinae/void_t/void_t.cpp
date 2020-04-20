#include <type_traits>
#include <vector>
#include <iostream>
#include <utility> // std::declval
#include "nonstd.hpp"

// Detect member type

// primary template
template<class, class = nonstd::void_t<>> // equiv to template<class, class = void>
struct has_value_type : std::false_type {};

// specialization
template< class T >
struct has_value_type<T, nonstd::void_t<typename T::value_type>> : std::true_type { };

void detect_member_type()
{
    std::cout << "(1) " << has_value_type<std::vector<int>>::value << "\n";
    std::cout << "(2) " << has_value_type<int>::value << "\n";
}

// Detect member function

// primary template
template<class, class = std::void_t<>>
struct has_data
    : std::false_type {}; // (*)

// specialized as has_data<T, void> or discarded (SFINAE)
template< class T >
struct has_data<T, std::void_t<decltype(std::declval<T>().data())>>
    : std::true_type { }; // (**)

void detect_member_function()
{
    std::cout << "(1) " << has_data<std::vector<int>>::value << "\n";
    std::cout << "(2) " << has_data<int>::value << "\n";
}

int main()
{
    detect_member_type();

    detect_member_function();
}
