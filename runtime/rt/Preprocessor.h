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

#define CLASSX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), CLASS00_ , CLASS11_)
#define CLASS(...) CLASSX(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define ARRAY_(n, name, code) \
  template <class T1 = void, class T2 = void>\
  class name {};\
  template <class T1 = void, class T2 = void>\
  using n = rt::ref<name<T1, T2>>;\
  template <>\
  class name<>\
  BOOST_PP_TUPLE_ENUM(code);\
  template <class T>\
  class name<T> : public rt::Array<T>, public name<> {};
  
#define ARRAY(code) ARRAY_(Array, NAME(Array), code)

#define CLASS_VOID_OP(s, d, e) class e = void
#define TEMPLATE_VOID(seq) (template<BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(CLASS_VOID_OP, _, seq))>)

#define CLASS_MULTI_FORWARD__(n, name, T, seq) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name {};\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;

#define CLASS_MULTI_FORWARD_(n, name, seq) CLASS_MULTI_FORWARD__(n, name, TEMPLATE_VOID(seq), seq)
#define CLASS_FORWARD(name, ...) CLASS_MULTI_FORWARD_(name, NAME_(name, _, _), BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define CLASS_MULTI0(name) \
  template <> \
  class NAME_(name, _, _)<> \

#define CLASS_MULTI0_(seq) CLASS_MULTI0(BOOST_PP_SEQ_HEAD(seq))

#define CLASS_MULTI1(name, seq) \
  BOOST_PP_TUPLE_ENUM(TEMPLATE(seq)) \
  class NAME_(name, _, _)<BOOST_PP_SEQ_ENUM(seq)> \

#define CLASS_MULTI1_(seq) CLASS_MULTI1(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq)) 
#define CLASS_MULTI_(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), CLASS_MULTI0_, CLASS_MULTI1_)
#define CLASS_(...) CLASS_MULTI_(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define FORWARD0(n, name) \
  class name;\
  using n = rt::ref<name>;\

#define FORWARD0_(name) FORWARD0(name, NAME(name))
#define FORWARD00_(seq) FORWARD0_(BOOST_PP_SEQ_HEAD(seq))

#define FORWARD1(n, name, T, seq) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name;\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;

#define FORWARD1_(name, seq) FORWARD1(name, NAME(name), TEMPLATE(seq), seq)
#define FORWARD11_(seq) FORWARD1_(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq))

#define FORWARDX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), FORWARD00_, FORWARD11_)
#define FORWARD(...) FORWARDX(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define FORWARD_MULTI(n, name, seq) \
  BOOST_PP_TUPLE_ENUM(TEMPLATE(seq))\
  class name;\
  BOOST_PP_TUPLE_ENUM(TEMPLATE_VOID(seq))\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;

#define FORWARD_(name, ...) FORWARD_MULTI(name, NAME(name), BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))