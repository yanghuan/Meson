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

#define FORWARD0(n, name, ns) namespace ns{class name;}
#define FORWARD0_(name) FORWARD0(name, NAME(name), BOOST_PP_CAT(name, Namespace))
#define FORWARD00_(seq) FORWARD0_(BOOST_PP_SEQ_HEAD(seq))

#define FORWARD1(n, name, T, seq, ns) namespace ns{BOOST_PP_TUPLE_ENUM(T) class name;}
#define FORWARD1_(name, seq) FORWARD1(name, NAME(name), TEMPLATE(seq), seq, BOOST_PP_CAT(name, Namespace))
#define FORWARD11_(seq) FORWARD1_(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq))

#define FORWARDX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), FORWARD00_, FORWARD11_)
#define FORWARD(...) FORWARDX(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define FORWARDN0(n, name) \
  class name;\
  using n = rt::ref<name>;\

#define FORWARDN0_(name) FORWARDN0(name, NAME(name))
#define FORWARDN00_(seq) FORWARDN0_(BOOST_PP_SEQ_HEAD(seq))

#define FORWARDN1(n, name, T, seq) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name;\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;

#define FORWARDN1_(name, seq) FORWARDN1(name, NAME(name), TEMPLATE(seq), seq)
#define FORWARDN11_(seq) FORWARDN1_(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq))

#define FORWARDNX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), FORWARDN00_, FORWARDN11_)
#define FORWARDN(...) FORWARDNX(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define FORWARD_MULTI(n, name, seq, ns) namespace ns{BOOST_PP_TUPLE_ENUM(TEMPLATE(seq)) class name;}
#define FORWARD_(name, ...) FORWARD_MULTI(name, NAME(name), BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), BOOST_PP_CAT(name, Namespace))

#define FORWARDN_MULTI(n, name, seq) \
  BOOST_PP_TUPLE_ENUM(TEMPLATE(seq))\
  class name;\
  BOOST_PP_TUPLE_ENUM(TEMPLATE_VOID(seq))\
  using n = rt::ref<name<BOOST_PP_SEQ_ENUM(seq)>>;

#define FORWARDN_(name, ...) FORWARDN_MULTI(name, NAME(name), BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define FORWARDS0(n, name, ns) namespace ns{struct name;}
#define FORWARDS0_(name) FORWARDS0(name, name, BOOST_PP_CAT(name, Namespace))
#define FORWARDS00_(seq) FORWARDS0_(BOOST_PP_SEQ_HEAD(seq))

#define FORWARDS1(n, name, T, seq, ns) namespace ns{BOOST_PP_TUPLE_ENUM(T) struct name;}
#define FORWARDS1_(name, seq) FORWARDS1(name, name, TEMPLATE(seq), seq, BOOST_PP_CAT(name, Namespace))
#define FORWARDS11_(seq) FORWARDS1_(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq))

#define FORWARDSX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), FORWARDS00_, FORWARDS11_)
#define FORWARDS(...) FORWARDSX(__VA_ARGS__)(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define FORWARDS_MULTI(n, name, seq, ns) namespace ns{BOOST_PP_TUPLE_ENUM(TEMPLATE(seq)) struct name;}
#define FORWARDS_(name, ...) FORWARDS_MULTI(name, name, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), BOOST_PP_CAT(name, Namespace))


// USING
#define NAMESPACE(ns, name) ns##::##name##Namespace

#define USING0(n, name, ns) \
  using n = rt::ref<ns::name>;\

#define USING0_(ns, name) USING0(name, NAME(name), NAMESPACE(ns, name))
#define USING00_(ns, seq) USING0_(ns, BOOST_PP_SEQ_HEAD(seq))

#define USING1(n, name, T, seq, ns) \
  BOOST_PP_TUPLE_ENUM(T)\
  using n = rt::ref<ns::name<BOOST_PP_SEQ_ENUM(seq)>>;

#define USING1_(name, seq) USING1(name, NAME(name), TEMPLATE(seq), seq, BOOST_PP_CAT(name, Namespace))
#define USING11_(seq) USING1_(BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq))

#define USINGX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), USING00_, USING11_)
#define USING(ns, ...) USINGX(__VA_ARGS__)(ns, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define USING_MULTI(n, name, seq, ns) \
  BOOST_PP_TUPLE_ENUM(TEMPLATE_VOID(seq))\
  using n = rt::ref<ns::name<BOOST_PP_SEQ_ENUM(seq)>>;

#define USING_(name, ...) USING_MULTI(name, NAME(name), BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), BOOST_PP_CAT(name, Namespace))

#define USINGS0(n, name, ns) using n = ns::name;
#define USINGS0_(ns, name) USINGS0(name, name, NAMESPACE(ns, name))
#define USINGS00_(ns, seq) USINGS0_(ns, BOOST_PP_SEQ_HEAD(seq))

#define USINGS1(n, name, T, seq, ns) \
  BOOST_PP_TUPLE_ENUM(T)\
  using n = ns::name<BOOST_PP_SEQ_ENUM(seq)>;

#define USINGS1_(ns, name, seq) USINGS1(name, name, TEMPLATE(seq), seq, NAMESPACE(ns, name))
#define USINGS11_(ns, seq) USINGS1_(ns, BOOST_PP_SEQ_HEAD(seq), BOOST_PP_SEQ_TAIL(seq))

#define USINGSX(...) BOOST_PP_IF(BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), 1), USINGS00_, USINGS11_)
#define USINGS(ns, ...) USINGSX(__VA_ARGS__)(ns, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define USINGS_MULTI(n, name, seq, ns) \
  BOOST_PP_TUPLE_ENUM(TEMPLATE_VOID(seq))\
  using n = ns::name<BOOST_PP_SEQ_ENUM(seq)>;

#define USINGS_(name, ...) USINGS_MULTI(name, name, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__), BOOST_PP_CAT(name, Namespace))

