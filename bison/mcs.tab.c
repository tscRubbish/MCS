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
#include <vector>

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
int para_idx_tmp[MAX_N_PARA];
int mp[MAX_N_DEF];

bool createDef;

void initNewModel();
int getDefByName(char *s);
int getNameLength(char *s);
void printModel();
void printAssign();
void generateTerm();
void generateFormula();



#line 114 "mcs.tab.c"

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
  YYSYMBOL_LP = 3,                         /* LP  */
  YYSYMBOL_RP = 4,                         /* RP  */
  YYSYMBOL_EQ = 5,                         /* EQ  */
  YYSYMBOL_Split = 6,                      /* Split  */
  YYSYMBOL_Annotate = 7,                   /* Annotate  */
  YYSYMBOL_END = 8,                        /* END  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_SP_STR = 10,                    /* SP_STR  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_YYACCEPT = 12,                  /* $accept  */
  YYSYMBOL_MCS = 13,                       /* MCS  */
  YYSYMBOL_Model_List = 14,                /* Model_List  */
  YYSYMBOL_Model = 15,                     /* Model  */
  YYSYMBOL_16_1 = 16,                      /* $@1  */
  YYSYMBOL_17_2 = 17,                      /* $@2  */
  YYSYMBOL_Res_List = 18,                  /* Res_List  */
  YYSYMBOL_Res = 19,                       /* Res  */
  YYSYMBOL_20_3 = 20,                      /* $@3  */
  YYSYMBOL_21_4 = 21,                      /* $@4  */
  YYSYMBOL_Para_List = 22                  /* Para_List  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   55

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  12
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  16
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  46

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   266


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
       5,     6,     7,     8,     9,    10,    11
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    71,    76,    83,    91,    83,    96,    97,
     100,    99,   139,   138,   173,   199,   204
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
  "\"end of file\"", "error", "\"invalid token\"", "LP", "RP", "EQ",
  "Split", "Annotate", "END", "STR", "SP_STR", "INT", "$accept", "MCS",
  "Model_List", "Model", "$@1", "$@2", "Res_List", "Res", "$@3", "$@4",
  "Para_List", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-9)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -9,     6,     0,    -9,     1,    -9,    -9,     2,     4,    -1,
       5,     7,     8,     3,    10,     9,    11,    12,    13,    -9,
      -5,    14,    -9,    -5,    -9,    15,    19,    20,    -9,    17,
      16,    16,    -9,    -9,    -4,    -3,    23,    18,    25,    21,
      -9,    22,    26,    27,    -9,    -9
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     4,     0,     1,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,    12,    10,     7,     9,     0,     0,     0,     8,     0,
       0,     0,    14,    16,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,    13,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -9,    -9,    -9,    29,    -9,    -9,    -9,    -8,    -9,    -9,
      24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     3,     4,    20,    23,    24,    27,    26,
      34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    38,    37,    37,    21,    22,     5,    -5,     7,     9,
      10,     8,    11,    13,    14,    28,    12,    15,    16,    25,
      17,    18,    30,    31,    19,    32,    29,    33,    39,    40,
      41,     6,    42,    43,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35
};

static const yytype_int8 yycheck[] =
{
       4,     4,     6,     6,     9,    10,     0,     7,     7,     5,
      11,     9,     7,     5,    11,    23,     9,     7,     9,     5,
       9,     9,     3,     3,    11,     8,    11,    11,     5,    11,
       5,     2,    11,    11,     8,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    14,    15,    16,     0,    15,     7,     9,     5,
      11,     7,     9,     5,    11,     7,     9,     9,     9,    11,
      17,     9,    10,    18,    19,     5,    21,    20,    19,    11,
       3,     3,     8,    11,    22,    22,     4,     6,     4,     5,
      11,     5,    11,    11,     8,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    12,    13,    14,    14,    16,    17,    15,    18,    18,
      20,    19,    21,    19,    19,    22,    22
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     0,    16,     2,     1,
       0,     8,     0,     8,     4,     3,     1
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
  case 2: /* MCS: Model_List  */
#line 66 "mcs.y"
                {
    generateTerm(); 
    generateFormula();
}
#line 1142 "mcs.tab.c"
    break;

  case 3: /* Model_List: Model_List Model  */
#line 72 "mcs.y"
    {
        printModel();
        initNewModel();
    }
#line 1151 "mcs.tab.c"
    break;

  case 4: /* Model_List: Model  */
#line 77 "mcs.y"
    {
        printModel();
        initNewModel();
    }
#line 1160 "mcs.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 83 "mcs.y"
    {
        MODEL model=(MODEL)malloc(sizeof(struct Model));
        
        Model_Table.push_back(model);
    }
#line 1170 "mcs.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 91 "mcs.y"
    {
        Model_Table[cur_model]->model_size=atoi((yyvsp[0].str));
    }
#line 1178 "mcs.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 100 "mcs.y"
    {
        len = strlen( (yyvsp[0].str) );
        //fname = (char*) malloc(sizeof(char)*(len+1));
        //strcpy(fname , $1);
        //printf("Len = %d\n",strlen($1));
        createDef=false;
        int idx=getDefByName((yyvsp[0].str));
        //printf("%s\n",fname);
        //printf("%d\n",idx);

        if (idx==-1) {
            createDef=true;
            DEF def=(DEF)malloc(sizeof(struct Def));
            def->fun_name=(char*) malloc(sizeof(char)*(len));
            strcpy(def->fun_name , (yyvsp[0].str));
            printf("def name = %s\n",def->fun_name);
            Def_Table.push_back(def);
        }
        //printf("%d\n",cur_assign);

        INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = createDef?cur_def:idx;

        para_size = 0;

    }
#line 1210 "mcs.tab.c"
    break;

  case 11: /* Res: SP_STR $@3 LP Para_List RP EQ INT END  */
#line 127 "mcs.y"
    {
        if (createDef){
            Def_Table[cur_def]->para_size=para_size;
            //printf("Def id = %d ,Def name = %s\n",cur_def,Def_Table[cur_def]->fun_name);
            cur_def++;
        }
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx]->para_size;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = atoi((yyvsp[-1].str));
        printAssign();
        cur_assign++;
    }
#line 1226 "mcs.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 139 "mcs.y"
    {
        len = strlen( (yyvsp[0].str) );
        createDef=false;
        int idx=getDefByName((yyvsp[0].str));
        //printf("%s\n",fname);
        //printf("%d\n",idx);

        if (idx==-1) {
            createDef=true;
            DEF def=(DEF)malloc(sizeof(struct Def));
            def->fun_name=(char*) malloc(sizeof(char)*(len));
            strcpy(def->fun_name , (yyvsp[0].str));
            printf("def name = %s\n",def->fun_name);
            Def_Table.push_back(def);
        }
        //printf("%d\n",cur_assign);

        INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = createDef?cur_def:idx;

        para_size = 0;

    }
#line 1255 "mcs.tab.c"
    break;

  case 13: /* Res: STR $@4 LP Para_List RP EQ INT END  */
#line 163 "mcs.y"
    {
        if (createDef){
            Def_Table[cur_def]->para_size=para_size;
            cur_def++;
        }
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx]->para_size;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = atoi((yyvsp[-1].str));
        printAssign();
        cur_assign++;
    }
#line 1270 "mcs.tab.c"
    break;

  case 14: /* Res: STR EQ INT END  */
#line 174 "mcs.y"
    {
        len =  strlen( (yyvsp[-3].str) );
        //fname = (char*) malloc(sizeof(char)*(len+1));
        //strcpy(fname , $1);

        int idx=getDefByName((yyvsp[-3].str));

        if (idx==-1){
            DEF def=(DEF)malloc(sizeof(struct Def));
            def->fun_name=(char*) malloc(sizeof(char)*(len));
            strcpy(def->fun_name , (yyvsp[-3].str));
            def->para_size=0;
            Def_Table.push_back(def);
            cur_def++;
        }

        INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = idx==-1?cur_def:idx;
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = 0;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = atoi((yyvsp[-1].str));
        printAssign();
        cur_assign++;
    }
#line 1299 "mcs.tab.c"
    break;

  case 15: /* Para_List: Para_List Split INT  */
#line 200 "mcs.y"
    {
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_list.push_back(atoi((yyvsp[0].str)));
        para_size++;
    }
#line 1308 "mcs.tab.c"
    break;

  case 16: /* Para_List: INT  */
#line 205 "mcs.y"
    {
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_list.push_back(atoi((yyvsp[0].str)));
        para_size++;
    }
#line 1317 "mcs.tab.c"
    break;


#line 1321 "mcs.tab.c"

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

#line 210 "mcs.y"

void initNewModel(){
    cur_assign=0;
    
    cur_model+=1;
}

int getDefByName(char *s){
    //printf("def size = %d\n",Def_Table.size());
    for (_i=0;_i<Def_Table.size();_i++){
            if (!strcmp(s, Def_Table[_i]->fun_name)){
                    return _i;
                    break;
            }
    }
    return -1;
}
int getNameLength(char *s){
    int len=1;
    // while ((*(s+len*sizeof(char))>='a'&&*(s+len*sizeof(char))<='z')||(*(s+len*sizeof(char))>='A'&&*(s+len*sizeof(char))<='Z')
    //     ||(*(s+len*sizeof(char))>='0'&&*(s+len*sizeof(char))<='9')){
    while (!(*(s+len*sizeof(char))==' '||*(s+len*sizeof(char))=='\t'||*(s+len*sizeof(char))=='\n')){
        len++;
        if (*(s+len*sizeof(char))=='\n'||*(s+len*sizeof(char))==' ') return len;
    }
    return len;
}

void printAssign(){
    printf("\ncur_def = %d\n",cur_def);
    for (_i=0;_i<cur_def;_i++){
        printf("def id =%d : %s\n",_i,Def_Table[_i]->fun_name);
    }
    printf("\nModel id = %d\n Assign id = %d\n",cur_model,cur_assign);
    printf("para size = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
    printf("def id = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx);
    printf("%s(",Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx]->fun_name);
    for (_i=0;_i<Model_Table[cur_model]->Assign_Table[cur_assign]->para_size;_i++){
        printf("%d,",Model_Table[cur_model]->Assign_Table[cur_assign]->para_list[_i]);
    }
    printf(") = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->res);
 }

void printModel(){
    // for (_i=0;_i<cur_constant;_i++){
    //     printf("Model id : %d , constant %s \n", cur_model, Model_Table[cur_model]->Constant_Table[_i]->const_name);
    // }
    for (_i=0;_i<cur_assign;_i++){
        printf("Assign is %s (", Def_Table[Model_Table[cur_model]->Assign_Table[_i]->fun_idx]->fun_name);
        for (_j=0;_j<Model_Table[cur_model]->Assign_Table[_i]->para_size;_j++){
            printf("%d ,",Model_Table[cur_model]->Assign_Table[_i]->para_list[_j]);
        }
        printf(" )= %d \n", Model_Table[cur_model]->Assign_Table[_i]->res);
    }
}
void printTerm(TERM term){
    FILE* fp;
    fp = fopen("result.txt","a");
    if (term->isfun==0){
        fprintf(fp,"$%s", 'a'+term->idx);
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
                if (Model_Table[model_id]->Assign_Table[i]->para_list[j]!=para_val_list[j]){
                    flag=0;
                    break;
                }
            }
            if (flag) return Model_Table[model_id]->Assign_Table[i]->res;
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
//int enumerateVal(int *pren_list,int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
int enumerateVal(int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
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
            return 0;
        return res1==res2;
    }
    // if (pren_list[pren_id]==-1) 
    //     return enumerateVal(pren_list,pren_id+1,val_list,term1,term2,model_id);
    //int t=0;
    for (int i=0;i<Model_Table[model_id]->model_size;i++){
        val_list[pren_id]=i;
        int res=enumerateVal(pren_id+1,val_list,term1,term2,model_id);
        //if (res!=-1)
         //   t+=res;
        if (res==0) 
            return 0;
        // if (pren_list[pren_id]==1){
        //     if (res==0) 
        //         return 0;       
        // }else {
        //     if (res==1)
        //         return 1;
        // }
    }
    //if (t==0) return -1;
    return 1;
}

//int checkByModel(int *pren_list,TERM term1,TERM term2){
int checkByModel(TERM term1,TERM term2){
    int *val_list;
    val_list=(int*)malloc(sizeof(int)*val_size);
    int res=0;
    for (int i=0;i<cur_model;i++){
        //printf("model_id = %d\n",i);
        res += enumerateVal(0,val_list,term1,term2,i);
    }
    if (res==cur_model) {
        FILE* fp;
        fp = fopen("result.txt","a");
        // for (int i=0;i<val_size;i++){
        //     if (pren_list[i]==1)
        //         fprintf(fp,"/forall %s ", Val_Table[i]->val_name);
        //     else if (pren_list[i]==0) fprintf(fp,"/exist %s ", Val_Table[i]->val_name);
        //}
        // fclose(fp);
        // printTerm(term1);
        // fp = fopen("result.txt","a");
        // fprintf(fp," = ");
        // fclose(fp);
        // printTerm(term2);
        // fp = fopen("result.txt","a");
        // fprintf(fp,"\n");
        // fclose(fp);
        //printf("formula is right\n");
        return 1;
    }
    //printf("formula is false\n");
    free(val_list);
    return 0;
}
// void getLitInTerm(TERM term,int* hasLit){
//     if (term->isfun==0){
//         hasLit[term->idx]=1;
//         return;
//     }
//     for (int i=0;i<term->para_size;i++){
//         getLitInTerm(term->para_list[i],hasLit);
//     }
// }
// //pren=1表示任意，=0表示存在量词
// int generatePREN(int id,int* pren_list,TERM term1,TERM term2,int* hasLit){
//     if (id>val_size){
//         int forall_sum=0;
//         for (int i=0;i<val_size;i++)
//             if (pren_list[i]==1) forall_sum+=1;
//         // for (int i=0;i<val_size;i++){
//         //     if (pren_list[i]==1)
//         //         printf("/forall %s ", Val_Table[i]->val_name);
//         //     else if (pren_list[i]==0) printf("/exist %s ", Val_Table[i]->val_name);
//         // }
//         // printTerm(term1);
//         // printf(" = ");
//         // printTerm(term2);
//         // printf("\n");
//         if (forall_sum>0)
//             return checkByModel(pren_list,term1,term2);
//         else return 0;
//     }
//     if (!hasLit[id]) {
//         pren_list[id]=-1;
//         return generatePREN(id+1,pren_list,term1,term2,hasLit); 
//     }
//     int flag;
//     for (int i=1;i>=0;i--){
//         if (i==0&&gen_exist==0) continue;  
//         pren_list[id]=i;
//         flag=generatePREN(id+1,pren_list,term1,term2,hasLit);
//         if (flag&&i==1) return 0;
//     }
//     return flag;
// }
//todo: 之后要将Formula建模成数据类型
void generateFormula(){
    for (int i1=1;i1<=max_depth;i1++){
        for (int j1=0;j1<term_num[i1];j1++){
            for (int i2=0;i2<=i1;i2++){
                for (int j2=0;j2<term_num[i2];j2++){
                    if (i2==i1&&j2==j1) break;
                    int flag = checkByModel(Term_Table[i1][j1],Term_Table[i2][j2]);
                    if (flag){
                        FORMULA f=(FORMULA)malloc(sizeof(struct Formula));
                        f->term1 = Term_Table[i1][j1];
                        f->term2 = Term_Table[i2][j2];
                        Formula_List.push_back(f);
                    }
                }
            }
        }
    }

    // int *hasLit=(int*)malloc(sizeof(int)*val_size);
    // int* pren_list=(int*)malloc(sizeof(int)*val_size);


    // for (int i1=1;i1<=max_depth;i1++){
    //     TERMLIST termlist1 = Term_Table[i1];
    //     for (int j1=0;j1<term_num[i1];j1++){
    //         memset(hasLit,0,sizeof(hasLit));
    //         TERM t1=termlist1->cur;
    //         for (int i2=0;i2<=i1;i2++){
    //             TERMLIST termlist2 = Term_Table[i2];
    //             for (int j2=0;j2<term_num[i2];j2++){
    //                 if (i2==i1&&j2==j1) break;
    //                 TERM t2=termlist2->cur;
    //                 for (_i=0;_i<val_size;_i++)
    //                     hasLit[_i]=0;
    //                 getLitInTerm(t1,hasLit);
    //                 getLitInTerm(t2,hasLit);
    //                 generatePREN(0,pren_list,t1,t2,hasLit);
    //                 termlist2=termlist2->next;
    //             }
    //         }
    //         termlist1=termlist1->next;
    //     }
    // }
    // free(hasLit);
    // free(pren_list);
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
        for (int j=0;j<term_num[depth];j++){
            memset(mp,-1,sizeof(mp));
            if (depth>=2&&hasRewrite(t,Term_Table[depth][j])) return;
        }
        // if (term_num[depth]==0){
        //     Term_Table[depth]=(TERMLIST)malloc(sizeof(struct TermList));
        //     Term_Table[depth]->cur=t;
        //     Term_Table[depth]->next=NULL;
        // }else {
        //     TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
        //     termlist->cur=t;
        //     termlist->next=NULL;
        //     TERMLIST cur=Term_Table[depth];
        //     memset(mp,-1,sizeof(mp));
        //     if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
        //     while (cur->next!=NULL){
        //         cur=cur->next;
        //         memset(mp,-1,sizeof(mp));
        //         if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
        //     }
        //     cur->next=termlist;
        //     // termlist->next = Term_Table[depth];
        //     // termlist->cur = term;
        //     // Term_Table[depth] = termlist;
        // }

        Term_Table[depth].push_back(t);
        // printf("get term : ");
        // printTerm(Term_Table[depth]->cur);
        // printf("\n");
        term_num[depth]++;
        return;
    }
    for (int i=nowdepth;i>=0;i--){
        //TERMLIST termlist = Term_Table[i];
        for (int k=0;k<term_num[i];k++){
            //term->para_list[para_idx] = termlist->cur;
            term->para_list[para_idx]=Term_Table[i][k];
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
            //termlist = termlist->next;
        }
    }
}
void generateTerm(){
    //Term_Table = malloc(sizeof(std::vector<TERM> )*max_depth);
    Term_Table = new std::vector<TERM> [max_depth];
    term_num = (int*)malloc(sizeof(int)*max_depth);
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
                Term_Table[i].push_back(term);
                // if (term_num[i]==0){
                //     Term_Table[i]=(TERMLIST)malloc(sizeof(struct TermList));
                //    Term_Table[i]->cur=term;
                // }else {
                //     TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
                //     termlist->cur=term;
                //     termlist->next=NULL;
                //     TERMLIST cur=Term_Table[i];
                //     while (cur->next!=NULL){
                //        cur=cur->next;
                //     }
                //     cur->next=termlist;
                //         //  termlist->next = Term_Table[i];
                //         //  termlist->cur = term;
                //         //  Term_Table[i] = termlist;
                // }

                term_num[i]++;
            }
            for (int j=0;j<cur_def;j++){
                if (Def_Table[j]->para_size==0){
                    printf("Constant : id = %d , cname = %s\n",j,Def_Table[j]->fun_name);
                    TERM term=(TERM)malloc(sizeof(struct Term));
                    term->isfun=1;
                    term->depth=0;
                    term->para_size=0;
                    term->idx=j;
                    Term_Table[i].push_back(term);
                }
            }
        }else {
            for (int j=0;j<cur_def;j++){
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
        for (int k=0;k<term_num[i];k++){
            printTerm(Term_Table[i][k]);
             fp = fopen("result.txt","a");
             fprintf(fp,"\n");
             fclose(fp);
        }
        // TERMLIST termlist = Term_Table[i];
        // fp = fopen("result.txt","a");
        // fprintf(fp,"dep = %d  ,  term_num has %d\n",i,term_num[i]);
        // fclose(fp);
        // for (int k=0;k<term_num[i];k++){
        //     printTerm(termlist->cur);
        //     fp = fopen("result.txt","a");
        //     fprintf(fp,"\n");
        //     fclose(fp);
        //     termlist = termlist->next;
        // }
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
