#include <type_traits>
#include <vector>
#include <iostream>
#include <utility> // std::declval
#include "nonstd.hpp"


// archetypal expression for conversion operation
template<typename Container>
using
container_data_t = decltype(std::declval<Container>().data());

// has_data
template<class Container>
using
has_data = nonstd::is_detected<container_data_t,Container>;

template<class Container>
constexpr bool
has_data_v = nonstd::is_detected_v<container_data_t, Container>;

// has_data_exact
template< class Ret,class Container>
using
has_data_exact = nonstd::is_detected_exact<Ret,container_data_t,Container>;

template< class Ret, class Container >
constexpr bool
has_data_exact_v = nonstd::is_detected_exact_v<Ret, container_data_t, Container>;

int main()
{
    std::cout << "(1) " << has_data_v<std::vector<int>> << "\n";

    std::cout << "(2) " << has_data_exact<int*,std::vector<int>>::value << "\n";

    std::cout << "(3) " << has_data_exact<char*, std::vector<int>>::value << "\n";

    std::cout << "(4) " << has_data_exact_v<int*,std::vector<int>> << "\n";
}
