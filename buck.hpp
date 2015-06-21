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

#define BUCK_GET_2ND_ARG(...) BUCK_GET_2ND_ARG_((__VA_ARGS__, ))
#define BUCK_GET_2ND_ARG_(args) BUCK_GET_2ND_ARG__ args
#define BUCK_GET_2ND_ARG__(arg1, arg2, ...) arg2

#define BUCK_GET_7TH_ARG(...) BUCK_GET_7TH_ARG_((__VA_ARGS__, ))
#define BUCK_GET_7TH_ARG_(args) BUCK_GET_7TH_ARG__ args
#define BUCK_GET_7TH_ARG__(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) arg7

#define BUCK_EMPTY_PROBE() 0, std::ignore
#define BUCK_REPLACE_EMPTY(...) \
  BUCK_GET_2ND_ARG(BUCK_EMPTY_PROBE __VA_ARGS__(), __VA_ARGS__)

#define BUCK_OPERATOR_1(arg1) std::tie(BUCK_REPLACE_EMPTY(arg1))

#define BUCK_OPERATOR_2(...) BUCK_OPERATOR_2_((__VA_ARGS__))
#define BUCK_OPERATOR_2_(args) BUCK_OPERATOR_2__ args
#define BUCK_OPERATOR_2__(arg1, arg2) \
  std::forward_as_tuple(BUCK_REPLACE_EMPTY(arg1), BUCK_REPLACE_EMPTY(arg2))

#define BUCK_OPERATOR_3(...) BUCK_OPERATOR_3_((__VA_ARGS__))
#define BUCK_OPERATOR_3_(args) BUCK_OPERATOR_3__ args
#define BUCK_OPERATOR_3__(arg1, arg2, arg3)                                 \
  std::forward_as_tuple(BUCK_REPLACE_EMPTY(arg1), BUCK_REPLACE_EMPTY(arg2), \
                        BUCK_REPLACE_EMPTY(arg3))

#define BUCK_OPERATOR_4(...) BUCK_OPERATOR_4_((__VA_ARGS__))
#define BUCK_OPERATOR_4_(args) BUCK_OPERATOR_4__ args
#define BUCK_OPERATOR_4__(arg1, arg2, arg3, arg4)                           \
  std::forward_as_tuple(BUCK_REPLACE_EMPTY(arg1), BUCK_REPLACE_EMPTY(arg2), \
                        BUCK_REPLACE_EMPTY(arg3), BUCK_REPLACE_EMPTY(arg4))

#define BUCK_OPERATOR_5(...) BUCK_OPERATOR_5_((__VA_ARGS__))
#define BUCK_OPERATOR_5_(args) BUCK_OPERATOR_5__ args
#define BUCK_OPERATOR_5__(arg1, arg2, arg3, arg4, arg5)                     \
  std::forward_as_tuple(BUCK_REPLACE_EMPTY(arg1), BUCK_REPLACE_EMPTY(arg2), \
                        BUCK_REPLACE_EMPTY(arg3), BUCK_REPLACE_EMPTY(arg4), \
                        BUCK_REPLACE_EMPTY(arg5))

#define BUCK_OPERATOR_6(...) BUCK_OPERATOR_6_((__VA_ARGS__))
#define BUCK_OPERATOR_6_(args) BUCK_OPERATOR_6__ args
#define BUCK_OPERATOR_6__(arg1, arg2, arg3, arg4, arg5, arg6)               \
  std::forward_as_tuple(BUCK_REPLACE_EMPTY(arg1), BUCK_REPLACE_EMPTY(arg2), \
                        BUCK_REPLACE_EMPTY(arg3), BUCK_REPLACE_EMPTY(arg4), \
                        BUCK_REPLACE_EMPTY(arg5), BUCK_REPLACE_EMPTY(arg6))

#define BUCK_OPERATOR_CHOOSER(...)                                    \
  BUCK_GET_7TH_ARG(__VA_ARGS__, BUCK_OPERATOR_6, BUCK_OPERATOR_5,     \
                   BUCK_OPERATOR_4, BUCK_OPERATOR_3, BUCK_OPERATOR_2, \
                   BUCK_OPERATOR_1, )

#define $(...) BUCK_OPERATOR_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
