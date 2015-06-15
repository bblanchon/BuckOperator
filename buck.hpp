// The C++ buck operator (or dollar sign operator) to return multiple values
// from a function
//
// A stupid idea of Benoit Blanchon in 2015
// MIT License

// HOWTO:
// 1. Declare a function that returns $<T1,T2...>
// 2. In that function: return $(val1, val2...)
// 3. In calling site, use $(val1, val2...) = myfunction()

#pragma once

#include <tuple>

template <typename... Types>
using $ = std::tuple<Types...>;

template <typename... Types>
std::tuple<Types&...> buck_operator(Types&... args) {
  return std::tie(args...);
}

template <typename... Types>
std::tuple<Types...> buck_operator(Types&&... args) {
  return std::tuple<Types...>(args...);
}

#define $(...) buck_operator(__VA_ARGS__)
