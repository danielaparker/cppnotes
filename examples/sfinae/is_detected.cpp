#include <type_traits>
#include <vector>
#include <iostream>
#include <utility> // std::declval
#include "nonstd.hpp"

// primary template handles all types not supporting the archetypal Op
template< class Default
, class // always void; supplied externally
, template<class...> class Op
, class... Args
>
struct
detector
{
 constexpr static auto value = false;
 using type = Default;
 };
 // specialization recognizes and handles only types supporting Op
 template< class Default
 , template<class...> class Op
 , class... Args
 >
 struct
 detector<Default, nonstd::void_t<Op<Args...>>, Op, Args...>
 {
 constexpr static auto value = true;
 using type = Op<Args...>;
 };

template< template<class...> class Op, class... Args >
using
is_detected = detector<void, void, Op, Args...>;

template< template<class...> class Op, class... Args >
constexpr bool
is_detected_v = is_detected<Op, Args...>::value;

template< template<class...> class Op, class... Args >
 using
 is_detected_t = typename is_detected<Op, Args...>::type;

int main()
{
}
