#ifndef NONSTD_HPP
#define NONSTD_HPP

namespace nonstd {

    // void_t

    template<typename... Ts> struct make_void { typedef void type;};
    template<typename... Ts> using void_t = typename make_void<Ts...>::type;

}

#endif
