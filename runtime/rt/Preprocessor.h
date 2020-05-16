#pragma once

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/preprocessor/tuple/enum.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#define NAME(s) BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(s, _), _), __LINE__)

#define CLASS0_(n, name) \
  class name;\
  using n = meson::ref<name>;\
  class name

#define CLASS0(name) CLASS0_(name, NAME(name))
#define CLASS_OP(s, d, e) class e
#define TEMPLATE(...) (template<BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(CLASS_OP, _, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))>)

#define CLASS1_(n, name, T, ...) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name;\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = meson::ref<name<__VA_ARGS__>>;\
  BOOST_PP_TUPLE_ENUM(T)\
  class name

#define CLASS1(name, ...) CLASS1_(name, NAME(name), TEMPLATE(__VA_ARGS__), __VA_ARGS__)
#define CLASS_(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), CLASS0 , CLASS1)
#define CLASS(...) CLASS_(__VA_ARGS__)(__VA_ARGS__)

#define CLASS_ARRAY_(n, name, n1, name1, code) \
  class name;\
  using Array = meson::ref<name>;\
  template <class T>\
  class name1;\
  template <class T>\
  using array = meson::ref<name1<T>>;\
  class name \
  BOOST_PP_TUPLE_ENUM(code); \
  template <class T> \
  class name1 : public meson::Array<T>, public name {};
  
#define CLASS_ARRAY(code) CLASS_ARRAY_(Array, NAME(Array), array, NAME(array), code)
