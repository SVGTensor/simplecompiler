/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "comp.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "parser.h"
#include "interpret.h"

static int base_type = TYPE_UNDEFINED;
NameTable name_table;
LabelTable label_table;
IProgram icode;
static char error_text[128];

static int binOper = 0;

static const Label* breakLabel = 0;
static const Label* continueLabel = 0;
static const Label* endifLabel = 0;

static void genExpr(const TreeNode* tree);

// Either trueLabel or falseLabel == 0
static void genLExpr(
    const TreeNode* tree,   // Represents a logical expression
    const Label* trueLabel,
    const Label* falseLabel
);

static void genNop(const Label* label);
static void genGoto(const Label* label);
static const Label* genLabel();
static void checkNames();
static void printWarning(const char *text);
static void printError(const char *text);



/* Line 189 of yacc.c  */
#line 111 "comp.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     INT_CONST = 259,
     DOUBLE_CONST = 260,
     STRING_CONST = 261,
     WHILE = 262,
     ENDWHILE = 263,
     IF = 264,
     ENDIF = 265,
     ELSE = 266,
     ELSEIF = 267,
     TYPE = 268,
     BREAK = 269,
     CONTINUE = 270,
     SM = 271,
     CM = 272,
     LBR = 273,
     RBR = 274,
     LPAR = 275,
     RPAR = 276,
     ILLEGAL = 277,
     INPUT = 278,
     OUTPUT = 279,
     OUTPUTLN = 280,
     END = 281,
     SQRT = 282,
     SIN = 283,
     COS = 284,
     EXP = 285,
     POW = 286,
     ASG = 287,
     RELOP = 288,
     LOR = 289,
     LAND = 290,
     LNOT = 291,
     MINUS = 292,
     PLUS = 293,
     MOD = 294,
     DIV = 295,
     MUL = 296,
     UMINUS = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "comp.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    20,
      23,    26,    30,    32,    34,    38,    40,    45,    47,    49,
      51,    54,    57,    59,    61,    63,    68,    70,    75,    77,
      81,    85,    89,    93,    97,   100,   102,   107,   109,   111,
     113,   117,   122,   127,   132,   137,   144,   148,   149,   155,
     156,   162,   167,   169,   172,   174,   177,   180,   183,   188,
     192,   196,   200,   203,   207,   211,   216,   220,   222,   226,
     230,   233,   237,   239
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    45,    26,    -1,    46,    -1,
      45,    46,    -1,    47,    -1,    51,    -1,     1,    16,    -1,
       1,    10,    -1,     1,     8,    -1,    48,    49,    16,    -1,
      13,    -1,    50,    -1,    49,    17,    50,    -1,     3,    -1,
       3,    18,    55,    19,    -1,    52,    -1,    56,    -1,    66,
      -1,    14,    16,    -1,    15,    16,    -1,    68,    -1,    70,
      -1,    71,    -1,    53,    32,    55,    16,    -1,    54,    -1,
      54,    18,    55,    19,    -1,     3,    -1,    55,    38,    55,
      -1,    55,    37,    55,    -1,    55,    41,    55,    -1,    55,
      40,    55,    -1,    55,    39,    55,    -1,    37,    55,    -1,
       3,    -1,     3,    18,    55,    19,    -1,     4,    -1,     5,
      -1,     6,    -1,    20,    55,    21,    -1,    27,    20,    55,
      21,    -1,    28,    20,    55,    21,    -1,    29,    20,    55,
      21,    -1,    30,    20,    55,    21,    -1,    31,    20,    55,
      17,    55,    21,    -1,    59,    45,    10,    -1,    -1,    59,
      45,    57,    62,    10,    -1,    -1,    59,    45,    58,    60,
      10,    -1,     9,    20,    65,    21,    -1,    61,    -1,    61,
      62,    -1,    63,    -1,    61,    63,    -1,    11,    45,    -1,
      64,    45,    -1,    12,    20,    65,    21,    -1,    55,    33,
      55,    -1,    65,    34,    65,    -1,    65,    35,    65,    -1,
      36,    65,    -1,    20,    65,    21,    -1,    67,    45,     8,
      -1,     7,    20,    65,    21,    -1,    23,    69,    16,    -1,
      53,    -1,    69,    17,    53,    -1,    24,    72,    16,    -1,
      25,    16,    -1,    25,    72,    16,    -1,    55,    -1,    72,
      17,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    60,    69,    72,    77,    80,    83,    86,
      89,    94,    99,   104,   107,   112,   132,   157,   158,   159,
     160,   167,   174,   175,   176,   179,   190,   191,   198,   209,
     218,   222,   226,   230,   234,   240,   248,   260,   266,   272,
     278,   279,   285,   291,   297,   303,   312,   316,   316,   328,
     328,   342,   351,   352,   355,   356,   359,   362,   368,   375,
     383,   390,   397,   403,   408,   418,   435,   438,   443,   446,
     449,   459,   462,   469
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "INT_CONST", "DOUBLE_CONST",
  "STRING_CONST", "WHILE", "ENDWHILE", "IF", "ENDIF", "ELSE", "ELSEIF",
  "TYPE", "BREAK", "CONTINUE", "SM", "CM", "LBR", "RBR", "LPAR", "RPAR",
  "ILLEGAL", "INPUT", "OUTPUT", "OUTPUTLN", "END", "SQRT", "SIN", "COS",
  "EXP", "POW", "ASG", "RELOP", "LOR", "LAND", "LNOT", "MINUS", "PLUS",
  "MOD", "DIV", "MUL", "UMINUS", "$accept", "program", "stms", "stm",
  "decl", "type", "defs", "def", "oper", "assign", "lval", "lval_name",
  "expr", "if", "$@1", "$@2", "ifh", "elseifs", "elseiflist", "else",
  "elseif", "elseifh", "lexpr", "while", "whileh", "input", "inputlst",
  "output", "outputln", "outputlst", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    57,    56,    58,
      56,    59,    60,    60,    61,    61,    62,    63,    64,    65,
      65,    65,    65,    65,    66,    67,    68,    69,    69,    70,
      71,    71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     2,
       2,     3,     1,     1,     3,     1,     4,     1,     1,     1,
       2,     2,     1,     1,     1,     4,     1,     4,     1,     3,
       3,     3,     3,     3,     2,     1,     4,     1,     1,     1,
       3,     4,     4,     4,     4,     6,     3,     0,     5,     0,
       5,     4,     1,     2,     1,     2,     2,     2,     4,     3,
       3,     3,     2,     3,     3,     4,     3,     1,     3,     3,
       2,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    28,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     4,     6,     0,     7,    17,     0,    26,
      18,     0,    19,     0,    22,    23,    24,    10,     9,     8,
       0,     0,    20,    21,    67,     0,    35,    37,    38,    39,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    70,
       0,     1,     3,     5,    15,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,    69,     0,    71,     0,    11,     0,     0,     0,    46,
       0,     0,    64,     0,     0,    62,     0,    65,     0,     0,
      51,    68,     0,    40,     0,     0,     0,     0,     0,    30,
      29,    33,    32,    31,    73,     0,    14,    25,    27,     0,
       0,     0,     0,    52,    54,     0,    63,    59,    60,    61,
      36,    41,    42,    43,    44,     0,    16,     0,    48,     0,
      50,    53,    55,     0,     0,     0,    45,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    55,    56,    16,    17,
      18,    19,    63,    20,    90,    91,    21,   122,   123,   120,
     124,   125,    64,    22,    23,    24,    35,    25,    26,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -27
static const yytype_int16 yypact[] =
{
     234,    77,   -27,   -14,   -11,   -27,     1,     6,    36,    92,
      15,    51,   132,   -27,   -27,    58,   -27,   -27,    43,    61,
     -27,   234,   -27,   234,   -27,   -27,   -27,   -27,   -27,   -27,
      53,    53,   -27,   -27,   -27,    17,    73,   -27,   -27,   -27,
      92,    74,    91,   106,   108,   114,    92,   262,    38,   -27,
      83,   -27,   -27,   -27,   118,   126,   -27,    92,    92,   158,
     196,    53,    53,   -26,    -5,     2,   -27,    36,    92,    65,
      92,    92,    92,    92,    92,   -27,    92,    92,    92,    92,
      92,   -27,    92,   -27,    92,   -27,    58,    76,   111,   -27,
     133,   148,   -27,   235,   103,   -27,    92,   -27,    53,    53,
     -27,   -27,   213,   -27,   244,   249,   256,   270,   -13,    69,
      69,   -27,   -27,   -27,   262,   223,   -27,   -27,   -27,   234,
     154,   146,   164,   151,   -27,   234,   -27,   262,   140,   -27,
     -27,   -27,   -27,   -27,   -27,    92,   -27,   215,   -27,    53,
     -27,   -27,   -27,   177,   277,   119,   -27,   -27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,   -18,   -12,   -27,   -27,   -27,    90,   -27,   -27,
       0,   -27,    -8,   -27,   -27,   -27,   -27,   -27,   -27,    54,
      56,   -27,   -21,   -27,   -27,   -27,   -27,   -27,   -27,   175
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      53,    47,    47,    59,   135,    60,    30,    96,    34,    31,
      65,    76,    77,    78,    79,    80,    97,    32,    36,    37,
      38,    39,    33,   100,    76,    77,    78,    79,    80,    98,
      99,    49,    69,    66,    67,    40,    98,    99,    75,     2,
      94,    95,    41,    42,    43,    44,    45,    53,    53,    87,
      88,    51,    46,    93,    81,    82,    36,    37,    38,    39,
     102,    54,   104,   105,   106,   107,   108,   101,   109,   110,
     111,   112,   113,    61,   114,    57,   115,   128,   129,    58,
      41,    42,    43,    44,    45,    27,   103,    28,   127,    62,
      46,    68,   117,    29,    70,    36,    37,    38,    39,    83,
      82,   137,    76,    77,    78,    79,    80,   143,    78,    79,
      80,    71,    40,    76,    77,    78,    79,    80,   145,    41,
      42,    43,    44,    45,   126,    53,    72,   144,    73,    46,
     118,    53,    -2,     1,    74,     2,    84,    98,    99,     3,
     147,     4,    85,    86,   119,     5,     6,     7,    76,    77,
      78,    79,    80,    98,    99,     8,     9,    10,    52,     1,
     121,     2,   119,   121,   138,     3,   139,     4,    89,   -47,
     -49,     5,     6,     7,   140,    99,   116,   141,     1,   142,
       2,     8,     9,    10,     3,    50,     4,   -57,   -57,   -57,
       5,     6,     7,     0,     0,     0,     0,     1,     0,     2,
       8,     9,    10,     3,    92,     4,     0,     0,     0,     5,
       6,     7,     0,     0,     0,     0,     1,     0,     2,     8,
       9,    10,     3,     0,     4,   -56,     0,     0,     5,     6,
       7,     0,   130,     0,     0,     1,     0,     2,     8,     9,
      10,     3,   136,     4,     0,     0,     0,     5,     6,     7,
      76,    77,    78,    79,    80,     0,   103,     8,     9,    10,
      76,    77,    78,    79,    80,   131,     0,     0,    96,     0,
     132,     0,    76,    77,    78,    79,    80,   133,     0,     0,
       0,    76,    77,    78,    79,    80,    76,    77,    78,    79,
      80,   134,     0,    76,    77,    78,    79,    80,   146,    76,
      77,    78,    79,    80,     0,     0,     0,    76,    77,    78,
      79,    80,     0,     0,    76,    77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      12,     9,    10,    21,    17,    23,    20,    33,     8,    20,
      31,    37,    38,    39,    40,    41,    21,    16,     3,     4,
       5,     6,    16,    21,    37,    38,    39,    40,    41,    34,
      35,    16,    40,    16,    17,    20,    34,    35,    46,     3,
      61,    62,    27,    28,    29,    30,    31,    59,    60,    57,
      58,     0,    37,    61,    16,    17,     3,     4,     5,     6,
      68,     3,    70,    71,    72,    73,    74,    67,    76,    77,
      78,    79,    80,    20,    82,    32,    84,    98,    99,    18,
      27,    28,    29,    30,    31,     8,    21,    10,    96,    36,
      37,    18,    16,    16,    20,     3,     4,     5,     6,    16,
      17,   119,    37,    38,    39,    40,    41,   125,    39,    40,
      41,    20,    20,    37,    38,    39,    40,    41,   139,    27,
      28,    29,    30,    31,    21,   137,    20,   135,    20,    37,
      19,   143,     0,     1,    20,     3,    18,    34,    35,     7,
      21,     9,    16,    17,    11,    13,    14,    15,    37,    38,
      39,    40,    41,    34,    35,    23,    24,    25,    26,     1,
      12,     3,    11,    12,    10,     7,    20,     9,    10,    11,
      12,    13,    14,    15,    10,    35,    86,   123,     1,   123,
       3,    23,    24,    25,     7,    10,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,     1,    -1,     3,
      23,    24,    25,     7,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,     1,    -1,     3,    23,
      24,    25,     7,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    19,    -1,    -1,     1,    -1,     3,    23,    24,
      25,     7,    19,     9,    -1,    -1,    -1,    13,    14,    15,
      37,    38,    39,    40,    41,    -1,    21,    23,    24,    25,
      37,    38,    39,    40,    41,    21,    -1,    -1,    33,    -1,
      21,    -1,    37,    38,    39,    40,    41,    21,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    37,    38,    39,    40,
      41,    21,    -1,    37,    38,    39,    40,    41,    21,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    -1,    -1,    37,    38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     9,    13,    14,    15,    23,    24,
      25,    44,    45,    46,    47,    48,    51,    52,    53,    54,
      56,    59,    66,    67,    68,    70,    71,     8,    10,    16,
      20,    20,    16,    16,    53,    69,     3,     4,     5,     6,
      20,    27,    28,    29,    30,    31,    37,    55,    72,    16,
      72,     0,    26,    46,     3,    49,    50,    32,    18,    45,
      45,    20,    36,    55,    65,    65,    16,    17,    18,    55,
      20,    20,    20,    20,    20,    55,    37,    38,    39,    40,
      41,    16,    17,    16,    18,    16,    17,    55,    55,    10,
      57,    58,     8,    55,    65,    65,    33,    21,    34,    35,
      21,    53,    55,    21,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    50,    16,    19,    11,
      62,    12,    60,    61,    63,    64,    21,    55,    65,    65,
      19,    21,    21,    21,    21,    17,    19,    45,    10,    20,
      10,    62,    63,    45,    55,    65,    21,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 55 "comp.y"
    {
              checkNames();
              icode.print();
              printf("--------\n\n");
          ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 60 "comp.y"
    {
              checkNames();
              icode.print();
              printf("--------\n\n");
              // YYACCEPT;
              return 0;
          ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 69 "comp.y"
    {
              // printf("stms: stm\n"); 
          ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 72 "comp.y"
    { 
              // printf("stms: stms stm\n");
          ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 77 "comp.y"
    {
              // printf("stm: decl\n");
          ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 80 "comp.y"
    {
              // printf("stm: oper\n"); 
          ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 83 "comp.y"
    {
              // printf("stm: error SM\n"); 
          ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 86 "comp.y"
    {
              // printf("stm: error ENDIF\n"); 
          ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 89 "comp.y"
    { 
              // printf("stm: error WHILE\n"); 
          ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 94 "comp.y"
    {
              // printf("decl\n"); 
          ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 99 "comp.y"
    {
              base_type = (yyvsp[(1) - (1)]).int_value;
          ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 104 "comp.y"
    {
              // printf("def\n"); 
          ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 107 "comp.y"
    {
              // printf("defs CM def\n"); 
          ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 112 "comp.y"
    {
              NameDef* n = name_table.addName((yyvsp[(1) - (1)]).name);
              n->baseType = base_type;
              n->dimension = 0;
              ++(n->numDefinitions);
              n->modifiers |= NameDef::NAME_VARIABLE;
              if (n->numDefinitions > 1) {
                  sprintf(
                      error_text, "Multiple definition of %s",
                      n->name.c_str()
                  );
                  yyerror(error_text);
              }
              // printf("variable %s\n", n->name);

              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::def_variable;
              c->ext = base_type;
              c->name_ptr = n;
          ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 132 "comp.y"
    {
              // $3.tree->print();
              genExpr((yyvsp[(3) - (4)]).tree);

              NameDef* n = name_table.addName((yyvsp[(1) - (4)]).name);
              n->baseType = base_type;
              n->dimension = 1; // Array
              ++(n->numDefinitions);
              n->modifiers |= NameDef::NAME_ARRAY;
              if (n->numDefinitions > 1) {
                  sprintf(
                      error_text, "Multiple definition of %s",
                      n->name.c_str()
                  );
                  yyerror(error_text);
              }
              // printf("variable %s\n", n->name);

              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::def_array;
              c->ext = base_type;
              c->name_ptr = n;
          ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 160 "comp.y"
    {
              if (breakLabel == 0) {
                  yyerror("break out of loop");
              } else {
                  genGoto(breakLabel);
              }
          ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 167 "comp.y"
    {
              if (continueLabel == 0) {
                  yyerror("continue out of loop");
              } else {
                  genGoto(continueLabel);
              }
          ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 179 "comp.y"
    {
              // printf("assign: right expr:\n");
              // $3.tree->print();

              genExpr((yyvsp[(3) - (4)]).tree);

              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::assign;
          ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 191 "comp.y"
    {
              genExpr((yyvsp[(3) - (4)]).tree);
              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::array_lvalue;
          ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 198 "comp.y"
    {
                NameDef* n = name_table.addName((yyvsp[(1) - (1)]).name);
                // printf("l-value %s\n", n->name);
                ++(n->numWrites);

                IProgram::iterator c = icode.addNewCommand();
                c->type = ICommand::name_lvalue;
                c->name_ptr = n;
            ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 209 "comp.y"
    {
              binOper = TreeNode::plus;
              LBinOper: ;
              TreeNode* t = new TreeNode();
              t->nodeType = binOper;
              t->addLeftSon((yyvsp[(1) - (3)]).tree);
              t->addRightSon((yyvsp[(3) - (3)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 218 "comp.y"
    {
              binOper = TreeNode::minus;
              goto LBinOper;
          ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 222 "comp.y"
    {
              binOper = TreeNode::mul;
              goto LBinOper;
          ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 226 "comp.y"
    {
              binOper = TreeNode::div;
              goto LBinOper;
          ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 230 "comp.y"
    {
              binOper = TreeNode::mod;
              goto LBinOper;
          ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 234 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::uminus;
              t->addLeftSon((yyvsp[(2) - (2)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 240 "comp.y"
    {
              TreeNode* t = new TreeNode();
              NameDef* n = name_table.addName((yyvsp[(1) - (1)]).name);
              ++(n->numReads);
              t->nodeType = TreeNode::name;
              t->nameDef = n;
              (yyval).tree = t;
          ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 248 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::array_idx;
              NameDef* n = name_table.addName((yyvsp[(1) - (4)]).name);
              ++(n->numReads);
              TreeNode* t1 = new TreeNode();
              t1->nodeType = TreeNode::name;
              t1->nameDef = n;
              t->addLeftSon(t1);
              t->addRightSon((yyvsp[(3) - (4)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 260 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::int_const;
              t->intValue = (yyvsp[(1) - (1)]).int_value;
              (yyval).tree = t;
          ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 266 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::double_const;
              t->doubleValue = (yyvsp[(1) - (1)]).double_value;
              (yyval).tree = t;
          ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 272 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::string_const;
              t->stringValue = (yyvsp[(1) - (1)]).name;
              (yyval).tree = t;
          ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 278 "comp.y"
    { (yyval).tree = (yyvsp[(2) - (3)]).tree; ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 279 "comp.y"
    { 
            TreeNode* t = new TreeNode();
            t->nodeType = TreeNode::sqrt;
            t->addLeftSon((yyvsp[(3) - (4)]).tree);
            (yyval).tree = t; 
        ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 285 "comp.y"
    { 
            TreeNode* t = new TreeNode();
            t->nodeType = TreeNode::sin;
            t->addLeftSon((yyvsp[(3) - (4)]).tree);
            (yyval).tree = t; 
        ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 291 "comp.y"
    { 
            TreeNode* t = new TreeNode();
            t->nodeType = TreeNode::cos;
            t->addLeftSon((yyvsp[(3) - (4)]).tree);
            (yyval).tree = t; 
        ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 297 "comp.y"
    { 
            TreeNode* t = new TreeNode();
            t->nodeType = TreeNode::exp;
            t->addLeftSon((yyvsp[(3) - (4)]).tree);
            (yyval).tree = t; 
        ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 303 "comp.y"
    { 
            TreeNode* t = new TreeNode();
            t->nodeType = TreeNode::pow;
            t->addLeftSon((yyvsp[(3) - (6)]).tree);
            t->addRightSon((yyvsp[(5) - (6)]).tree);
            (yyval).tree = t; 
        ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 312 "comp.y"
    { 
              // printf("if: ifh stmd ENDIF\n");
              genNop((yyvsp[(1) - (3)]).label1);        // Label of endif
          ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 316 "comp.y"
    {
              const Label* endif_label = genLabel();
              (yyvsp[(1) - (2)]).label2 = endif_label;
              (yyvsp[(1) - (2)]).saved_label2 = endifLabel;
              endifLabel = endif_label;
              genGoto(endif_label);
              genNop((yyvsp[(1) - (2)]).label1);
          ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 324 "comp.y"
    {
              genNop((yyvsp[(1) - (5)]).label2);
              endifLabel = (yyvsp[(1) - (5)]).saved_label2;
          ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 328 "comp.y"
    {
              const Label* endif_label = genLabel();
              (yyvsp[(1) - (2)]).label2 = endif_label;
              (yyvsp[(1) - (2)]).saved_label2 = endifLabel;  // Save previous endif label
              endifLabel = endif_label;
              genGoto(endif_label);
              genNop((yyvsp[(1) - (2)]).label1);
          ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 336 "comp.y"
    {
              genNop((yyvsp[(1) - (5)]).label2);
              endifLabel = (yyvsp[(1) - (5)]).saved_label2;
          ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 342 "comp.y"
    { 
              // printf("ifh\n");
              const Label* l = genLabel();
              // $3.tree->print();
              genLExpr((yyvsp[(3) - (4)]).tree, 0, l);
              (yyval).label1 = l;
          ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 362 "comp.y"
    {
              genGoto(endifLabel);
              genNop((yyvsp[(1) - (2)]).label1);
          ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 368 "comp.y"
    {
              const Label* l = genLabel();
              genLExpr((yyvsp[(3) - (4)]).tree, 0, l);
              (yyval).label1 = l;
          ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 375 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::relop;
              t->intValue = (yyvsp[(2) - (3)]).int_value; // operation: RELOP_EQ, etc.
              t->addLeftSon((yyvsp[(1) - (3)]).tree);
              t->addRightSon((yyvsp[(3) - (3)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 383 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::lor;
              t->addLeftSon((yyvsp[(1) - (3)]).tree);
              t->addRightSon((yyvsp[(3) - (3)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 390 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::land;
              t->addLeftSon((yyvsp[(1) - (3)]).tree);
              t->addRightSon((yyvsp[(3) - (3)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 397 "comp.y"
    {
              TreeNode* t = new TreeNode();
              t->nodeType = TreeNode::lnot;
              t->addLeftSon((yyvsp[(2) - (2)]).tree);
              (yyval).tree = t;
          ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 403 "comp.y"
    {
              (yyval).tree = (yyvsp[(2) - (3)]).tree;
          ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 408 "comp.y"
    { 
              // printf("while\n");
              // Restore loop labels
              genGoto((yyvsp[(1) - (3)]).label1);
              genNop((yyvsp[(1) - (3)]).label2);
              continueLabel = (yyvsp[(1) - (3)]).saved_label1;
              breakLabel = (yyvsp[(1) - (3)]).saved_label2;
          ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 418 "comp.y"
    { 
              // printf("whileh\n");
              const Label* beginLab = genLabel();
              const Label* endLab = genLabel();
              (yyval).label1 = beginLab;
              (yyval).label2 = endLab;

              genNop(beginLab);
              genLExpr((yyvsp[(3) - (4)]).tree, 0, endLab);

              (yyval).saved_label1 = continueLabel;
              (yyval).saved_label2 = breakLabel;
              continueLabel = beginLab;
              breakLabel = endLab;
          ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 438 "comp.y"
    {
              LInput: ;
              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::input;
          ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 443 "comp.y"
    { goto LInput; ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 449 "comp.y"
    {
              LNewLine: ;   
              // Output the "new line" character
              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::string_const;
              c->string_value = "\n";
                
              c = icode.addNewCommand();
              c->type = ICommand::output;
          ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 459 "comp.y"
    { goto LNewLine; ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 462 "comp.y"
    {
              LOutput: ;
              genExpr((yyvsp[(1) - (1)]).tree);

              IProgram::iterator c = icode.addNewCommand();
              c->type = ICommand::output;
          ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 469 "comp.y"
    { goto LOutput; ;}
    break;



/* Line 1464 of yacc.c  */
#line 2254 "comp.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 472 "comp.y"


int main(int argc, char *argv[]) {
    FILE* f = NULL;
    if (argc > 1) {
        // Open an input file
        FILE* f = fopen(argv[1], "r");
        if (f != NULL)
            yyin = f;
    }
    yyparse();
    if (f != NULL)
        fclose(f);

    ICodeInterpretator interpretator;
    interpretator.initialize(&icode);
    try {
        interpretator.execute();
        /*
        printf("stack depth = %d\n", interpretator.stack.size());
        if (interpretator.stack.size() > 0) {
            printf("stack top: ");
            interpretator.printStackTop();
            printf("\n");
        }
        */
    } catch (InterpretatorException& e) {
        printf(
            "InterpretatorException: %s\n",
            e.reason
        );
        exit(1);
    } catch (StackException& e) {
        printf(
            "StackException: %s\n",
            e.reason
        );
        exit(1);
    } catch (OutOfRangeException& e) {
        printf(
            "OutOfRangeException: %s\n",
            e.reason
        );
        exit(1);
    }
    return 0;
}

int yyerror(const char *s) {
    printf("%s in line %d\n", s, yylineno);
    return 0;
}

static void genExpr(const TreeNode* tree) {
    if (tree == 0)
        return;
    IProgram::iterator c;
    int binop;

    switch(tree->nodeType) {
    case TreeNode::int_const:
        c = icode.addNewCommand();
        c->type = ICommand::int_const;
        c->int_value = tree->intValue;
        break;
    case TreeNode::double_const:
        c = icode.addNewCommand();
        c->type = ICommand::double_const;
        c->double_value = tree->doubleValue;
        break;
    case TreeNode::string_const:
        c = icode.addNewCommand();
        c->type = ICommand::string_const;
        c->string_value = tree->stringValue;
        break;
    case TreeNode::name:
        c = icode.addNewCommand();
        c->type = ICommand::name;
        c->name_ptr = tree->nameDef;
        break;
    case TreeNode::array_idx:
        if (tree->left == 0 || tree->right == 0) {
            yyerror("Illegal expression");
            return;
        }
        c = icode.addNewCommand();
        c->type = ICommand::name_lvalue;
        c->name_ptr = tree->left->nameDef;

        genExpr(tree->right);

        c = icode.addNewCommand();
        c->type = ICommand::array_element;
        break;
    case TreeNode::plus:
        binop = ICommand::plus;
        LBinOp: ;
        if (tree->left == 0 || tree->right == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->left);
        genExpr(tree->right);
        c = icode.addNewCommand();
        c->type = binop;
        break;
    case TreeNode::minus:
        binop = ICommand::minus;
        goto LBinOp;
    case TreeNode::mul:
        binop = ICommand::mul;
        goto LBinOp;
    case TreeNode::div:
        binop = ICommand::div;
        goto LBinOp;
    case TreeNode::mod:
        binop = ICommand::mod;
        goto LBinOp;
    case TreeNode::uminus:
        if (tree->left == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->left);
        c = icode.addNewCommand();
        c->type = ICommand::uminus;
        break;
    case TreeNode::sqrt:
        if (tree->left == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->left);
        c = icode.addNewCommand();
        c->type = ICommand::sqrt;
        break;
    case TreeNode::sin:
        if (tree->left == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->left);
        c = icode.addNewCommand();
        c->type = ICommand::sin;
        break;
    case TreeNode::cos:
        if (tree->left == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->left);
        c = icode.addNewCommand();
        c->type = ICommand::cos;
        break;
    case TreeNode::exp:
        if (tree->left == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->left);
        c = icode.addNewCommand();
        c->type = ICommand::exp;
        break;

    case TreeNode::pow:
        if (tree->left == 0) {
            yyerror("Illegal expression");
            return;
        }
        if (tree->right == 0) {
            yyerror("Illegal expression");
            return;
        }
        genExpr(tree->right);
        genExpr(tree->left);
        c = icode.addNewCommand();
        c->type = ICommand::pow;
        break;
    
    default:
        yyerror("Illegal expression");
    }
}

static void genNop(const Label* label) {
    IProgram::iterator c = icode.addNewCommand();
    label->location = c;
    c->type = ICommand::nop;
    c->label_ptr = label;
    c->label = label->number;
}

static void genGoto(const Label* label) {
    IProgram::iterator c = icode.addNewCommand();
    c->type = ICommand::go_to;
    c->goto_label_ptr = label;
    c->goto_label = label->number;
}

static int baseLabel = 0;

static const Label* genLabel() {
    ++baseLabel;
    const Label* lab = label_table.addLabel(baseLabel);
    return lab;
}

static void genLExpr(
    const TreeNode* tree,   // Represents a logical expression
    const Label* trueLabel,
    const Label* falseLabel
) {
    IProgram::iterator c;

    switch (tree->nodeType) {
    case TreeNode::relop:
        if (tree->left == 0 || tree->right == 0) {
            yyerror("Illegal comparing");
            return;
        }
        genExpr(tree->left);
        genExpr(tree->right);
        c = icode.addNewCommand();
        c->type = ICommand::cmp;        // Compare

        c = icode.addNewCommand();
        c->type = ICommand::if_goto;

        if (trueLabel != 0) {
            switch (tree->intValue) {   // relation
                case RELOP_EQ: c->ext = ICommand::eq; break;
                case RELOP_NE: c->ext = ICommand::ne; break;
                case RELOP_LT: c->ext = ICommand::lt; break;
                case RELOP_LE: c->ext = ICommand::le; break;
                case RELOP_GT: c->ext = ICommand::gt; break;
                case RELOP_GE: c->ext = ICommand::ge; break;
            }
            c->goto_label_ptr = trueLabel;
            c->goto_label = trueLabel->number;
        } else {
            assert(falseLabel != 0);
            switch (tree->intValue) {  // relation
                case RELOP_EQ: c->ext = ICommand::ne; break; // Inverse
                case RELOP_NE: c->ext = ICommand::eq; break;
                case RELOP_LT: c->ext = ICommand::ge; break;
                case RELOP_LE: c->ext = ICommand::gt; break;
                case RELOP_GT: c->ext = ICommand::le; break;
                case RELOP_GE: c->ext = ICommand::lt; break;
            }
            c->goto_label_ptr = falseLabel;
            c->goto_label = falseLabel->number;
        }
        break;
    case TreeNode::lor:
        if (tree->left == 0 || tree->right == 0) {
            yyerror("Illegal logical expression");
            return;
        }
        if (trueLabel != 0) {
            genLExpr(tree->left, trueLabel, 0);
            genLExpr(tree->right, trueLabel, 0);
        } else {
            const Label* lab = genLabel();
            genLExpr(tree->left, lab, 0);
            genLExpr(tree->right, 0, falseLabel);
            genNop(lab);
        }
        break;
    case TreeNode::land:
        if (falseLabel != 0) {
            genLExpr(tree->left, 0, falseLabel);
            genLExpr(tree->right, 0, falseLabel);
        } else {
            const Label* lab = genLabel();
            genLExpr(tree->left, 0, lab);
            genLExpr(tree->right, trueLabel, 0);
            genNop(lab);
        }
        break;
    case TreeNode::lnot:
        genLExpr(tree->left, falseLabel, trueLabel);
        break;
    }
}

static void checkNames() {
    NameTable::const_iterator i = name_table.begin();
    while (i != name_table.end()) {
        const NameDef* n = &(*i);
        if ((n->modifiers & NameDef::NAME_FUNCTION) == 0) {
            // n is not a name of function
            if (n->numDefinitions == 0) {
                sprintf(
                    error_text, "Udefined variable %s", 
                    n->name.c_str()
                );
                printError(error_text);
            }
            if (n->numReads == 0) {
                sprintf(
                    error_text, "Unused variable %s", 
                    n->name.c_str()
                );
                printWarning(error_text);
            }
            if (
                n->numWrites == 0 && 
                (n->modifiers & NameDef::NAME_ARRAY) == 0
            ) {
                sprintf(
                    error_text, 
                    "Variable %s was never assigned any value",
                    n->name.c_str()
                );
                printWarning(error_text);
            }
        }
        ++i;
    }
}

static void printWarning(const char *text) {
    fprintf(stderr, "Warning: %s\n", text);
}

static void printError(const char *text) {
    fprintf(stderr, "Error: %s\n", text);
}

