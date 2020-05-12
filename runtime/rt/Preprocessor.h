#pragma once

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/tuple/enum.hpp>

#define INSERT_METADATA_OBJ \
  public:\
    static const meson::TypeMetadata& getTypeMetadata() {\
      return typeMetadata_;\
    };\
  private:\
    static meson::TypeMetadata typeMetadata_;


#define NAME(s, c, l) BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(s, _), _), _)

#define CLASS_0_(n, name) \
  class name;\
  using n = meson::ref<name>;\
  class name

#define CLASS(name) CLASS_0_(name, NAME(name, __COUNTER__, __LINE__))
#define CLASS_OP(s, d, e) class e
#define TEMPLATE(...) (template<BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(CLASS_OP, _, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))>)

#define CLASS_1_(n, name, T, ...) \
  BOOST_PP_TUPLE_ENUM(T)\
  class name;\
  BOOST_PP_TUPLE_ENUM(T)\
  using n = meson::ref<name<__VA_ARGS__>>;\
  BOOST_PP_TUPLE_ENUM(T)\
  class name

#define CLASS_(name, ...) CLASS_1_(name, NAME(name, __COUNTER__, __LINE__), TEMPLATE(__VA_ARGS__), __VA_ARGS__)


