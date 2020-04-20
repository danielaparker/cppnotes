# SFINAE

## void_t

```c++
template< class... >
using void_t = void;
```

Maps a sequence of any types to type void

## Examples

### Detect ill-formed types 

```c++
#include <type_traits>
#include <vector>
#include <iostream>

// primary template
template<class, class = std::void_t<>> // equiv to template<class, class = void>
struct has_value_type : std::false_type{};

// specialization
template< class T >
struct has_value_type<T, std::void_t<typename T::value_type>> : std::true_type{ };

int main()
{
    std::cout << "(1) " << has_value_type<std::vector<int>>::value << "\n";
    std::cout << "(2) " << has_value_type<int>::value << "\n";
}
```

## Reference

[cppreference](https://en.cppreference.com/w/cpp/types/void_t)


