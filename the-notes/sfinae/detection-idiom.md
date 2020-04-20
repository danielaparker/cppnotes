# void_t

```c++
template< class... >
using void_t = void;
```

Maps a sequence of types to type void

## Implementation (until C++17)

```c++
template<typename... Ts> struct make_void { typedef void type;};
template<typename... Ts> using void_t = typename make_void<Ts...>::type;
```

## Examples

### Detect ill-formed types 

```c++
#include <type_traits>
#include <vector>
#include <iostream>

// primary template
template<class, class = std::void_t<>> // or template<class, class = void>
struct has_value_type 
    : std::false_type{}; // (*)

// specialized as has_value_type<T, void> or discarded (SFINAE)
template< class T >
struct has_value_type<T, std::void_t<typename T::value_type>> 
    : std::true_type{ }; // (**)

int main()
{
    // value_type exists, specialization is well-formed, specialization will be selected     
    std::cout << "(1) " << has_value_type<std::vector<int>>::value << "\n";

    // specialization is nonviable (SFINAE), primary template will be selected
    std::cout << "(2) " << has_value_type<int>::value << "\n";
}
```

#### Remarks

- The default argument `void` in (*) must be the exact same type as the argument in (**).

## Reference

[cppreference](https://en.cppreference.com/w/cpp/types/void_t)

[Proposing Standard Library Support for the C++ Detection Idiom](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4436.pdf)
