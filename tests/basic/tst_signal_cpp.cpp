#include <wobjectdefs.h>
#include <wobjectimpl.h>
#define W_SIGNAL_H(...) W_MACRO_MSVC_EXPAND(W_SIGNAL2_H(__VA_ARGS__ , 0))
#define W_SIGNAL2_H(NAME, ...) \
    ; \
    static constexpr int w_signalIndex_##NAME = \
        decltype(w_SignalState(w_internal::w_number<>{}, static_cast<W_ThisType**>(nullptr)))::size; \
    friend constexpr auto w_SignalState(w_internal::w_number<w_signalIndex_##NAME + 1> w_counter, W_ThisType **w_this) \
        W_RETURN(w_internal::binary::tree_append(w_SignalState(w_counter.prev(), w_this), \
            w_internal::makeMetaSignalInfo( \
                W_OVERLOAD_RESOLVE(__VA_ARGS__)(&W_ThisType::NAME), #NAME, \
                W_INTEGRAL_CONSTANT_HELPER(NAME, __VA_ARGS__)(), \
                W_PARAM_TOSTRING(W_OVERLOAD_TYPES(__VA_ARGS__)), W_PARAM_TOSTRING(W_OVERLOAD_REMOVE(__VA_ARGS__))))) \
    static inline void w_GetAccessSpecifierHelper(W_INTEGRAL_CONSTANT_HELPER(NAME, __VA_ARGS__)) {}

#define W_SIGNAL2_IMPL(NAME, ...) \
    { /* W_SIGNAL need to be placed directly after the signal declaration, without semicolon. */\
        using w_SignalType = decltype(W_OVERLOAD_RESOLVE(__VA_ARGS__)(&W_ThisType::NAME)); \
        return w_internal::SignalImplementation<w_SignalType, w_signalIndex_##NAME>{this}(W_OVERLOAD_REMOVE(__VA_ARGS__)); \
    }
#if defined(Q_CC_MSVC)
#define K_SIGNAL(EXPORT_MACRO, ...) W_MACRO_MSVC_EXPAND(W_SIGNAL2_H(__VA_ARGS__ , 0))
#else
#define K_SIGNAL(EXPORT_MACRO, ...) W_MACRO_MSVC_EXPAND(W_SIGNAL2_H(__VA_ARGS__ , 0))
#endif

class foo : public QObject
{
  W_OBJECT(foo)
  public:
  void tutu(int x, const double& y) K_SIGNAL(_, tutu, x, y)
};

#define CAT_ARGS()
#define CAT_ARGS_0() T
#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__
# define EMPTY(...)
# define DEFER(...) __VA_ARGS__ EMPTY()
# define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()
# define EXPAND(...) __VA_ARGS__



#define K_EXPAND_PROTOTYPE2(T1, V1) T1 V1
#define K_EXPAND_PROTOTYPE3(T1, V1, T2) error
#define K_EXPAND_PROTOTYPE4(T1, V1, T2, V2) T1 V1, T2 V2
#define K_EXPAND_PROTOTYPE5(T1, V1, T2, V2, T3) error
#define K_EXPAND_PROTOTYPE6(T1, V1, T2, V2, T3, V3) T1 V1, T2 V2, T3 V3
#define K_EXPAND_PROTOTYPE7(T1, V1, T2, V2, T3, V3, T4) error
#define K_EXPAND_PROTOTYPE8(T1, V1, T2, V2, T3, V3, T4, V4) T1 V1, T2 V2, T3 V3, T4 V4
#define K_EXPAND_PROTOTYPE9(T1, V1, T2, V2, T3, V3, T4, V4, T5) error
#define K_EXPAND_PROTOTYPE10(T1, V1, T2, V2, T3, V3, T4, V4, T5, V5) T1 V1, T2 V2, T3 V3, T4 V4, T5 V5

#define K_EXPAND_PROTOTYPE_GET(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define K_EXPAND_PROTOTYPE(...) K_EXPAND_PROTOTYPE_GET(__VA_ARGS__, K_EXPAND_PROTOTYPE10, K_EXPAND_PROTOTYPE9, K_EXPAND_PROTOTYPE8, K_EXPAND_PROTOTYPE7, K_EXPAND_PROTOTYPE6, K_EXPAND_PROTOTYPE5, K_EXPAND_PROTOTYPE4, K_EXPAND_PROTOTYPE3, K_EXPAND_PROTOTYPE2)(__VA_ARGS__)


#define K_EXPAND_TYPES2(T1, V1) T1
#define K_EXPAND_TYPES3(T1, V1, T2) error
#define K_EXPAND_TYPES4(T1, V1, T2, V2) T1, T2
#define K_EXPAND_TYPES5(T1, V1, T2, V2, T3) error
#define K_EXPAND_TYPES6(T1, V1, T2, V2, T3, V3) T1, T2, T3
#define K_EXPAND_TYPES7(T1, V1, T2, V2, T3, V3, T4) error
#define K_EXPAND_TYPES8(T1, V1, T2, V2, T3, V3, T4, V4) T1, T2, T3, T4
#define K_EXPAND_TYPES9(T1, V1, T2, V2, T3, V3, T4, V4, T5) error
#define K_EXPAND_TYPES10(T1, V1, T2, V2, T3, V3, T4, V4, T5, V5) T1, T2, T3, T4, T5

#define K_EXPAND_TYPES_GET(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define K_EXPAND_TYPES(...) K_EXPAND_TYPES_GET(__VA_ARGS__, K_EXPAND_TYPES10, K_EXPAND_TYPES9, K_EXPAND_TYPES8, K_EXPAND_TYPES7, K_EXPAND_TYPES6, K_EXPAND_TYPES5, K_EXPAND_TYPES4, K_EXPAND_TYPES3, K_EXPAND_TYPES2)(__VA_ARGS__)


#define K_EXPAND_VALUES2(T1, V1) V1
#define K_EXPAND_VALUES3(T1, V1, T2) error
#define K_EXPAND_VALUES4(T1, V1, T2, V2) V1, V2
#define K_EXPAND_VALUES5(T1, V1, T2, V2, T3) error
#define K_EXPAND_VALUES6(T1, V1, T2, V2, T3, V3) V1, V2, V3
#define K_EXPAND_VALUES7(T1, V1, T2, V2, T3, V3, T4) error
#define K_EXPAND_VALUES8(T1, V1, T2, V2, T3, V3, T4, V4) V1, V2, V3, V4
#define K_EXPAND_VALUES9(T1, V1, T2, V2, T3, V3, T4, V4, T5) error
#define K_EXPAND_VALUES10(T1, V1, T2, V2, T3, V3, T4, V4, T5, V5) V1, V2, V3, V4, V5

#define K_EXPAND_VALUES_GET(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define K_EXPAND_VALUES(...) K_EXPAND_VALUES_GET(__VA_ARGS__, K_EXPAND_VALUES10, K_EXPAND_VALUES9, K_EXPAND_VALUES8, K_EXPAND_VALUES7, K_EXPAND_VALUES6, K_EXPAND_VALUES5, K_EXPAND_VALUES4, K_EXPAND_VALUES3, K_EXPAND_VALUES2)(__VA_ARGS__)


#define E_SIGNAL_IMPL(Class, Function, ...)\
  void Class::Function(K_EXPAND_PROTOTYPE(__VA_ARGS__)) {\
  using w_SignalType = decltype(W_OVERLOAD_RESOLVE(K_EXPAND_TYPES(__VA_ARGS__))(&W_ThisType::Function)); \
  return w_internal::SignalImplementation<w_SignalType, w_signalIndex_##Function>{this}(K_EXPAND_VALUES(__VA_ARGS__), 0); \
}

E_SIGNAL_IMPL(foo, tutu, int, x, const double&, y)
