// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_MACROS_H__
#define __MURL_MACROS_H__

// Visual Studio helper
#define MURL_EXPAND(x) x
#define MURL_EXPAND2(x, ...) x,##__VA_ARGS__
#define MURL_EXPAND3(...) __VA_ARGS__

// Stringize
#define MURL_STRINGIZE(arg)  MURL_STRINGIZE_1(arg)
#define MURL_STRINGIZE_1(arg) MURL_STRINGIZE_2(arg)
#define MURL_STRINGIZE_2(arg) #arg

// Concatenate
#define MURL_CONCATENATE(arg1, arg2)   MURL_CONCATENATE_1(arg1, arg2)
#define MURL_CONCATENATE_1(arg1, arg2)  MURL_CONCATENATE_2(arg1, arg2)
#define MURL_CONCATENATE_2(arg1, arg2)  arg1##arg2

// Apply
#define MURL_APPLY(arg1, arg2)   MURL_APPLY_1(arg1, arg2)
#define MURL_APPLY_1(arg1, arg2)  MURL_APPLY_2(arg1, arg2)
#define MURL_APPLY_2(arg1, arg2)  arg1 arg2

// Helpers for varargs
//#define MURL_X(a1,a2,a3,a4,a5,a6,...) *a1*a2*a3*a4*a5*a6*

#ifdef MURL_COMPILER_VS

#define MURL_X(a1,a2,a3,a4,a5,a6,a7,...) a7
#define MURL_COMMA_IF_NOT_EMPTY(...) MURL_EXPAND(MURL_X(XX, __VA_ARGS__, MURL_COMMA,MURL_COMMA,MURL_COMMA,MURL_COMMA,,,))
#define MURL_LT_IF_NOT_EMPTY(...) MURL_EXPAND(MURL_X(XX, __VA_ARGS__, MURL_LT,MURL_LT,MURL_LT,MURL_LT,,,))
#define MURL_RT_IF_NOT_EMPTY(...) MURL_EXPAND(MURL_X(XX, __VA_ARGS__, MURL_RT,MURL_RT,MURL_RT,MURL_RT,,,))

#else

#define MURL_GET_6TH_ARG(a1,a2,a3,a4,a5,a6,...) a6
#define MURL_COMMA_IF_NOT_EMPTY(...) MURL_GET_6TH_ARG(,##__VA_ARGS__,MURL_COMMA,MURL_COMMA,MURL_COMMA,MURL_COMMA,)
#define MURL_LT_IF_NOT_EMPTY(...) MURL_GET_6TH_ARG(,##__VA_ARGS__,MURL_LT,MURL_LT,MURL_LT,MURL_LT,)
#define MURL_RT_IF_NOT_EMPTY(...) MURL_GET_6TH_ARG(,##__VA_ARGS__,MURL_RT,MURL_RT,MURL_RT,MURL_RT,)

#endif


#define MURL_COMMA ,
#define MURL_LT <
#define MURL_RT >

// Strip parentheses
#define MURL_STRIP_PARENTHESES(x) MURL_STRIP_PARENTHESES_EVAL((MURL_STRIP_PARENTHESES_I x), x)
#define MURL_STRIP_PARENTHESES_I(...) 1,1

#define MURL_STRIP_PARENTHESES_EVAL(test, x) MURL_STRIP_PARENTHESES_EVAL_I(test, x)
#define MURL_STRIP_PARENTHESES_EVAL_I(test, x) MURL_MAYBE_STRIP_PARENTHESES(MURL_STRIP_PARENTHESES_TEST_ARITY test, x)

#define MURL_STRIP_PARENTHESES_TEST_ARITY(...) MURL_APPLY(MURL_STRIP_PARENTHESES_TEST_ARITY_I, (__VA_ARGS__, 2, 1))
#define MURL_STRIP_PARENTHESES_TEST_ARITY_I(a,b,c,...) c

#define MURL_MAYBE_STRIP_PARENTHESES(cond, x) MURL_MAYBE_STRIP_PARENTHESES_I(cond, x)
#define MURL_MAYBE_STRIP_PARENTHESES_I(cond, x) MURL_CONCATENATE(MURL_MAYBE_STRIP_PARENTHESES_, cond)(x)

#define MURL_MAYBE_STRIP_PARENTHESES_1(x) x
#define MURL_MAYBE_STRIP_PARENTHESES_2(x) MURL_APPLY(MURL_MAYBE_STRIP_PARENTHESES_2_I, x)
#define MURL_MAYBE_STRIP_PARENTHESES_2_I(...) __VA_ARGS__

// For..Each iteration
#define MURL_FOR_EACH_1(what, x, ...) what(x)
#define MURL_FOR_EACH_2(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_1(what, __VA_ARGS__))
#define MURL_FOR_EACH_3(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_2(what, __VA_ARGS__))
#define MURL_FOR_EACH_4(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_3(what, __VA_ARGS__))
#define MURL_FOR_EACH_5(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_4(what, __VA_ARGS__))
#define MURL_FOR_EACH_6(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_5(what, __VA_ARGS__))
#define MURL_FOR_EACH_7(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_6(what, __VA_ARGS__))
#define MURL_FOR_EACH_8(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_7(what, __VA_ARGS__))
#define MURL_FOR_EACH_9(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_8(what, __VA_ARGS__))
#define MURL_FOR_EACH_10(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_9(what, __VA_ARGS__))

#define MURL_FOR_EACH_11(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_10(what, __VA_ARGS__))
#define MURL_FOR_EACH_12(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_11(what, __VA_ARGS__))
#define MURL_FOR_EACH_13(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_12(what, __VA_ARGS__))
#define MURL_FOR_EACH_14(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_13(what, __VA_ARGS__))
#define MURL_FOR_EACH_15(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_14(what, __VA_ARGS__))
#define MURL_FOR_EACH_16(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_15(what, __VA_ARGS__))
#define MURL_FOR_EACH_17(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_16(what, __VA_ARGS__))
#define MURL_FOR_EACH_18(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_17(what, __VA_ARGS__))
#define MURL_FOR_EACH_19(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_18(what, __VA_ARGS__))
#define MURL_FOR_EACH_20(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_19(what, __VA_ARGS__))

#define MURL_FOR_EACH_21(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_20(what, __VA_ARGS__))
#define MURL_FOR_EACH_22(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_21(what, __VA_ARGS__))
#define MURL_FOR_EACH_23(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_22(what, __VA_ARGS__))
#define MURL_FOR_EACH_24(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_23(what, __VA_ARGS__))
#define MURL_FOR_EACH_25(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_24(what, __VA_ARGS__))
#define MURL_FOR_EACH_26(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_25(what, __VA_ARGS__))
#define MURL_FOR_EACH_27(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_26(what, __VA_ARGS__))
#define MURL_FOR_EACH_28(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_27(what, __VA_ARGS__))
#define MURL_FOR_EACH_29(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_28(what, __VA_ARGS__))
#define MURL_FOR_EACH_30(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_29(what, __VA_ARGS__))

#define MURL_FOR_EACH_31(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_30(what, __VA_ARGS__))
#define MURL_FOR_EACH_32(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_31(what, __VA_ARGS__))
#define MURL_FOR_EACH_33(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_32(what, __VA_ARGS__))
#define MURL_FOR_EACH_34(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_33(what, __VA_ARGS__))
#define MURL_FOR_EACH_35(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_34(what, __VA_ARGS__))
#define MURL_FOR_EACH_36(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_35(what, __VA_ARGS__))
#define MURL_FOR_EACH_37(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_36(what, __VA_ARGS__))
#define MURL_FOR_EACH_38(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_37(what, __VA_ARGS__))
#define MURL_FOR_EACH_39(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_38(what, __VA_ARGS__))
#define MURL_FOR_EACH_40(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_39(what, __VA_ARGS__))

#define MURL_FOR_EACH_41(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_40(what, __VA_ARGS__))
#define MURL_FOR_EACH_42(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_41(what, __VA_ARGS__))
#define MURL_FOR_EACH_43(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_42(what, __VA_ARGS__))
#define MURL_FOR_EACH_44(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_43(what, __VA_ARGS__))
#define MURL_FOR_EACH_45(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_44(what, __VA_ARGS__))
#define MURL_FOR_EACH_46(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_45(what, __VA_ARGS__))
#define MURL_FOR_EACH_47(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_46(what, __VA_ARGS__))
#define MURL_FOR_EACH_48(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_47(what, __VA_ARGS__))
#define MURL_FOR_EACH_49(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_48(what, __VA_ARGS__))
#define MURL_FOR_EACH_50(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_49(what, __VA_ARGS__))

#define MURL_FOR_EACH_51(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_50(what, __VA_ARGS__))
#define MURL_FOR_EACH_52(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_51(what, __VA_ARGS__))
#define MURL_FOR_EACH_53(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_52(what, __VA_ARGS__))
#define MURL_FOR_EACH_54(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_53(what, __VA_ARGS__))
#define MURL_FOR_EACH_55(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_54(what, __VA_ARGS__))
#define MURL_FOR_EACH_56(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_55(what, __VA_ARGS__))
#define MURL_FOR_EACH_57(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_56(what, __VA_ARGS__))
#define MURL_FOR_EACH_58(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_57(what, __VA_ARGS__))
#define MURL_FOR_EACH_59(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_58(what, __VA_ARGS__))
#define MURL_FOR_EACH_60(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_59(what, __VA_ARGS__))

#define MURL_FOR_EACH_61(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_60(what, __VA_ARGS__))
#define MURL_FOR_EACH_62(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_61(what, __VA_ARGS__))
#define MURL_FOR_EACH_63(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_62(what, __VA_ARGS__))
#define MURL_FOR_EACH_64(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_63(what, __VA_ARGS__))
#define MURL_FOR_EACH_65(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_64(what, __VA_ARGS__))
#define MURL_FOR_EACH_66(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_65(what, __VA_ARGS__))
#define MURL_FOR_EACH_67(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_66(what, __VA_ARGS__))
#define MURL_FOR_EACH_68(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_67(what, __VA_ARGS__))
#define MURL_FOR_EACH_69(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_68(what, __VA_ARGS__))
#define MURL_FOR_EACH_70(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_69(what, __VA_ARGS__))

#define MURL_FOR_EACH_71(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_70(what, __VA_ARGS__))
#define MURL_FOR_EACH_72(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_71(what, __VA_ARGS__))
#define MURL_FOR_EACH_73(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_72(what, __VA_ARGS__))
#define MURL_FOR_EACH_74(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_73(what, __VA_ARGS__))
#define MURL_FOR_EACH_75(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_74(what, __VA_ARGS__))
#define MURL_FOR_EACH_76(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_75(what, __VA_ARGS__))
#define MURL_FOR_EACH_77(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_76(what, __VA_ARGS__))
#define MURL_FOR_EACH_78(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_77(what, __VA_ARGS__))
#define MURL_FOR_EACH_79(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_78(what, __VA_ARGS__))
#define MURL_FOR_EACH_80(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_79(what, __VA_ARGS__))

#define MURL_FOR_EACH_81(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_80(what, __VA_ARGS__))
#define MURL_FOR_EACH_82(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_81(what, __VA_ARGS__))
#define MURL_FOR_EACH_83(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_82(what, __VA_ARGS__))
#define MURL_FOR_EACH_84(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_83(what, __VA_ARGS__))
#define MURL_FOR_EACH_85(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_84(what, __VA_ARGS__))
#define MURL_FOR_EACH_86(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_85(what, __VA_ARGS__))
#define MURL_FOR_EACH_87(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_86(what, __VA_ARGS__))
#define MURL_FOR_EACH_88(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_87(what, __VA_ARGS__))
#define MURL_FOR_EACH_89(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_88(what, __VA_ARGS__))
#define MURL_FOR_EACH_90(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_89(what, __VA_ARGS__))

#define MURL_FOR_EACH_91(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_90(what, __VA_ARGS__))
#define MURL_FOR_EACH_92(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_91(what, __VA_ARGS__))
#define MURL_FOR_EACH_93(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_92(what, __VA_ARGS__))
#define MURL_FOR_EACH_94(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_93(what, __VA_ARGS__))
#define MURL_FOR_EACH_95(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_94(what, __VA_ARGS__))
#define MURL_FOR_EACH_96(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_95(what, __VA_ARGS__))
#define MURL_FOR_EACH_97(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_96(what, __VA_ARGS__))
#define MURL_FOR_EACH_98(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_97(what, __VA_ARGS__))
#define MURL_FOR_EACH_99(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_98(what, __VA_ARGS__))
#define MURL_FOR_EACH_100(what, x, ...) what(x) MURL_EXPAND(MURL_FOR_EACH_99(what, __VA_ARGS__))

#define MURL_FOR_EACH_NARG(...) MURL_FOR_EACH_NARG_(__VA_ARGS__, MURL_FOR_EACH_RSEQ_N())
#define MURL_FOR_EACH_NARG_(...) MURL_EXPAND(MURL_FOR_EACH_ARG_N(__VA_ARGS__))

#define MURL_FOR_EACH_ARG_N( \
_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
_11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
_21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
_31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
_41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
_51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
_61, _62, _63, _64, _65, _66, _67, _68, _69, _70, \
_71, _72, _73, _74, _75, _76, _77, _78, _79, _80, \
_81, _82, _83, _84, _85, _86, _87, _88, _89, _90, \
_91, _92, _93, _94, _95, _96, _97, _98, _99, _100, \
N, ...) N

#define MURL_FOR_EACH_RSEQ_N() \
100, 99, 98, 97, 96, 95, 94, 93, 92, 91, \
90, 89, 88, 87, 86, 85, 84, 83, 82, 81, \
80, 79, 78, 77, 76, 75, 74, 73, 72, 71, \
70, 69, 68, 67, 66, 65, 64, 63, 62, 61, \
60, 59, 58, 57, 56, 55, 54, 53, 52, 51, \
50, 49, 48, 47, 46, 45, 44, 43, 42, 41, \
40, 39, 38, 37, 36, 35, 34, 33, 32, 31, \
30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
20, 19, 18, 17, 16, 15, 14, 13, 12, 11, \
10, 9, 8, 7, 6, 5, 4, 3, 2, 1, \
0

#define MURL_FOR_EACH_(N, what, x, ...) MURL_EXPAND(MURL_CONCATENATE(MURL_FOR_EACH_, N)(what, x, __VA_ARGS__))
#define MURL_FOR_EACH(what, ...) MURL_FOR_EACH_(MURL_FOR_EACH_NARG(__VA_ARGS__), what, __VA_ARGS__)

// Link-time class removal

#ifdef MURL_COMPILER_VS

#define MURL_REMOVE_CLASS(...) 

#else

#define MURL_REMOVE_CLASS_N0(name, base) \
class name \
{ \
public: \
    __attribute__((visibility("default"))) __attribute__((used)) static const base::ClassInfo& GetClassInfo() \
    { \
        static const base::ClassInfo sClassInfo; \
        return sClassInfo; \
    } \
};

#define MURL_REMOVE_CLASS_N1(nmspc1, name, base) \
namespace nmspc1 \
{ \
    class name \
    { \
    public: \
        __attribute__((visibility("default"))) __attribute__((used)) static const base::ClassInfo& GetClassInfo() \
        { \
            static const base::ClassInfo sClassInfo; \
            return sClassInfo; \
        } \
    }; \
}

#define MURL_REMOVE_CLASS_N2(nmspc1, nmspc2, name, base) \
namespace nmspc1 \
{ \
    namespace nmspc2 \
    { \
        class name \
        { \
        public: \
            __attribute__((visibility("default"))) __attribute__((used)) static const base::ClassInfo& GetClassInfo() \
            { \
                static const base::ClassInfo sClassInfo; \
                return sClassInfo; \
            } \
        }; \
    } \
}

#define MURL_REMOVE_CLASS_N3(nmspc1, nmspc2, nmspc3, name, base) \
namespace nmspc1 \
{ \
    namespace nmspc2 \
    { \
        namespace nmspc3 \
        { \
            class name \
            { \
            public: \
                __attribute__((visibility("default"))) __attribute__((used)) static const base::ClassInfo& GetClassInfo() \
                { \
                    static const base::ClassInfo sClassInfo; \
                    return sClassInfo; \
                } \
            }; \
        } \
    } \
}

#define MURL_GET_REMOVE_CLASS(_1, _2, _3, _4, _5, NAME, ...) NAME
#define MURL_REMOVE_CLASS(...) MURL_GET_REMOVE_CLASS(__VA_ARGS__, MURL_REMOVE_CLASS_N3, MURL_REMOVE_CLASS_N2, MURL_REMOVE_CLASS_N1, MURL_REMOVE_CLASS_N0)(__VA_ARGS__)

#endif

#define MURL_REMOVE_GRAPH_NODE_CLASS(...)                   MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Graph::INode);
#define MURL_REMOVE_GRAPH_CONTROLLER_CLASS(...)             MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Graph::IController);
#define MURL_REMOVE_AUDIO_RENDERER_CLASS(...)               MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Audio::IRenderer);
#define MURL_REMOVE_AUDIO_OBJECT_CLASS(...)                 MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Audio::IObject);
#define MURL_REMOVE_VIDEO_RENDERER_CLASS(...)               MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Video::IRenderer);
#define MURL_REMOVE_VIDEO_OBJECT_CLASS(...)                 MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Video::IObject);
#define MURL_REMOVE_PHYSICS_SIMULATOR_CLASS(...)            MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Physics::ISimulator);
#define MURL_REMOVE_PHYSICS_OBJECT_CLASS(...)               MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Physics::IObject);
#define MURL_REMOVE_RESOURCE_COLLECTION_FACTORY_CLASS(...)  MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Resource::ICollectionFactory);
#define MURL_REMOVE_RESOURCE_COLLECTION_CLASS(...)          MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Resource::ICollection);
#define MURL_REMOVE_RESOURCE_PACKAGE_FACTORY_CLASS(...)     MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Resource::IPackageFactory);
#define MURL_REMOVE_RESOURCE_PACKAGE_CLASS(...)             MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Resource::IPackage);
#define MURL_REMOVE_RESOURCE_OBJECT_FACTORY_CLASS(...)      MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Resource::IObjectFactory);
#define MURL_REMOVE_RESOURCE_OBJECT_CLASS(...)              MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Resource::IObject);
#define MURL_REMOVE_UTIL_IMAGE_DECODER_CLASS(...)           MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Util::IImageDecoder);
#define MURL_REMOVE_UTIL_IMAGE_ENCODER_CLASS(...)           MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Util::IImageEncoder);
#define MURL_REMOVE_UTIL_IMAGE_DECOMPRESSOR_CLASS(...)      MURL_REMOVE_CLASS(__VA_ARGS__, Murl::Util::IImageDecompressor);

#endif  // __MURL_MACROS_H__
