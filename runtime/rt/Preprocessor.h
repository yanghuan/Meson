#pragma once

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/preprocessor/tuple/enum.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#define NAME_(s, c, l) BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(s, c), _), l)
#define NAME(s) NAME_(s, _, _)

#define CLASS0_(n, name) \
  class name;\
  using n = rt::ref<name>;\
  class name

#define CLASS0(name) CLASS0_(name, NAME(name))
#define CLASS_OP(s, d, e) class e
#define TEMPLATE(seq) (template<BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(CLASS_OP, _, seq))>)

#define CLASS1_(n, name, T, seq) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name;\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;\
  BOOST_PP_TUPLE_ENUM(T)\
  class name

#define CLASS1(name, seq) CLASS1_(name, NAME(name), TEMPLATE(seq), seq)
#define CLASS11_(seq) CLASS1(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq)) 
#define CLASS00_(seq) CLASS0(BOOST_PP_SEQ_HEAD(seq))

#define CLASS_(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), CLASS00_ , CLASS11_)
#define CLASS(...) CLASS_(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define CLASS_ARRAY_(n, name, n1, name1, code) \
  class name;\
  using Array = rt::ref<name>;\
  template <class T>\
  class name1;\
  template <class T>\
  using array = rt::ref<name1<T>>;\
  class name \
  BOOST_PP_TUPLE_ENUM(code); \
  template <class T> \
  class name1 : public rt::Array<T>, public name {};
  
#define CLASS_ARRAY(code) CLASS_ARRAY_(Array, NAME(Array), array, NAME(array), code)

#define CLASS_VOID_OP(s, d, e) class e = void
#define TEMPLATE_VOID(seq) (template<BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(CLASS_VOID_OP, _, seq))>)

#define CLASS_MULTI_FORWARD__(n, name, T, seq) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name {};\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;

#define CLASS_MULTI_FORWARD_(n, name, seq) CLASS_MULTI_FORWARD__(n, name, TEMPLATE_VOID(seq), seq)
#define CLASS_MULTI_FORWARD(name, ...) CLASS_MULTI_FORWARD_(name, NAME_(name, _, _), BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define CLASS_MULTI0(name) \
  template <> \
  class NAME_(name, _, _)<> \

#define CLASS_MULTI0_(seq) CLASS_MULTI0(BOOST_PP_SEQ_HEAD(seq))

#define CLASS_MULTI1(name, seq) \
  BOOST_PP_TUPLE_ENUM(TEMPLATE(seq)) \
  class NAME_(name, _, _)<BOOST_PP_SEQ_ENUM(seq)> \

#define CLASS_MULTI1_(seq) CLASS_MULTI1(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq)) 
#define CLASS_MULTI_(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), CLASS_MULTI0_, CLASS_MULTI1_)
#define CLASS_MULTI(...) CLASS_MULTI_(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

