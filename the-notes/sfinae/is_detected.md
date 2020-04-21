# is_detected

```c++
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
```

```c++
template< template<class...> class Op, class... Args >
using
is_detected = detector<void, void, Op, Args...>;

template< template<class...> class Op, class... Args >
constexpr bool
is_detected_v = is_detected<Op, Args...>::value;

template< template<class...> class Op, class... Args >
 using
 detected_t = typename is_detected<Op, Args...>::type;
```

```c++
template< class Default, template<class...> class Op, class... Args >
using
detected_or = detector<Default, void, Op, Args...>;

template< class Default, template<class...> class Op, class... Args >
using
detected_or_t = typename detected_or<Default, Op, Args...>::type;
```

```c++
template< class Expected, template<class...> class Op, class... Args >
using
is_detected_exact = is_same< Expected, detected_t<Op, Args...> >;

template< class Expected, template<class...> class Op, class... Args >
constexpr bool
is_detected_exact_v = is_detected_exact< Expected, Op, Args...>::value;
```

```c++
template< class To, template<class...> class Op, class... Args >
using
is_detected_convertible = is_convertible< detected_t<Op, Args...>, To >;

template< class To, template<class...> class Op, class... Args >
constexpr bool
is_detected_convertible_v = is_detected_convertible<To, Op, Args...>::value;
```

```c++
struct
nonesuch
{
    nonesuch( ) = delete;
    ~nonesuch( ) = delete;
    nonesuch( nonesuch const& ) = delete;
    void
    operator = ( nonesuch const& ) = delete;
};
```

```c++
detected_or
```
Attempt to detect nested type, produce alias to type if detected, otherwise produce alias to default type.
E.g. `Alloc::pointer` if exists; otherwise, `value_type*`.

```c++
is_detected_exact
```

Detect archetype iff it also produced a designated result type.

```c++
is_detected_convertible
```

Detect an archetype iff it also produced a result type convertible to a
specified type. 
```

## Reference

[Proposing Standard Library Support for the C++ Detection Idiom](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4436.pdf)
