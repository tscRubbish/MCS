/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mcs.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "mcs_def.h"
int yylex(void);
void yyerror(char *); 
extern int yylineno;

//int maxModelSize=1024
//model modelList[1024];
//int model_size=0;
//def* now_def_list;
//formula* now_formula_list;
int cur_constant=0;
int cur_assign=0;

int cur_model=0;
int cur_val=0;
int cur_def=0;
int _i,_j,len;
int para_size=0;
char* fname;
//PARAIDXLIST pil;
int para_idx_tmp[MAX_N_PARA];
int mp[MAX_N_DEF];

//int* constant_id;
//int* id_constant;


#line 105 "mcs.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "mcs.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ModelSize = 3,                  /* ModelSize  */
  YYSYMBOL_TermDepth = 4,                  /* TermDepth  */
  YYSYMBOL_ValSize = 5,                    /* ValSize  */
  YYSYMBOL_DefSize = 6,                    /* DefSize  */
  YYSYMBOL_ConstantSize = 7,               /* ConstantSize  */
  YYSYMBOL_AssignSize = 8,                 /* AssignSize  */
  YYSYMBOL_ModelSplit = 9,                 /* ModelSplit  */
  YYSYMBOL_LFun = 10,                      /* LFun  */
  YYSYMBOL_RFun = 11,                      /* RFun  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_STR = 13,                       /* STR  */
  YYSYMBOL_INT_NUMBER = 14,                /* INT_NUMBER  */
  YYSYMBOL_Split = 15,                     /* Split  */
  YYSYMBOL_DefSplit = 16,                  /* DefSplit  */
  YYSYMBOL_End = 17,                       /* End  */
  YYSYMBOL_ResSplit = 18,                  /* ResSplit  */
  YYSYMBOL_YYACCEPT = 19,                  /* $accept  */
  YYSYMBOL_MCS = 20,                       /* MCS  */
  YYSYMBOL_21_1 = 21,                      /* $@1  */
  YYSYMBOL_22_2 = 22,                      /* $@2  */
  YYSYMBOL_23_3 = 23,                      /* $@3  */
  YYSYMBOL_24_4 = 24,                      /* $@4  */
  YYSYMBOL_val_list = 25,                  /* val_list  */
  YYSYMBOL_def_list = 26,                  /* def_list  */
  YYSYMBOL_def = 27,                       /* def  */
  YYSYMBOL_28_5 = 28,                      /* $@5  */
  YYSYMBOL_29_6 = 29,                      /* $@6  */
  YYSYMBOL_model_list = 30,                /* model_list  */
  YYSYMBOL_31_7 = 31,                      /* $@7  */
  YYSYMBOL_32_8 = 32,                      /* $@8  */
  YYSYMBOL_model = 33,                     /* model  */
  YYSYMBOL_34_9 = 34,                      /* $@9  */
  YYSYMBOL_35_10 = 35,                     /* $@10  */
  YYSYMBOL_constant_list = 36,             /* constant_list  */
  YYSYMBOL_res_list = 37,                  /* res_list  */
  YYSYMBOL_38_11 = 38,                     /* $@11  */
  YYSYMBOL_res = 39,                       /* res  */
  YYSYMBOL_fun = 40,                       /* fun  */
  YYSYMBOL_41_12 = 41,                     /* $@12  */
  YYSYMBOL_para_list = 42                  /* para_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   54

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  76

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    70,    76,    82,    64,    93,   103,   114,
     115,   117,   122,   117,   138,   140,   145,   139,   153,   159,
     152,   166,   175,   184,   193,   203,   203,   208,   211,   231,
     258,   257,   285,   307,   329,   350
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ModelSize",
  "TermDepth", "ValSize", "DefSize", "ConstantSize", "AssignSize",
  "ModelSplit", "LFun", "RFun", "EQ", "STR", "INT_NUMBER", "Split",
  "DefSplit", "End", "ResSplit", "$accept", "MCS", "$@1", "$@2", "$@3",
  "$@4", "val_list", "def_list", "def", "$@5", "$@6", "model_list", "$@7",
  "$@8", "model", "$@9", "$@10", "constant_list", "res_list", "$@11",
  "res", "fun", "$@12", "para_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     7,    22,   -25,   -25,     8,    20,    11,   -25,    12,
      21,    14,   -25,    15,    23,    17,   -25,    16,    19,   -25,
     -12,    24,   -25,   -25,   -11,   -25,    25,   -25,    -9,   -25,
     -25,   -25,   -25,   -25,    26,    28,    27,    29,   -25,    31,
     -25,    -9,   -25,    30,   -25,    -3,   -25,   -25,    -6,     0,
      32,   -25,   -25,    33,   -25,    34,    36,   -25,    37,   -25,
      35,    39,    44,    36,     2,     4,   -25,   -25,   -25,   -25,
     -25,   -10,   -25,     6,   -25,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     5,     0,     0,     8,
       0,     0,    11,     7,     0,    10,     0,    11,     0,    12,
       9,    15,    14,     6,     0,     0,     0,     0,    16,     0,
      18,     0,    13,     0,    17,     0,    23,    24,     0,     0,
       0,    21,    22,     0,    19,     0,    27,    20,     0,    30,
       0,     0,     0,    27,     0,     0,    26,    28,    29,    34,
      35,     0,    31,     0,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,    18,   -25,
     -25,    -8,   -25,   -25,   -25,   -25,   -25,   -25,   -24,   -25,
     -25,   -25,   -25,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,     9,    13,    17,    20,    24,    25,    26,
      34,    33,    35,    41,    38,    43,    55,    48,    57,    58,
      60,    61,    62,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    72,     1,    21,    27,    73,    22,    28,    32,    49,
      46,    47,    50,    51,    52,    67,    68,    69,    70,    74,
      75,     3,     4,     6,     7,     8,    11,    10,    12,    15,
      14,    16,    19,    44,    18,    37,    36,    23,    29,    66,
      53,    39,    42,    40,     0,    30,     0,    54,    45,   -25,
      59,    64,    56,    63,    65
};

static const yytype_int8 yycheck[] =
{
       9,    11,     3,    15,    15,    15,    18,    18,    17,    15,
      13,    14,    18,    13,    14,    13,    14,    13,    14,    13,
      14,    14,     0,    15,     4,    14,     5,    15,    14,     6,
      15,    14,    13,    41,    18,     7,    10,    13,    13,    63,
       8,    14,    11,    14,    -1,    27,    -1,    14,    18,    13,
      13,    12,    18,    18,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    20,    14,     0,    21,    15,     4,    14,    22,
      15,     5,    14,    23,    15,     6,    14,    24,    18,    13,
      25,    15,    18,    13,    26,    27,    28,    15,    18,    13,
      27,     9,    17,    30,    29,    31,    10,     7,    33,    14,
      14,    32,    11,    34,    30,    18,    13,    14,    36,    15,
      18,    13,    14,     8,    14,    35,    18,    37,    38,    13,
      39,    40,    41,    18,    12,    10,    37,    13,    14,    13,
      14,    42,    11,    15,    13,    14
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    19,    21,    22,    23,    24,    20,    25,    25,    26,
      26,    28,    29,    27,    30,    31,    32,    30,    34,    35,
      33,    36,    36,    36,    36,    38,    37,    37,    39,    39,
      41,    40,    42,    42,    42,    42
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    21,     3,     1,     3,
       1,     0,     0,     6,     1,     0,     0,     5,     0,     0,
      11,     3,     3,     1,     1,     0,     4,     0,     3,     3,
       0,     5,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 65 "mcs.y"
    {
        model_size = atoi((yyvsp[0].str));
        Model_Table = (MODEL*)malloc(sizeof(MODEL)*model_size);
    }
#line 1174 "mcs.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 70 "mcs.y"
    {
        max_depth= atoi((yyvsp[0].str));
        Term_Table = (TERMLIST*)malloc(sizeof(TERMLIST)*max_depth);
        term_num = (int*)malloc(sizeof(int)*max_depth);
    }
#line 1184 "mcs.tab.c"
    break;

  case 4: /* $@3: %empty  */
#line 76 "mcs.y"
    {
        val_size=atoi((yyvsp[0].str));
        Val_Table = (VAL*)malloc(sizeof(VAL)*val_size);
        printf("Val number = %d\n",atoi((yyvsp[0].str)));
    }
#line 1194 "mcs.tab.c"
    break;

  case 5: /* $@4: %empty  */
#line 82 "mcs.y"
    {
        def_size=atoi((yyvsp[0].str));
        Def_Table = (DEF*)malloc(sizeof(DEF)*def_size);
        printf("Def number = %d\n",atoi((yyvsp[0].str)));
    }
#line 1204 "mcs.tab.c"
    break;

  case 6: /* MCS: ModelSize INT_NUMBER $@1 Split TermDepth INT_NUMBER $@2 Split ValSize INT_NUMBER $@3 Split DefSize INT_NUMBER $@4 ResSplit val_list ResSplit def_list ResSplit model_list  */
#line 88 "mcs.y"
    {
        generateTerm(); 
        generateFormula();
    }
#line 1213 "mcs.tab.c"
    break;

  case 7: /* val_list: val_list Split STR  */
#line 94 "mcs.y"
    {
        len = getNameLength( (yyvsp[0].str) );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , (yyvsp[0].str));

        Val_Table[cur_val]=(VAL)malloc(sizeof(struct Val));
        Val_Table[cur_val++]->val_name =fname;
        printf("val name : %s , name len is %d\n", fname, len);
    }
#line 1227 "mcs.tab.c"
    break;

  case 8: /* val_list: STR  */
#line 104 "mcs.y"
    {
        len = getNameLength( (yyvsp[0].str) );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , (yyvsp[0].str));

        Val_Table[cur_val]=(VAL)malloc(sizeof(struct Val));
        Val_Table[cur_val++]->val_name =fname;
        printf("val name : %s , name len is %d\n", fname, len);
    }
#line 1241 "mcs.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 117 "mcs.y"
        {
            Def_Table[cur_def] = (DEF)malloc(sizeof(struct Def));
            Def_Table[cur_def]->para_size=0;
        }
#line 1250 "mcs.tab.c"
    break;

  case 12: /* $@6: %empty  */
#line 122 "mcs.y"
        {
            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            Def_Table[cur_def]->fun_name =fname;
            printf("fun def : %s  len is %d\n", fname, len);
        }
#line 1263 "mcs.tab.c"
    break;

  case 13: /* def: $@5 STR $@6 LFun INT_NUMBER RFun  */
#line 131 "mcs.y"
        {
            Def_Table[cur_def]->para_size = atoi((yyvsp[-1].str));
            cur_def++;
            printf("def para size is %d \n", atoi((yyvsp[-1].str)));
            //printf("len = %d\n", len);
        }
#line 1274 "mcs.tab.c"
    break;

  case 15: /* $@7: %empty  */
#line 140 "mcs.y"
        {
            Model_Table[cur_model]=(MODEL)malloc(sizeof(struct Model));
            printf("model id = %d\n",cur_model);
        }
#line 1283 "mcs.tab.c"
    break;

  case 16: /* $@8: %empty  */
#line 145 "mcs.y"
        {
            //max_constant_num = max(max_constant_num,cur_constant);
            printModel();
            initNewModel();
        }
#line 1293 "mcs.tab.c"
    break;

  case 18: /* $@9: %empty  */
#line 153 "mcs.y"
        {
           Model_Table[cur_model]->constant_size=atoi((yyvsp[0].str));
           Model_Table[cur_model]->Constant_Table=(CONSTANT*)malloc(sizeof(CONSTANT)*Model_Table[cur_model]->constant_size);
           printf("Constant number = %d\n",atoi((yyvsp[0].str)));
        }
#line 1303 "mcs.tab.c"
    break;

  case 19: /* $@10: %empty  */
#line 159 "mcs.y"
        {
            Model_Table[cur_model]->assign_size =atoi((yyvsp[0].str));
            Model_Table[cur_model]->Assign_Table = (INPUTASSIGN*)malloc(sizeof(INPUTASSIGN)*Model_Table[cur_model]->assign_size);
            printf("Assign number = %d\n",atoi((yyvsp[0].str)));
        }
#line 1313 "mcs.tab.c"
    break;

  case 21: /* constant_list: constant_list Split STR  */
#line 167 "mcs.y"
    {
        len = getNameLength( (yyvsp[0].str) );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , (yyvsp[0].str));
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }
#line 1326 "mcs.tab.c"
    break;

  case 22: /* constant_list: constant_list Split INT_NUMBER  */
#line 176 "mcs.y"
    {
        len = getNameLength( (yyvsp[0].str) );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , (yyvsp[0].str));
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }
#line 1339 "mcs.tab.c"
    break;

  case 23: /* constant_list: STR  */
#line 185 "mcs.y"
    {
        len = getNameLength( (yyvsp[0].str) );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , (yyvsp[0].str));
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }
#line 1352 "mcs.tab.c"
    break;

  case 24: /* constant_list: INT_NUMBER  */
#line 194 "mcs.y"
    {
        len = getNameLength( (yyvsp[0].str) );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , (yyvsp[0].str));
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }
#line 1365 "mcs.tab.c"
    break;

  case 25: /* $@11: %empty  */
#line 203 "mcs.y"
          {
            Model_Table[cur_model]->Assign_Table[cur_assign]=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
            Model_Table[cur_model]->Assign_Table[cur_assign]->para_size=0;
        }
#line 1374 "mcs.tab.c"
    break;

  case 28: /* res: fun EQ STR  */
#line 212 "mcs.y"
        {
            printf("eq res is %s\n",(yyvsp[0].str));
            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    Model_Table[cur_model]->Assign_Table[cur_assign]->res_idx=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no definition of constant %s" ,(yyvsp[0].str));
                exit(1);
            }
            cur_assign++;
            free(fname);
        }
#line 1398 "mcs.tab.c"
    break;

  case 29: /* res: fun EQ INT_NUMBER  */
#line 232 "mcs.y"
        {
            printf("eq res is %s\n",(yyvsp[0].str));
            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    Model_Table[cur_model]->Assign_Table[cur_assign]->res_idx=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no definition of constant %s" ,(yyvsp[0].str));
                exit(1);
            }
            cur_assign++;
            free(fname);
        }
#line 1422 "mcs.tab.c"
    break;

  case 30: /* $@12: %empty  */
#line 258 "mcs.y"
        {
            printf("fun STR = %s\n",(yyvsp[0].str));
            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<def_size;_i++){
                if (!strcmp(fname,Def_Table[_i]->fun_name)){
                    Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx=_i;
                    break;
                }
            }
            if (_i==def_size){
                printf("error : no exist definition of function %s" ,(yyvsp[0].str));
                exit(1);
            }
            free(fname);
        }
#line 1445 "mcs.tab.c"
    break;

  case 31: /* fun: STR $@12 LFun para_list RFun  */
#line 277 "mcs.y"
        {
            printf("assign para size = %d\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
            Model_Table[cur_model]->Assign_Table[cur_assign]->para_list_idx = (int*) malloc(sizeof(int)* Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
            for (_i=0;_i<Model_Table[cur_model]->Assign_Table[cur_assign]->para_size;_i++){
                 Model_Table[cur_model]->Assign_Table[cur_assign]->para_list_idx[_i] = para_idx_tmp[_i];
            }
        }
#line 1457 "mcs.tab.c"
    break;

  case 32: /* para_list: para_list Split STR  */
#line 286 "mcs.y"
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            //pil->next=(PARAIDXLIST)malloc(sizeof(struct ParaIdxList));

            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,(yyvsp[0].str));
            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of constant %s" ,fname);
                exit(1);
            }
            free(fname);
        }
#line 1483 "mcs.tab.c"
    break;

  case 33: /* para_list: para_list Split INT_NUMBER  */
#line 308 "mcs.y"
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            //pil->next=(PARAIDXLIST)malloc(sizeof(struct ParaIdxList));

            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,(yyvsp[0].str));
            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of constant %s" ,fname);
                exit(1);
            }
            free(fname);
        }
#line 1509 "mcs.tab.c"
    break;

  case 34: /* para_list: STR  */
#line 330 "mcs.y"
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,(yyvsp[0].str));

            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of function %s" ,fname);
                exit(1);
            }
            free(fname);
        }
#line 1534 "mcs.tab.c"
    break;

  case 35: /* para_list: INT_NUMBER  */
#line 351 "mcs.y"
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,(yyvsp[0].str));

            len = getNameLength( (yyvsp[0].str) );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , (yyvsp[0].str));

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of function %s" ,fname);
                exit(1);
            }
            free(fname);
        }
#line 1559 "mcs.tab.c"
    break;


#line 1563 "mcs.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 372 "mcs.y"

void initNewModel(){
    //for (_i=0;_i<cur_def;_i++){
        //free(Def_Table[_i]->fun_name);
        //free(Def_Table[_i]);
    //}
    //for (_i;_i<cur_assign;_i++){
        //free(Assgin_Table[_i]->para_list_idx);
        //free(Assgin_Table[_i]);
    //}
    cur_assign=0;
    cur_constant=0;
    
    cur_model+=1;
    //memset(term_num,0,sizeof(term_num));
    //pil=NULL;

    // model now=model_list[model_size];
    // now.max_def_size=1024;
    // now.def_size=0;
    // now.max_formula_size=1024;
    // now.formula_size=0;
    // now.def_list=(def*)malloc(sizeof(def)*now.max_def_size);
    // now.formula_list=(formula*)malloc(sizeof(formula)*now.max_formula_size);
}
// void createNewDef(char* s,int n){
//     model now=model_list[model_size];
//     def* Def=&now.def_list[now.def_size++];
//     Def->para_num=n;
//     Def->name=s;
//     Def->name_size=getNameLength(s);
// }
int getNameLength(char *s){
    int len=1;
    while ((*(s+len*sizeof(char))>='a'&&*(s+len*sizeof(char))<='z')||(*(s+len*sizeof(char))>='A'&&*(s+len*sizeof(char))<='Z')
        ||(*(s+len*sizeof(char))>='0'&&*(s+len*sizeof(char))<='9')){
        len++;
        if (*(s+len*sizeof(char))=='\n'||*(s+len*sizeof(char))==' ') return len;
    }
    return len;
}

void printModel(){
    for (_i=0;_i<cur_constant;_i++){
        printf("Model id : %d , constant %s \n", cur_model, Model_Table[cur_model]->Constant_Table[_i]->const_name);
    }
    for (_i=0;_i<cur_assign;_i++){
        printf("Assign is %s (", Def_Table[Model_Table[cur_model]->Assign_Table[_i]->fun_idx]->fun_name);
        for (_j=0;_j<Model_Table[cur_model]->Assign_Table[_i]->para_size;_j++){
            printf("%s ,",Model_Table[cur_model]->Constant_Table[Model_Table[cur_model]->Assign_Table[_i]->para_list_idx[_j]]->const_name);
        }
        printf(" )= %s \n", Model_Table[cur_model]->Constant_Table[Model_Table[cur_model]->Assign_Table[_i]->res_idx]->const_name);
    }
}
void printTerm(TERM term){
    FILE* fp;
    fp = fopen("result.txt","a");
    if (term->isfun==0){
        fprintf(fp,"%s", Val_Table[term->idx]->val_name);
        fclose(fp);
        return;
    }
    fprintf(fp,"%s(", Def_Table[term->idx]->fun_name);
    fclose(fp);
    for (int i=0;i<term->para_size;i++){
        fp = fopen("result.txt","a");
        if (i>=1) fprintf(fp,",");
        fclose(fp);
        printTerm(term->para_list[i]);
    }
    fp = fopen("result.txt","a");
    fprintf(fp,")");
    fclose(fp);
}
int hasRewrite(TERM term1 ,TERM term2){
    if (term1->isfun!=term2->isfun) return 0;
    if (term1->isfun==0) {
        if (mp[term1->idx]>=0&&mp[term1->idx]!=term2->idx) return 0;
        mp[term1->idx]=term2->idx;
        return 1;
    }
    if (term1->idx!=term2->idx) return 0;
    for (int i=0;i<term1->para_size;i++){
        if (!hasRewrite(term1->para_list[i],term2->para_list[i])) return 0;
    }
    return 1;
}

int calculateByModel(TERM term,int *para_val_list,int model_id){
    for (int i=0;i<Model_Table[model_id]->assign_size;i++){
        if (Model_Table[model_id]->Assign_Table[i]->fun_idx==term->idx){
            int flag=1;
            for (int j=0;j<term->para_size;j++){
                if (Model_Table[model_id]->Assign_Table[i]->para_list_idx[j]!=para_val_list[j]){
                    flag=0;
                    break;
                }
            }
            if (flag) return Model_Table[model_id]->Assign_Table[i]->res_idx;
        }
    }
    return -1;
}
int getResult(TERM term,int* val_list,int model_id){
    if (term->isfun==0){
        return val_list[term->idx];
    }
    int *para_val_list;
    para_val_list=(int*)malloc(sizeof(int)*term->para_size);
    for (int i=0;i<term->para_size;i++){
        para_val_list[i]=getResult(term->para_list[i],val_list,model_id);
        if (para_val_list[i]==-1) 
            return -1;
    }
    int res=calculateByModel(term,para_val_list,model_id);
    free(para_val_list);
    return res;
}
int enumerateVal(int *pren_list,int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
    if (pren_id == val_size){
        // for (int i=0;i<val_size;i++){
        //     if (pren_list[i]!=-1)
        //         printf("%s = %s,",Val_Table[i]->val_name,Model_Table[model_id]->Constant_Table[val_list[i]]->const_name);
        // }
        //printf("\n");
        int res1=getResult(term1,val_list,model_id);
        int res2=getResult(term2,val_list,model_id);
        // printf("res1 = %d\n",res1);
        // printf("res2 = %d\n",res2);
        if (res1==-1||res2==-1) 
            return -1;
        return res1==res2;
    }
    if (pren_list[pren_id]==-1) 
        return enumerateVal(pren_list,pren_id+1,val_list,term1,term2,model_id);
    int t=0;
    for (int i=0;i<Model_Table[model_id]->constant_size;i++){
        val_list[pren_id]=i;
        int res=enumerateVal(pren_list,pren_id+1,val_list,term1,term2,model_id);
        if (res!=-1)
            t+=res;
        if (pren_list[pren_id]==1){
            if (res==0) 
                return 0;       
        }else {
            if (res==1)
                return 1;
        }
    }
    if (t==0) return -1;
    return 1;
}
// int checkFormulaEQ(FORMULA formula1,){
    
// }
// void AddFormula(int *pren_list,TERM term1,TERM term2){
//     FORMULALIST now = Formula_List->cur;
//     for (int i=0;i<formula_num;i++){
//         //if (checkFormulaEQ(now,)) return;
//         now = now->next->cur;
//     }
//     FORMULA formula = (FORMULA)malloc(sizeof(struct Formula));
//     formula->term1 = term1;
//     formula->term2 = term2;
//     formula->pren_list = (int*)malloc(sizeof(int)*val_size);
//     for (int i=0;i<val_size;i++)
//     formula->pren_list[i] = pren_list[i];

//     formula_num+=1;
//     FORMULALIST formula_list = (FORMULALIST)malloc(sizeof(struct FormulaList));
//     formula_list->cur = formula;
//     formula_list->next = Formula_List;
//     Formula_List = formula_list;
// }
int checkByModel(int *pren_list,TERM term1,TERM term2){
    int *val_list;
    val_list=(int*)malloc(sizeof(int)*val_size);
    int res=0;
    for (int i=0;i<model_size;i++){
        //printf("model_id = %d\n",i);
        res += enumerateVal(pren_list,0,val_list,term1,term2,i);
    }
    if (res==model_size) {
        FILE* fp;
        fp = fopen("result.txt","a");
        for (int i=0;i<val_size;i++){
            if (pren_list[i]==1)
                fprintf(fp,"/forall %s ", Val_Table[i]->val_name);
            else if (pren_list[i]==0) fprintf(fp,"/exist %s ", Val_Table[i]->val_name);
        }
        fclose(fp);
        printTerm(term1);
        fp = fopen("result.txt","a");
        fprintf(fp," = ");
        fclose(fp);
        printTerm(term2);
        fp = fopen("result.txt","a");
        fprintf(fp,"\n");
        fclose(fp);
        //AddFormula(pren_list,term1,term2);
        //printf("formula is right\n");
        return 1;
    }
    //printf("formula is false\n");
    free(val_list);
    return 0;
}
void getLitInTerm(TERM term,int* hasLit){
    if (term->isfun==0){
        hasLit[term->idx]=1;
        return;
    }
    for (int i=0;i<term->para_size;i++){
        getLitInTerm(term->para_list[i],hasLit);
    }
}
//pren=1表示任意，=0表示存在量词
int generatePREN(int id,int* pren_list,TERM term1,TERM term2,int* hasLit){
    if (id>val_size){
        int forall_sum=0;
        for (int i=0;i<val_size;i++)
            if (pren_list[i]==1) forall_sum+=1;
        // for (int i=0;i<val_size;i++){
        //     if (pren_list[i]==1)
        //         printf("/forall %s ", Val_Table[i]->val_name);
        //     else if (pren_list[i]==0) printf("/exist %s ", Val_Table[i]->val_name);
        // }
        // printTerm(term1);
        // printf(" = ");
        // printTerm(term2);
        // printf("\n");
        if (forall_sum>0)
            return checkByModel(pren_list,term1,term2);
        else return 0;
    }
    if (!hasLit[id]) {
        pren_list[id]=-1;
        return generatePREN(id+1,pren_list,term1,term2,hasLit); 
    }
    int flag;
    for (int i=1;i>=0;i--){
        if (i==0&&gen_exist==0) continue;  
        pren_list[id]=i;
        flag=generatePREN(id+1,pren_list,term1,term2,hasLit);
        if (flag&&i==1) return 0;
    }
    return flag;
}
//todo: 之后要将Formula建模成数据类型
void generateFormula(){
    int *hasLit=(int*)malloc(sizeof(int)*val_size);
    int* pren_list=(int*)malloc(sizeof(int)*val_size);


    for (int i1=1;i1<=max_depth;i1++){
        TERMLIST termlist1 = Term_Table[i1];
        for (int j1=0;j1<term_num[i1];j1++){
            memset(hasLit,0,sizeof(hasLit));
            TERM t1=termlist1->cur;
            for (int i2=0;i2<=i1;i2++){
                TERMLIST termlist2 = Term_Table[i2];
                for (int j2=0;j2<term_num[i2];j2++){
                    if (i2==i1&&j2==j1) break;
                    TERM t2=termlist2->cur;
                    for (_i=0;_i<val_size;_i++)
                        hasLit[_i]=0;
                    getLitInTerm(t1,hasLit);
                    getLitInTerm(t2,hasLit);
                    generatePREN(0,pren_list,t1,t2,hasLit);
                    termlist2=termlist2->next;
                }
            }
            termlist1=termlist1->next;
        }
    }
    free(hasLit);
    free(pren_list);
}
void allocatePara(int depth,int nowdepth,int para_idx,int para_num,TERM term){
    //printf("allocate nowdep=%d para_idx=%d \n",nowdepth,para_idx);
    if (para_idx>=para_num){
        if (nowdepth>0) return;
        TERM t=(TERM)malloc(sizeof(struct Term));
        t->isfun=term->isfun;
        t->depth=term->depth;
        t->para_size=term->para_size;
        t->idx=term->idx;
        t->para_list = (TERM*)malloc(sizeof(TERM)*term->para_size);
        for (int i=0;i<term->para_size;i++){
            t->para_list[i]=term->para_list[i];
        }
        if (term_num[depth]==0){
            Term_Table[depth]=(TERMLIST)malloc(sizeof(struct TermList));
            Term_Table[depth]->cur=t;
            Term_Table[depth]->next=NULL;
        }else {
            TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
            termlist->cur=t;
            termlist->next=NULL;
            TERMLIST cur=Term_Table[depth];
            memset(mp,-1,sizeof(mp));
            if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
            while (cur->next!=NULL){
                cur=cur->next;
                memset(mp,-1,sizeof(mp));
                if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
            }
            cur->next=termlist;
            // termlist->next = Term_Table[depth];
            // termlist->cur = term;
            // Term_Table[depth] = termlist;
        }
        // printf("get term : ");
        // printTerm(Term_Table[depth]->cur);
        // printf("\n");
        term_num[depth]++;
        return;
    }
    for (int i=nowdepth;i>=0;i--){
        TERMLIST termlist = Term_Table[i];
        for (int k=0;k<term_num[i];k++){
            term->para_list[para_idx] = termlist->cur;
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
            termlist = termlist->next;
        }
    }
}
void generateTerm(){
    for (int i=0;i<=max_depth;i++){
        printf("i=%d\n",i);
        if (i==0){
            for (int j=0;j<val_size;j++){
                printf("j=%d\n",j);
                TERM term=(TERM)malloc(sizeof(struct Term));
                term->isfun=0;
                term->depth=0;
                term->para_size=0;
                term->idx=j;
                if (term_num[i]==0){
                    Term_Table[i]=(TERMLIST)malloc(sizeof(struct TermList));
                    Term_Table[i]->cur=term;
                }else {
                    TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
                    termlist->cur=term;
                    termlist->next=NULL;
                    TERMLIST cur=Term_Table[i];
                    while (cur->next!=NULL){
                       cur=cur->next;
                    }
                    cur->next=termlist;
                        //  termlist->next = Term_Table[i];
                        //  termlist->cur = term;
                        //  Term_Table[i] = termlist;
                }
                term_num[i]++;
            }
        }else {
            for (int j=0;j<def_size;j++){
                if (Def_Table[j]->para_size>0){
                    TERM term=(TERM)malloc(sizeof(struct Term));
                    term->isfun=1;
                    term->depth=i;
                    term->para_size=Def_Table[j]->para_size;
                    term->idx=j;
                    term->para_list=(TERM*)malloc(sizeof(TERM)*term->para_size);
                    allocatePara(i,i-1,0,term->para_size,term);
                }
            }
        }
    }
    FILE* fp;
    fp = fopen("result.txt","a");
    for (int i=0;i<=max_depth;i++){
        TERMLIST termlist = Term_Table[i];
        fp = fopen("result.txt","a");
        fprintf(fp,"dep = %d  ,  term_num has %d\n",i,term_num[i]);
        fclose(fp);
        for (int k=0;k<term_num[i];k++){
            printTerm(termlist->cur);
            fp = fopen("result.txt","a");
            fprintf(fp,"\n");
            fclose(fp);
            termlist = termlist->next;
        }
    }
    fp = fopen("result.txt","a");
    fprintf(fp,"\n");
    fclose(fp);
}
int max(int a,int b){
    return (a>b)?a:b;
}
void yyerror(char *s) {
    //fprintf(stdout, "%s\n", s);
    //STR LFun para_list RFun EQ STR LFun para_list RFun {printf("left fun is %s , right fun is %s\n",$1,$6);}|
    extern int yylineno;	// defined and maintained in lex
	extern char *yytext;	// defined and maintained in lex
	int len=strlen(yytext);
	int i;
	char buf[512]={0};
	for (i=0;i<len;++i)
	{
		sprintf(buf,"%s%d ",buf,(char)yytext[i]);
	}
    fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", s, buf, yylineno);
	yyparse();
}
int main(int argc, char **argv) {
    FILE* fp = fopen("result.txt","w");
    fprintf(fp,"");
    fclose(fp);
    yyparse();
}
