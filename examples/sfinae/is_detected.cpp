#include <type_traits>
#include <vector>
#include <iostream>
#include <utility> // std::declval
#include "nonstd.hpp"

// archetypal expression for conversion operation
template< class L, class R >
using
assign_t = decltype(std::declval<L>() = std::declval<R>());

// trait corresponding to that archetype
template< class L, class R >
using
is_assignable = nonstd::is_detected<assign_t, L, R>;

template< class L, class R >
constexpr bool
is_assignable_v = nonstd::is_detected_v<assign_t, L, R>;

int main()
{
    std::cout << "(1) " << is_assignable<int&,int>::value << "\n";
    std::cout << "(2) " << is_assignable<int,int>::value << "\n";

    std::cout << "(3) " << is_assignable_v<int&, int> << "\n";
    std::cout << "(4) " << is_assignable_v<int, int> << "\n";
}
