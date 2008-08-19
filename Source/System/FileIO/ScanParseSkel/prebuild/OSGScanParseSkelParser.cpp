/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse OSGScanParseSkel_parse
#define yylex   OSGScanParseSkel_lex
#define yyerror OSGScanParseSkel_error
#define yylval  OSGScanParseSkel_lval
#define yychar  OSGScanParseSkel_char
#define yydebug OSGScanParseSkel_debug
#define yynerrs OSGScanParseSkel_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_HEADER = 258,
     TOK_PROFILE = 259,
     TOK_COMPONENT = 260,
     TOK_META = 261,
     TOK_PROTO = 262,
     TOK_EXTERNPROTO = 263,
     TOK_IS = 264,
     TOK_DEF = 265,
     TOK_USE = 266,
     TOK_ROUTE = 267,
     TOK_TO = 268,
     TOK_IMPORT = 269,
     TOK_EXPORT = 270,
     TOK_AS = 271,
     TOK_eventIn = 272,
     TOK_eventOut = 273,
     TOK_exposedField = 274,
     TOK_field = 275,
     TOK_MFBool = 276,
     TOK_MFColor = 277,
     TOK_MFColorRGBA = 278,
     TOK_MFDouble = 279,
     TOK_MFFloat = 280,
     TOK_MFImage = 281,
     TOK_MFInt32 = 282,
     TOK_MFMatrix3d = 283,
     TOK_MFMatrix3f = 284,
     TOK_MFMatrix4d = 285,
     TOK_MFMatrix4f = 286,
     TOK_MFNode = 287,
     TOK_MFRotation = 288,
     TOK_MFString = 289,
     TOK_MFTime = 290,
     TOK_MFVec2d = 291,
     TOK_MFVec2f = 292,
     TOK_MFVec3d = 293,
     TOK_MFVec3f = 294,
     TOK_MFVec4d = 295,
     TOK_MFVec4f = 296,
     TOK_SFBool = 297,
     TOK_SFColor = 298,
     TOK_SFColorRGBA = 299,
     TOK_SFDouble = 300,
     TOK_SFFloat = 301,
     TOK_SFImage = 302,
     TOK_SFInt32 = 303,
     TOK_SFMatrix3d = 304,
     TOK_SFMatrix3f = 305,
     TOK_SFMatrix4d = 306,
     TOK_SFMatrix4f = 307,
     TOK_SFNode = 308,
     TOK_SFRotation = 309,
     TOK_SFString = 310,
     TOK_SFTime = 311,
     TOK_SFVec2d = 312,
     TOK_SFVec2f = 313,
     TOK_SFVec3d = 314,
     TOK_SFVec3f = 315,
     TOK_SFVec4d = 316,
     TOK_SFVec4f = 317,
     TOK_MFColor4i = 318,
     TOK_MFPnt2f = 319,
     TOK_MFPnt3f = 320,
     TOK_MFPnt4f = 321,
     TOK_MFPlane = 322,
     TOK_SFColor4i = 323,
     TOK_SFPnt2f = 324,
     TOK_SFPnt3f = 325,
     TOK_SFPnt4f = 326,
     TOK_SFPlane = 327,
     TOK_SFVolume = 328,
     TOK_SFVec2i = 329,
     TOK_hex = 330,
     TOK_int32 = 331,
     TOK_double = 332,
     TOK_string = 333,
     TOK_bool = 334,
     TOK_NULL = 335,
     TOK_Id = 336,
     TOK_ImageFinished = 337,
     TOK_Error = 338
   };
#endif
/* Tokens.  */
#define TOK_HEADER 258
#define TOK_PROFILE 259
#define TOK_COMPONENT 260
#define TOK_META 261
#define TOK_PROTO 262
#define TOK_EXTERNPROTO 263
#define TOK_IS 264
#define TOK_DEF 265
#define TOK_USE 266
#define TOK_ROUTE 267
#define TOK_TO 268
#define TOK_IMPORT 269
#define TOK_EXPORT 270
#define TOK_AS 271
#define TOK_eventIn 272
#define TOK_eventOut 273
#define TOK_exposedField 274
#define TOK_field 275
#define TOK_MFBool 276
#define TOK_MFColor 277
#define TOK_MFColorRGBA 278
#define TOK_MFDouble 279
#define TOK_MFFloat 280
#define TOK_MFImage 281
#define TOK_MFInt32 282
#define TOK_MFMatrix3d 283
#define TOK_MFMatrix3f 284
#define TOK_MFMatrix4d 285
#define TOK_MFMatrix4f 286
#define TOK_MFNode 287
#define TOK_MFRotation 288
#define TOK_MFString 289
#define TOK_MFTime 290
#define TOK_MFVec2d 291
#define TOK_MFVec2f 292
#define TOK_MFVec3d 293
#define TOK_MFVec3f 294
#define TOK_MFVec4d 295
#define TOK_MFVec4f 296
#define TOK_SFBool 297
#define TOK_SFColor 298
#define TOK_SFColorRGBA 299
#define TOK_SFDouble 300
#define TOK_SFFloat 301
#define TOK_SFImage 302
#define TOK_SFInt32 303
#define TOK_SFMatrix3d 304
#define TOK_SFMatrix3f 305
#define TOK_SFMatrix4d 306
#define TOK_SFMatrix4f 307
#define TOK_SFNode 308
#define TOK_SFRotation 309
#define TOK_SFString 310
#define TOK_SFTime 311
#define TOK_SFVec2d 312
#define TOK_SFVec2f 313
#define TOK_SFVec3d 314
#define TOK_SFVec3f 315
#define TOK_SFVec4d 316
#define TOK_SFVec4f 317
#define TOK_MFColor4i 318
#define TOK_MFPnt2f 319
#define TOK_MFPnt3f 320
#define TOK_MFPnt4f 321
#define TOK_MFPlane 322
#define TOK_SFColor4i 323
#define TOK_SFPnt2f 324
#define TOK_SFPnt3f 325
#define TOK_SFPnt4f 326
#define TOK_SFPlane 327
#define TOK_SFVolume 328
#define TOK_SFVec2i 329
#define TOK_hex 330
#define TOK_int32 331
#define TOK_double 332
#define TOK_string 333
#define TOK_bool 334
#define TOK_NULL 335
#define TOK_Id 336
#define TOK_ImageFinished 337
#define TOK_Error 338




/* Copy the first part of user declarations.  */


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
{
    long intVal;
    double doubleVal;
    float floatVal;
    const char *stringVal;
    bool boolVal;
}
/* Line 187 of yacc.c.  */
#line 279 "build.linux.g++/type-debug--arch-x64/Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 49 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"


#define YYPARSE_PARAM pSkel
#define YYLEX_PARAM   pSkel

#define OSGScanParseSkel_error SKEL->handleError

#include "OSGConfig.h"
#include "OSGBaseFunctions.h"
#include "OSGScanParseLexer.h"
#include "OSGScanParseSkel.h"

#include <iostream>

#if defined(OSG_LINUX_ICC) || defined(OSG_WIN32_ICL)
#pragma warning( disable : 193 810 177 )
#endif

OSG_USING_NAMESPACE

int OSGScanParseSkel_lex(YYSTYPE *lvalp, void *);

#define SKEL (static_cast<ScanParseSkel *>(pSkel))

#if(!defined(__GNUC__) && defined(__ICL) && __INTEL_COMPILER_VERSION >= 900)
# define alloca(size)   __builtin_alloca (size)
#endif



/* Line 216 of yacc.c.  */
#line 321 "build.linux.g++/type-debug--arch-x64/Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.cpp"

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
# if YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   952

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  253
/* YYNRULES -- Number of rules.  */
#define YYNRULES  453
/* YYNRULES -- Number of states.  */
#define YYNSTATES  742

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  (static_cast<unsigned int>(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    88,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    84,     2,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,     2,    87,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    11,    12,    15,    16,    18,    21,
      22,    25,    27,    29,    32,    33,    34,    39,    41,    43,
      46,    47,    49,    51,    53,    55,    57,    58,    62,    63,
      64,    71,    74,    76,    78,    79,    80,    91,    94,    95,
      96,   101,   102,   107,   108,   109,   116,   117,   118,   125,
     126,   127,   136,   139,   140,   141,   146,   147,   152,   153,
     158,   159,   164,   165,   166,   167,   179,   180,   181,   189,
     190,   195,   198,   199,   201,   205,   208,   209,   211,   213,
     215,   217,   219,   221,   222,   223,   230,   231,   232,   239,
     240,   243,   244,   245,   252,   253,   254,   261,   263,   267,
     268,   272,   274,   276,   278,   280,   282,   286,   288,   290,
     292,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     312,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   338,   340,   342,   344,   346,   348,   350,
     352,   354,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   405,   408,   411,   414,
     417,   420,   423,   426,   429,   432,   435,   438,   441,   444,
     447,   450,   453,   456,   459,   462,   465,   468,   471,   474,
     477,   480,   483,   486,   489,   492,   495,   498,   501,   504,
     507,   510,   513,   516,   519,   522,   525,   528,   531,   534,
     537,   540,   543,   546,   549,   552,   555,   558,   561,   564,
     566,   568,   570,   572,   574,   576,   578,   580,   581,   582,
     588,   589,   590,   591,   599,   601,   603,   604,   605,   606,
     615,   618,   619,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   767,   769,   771,   772,   773,   774,   782,
     784,   786,   788,   790,   791,   795,   796,   800,   801,   802,
     803,   810,   811,   812,   813,   820,   821,   822,   823,   824,
     833,   834,   835,   836,   837,   846,   848,   852,   855,   856,
     858,   862,   865,   866,   868,   872,   875,   876,   878,   882,
     885,   886,   888,   892,   895,   896,   898,   902,   905,   906,
     908,   912,   915,   916,   918,   922,   925,   926,   928,   932,
     935,   936,   938,   942,   945,   946,   948,   952,   955,   956,
     958,   962,   965,   966,   968,   972,   975,   976,   978,   982,
     985,   986,   988,   992,   995,   996,   998,  1002,  1005,  1006,
    1008,  1012,  1015,  1016,  1018,  1022,  1025,  1026,  1028,  1032,
    1035,  1036,  1038,  1042,  1045,  1046,  1048,  1052,  1055,  1056,
    1057,  1058,  1059,  1067,  1068,  1072,  1073,  1074,  1080,  1081,
    1082,  1083,  1091,  1092,  1093,  1094,  1102,  1103,  1104,  1105,
    1106,  1107,  1119,  1120,  1124,  1126,  1130,  1133,  1134,  1136,
    1140,  1143,  1144,  1146,  1150,  1153,  1154,  1156,  1160,  1163,
    1164,  1166,  1170,  1173
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    91,    92,    94,    97,   102,    -1,     3,
      -1,    -1,     4,    93,    -1,    -1,    81,    -1,    94,    95,
      -1,    -1,     5,    96,    -1,    81,    -1,    78,    -1,    97,
      98,    -1,    -1,    -1,     6,   100,    99,   101,    -1,    78,
      -1,    78,    -1,   102,   103,    -1,    -1,   104,    -1,   108,
      -1,   129,    -1,   133,    -1,   136,    -1,    -1,   161,   105,
     140,    -1,    -1,    -1,    10,   160,   106,   161,   107,   140,
      -1,    11,   160,    -1,   109,    -1,   120,    -1,    -1,    -1,
       7,   161,   110,    84,   112,    85,   111,    86,   102,    87,
      -1,   112,   113,    -1,    -1,    -1,    17,   165,   114,   163,
      -1,    -1,    18,   165,   115,   164,    -1,    -1,    -1,    20,
     165,   116,   162,   117,   166,    -1,    -1,    -1,    19,   165,
     118,   162,   119,   166,    -1,    -1,    -1,     8,   161,   121,
      84,   123,    85,   122,   139,    -1,   123,   124,    -1,    -1,
      -1,    17,   165,   125,   163,    -1,    -1,    18,   165,   126,
     164,    -1,    -1,    20,   165,   127,   162,    -1,    -1,    19,
     165,   128,   162,    -1,    -1,    -1,    -1,    12,   160,   130,
      88,   164,   131,    13,   160,   132,    88,   163,    -1,    -1,
      -1,    14,   160,   134,    88,   160,   135,   138,    -1,    -1,
      15,   160,   137,   138,    -1,    16,   160,    -1,    -1,   291,
      -1,    86,   141,    87,    -1,   141,   142,    -1,    -1,   157,
      -1,   143,    -1,   146,    -1,   150,    -1,   153,    -1,     1,
      -1,    -1,    -1,    17,   165,   144,   163,   145,   149,    -1,
      -1,    -1,    18,   165,   147,   164,   148,   149,    -1,    -1,
       9,   162,    -1,    -1,    -1,    20,   165,   151,   162,   152,
     156,    -1,    -1,    -1,    19,   165,   154,   162,   155,   156,
      -1,   166,    -1,   165,     9,   162,    -1,    -1,   162,   158,
     159,    -1,   129,    -1,   108,    -1,   133,    -1,   136,    -1,
     166,    -1,   165,     9,   162,    -1,    81,    -1,    81,    -1,
      81,    -1,    81,    -1,    81,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,
      43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,
      48,    -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,
      53,    -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      73,    -1,    21,   265,    -1,    22,   267,    -1,    23,   269,
      -1,    24,   271,    -1,    25,   273,    -1,    26,   275,    -1,
      27,   277,    -1,    28,   279,    -1,    29,   281,    -1,    30,
     283,    -1,    31,   285,    -1,    32,   287,    -1,    33,   289,
      -1,    34,   291,    -1,    35,   293,    -1,    36,   295,    -1,
      37,   297,    -1,    38,   299,    -1,    39,   301,    -1,    40,
     303,    -1,    41,   305,    -1,    42,   170,    -1,    43,   171,
      -1,    44,   174,    -1,    45,   178,    -1,    46,   179,    -1,
      47,   180,    -1,    48,   185,    -1,    49,   186,    -1,    50,
     195,    -1,    51,   204,    -1,    52,   220,    -1,    53,   236,
      -1,    54,   237,    -1,    55,   241,    -1,    56,   242,    -1,
      57,   243,    -1,    58,   245,    -1,    59,   247,    -1,    60,
     251,    -1,    61,   255,    -1,    62,   260,    -1,    63,   332,
      -1,    64,   334,    -1,    65,   336,    -1,    66,   338,    -1,
      67,   340,    -1,    68,   307,    -1,    69,   311,    -1,    70,
     313,    -1,    71,   316,    -1,    72,   320,    -1,    73,   324,
      -1,    74,   330,    -1,    75,    -1,    76,    -1,    76,    -1,
      77,    -1,    76,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,   169,   172,   169,   173,   169,    -1,    -1,    -1,
      -1,   169,   175,   169,   176,   169,   177,   169,    -1,   168,
      -1,   169,    -1,    -1,    -1,    -1,   167,   181,   167,   182,
     167,   183,   184,    82,    -1,   184,   167,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     187,   168,   188,   168,   189,   168,   190,   168,   191,   168,
     192,   168,   193,   168,   194,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   196,   169,   197,   169,
     198,   169,   199,   169,   200,   169,   201,   169,   202,   169,
     203,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   205,
     168,   206,   168,   207,   168,   208,   168,   209,   168,   210,
     168,   211,   168,   212,   168,   213,   168,   214,   168,   215,
     168,   216,   168,   217,   168,   218,   168,   219,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   221,   169,   222,   169,
     223,   169,   224,   169,   225,   169,   226,   169,   227,   169,
     228,   169,   229,   169,   230,   169,   231,   169,   232,   169,
     233,   169,   234,   169,   235,   169,    -1,   104,    -1,    80,
      -1,    -1,    -1,    -1,   169,   238,   169,   239,   169,   240,
     169,    -1,    78,    -1,    81,    -1,    75,    -1,   168,    -1,
      -1,   168,   244,   168,    -1,    -1,   169,   246,   169,    -1,
      -1,    -1,    -1,   168,   248,   168,   249,   168,   250,    -1,
      -1,    -1,    -1,   169,   252,   169,   253,   169,   254,    -1,
      -1,    -1,    -1,    -1,   168,   256,   168,   257,   168,   258,
     168,   259,    -1,    -1,    -1,    -1,    -1,   169,   261,   169,
     262,   169,   263,   169,   264,    -1,   170,    -1,    84,   266,
      85,    -1,   266,   170,    -1,    -1,   171,    -1,    84,   268,
      85,    -1,   268,   171,    -1,    -1,   174,    -1,    84,   270,
      85,    -1,   270,   174,    -1,    -1,   178,    -1,    84,   272,
      85,    -1,   272,   178,    -1,    -1,   179,    -1,    84,   274,
      85,    -1,   274,   179,    -1,    -1,   180,    -1,    84,   276,
      85,    -1,   276,   180,    -1,    -1,   185,    -1,    84,   278,
      85,    -1,   278,   185,    -1,    -1,   186,    -1,    84,   280,
      85,    -1,   280,   186,    -1,    -1,   195,    -1,    84,   282,
      85,    -1,   282,   195,    -1,    -1,   204,    -1,    84,   284,
      85,    -1,   284,   204,    -1,    -1,   220,    -1,    84,   286,
      85,    -1,   286,   220,    -1,    -1,   236,    -1,    84,   288,
      85,    -1,   288,   236,    -1,    -1,   237,    -1,    84,   290,
      85,    -1,   290,   237,    -1,    -1,   241,    -1,    84,   292,
      85,    -1,   292,   241,    -1,    -1,   242,    -1,    84,   294,
      85,    -1,   294,   242,    -1,    -1,   243,    -1,    84,   296,
      85,    -1,   296,   243,    -1,    -1,   245,    -1,    84,   298,
      85,    -1,   298,   245,    -1,    -1,   247,    -1,    84,   300,
      85,    -1,   300,   247,    -1,    -1,   251,    -1,    84,   302,
      85,    -1,   302,   251,    -1,    -1,   255,    -1,    84,   304,
      85,    -1,   304,   255,    -1,    -1,   260,    -1,    84,   306,
      85,    -1,   306,   260,    -1,    -1,    -1,    -1,    -1,   167,
     308,   167,   309,   167,   310,   167,    -1,    -1,   169,   312,
     169,    -1,    -1,    -1,   169,   314,   169,   315,   169,    -1,
      -1,    -1,    -1,   169,   317,   169,   318,   169,   319,   169,
      -1,    -1,    -1,    -1,   169,   321,   169,   322,   169,   323,
     169,    -1,    -1,    -1,    -1,    -1,    -1,   169,   325,   169,
     326,   169,   327,   169,   328,   169,   329,   169,    -1,    -1,
     167,   331,   167,    -1,   307,    -1,    84,   333,    85,    -1,
     333,   307,    -1,    -1,   311,    -1,    84,   335,    85,    -1,
     335,   311,    -1,    -1,   313,    -1,    84,   337,    85,    -1,
     337,   313,    -1,    -1,   316,    -1,    84,   339,    85,    -1,
     339,   316,    -1,    -1,   320,    -1,    84,   341,    85,    -1,
     341,   320,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   204,   205,   208,   209,   212,   215,   216,
     220,   225,   226,   233,   234,   239,   237,   244,   247,   250,
     251,   254,   255,   256,   257,   258,   261,   261,   264,   265,
     263,   267,   271,   272,   279,   280,   279,   284,   285,   289,
     288,   292,   291,   295,   296,   294,   299,   300,   298,   304,
     305,   304,   309,   310,   314,   313,   317,   316,   320,   319,
     323,   322,   328,   330,   332,   327,   339,   341,   338,   352,
     351,   362,   364,   367,   370,   373,   374,   377,   378,   379,
     380,   381,   382,   386,   387,   385,   392,   393,   391,   396,
     398,   402,   403,   401,   408,   409,   407,   413,   414,   418,
     417,   426,   427,   428,   429,   432,   433,   436,   439,   442,
     445,   448,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   564,
     565,   568,   569,   572,   573,   576,   580,   583,   584,   583,
     592,   593,   594,   592,   602,   608,   614,   615,   617,   614,
     627,   631,   634,   640,   641,   642,   643,   644,   645,   646,
     647,   640,   658,   659,   660,   661,   662,   663,   664,   665,
     658,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   676,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   702,   728,   729,   732,   733,   734,   732,   742,
     746,   750,   756,   762,   762,   770,   770,   778,   779,   780,
     778,   787,   788,   789,   787,   796,   797,   798,   799,   796,
     806,   807,   808,   809,   806,   816,   817,   820,   821,   824,
     825,   828,   829,   832,   833,   836,   837,   840,   841,   844,
     845,   848,   849,   852,   853,   856,   857,   860,   861,   864,
     865,   868,   869,   872,   873,   876,   877,   880,   881,   884,
     885,   888,   889,   892,   893,   896,   897,   900,   901,   904,
     905,   908,   909,   912,   913,   916,   917,   920,   921,   924,
     925,   928,   929,   932,   933,   936,   937,   940,   941,   944,
     945,   948,   949,   952,   953,   956,   957,   960,   961,   964,
     965,   968,   969,   972,   973,   976,   977,   980,   981,   986,
     987,   988,   986,   997,   997,  1005,  1006,  1005,  1014,  1015,
    1016,  1014,  1024,  1025,  1026,  1024,  1034,  1035,  1036,  1037,
    1038,  1034,  1048,  1048,  1056,  1057,  1060,  1061,  1064,  1065,
    1068,  1069,  1072,  1073,  1076,  1077,  1080,  1081,  1084,  1085,
    1088,  1089,  1092,  1093
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_HEADER", "TOK_PROFILE",
  "TOK_COMPONENT", "TOK_META", "TOK_PROTO", "TOK_EXTERNPROTO", "TOK_IS",
  "TOK_DEF", "TOK_USE", "TOK_ROUTE", "TOK_TO", "TOK_IMPORT", "TOK_EXPORT",
  "TOK_AS", "TOK_eventIn", "TOK_eventOut", "TOK_exposedField", "TOK_field",
  "TOK_MFBool", "TOK_MFColor", "TOK_MFColorRGBA", "TOK_MFDouble",
  "TOK_MFFloat", "TOK_MFImage", "TOK_MFInt32", "TOK_MFMatrix3d",
  "TOK_MFMatrix3f", "TOK_MFMatrix4d", "TOK_MFMatrix4f", "TOK_MFNode",
  "TOK_MFRotation", "TOK_MFString", "TOK_MFTime", "TOK_MFVec2d",
  "TOK_MFVec2f", "TOK_MFVec3d", "TOK_MFVec3f", "TOK_MFVec4d",
  "TOK_MFVec4f", "TOK_SFBool", "TOK_SFColor", "TOK_SFColorRGBA",
  "TOK_SFDouble", "TOK_SFFloat", "TOK_SFImage", "TOK_SFInt32",
  "TOK_SFMatrix3d", "TOK_SFMatrix3f", "TOK_SFMatrix4d", "TOK_SFMatrix4f",
  "TOK_SFNode", "TOK_SFRotation", "TOK_SFString", "TOK_SFTime",
  "TOK_SFVec2d", "TOK_SFVec2f", "TOK_SFVec3d", "TOK_SFVec3f",
  "TOK_SFVec4d", "TOK_SFVec4f", "TOK_MFColor4i", "TOK_MFPnt2f",
  "TOK_MFPnt3f", "TOK_MFPnt4f", "TOK_MFPlane", "TOK_SFColor4i",
  "TOK_SFPnt2f", "TOK_SFPnt3f", "TOK_SFPnt4f", "TOK_SFPlane",
  "TOK_SFVolume", "TOK_SFVec2i", "TOK_hex", "TOK_int32", "TOK_double",
  "TOK_string", "TOK_bool", "TOK_NULL", "TOK_Id", "TOK_ImageFinished",
  "TOK_Error", "'['", "']'", "'{'", "'}'", "'.'", "$accept", "x3dScene",
  "headerStatement", "profileStatement", "profileNameId",
  "componentStatements", "componentStatement", "componentNameId",
  "metaStatements", "metaStatement", "@1", "metakey", "metavalue",
  "statements", "statement", "nodeStatement", "@2", "@3", "@4",
  "protoStatement", "proto", "@5", "@6", "interfaceDeclarations",
  "interfaceDeclaration", "@7", "@8", "@9", "@10", "@11", "@12",
  "externproto", "@13", "@14", "externInterfaceDeclarations",
  "externInterfaceDeclaration", "@15", "@16", "@17", "@18",
  "routeStatement", "@19", "@20", "@21", "importStatement", "@22", "@23",
  "exportStatement", "@24", "asStatement", "URLList", "node", "scriptBody",
  "scriptBodyElement", "eventInDeclaration", "@25", "@26",
  "eventOutDeclaration", "@27", "@28", "eventDeclarationEnd",
  "fieldDeclaration", "@29", "@30", "exposedFieldDeclaration", "@31",
  "@32", "fieldDeclarationEnd", "nodeBodyElement", "@33", "fieldEnd",
  "nodeNameId", "nodeTypeId", "fieldId", "eventInId", "eventOutId",
  "fieldType", "fieldValue", "int32", "double", "float", "sfboolValue",
  "sfcolorValue", "@34", "@35", "sfcolorRGBAValue", "@36", "@37", "@38",
  "sfdoubleValue", "sffloatValue", "sfimageValue", "@39", "@40", "@41",
  "pixels", "sfint32Value", "sfmatrix3dValue", "@42", "@43", "@44", "@45",
  "@46", "@47", "@48", "@49", "sfmatrix3fValue", "@50", "@51", "@52",
  "@53", "@54", "@55", "@56", "@57", "sfmatrix4dValue", "@58", "@59",
  "@60", "@61", "@62", "@63", "@64", "@65", "@66", "@67", "@68", "@69",
  "@70", "@71", "@72", "sfmatrix4fValue", "@73", "@74", "@75", "@76",
  "@77", "@78", "@79", "@80", "@81", "@82", "@83", "@84", "@85", "@86",
  "@87", "sfnodeValue", "sfrotationValue", "@88", "@89", "@90",
  "sfstringValue", "sftimeValue", "sfvec2dValue", "@91", "sfvec2fValue",
  "@92", "sfvec3dValue", "@93", "@94", "@95", "sfvec3fValue", "@96", "@97",
  "@98", "sfvec4dValue", "@99", "@100", "@101", "@102", "sfvec4fValue",
  "@103", "@104", "@105", "@106", "mfboolValue", "sfboolValues",
  "mfcolorValue", "sfcolorValues", "mfcolorRGBAValue", "sfcolorRGBAValues",
  "mfdoubleValue", "sfdoubleValues", "mffloatValue", "sffloatValues",
  "mfimageValue", "sfimageValues", "mfint32Value", "sfint32Values",
  "mfmatrix3dValue", "sfmatrix3dValues", "mfmatrix3fValue",
  "sfmatrix3fValues", "mfmatrix4dValue", "sfmatrix4dValues",
  "mfmatrix4fValue", "sfmatrix4fValues", "mfnodeValue", "sfnodeValues",
  "mfrotationValue", "sfrotationValues", "mfstringValue", "sfstringValues",
  "mftimeValue", "sftimeValues", "mfvec2dValue", "sfvec2dValues",
  "mfvec2fValue", "sfvec2fValues", "mfvec3dValue", "sfvec3dValues",
  "mfvec3fValue", "sfvec3fValues", "mfvec4dValue", "sfvec4dValues",
  "mfvec4fValue", "sfvec4fValues", "sfcolor4iValue", "@107", "@108",
  "@109", "sfpnt2fValue", "@110", "sfpnt3fValue", "@111", "@112",
  "sfpnt4fValue", "@113", "@114", "@115", "sfplaneValue", "@116", "@117",
  "@118", "sfVolumeValue", "@119", "@120", "@121", "@122", "@123",
  "sfvec2iValue", "@124", "mfcolor4iValue", "sfcolor4iValues",
  "mfpnt2fValue", "sfpnt2fValues", "mfpnt3fValue", "sfpnt3fValues",
  "mfpnt4fValue", "sfpnt4fValues", "mfplaneValue", "sfplaneValues", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,    91,    93,   123,   125,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    94,    94,
      95,    96,    96,    97,    97,    99,    98,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   105,   104,   106,   107,
     104,   104,   108,   108,   110,   111,   109,   112,   112,   114,
     113,   115,   113,   116,   117,   113,   118,   119,   113,   121,
     122,   120,   123,   123,   125,   124,   126,   124,   127,   124,
     128,   124,   130,   131,   132,   129,   134,   135,   133,   137,
     136,   138,   138,   139,   140,   141,   141,   142,   142,   142,
     142,   142,   142,   144,   145,   143,   147,   148,   146,   149,
     149,   151,   152,   150,   154,   155,   153,   156,   156,   158,
     157,   157,   157,   157,   157,   159,   159,   160,   161,   162,
     163,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   167,
     167,   168,   168,   169,   169,   170,   170,   172,   173,   171,
     175,   176,   177,   174,   178,   179,   181,   182,   183,   180,
     184,   184,   185,   187,   188,   189,   190,   191,   192,   193,
     194,   186,   196,   197,   198,   199,   200,   201,   202,   203,
     195,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   204,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   220,   236,   236,   238,   239,   240,   237,   241,
     241,   241,   242,   244,   243,   246,   245,   248,   249,   250,
     247,   252,   253,   254,   251,   256,   257,   258,   259,   255,
     261,   262,   263,   264,   260,   265,   265,   266,   266,   267,
     267,   268,   268,   269,   269,   270,   270,   271,   271,   272,
     272,   273,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   278,   278,   279,   279,   280,   280,   281,   281,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   292,
     292,   293,   293,   294,   294,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   301,   301,   302,
     302,   303,   303,   304,   304,   305,   305,   306,   306,   308,
     309,   310,   307,   312,   311,   314,   315,   313,   317,   318,
     319,   316,   321,   322,   323,   320,   325,   326,   327,   328,
     329,   324,   331,   330,   332,   332,   333,   333,   334,   334,
     335,   335,   336,   336,   337,   337,   338,   338,   339,   339,
     340,   340,   341,   341
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     0,     2,     0,     1,     2,     0,
       2,     1,     1,     2,     0,     0,     4,     1,     1,     2,
       0,     1,     1,     1,     1,     1,     0,     3,     0,     0,
       6,     2,     1,     1,     0,     0,    10,     2,     0,     0,
       4,     0,     4,     0,     0,     6,     0,     0,     6,     0,
       0,     8,     2,     0,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     0,     0,    11,     0,     0,     7,     0,
       4,     2,     0,     1,     3,     2,     0,     1,     1,     1,
       1,     1,     1,     0,     0,     6,     0,     0,     6,     0,
       2,     0,     0,     6,     0,     0,     6,     1,     3,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     5,
       0,     0,     0,     7,     1,     1,     0,     0,     0,     8,
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     1,     1,     0,     0,     0,     7,     1,
       1,     1,     1,     0,     3,     0,     3,     0,     0,     0,
       6,     0,     0,     0,     6,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     8,     1,     3,     2,     0,     1,
       3,     2,     0,     1,     3,     2,     0,     1,     3,     2,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     1,
       3,     2,     0,     1,     3,     2,     0,     1,     3,     2,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     1,
       3,     2,     0,     1,     3,     2,     0,     1,     3,     2,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     1,
       3,     2,     0,     1,     3,     2,     0,     1,     3,     2,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     0,
       0,     0,     7,     0,     3,     0,     0,     5,     0,     0,
       0,     7,     0,     0,     0,     7,     0,     0,     0,     0,
       0,    11,     0,     3,     1,     3,     2,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     1,     3,     2,     0,
       1,     3,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     3,     0,     6,     1,     0,     9,     7,     5,    14,
       0,     8,    20,    12,    11,    10,     0,    13,     2,    17,
      15,     0,     0,     0,     0,     0,     0,     0,   108,    19,
      21,    22,    32,    33,    23,    24,    25,    26,     0,    34,
      49,   107,    28,    31,    62,    66,    69,     0,    18,    16,
       0,     0,     0,     0,     0,    72,    76,    27,    38,    53,
      29,     0,     0,     0,    70,     0,     0,     0,     0,   111,
      63,    67,    71,    82,     0,     0,     0,     0,   109,    74,
     102,   101,   103,   104,    75,    78,    79,    80,    81,    77,
      99,     0,     0,     0,     0,    35,    37,     0,     0,     0,
       0,    50,    52,    30,     0,    72,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    83,
      86,    94,    91,     0,    39,    41,    46,    43,     0,    54,
      56,    60,    58,     0,     0,    68,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,   100,     0,   105,     0,     0,     0,
       0,    20,     0,     0,     0,     0,   301,   299,   300,   380,
      51,   377,    73,    64,   110,    84,    87,    95,    92,   225,
     226,   328,   325,   165,   223,   224,   332,   227,   329,   166,
     336,   230,   333,   167,   221,   222,   340,   234,   337,   168,
     344,   235,   341,   169,   219,   220,   348,   236,   345,   170,
     352,   242,   349,   171,   356,   243,   353,   172,   360,   252,
     357,   173,   364,   261,   361,   174,   368,   277,   365,   175,
     294,   372,   293,   369,   176,   376,   295,   373,   177,   178,
     384,   302,   381,   179,   388,   303,   385,   180,   392,   305,
     389,   181,   396,   307,   393,   182,   400,   311,   397,   183,
     404,   315,   401,   184,   408,   320,   405,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   437,
     409,   434,   207,   441,   413,   438,   208,   445,   415,   442,
     209,   449,   418,   446,   210,   453,   422,   450,   211,   212,
     213,   214,   215,   216,   426,   217,   432,   218,     0,    40,
      42,    47,    44,     0,    55,    57,    61,    59,     0,     0,
      89,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,    36,   378,   379,     0,     0,    85,    88,
      96,     0,    97,    93,   326,   327,   330,   331,   228,   334,
     335,   231,   338,   339,   342,   343,   346,   347,   237,   350,
     351,   354,   355,   244,   358,   359,   253,   362,   363,   262,
     366,   367,   278,   370,   371,   374,   375,   296,   382,   383,
     386,   387,   304,   390,   391,   306,   394,   395,   308,   398,
     399,   312,   402,   403,   316,   406,   407,   321,   435,   436,
     410,   439,   440,   414,   443,   444,   416,   447,   448,   419,
     451,   452,   423,   427,   433,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    45,
      65,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,   229,   232,   238,   245,   254,   263,   279,   297,   309,
     313,   317,   322,   411,   417,   420,   424,   428,     0,   241,
       0,     0,     0,     0,     0,   310,   314,     0,     0,     0,
       0,     0,     0,   233,     0,   246,   255,   264,   280,   298,
     318,   323,   412,   421,   425,   429,   239,   240,     0,     0,
       0,     0,   319,   324,     0,   247,   256,   265,   281,   430,
       0,     0,     0,     0,     0,   248,   257,   266,   282,   431,
       0,     0,     0,     0,   249,   258,   267,   283,     0,     0,
       0,     0,   250,   259,   268,   284,     0,     0,     0,     0,
     251,   260,   269,   285,     0,     0,   270,   286,     0,     0,
     271,   287,     0,     0,   272,   288,     0,     0,   273,   289,
       0,     0,   274,   290,     0,     0,   275,   291,     0,     0,
     276,   292
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,     9,    11,    15,    12,    17,
      38,    20,    49,    18,    29,   312,    47,    52,    68,    31,
      32,    50,   168,    66,    96,   237,   238,   240,   462,   239,
     461,    33,    51,   173,    67,   102,   242,   243,   245,   244,
      34,    53,   104,   409,    35,    54,   105,    36,    55,    64,
     250,    57,    65,    84,    85,   176,   410,    86,   177,   411,
     468,    87,   179,   413,    88,   178,   412,   470,    89,   163,
     234,    42,    37,    90,   255,    70,   471,   472,   287,   277,
     267,   262,   268,   416,   603,   272,   418,   604,   638,   278,
     282,   288,   422,   605,   639,   654,   292,   296,   425,   606,
     640,   668,   680,   690,   698,   706,   300,   427,   607,   641,
     669,   681,   691,   699,   707,   304,   429,   608,   642,   670,
     682,   692,   700,   708,   714,   718,   722,   726,   730,   734,
     738,   308,   431,   609,   643,   671,   683,   693,   701,   709,
     715,   719,   723,   727,   731,   735,   739,   313,   317,   434,
     610,   644,   251,   322,   326,   437,   330,   439,   334,   441,
     611,   645,   338,   443,   612,   646,   342,   445,   613,   647,
     672,   346,   447,   614,   648,   673,   263,   414,   269,   415,
     273,   417,   279,   419,   283,   420,   289,   421,   293,   423,
     297,   424,   301,   426,   305,   428,   309,   430,   314,   432,
     318,   433,   319,   408,   323,   435,   327,   436,   331,   438,
     335,   440,   339,   442,   343,   444,   347,   446,   371,   449,
     615,   649,   375,   451,   379,   453,   616,   383,   455,   617,
     650,   387,   457,   618,   651,   395,   458,   619,   652,   674,
     684,   397,   459,   372,   448,   376,   450,   380,   452,   384,
     454,   388,   456
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -211
static const yytype_int16 yypact[] =
{
      33,  -211,    40,    52,  -211,    -7,  -211,  -211,  -211,    62,
      48,  -211,    81,  -211,  -211,  -211,    37,  -211,   152,  -211,
    -211,    -1,    -1,    30,    30,    30,    30,    30,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,    44,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,    55,  -211,  -211,
      50,    64,    -1,    63,    80,   145,  -211,  -211,  -211,  -211,
    -211,    97,    30,    30,  -211,   113,    71,   127,    55,  -211,
    -211,  -211,  -211,  -211,   879,   879,   879,   879,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,   879,   879,   879,   879,  -211,  -211,   879,   879,   879,
     879,  -211,  -211,  -211,   175,   145,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,   537,  -211,  -211,  -211,  -211,   121,  -211,
    -211,  -211,  -211,   109,    30,  -211,   111,    97,   118,   118,
     124,    21,   141,   215,   221,   120,   122,   401,   406,   419,
     421,    74,   430,   109,   439,   444,   462,   536,   538,   540,
     542,   -27,   -52,   -52,    73,   -52,   191,   191,    73,   -52,
      73,   -52,    93,   -52,    35,    73,    73,   -52,    73,   -52,
      73,   -52,   126,   551,   553,   555,   557,   191,   -52,   -52,
     -52,   -52,   -52,   191,  -211,   202,  -211,   111,    97,   118,
     118,  -211,   111,    97,   118,   118,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   118,  -211,
    -211,  -211,  -211,   128,  -211,  -211,  -211,  -211,    94,   125,
     212,   212,   537,   537,   104,   177,   -52,   210,   -52,   234,
     236,    95,   191,   101,   252,    73,   254,   -52,   258,    73,
     264,   -52,    72,   268,   -52,   271,   274,    73,   278,   -52,
     284,    73,   362,   -52,   365,    73,   367,   -52,   106,   191,
     372,   -52,   378,   -52,   395,   -52,   399,   -52,   -52,   191,
    -211,   825,   825,  -211,  -211,  -211,   111,   118,  -211,  -211,
    -211,   214,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,   124,    21,   141,   215,   221,
     120,   122,   401,   406,   419,   421,    74,   430,   109,   439,
     444,   462,   536,   538,   540,   542,   -27,   -52,   -52,    73,
     -52,   191,   191,    73,   -52,    73,   -52,    93,   -52,    35,
      73,    73,   -52,    73,   -52,    73,   -52,   126,   551,   553,
     555,   557,   191,   -52,   -52,   -52,   -52,   -52,  -211,  -211,
    -211,  -211,   118,   -52,   -52,   191,    73,   -52,    73,   -52,
     -52,    73,   -52,    73,   -52,   191,   -52,   -52,   -52,   -52,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   -52,  -211,
      73,   -52,    73,   -52,   -52,  -211,  -211,    73,   -52,   191,
     -52,   -52,   -52,  -211,   -13,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,    73,   -52,
      73,   -52,  -211,  -211,   -52,  -211,  -211,  -211,  -211,  -211,
      73,   -52,    73,   -52,   -52,  -211,  -211,  -211,  -211,  -211,
      73,   -52,    73,   -52,  -211,  -211,  -211,  -211,    73,   -52,
      73,   -52,  -211,  -211,  -211,  -211,    73,   -52,    73,   -52,
    -211,  -211,  -211,  -211,    73,   -52,  -211,  -211,    73,   -52,
    -211,  -211,    73,   -52,  -211,  -211,    73,   -52,  -211,  -211,
      73,   -52,  -211,  -211,    73,   -52,  -211,  -211,    73,   -52,
    -211,  -211
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,   -11,  -211,   -14,  -211,  -211,  -211,   163,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
     174,  -211,  -211,  -211,   178,  -211,  -211,   194,  -211,   158,
    -211,   216,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -123,  -211,  -211,  -211,  -211,  -211,  -211,  -120,  -211,  -211,
    -211,    46,    85,  -121,  -177,  -126,     2,  -129,  -141,   107,
    -182,  -200,  -199,  -211,  -211,  -198,  -211,  -211,  -211,  -197,
    -196,  -195,  -211,  -211,  -211,  -211,  -194,  -193,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -189,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -188,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -183,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -186,  -201,  -211,
    -211,  -211,  -181,  -185,  -178,  -211,  -158,  -211,  -157,  -211,
    -211,  -211,  -187,  -211,  -211,  -211,  -203,  -211,  -211,  -211,
    -211,  -168,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,   130,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -163,  -211,
    -211,  -211,  -160,  -211,  -210,  -211,  -211,  -175,  -211,  -211,
    -211,  -156,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     271,   348,   281,   349,    30,   350,   299,   351,   307,   352,
     316,   353,   360,   354,   329,   355,   337,   367,   345,   391,
     356,   271,   357,   281,   264,   265,   359,   299,   358,   307,
     362,   316,   366,   361,   236,   329,     1,   337,   363,   345,
       4,   374,   378,   382,   386,   291,   374,   378,   382,   386,
     394,   256,   259,   368,   260,   392,     5,   257,   258,   364,
     399,   365,   284,   285,   389,   404,   291,    10,   390,   666,
      43,    44,    45,    46,     7,   393,   159,   160,   161,   162,
      28,   370,    23,    24,    23,    24,   370,    16,    91,    92,
      93,    94,   396,   164,   165,   166,   167,   264,   265,   169,
     170,   171,   172,    23,    24,   266,    39,    40,    71,    72,
     246,    41,   400,   247,    73,    19,   248,   405,   401,   402,
      21,    22,    48,   406,   407,    25,    13,    26,    27,    14,
      74,    75,    76,    77,    58,    21,    22,    60,    23,    24,
      25,    56,    26,    27,    97,    98,    99,   100,    59,   274,
     275,    61,   310,    28,   310,    28,    95,   503,   311,    21,
      22,    63,    23,    24,    25,   235,    26,    27,    62,   246,
     284,   285,   247,   310,    28,   248,   284,   285,    69,   464,
     486,   284,   285,   259,   246,   260,   489,   247,   174,   474,
     248,   528,   254,   249,    78,   284,   285,   284,   285,    78,
      79,   284,   285,   259,   286,   260,   290,   241,   261,    28,
     369,   398,   101,   466,   475,   463,   477,   264,   265,   480,
     253,   467,   483,   602,   485,   270,   487,   465,    80,   490,
     403,   492,   506,    28,   478,   271,   481,   495,   281,    81,
     498,   523,   535,    82,   299,   496,   504,   501,   307,   502,
     509,   316,   507,   264,   265,   520,   329,   515,   511,    83,
     337,   521,   476,   175,   345,   527,   284,   285,   374,   533,
     378,   536,   382,   539,   386,   542,   543,   460,   526,   538,
     514,   488,   291,   517,   103,   529,   264,   265,   469,   600,
     532,   274,   275,   473,   295,   479,   303,   264,   265,   276,
     541,   321,   325,   252,   333,   280,   341,   370,   530,     0,
     274,   275,   264,   265,     0,   295,     0,   303,   544,   482,
       0,   484,   321,   325,     0,   333,     0,   341,   274,   275,
     264,   265,   598,   599,   274,   275,     0,   491,     0,   494,
     264,   265,     0,   497,   264,   265,   601,   274,   275,   500,
     274,   275,     0,   505,   264,   265,   508,     0,     0,   510,
     274,   275,     0,   513,     0,   271,   348,   281,   349,   516,
     350,   299,   351,   307,   352,   316,   353,   360,   354,   329,
     355,   337,   367,   345,   391,   356,   271,   357,   281,    30,
       0,   359,   299,   358,   307,   362,   316,   366,   361,     0,
     329,     0,   337,   363,   345,     0,   374,   378,   382,   386,
     291,   374,   378,   382,   386,   394,     0,     0,   368,     0,
     392,   621,   622,     0,   364,   625,   365,   627,   628,   389,
     630,   291,   632,   390,   634,   635,   636,   637,   264,   265,
     393,   274,   275,   264,   265,     0,   370,   519,   264,   265,
     522,   370,   525,     0,   264,   265,   653,   531,     0,   656,
       0,   658,   659,   534,   623,     0,   661,     0,   663,   664,
     665,   264,   265,     0,   633,   264,   265,   274,   275,     0,
     537,   620,   264,   265,   540,   294,     0,   676,     0,   678,
     298,     0,   679,     0,     0,   274,   275,   264,   265,   686,
       0,   688,   689,   302,     0,   306,   264,   265,   662,   695,
       0,   697,     0,   667,   315,   274,   275,   703,     0,   705,
     274,   275,     0,   320,     0,   711,     0,   713,   324,     0,
       0,   295,   493,   717,     0,   303,   499,   721,   264,   265,
       0,   725,   321,   325,   512,   729,   328,   333,   518,   733,
       0,   341,   524,   737,     0,     0,     0,   741,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   274,   275,   264,   265,   274,   275,   264,   265,
     332,     0,   336,     0,   340,     0,   344,   264,   265,   264,
     265,   264,   265,   264,   265,   373,     0,   377,     0,   381,
       0,   385,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,   303,     0,     0,     0,     0,   321,   325,     0,   333,
       0,   341,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,   303,     0,     0,     0,     0,   321,   325,     0,
     333,     0,   341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   624,     0,   626,     0,     0,   629,     0,
     631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   655,     0,   657,
       0,     0,     0,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   675,     0,   677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   685,     0,   687,
       0,     0,     0,     0,     0,     0,     0,   694,     0,   696,
       0,     0,     0,     0,     0,   702,     0,   704,     0,     0,
       0,     0,     0,   710,     0,   712,     0,     0,     0,     0,
       0,   716,     0,     0,     0,   720,     0,     0,     0,   724,
       0,     0,     0,   728,     0,     0,     0,   732,     0,     0,
       0,   736,     0,     0,     0,   740,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   233,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158
};

static const yytype_int16 yycheck[] =
{
     182,   201,   184,   202,    18,   203,   188,   204,   190,   205,
     192,   206,   213,   207,   196,   208,   198,   220,   200,   229,
     209,   203,   210,   205,    76,    77,   212,   209,   211,   211,
     215,   213,   219,   214,   163,   217,     3,   219,   216,   221,
       0,   223,   224,   225,   226,   186,   228,   229,   230,   231,
     232,   177,    79,   221,    81,   230,     4,   178,   179,   217,
     237,   218,    75,    76,   227,   242,   207,     5,   228,    82,
      24,    25,    26,    27,    81,   231,    74,    75,    76,    77,
      81,   222,    10,    11,    10,    11,   227,     6,    17,    18,
      19,    20,   233,    91,    92,    93,    94,    76,    77,    97,
      98,    99,   100,    10,    11,    84,    21,    22,    62,    63,
      75,    81,   238,    78,     1,    78,    81,   243,   239,   240,
       7,     8,    78,   244,   245,    12,    78,    14,    15,    81,
      17,    18,    19,    20,    84,     7,     8,    52,    10,    11,
      12,    86,    14,    15,    17,    18,    19,    20,    84,    76,
      77,    88,    80,    81,    80,    81,    85,    85,    84,     7,
       8,    16,    10,    11,    12,   163,    14,    15,    88,    75,
      75,    76,    78,    80,    81,    81,    75,    76,    81,    85,
      85,    75,    76,    79,    75,    81,    85,    78,    13,    85,
      81,    85,    81,    84,    81,    75,    76,    75,    76,    81,
      87,    75,    76,    79,    84,    81,    84,    86,    84,    81,
      84,     9,    85,    88,   414,    87,   415,    76,    77,   417,
     174,     9,   419,     9,   420,    84,   421,   408,    65,   423,
     241,   424,   433,    81,   416,   417,   418,   426,   420,    65,
     428,   444,   452,    65,   426,   427,   432,   430,   430,   431,
     435,   433,   434,    76,    77,   442,   438,   439,   436,    65,
     442,   443,    85,   105,   446,   447,    75,    76,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   398,   446,   454,
     438,   422,   423,   440,    68,   448,    76,    77,   411,   466,
     450,    76,    77,   413,   187,    85,   189,    76,    77,    84,
     456,   194,   195,   173,   197,    84,   199,   448,   449,    -1,
      76,    77,    76,    77,    -1,   208,    -1,   210,   459,    85,
      -1,    85,   215,   216,    -1,   218,    -1,   220,    76,    77,
      76,    77,   461,   462,    76,    77,    -1,    85,    -1,    85,
      76,    77,    -1,    85,    76,    77,   467,    76,    77,    85,
      76,    77,    -1,    85,    76,    77,    85,    -1,    -1,    85,
      76,    77,    -1,    85,    -1,   547,   566,   549,   567,    85,
     568,   553,   569,   555,   570,   557,   571,   578,   572,   561,
     573,   563,   585,   565,   594,   574,   568,   575,   570,   403,
      -1,   577,   574,   576,   576,   580,   578,   584,   579,    -1,
     582,    -1,   584,   581,   586,    -1,   588,   589,   590,   591,
     551,   593,   594,   595,   596,   597,    -1,    -1,   586,    -1,
     595,   603,   604,    -1,   582,   607,   583,   609,   610,   592,
     612,   572,   614,   593,   616,   617,   618,   619,    76,    77,
     596,    76,    77,    76,    77,    -1,   587,    85,    76,    77,
      85,   592,    85,    -1,    76,    77,   638,    85,    -1,   641,
      -1,   643,   644,    85,   605,    -1,   648,    -1,   650,   651,
     652,    76,    77,    -1,   615,    76,    77,    76,    77,    -1,
      85,   602,    76,    77,    85,    84,    -1,   669,    -1,   671,
      84,    -1,   674,    -1,    -1,    76,    77,    76,    77,   681,
      -1,   683,   684,    84,    -1,    84,    76,    77,   649,   691,
      -1,   693,    -1,   654,    84,    76,    77,   699,    -1,   701,
      76,    77,    -1,    84,    -1,   707,    -1,   709,    84,    -1,
      -1,   424,   425,   715,    -1,   428,   429,   719,    76,    77,
      -1,   723,   435,   436,   437,   727,    84,   440,   441,   731,
      -1,   444,   445,   735,    -1,    -1,    -1,   739,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    76,    77,    76,    77,    76,    77,    76,    77,
      84,    -1,    84,    -1,    84,    -1,    84,    76,    77,    76,
      77,    76,    77,    76,    77,    84,    -1,    84,    -1,    84,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   552,
      -1,   554,    -1,    -1,    -1,    -1,   559,   560,    -1,   562,
      -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     573,    -1,   575,    -1,    -1,    -1,    -1,   580,   581,    -1,
     583,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   606,    -1,   608,    -1,    -1,   611,    -1,
     613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,    -1,   642,
      -1,    -1,    -1,    -1,   647,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   668,    -1,   670,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,    -1,   682,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   690,    -1,   692,
      -1,    -1,    -1,    -1,    -1,   698,    -1,   700,    -1,    -1,
      -1,    -1,    -1,   706,    -1,   708,    -1,    -1,    -1,    -1,
      -1,   714,    -1,    -1,    -1,   718,    -1,    -1,    -1,   722,
      -1,    -1,    -1,   726,    -1,    -1,    -1,   730,    -1,    -1,
      -1,   734,    -1,    -1,    -1,   738,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,    90,    91,     0,     4,    92,    81,    93,    94,
       5,    95,    97,    78,    81,    96,     6,    98,   102,    78,
     100,     7,     8,    10,    11,    12,    14,    15,    81,   103,
     104,   108,   109,   120,   129,   133,   136,   161,    99,   161,
     161,    81,   160,   160,   160,   160,   160,   105,    78,   101,
     110,   121,   106,   130,   134,   137,    86,   140,    84,    84,
     161,    88,    88,    16,   138,   141,   112,   123,   107,    81,
     164,   160,   160,     1,    17,    18,    19,    20,    81,    87,
     108,   129,   133,   136,   142,   143,   146,   150,   153,   157,
     162,    17,    18,    19,    20,    85,   113,    17,    18,    19,
      20,    85,   124,   140,   131,   135,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   165,
     165,   165,   165,   158,   165,   165,   165,   165,   111,   165,
     165,   165,   165,   122,    13,   138,   144,   147,   154,   151,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   159,   165,   166,   114,   115,   118,
     116,    86,   125,   126,   128,   127,    75,    78,    81,    84,
     139,   241,   291,   160,    81,   163,   164,   162,   162,    79,
      81,    84,   170,   265,    76,    77,    84,   169,   171,   267,
      84,   169,   174,   269,    76,    77,    84,   168,   178,   271,
      84,   169,   179,   273,    75,    76,    84,   167,   180,   275,
      84,   167,   185,   277,    84,   168,   186,   279,    84,   169,
     195,   281,    84,   168,   204,   283,    84,   169,   220,   285,
      80,    84,   104,   236,   287,    84,   169,   237,   289,   291,
      84,   168,   242,   293,    84,   168,   243,   295,    84,   169,
     245,   297,    84,   168,   247,   299,    84,   169,   251,   301,
      84,   168,   255,   303,    84,   169,   260,   305,   170,   171,
     174,   178,   179,   180,   185,   186,   195,   204,   220,   236,
     237,   241,   242,   243,   245,   247,   251,   255,   260,    84,
     167,   307,   332,    84,   169,   311,   334,    84,   169,   313,
     336,    84,   169,   316,   338,    84,   169,   320,   340,   307,
     311,   313,   316,   320,   169,   324,   167,   330,     9,   163,
     164,   162,   162,   102,   163,   164,   162,   162,   292,   132,
     145,   148,   155,   152,   266,   268,   172,   270,   175,   272,
     274,   276,   181,   278,   280,   187,   282,   196,   284,   205,
     286,   221,   288,   290,   238,   294,   296,   244,   298,   246,
     300,   248,   302,   252,   304,   256,   306,   261,   333,   308,
     335,   312,   337,   314,   339,   317,   341,   321,   325,   331,
     162,   119,   117,    87,    85,   241,    88,     9,   149,   149,
     156,   165,   166,   156,    85,   170,    85,   171,   169,    85,
     174,   169,    85,   178,    85,   179,    85,   180,   167,    85,
     185,    85,   186,   168,    85,   195,   169,    85,   204,   168,
      85,   220,   169,    85,   236,    85,   237,   169,    85,   242,
      85,   243,   168,    85,   245,   169,    85,   247,   168,    85,
     251,   169,    85,   255,   168,    85,   260,   169,    85,   307,
     167,    85,   311,   169,    85,   313,   169,    85,   316,   169,
      85,   320,   169,   169,   167,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   166,   166,
     163,   162,     9,   173,   176,   182,   188,   197,   206,   222,
     239,   249,   253,   257,   262,   309,   315,   318,   322,   326,
     162,   169,   169,   167,   168,   169,   168,   169,   169,   168,
     169,   168,   169,   167,   169,   169,   169,   169,   177,   183,
     189,   198,   207,   223,   240,   250,   254,   258,   263,   310,
     319,   323,   327,   169,   184,   168,   169,   168,   169,   169,
     168,   169,   167,   169,   169,   169,    82,   167,   190,   199,
     208,   224,   259,   264,   328,   168,   169,   168,   169,   169,
     191,   200,   209,   225,   329,   168,   169,   168,   169,   169,
     192,   201,   210,   226,   168,   169,   168,   169,   193,   202,
     211,   227,   168,   169,   168,   169,   194,   203,   212,   228,
     168,   169,   168,   169,   213,   229,   168,   169,   214,   230,
     168,   169,   215,   231,   168,   169,   216,   232,   168,   169,
     217,   233,   168,   169,   218,   234,   168,   169,   219,   235,
     168,   169
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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






/*----------.
| yyparse.  |
`----------*/

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	  static_cast<union yyalloc *>( YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize)));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 3:
#line 204 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->verifyHeader((yyvsp[(1) - (1)].stringVal)); ;}
    break;

  case 5:
#line 208 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->profileElement((yyvsp[(2) - (2)].stringVal)); ;}
    break;

  case 10:
#line 222 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->componentElement((yyvsp[(2) - (2)].stringVal)); ;}
    break;

  case 15:
#line 239 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = (yyvsp[(2) - (2)].stringVal); ;}
    break;

  case 16:
#line 241 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->metaElement(SKEL->_tmpString1.c_str(), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 26:
#line 261 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginNode((yyvsp[(1) - (1)].stringVal), 0); ;}
    break;

  case 28:
#line 264 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = (yyvsp[(2) - (2)].stringVal); ;}
    break;

  case 29:
#line 265 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginNode((yyvsp[(4) - (4)].stringVal), SKEL->_tmpString1.c_str()); ;}
    break;

  case 31:
#line 268 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->use((yyvsp[(2) - (2)].stringVal)); ;}
    break;

  case 34:
#line 279 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginProto((yyvsp[(2) - (2)].stringVal)); ;}
    break;

  case 35:
#line 280 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endProtoInterface(); ;}
    break;

  case 36:
#line 281 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endProto(); ;}
    break;

  case 39:
#line 289 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 40:
#line 290 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginEventInDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); SKEL->endEventDecl(); ;}
    break;

  case 41:
#line 292 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 42:
#line 293 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginEventOutDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); SKEL->endEventDecl(); ;}
    break;

  case 43:
#line 295 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 44:
#line 296 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginFieldDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); SKEL->getLexer()->expectType((yyvsp[(2) - (4)].intVal)); ;}
    break;

  case 45:
#line 297 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endFieldDecl(); ;}
    break;

  case 46:
#line 299 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 47:
#line 300 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginExposedFieldDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); SKEL->getLexer()->expectType((yyvsp[(2) - (4)].intVal)); ;}
    break;

  case 48:
#line 301 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endExposedFieldDecl(); ;}
    break;

  case 49:
#line 304 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginExternProto((yyvsp[(2) - (2)].stringVal)); ;}
    break;

  case 50:
#line 305 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endExternProtoInterface(); ;}
    break;

  case 51:
#line 306 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endExternProto(); ;}
    break;

  case 54:
#line 314 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 55:
#line 315 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->addExternEventInDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 56:
#line 317 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 57:
#line 318 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->addExternEventOutDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 58:
#line 320 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 59:
#line 321 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->addExternFieldDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 60:
#line 323 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 61:
#line 324 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->addExternExposedFieldDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 62:
#line 328 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = (yyvsp[(2) - (2)].stringVal); ;}
    break;

  case 63:
#line 330 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString2 = (yyvsp[(5) - (5)].stringVal); ;}
    break;

  case 64:
#line 332 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString3 = (yyvsp[(8) - (8)].stringVal); ;}
    break;

  case 65:
#line 335 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->addRoute(SKEL->_tmpString1.c_str(), SKEL->_tmpString2.c_str(), SKEL->_tmpString3.c_str(), (yyvsp[(11) - (11)].stringVal)); ;}
    break;

  case 66:
#line 339 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = (yyvsp[(2) - (2)].stringVal); ;}
    break;

  case 67:
#line 341 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString2 = (yyvsp[(5) - (5)].stringVal); ;}
    break;

  case 68:
#line 343 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        if ((yyvsp[(7) - (7)].stringVal) != 0)
            SKEL->importElement(SKEL->_tmpString1.c_str(), SKEL->_tmpString2.c_str(), (yyvsp[(7) - (7)].stringVal));
        else
            SKEL->importElement(SKEL->_tmpString1.c_str(), SKEL->_tmpString2.c_str(), 0);
    ;}
    break;

  case 69:
#line 352 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = (yyvsp[(2) - (2)].stringVal); ;}
    break;

  case 70:
#line 354 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        if ((yyvsp[(4) - (4)].stringVal) != 0)
            SKEL->exportElement(SKEL->_tmpString1.c_str(), (yyvsp[(4) - (4)].stringVal));
        else
            SKEL->exportElement(SKEL->_tmpString1.c_str(), 0);
    ;}
    break;

  case 71:
#line 363 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.stringVal) = (yyvsp[(2) - (2)].stringVal); ;}
    break;

  case 72:
#line 364 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.stringVal) = 0; ;}
    break;

  case 74:
#line 370 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endNode(); ;}
    break;

  case 83:
#line 386 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 84:
#line 387 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginEventInDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 85:
#line 388 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endEventDecl(); ;}
    break;

  case 86:
#line 392 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 87:
#line 393 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginEventOutDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); ;}
    break;

  case 88:
#line 394 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endEventDecl(); ;}
    break;

  case 90:
#line 398 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->is((yyvsp[(2) - (2)].stringVal)); ;}
    break;

  case 91:
#line 402 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 92:
#line 403 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginFieldDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); SKEL->getLexer()->expectType((yyvsp[(2) - (4)].intVal)); ;}
    break;

  case 93:
#line 404 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endFieldDecl(); ;}
    break;

  case 94:
#line 408 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->_tmpString1 = SKEL->getLexer()->YYText(); ;}
    break;

  case 95:
#line 409 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginExposedFieldDecl(SKEL->_tmpString1.c_str(), (yyvsp[(2) - (4)].intVal), (yyvsp[(4) - (4)].stringVal)); SKEL->getLexer()->expectType((yyvsp[(2) - (4)].intVal)); ;}
    break;

  case 96:
#line 410 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endExposedFieldDecl(); ;}
    break;

  case 98:
#line 414 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->is((yyvsp[(3) - (3)].stringVal)); ;}
    break;

  case 99:
#line 418 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        Int32 iFieldTypeId = SKEL->getFieldType((yyvsp[(1) - (1)].stringVal));
        if (SKEL->getMapFieldTypes() == true)
            iFieldTypeId = SKEL->mapExtIntFieldType((yyvsp[(1) - (1)].stringVal), iFieldTypeId);
        SKEL->getLexer()->expectType(iFieldTypeId);
        SKEL->beginField((yyvsp[(1) - (1)].stringVal), iFieldTypeId);
    ;}
    break;

  case 100:
#line 425 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->endField(); ;}
    break;

  case 106:
#line 433 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->is((yyvsp[(3) - (3)].stringVal)); ;}
    break;

  case 219:
#line 564 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.intVal) = (yyvsp[(1) - (1)].intVal); ;}
    break;

  case 220:
#line 565 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.intVal) = (yyvsp[(1) - (1)].intVal); ;}
    break;

  case 221:
#line 568 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.doubleVal) = (yyvsp[(1) - (1)].intVal); ;}
    break;

  case 222:
#line 569 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.doubleVal) = (yyvsp[(1) - (1)].doubleVal); ;}
    break;

  case 223:
#line 572 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.floatVal) = static_cast<float>((yyvsp[(1) - (1)].intVal)); ;}
    break;

  case 224:
#line 573 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { (yyval.floatVal) = static_cast<float>((yyvsp[(1) - (1)].doubleVal)); ;}
    break;

  case 225:
#line 577 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addBoolValue((yyvsp[(1) - (1)].boolVal));
    ;}
    break;

  case 226:
#line 580 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->addFieldValue((yyvsp[(1) - (1)].stringVal)); ;}
    break;

  case 227:
#line 583 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 228:
#line 584 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 229:
#line 586 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addColorValue(Color3f((yyvsp[(1) - (5)].floatVal), (yyvsp[(3) - (5)].floatVal), (yyvsp[(5) - (5)].floatVal)));
    ;}
    break;

  case 230:
#line 592 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 231:
#line 593 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 232:
#line 594 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 233:
#line 596 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addColorRGBAValue(Color4f((yyvsp[(1) - (7)].floatVal), (yyvsp[(3) - (7)].floatVal), (yyvsp[(5) - (7)].floatVal), (yyvsp[(7) - (7)].floatVal)));
    ;}
    break;

  case 234:
#line 603 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addDoubleValue((yyvsp[(1) - (1)].doubleVal));
    ;}
    break;

  case 235:
#line 609 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addFloatValue((yyvsp[(1) - (1)].floatVal));
    ;}
    break;

  case 236:
#line 614 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 237:
#line 615 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 238:
#line 617 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->beginImage((yyvsp[(1) - (5)].intVal), (yyvsp[(3) - (5)].intVal), (yyvsp[(5) - (5)].intVal));
    ;}
    break;

  case 239:
#line 622 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->endImage();
    ;}
    break;

  case 240:
#line 628 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addImagePixel((yyvsp[(2) - (2)].intVal));
    ;}
    break;

  case 242:
#line 635 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addInt32Value((yyvsp[(1) - (1)].intVal));
    ;}
    break;

  case 243:
#line 640 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 244:
#line 641 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 245:
#line 642 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 246:
#line 643 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 247:
#line 644 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 248:
#line 645 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 249:
#line 646 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 250:
#line 647 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 251:
#line 649 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addMatrix3dValue(
            (yyvsp[(1) - (17)].doubleVal),  (yyvsp[(7) - (17)].doubleVal), (yyvsp[(13) - (17)].doubleVal),
            (yyvsp[(3) - (17)].doubleVal),  (yyvsp[(9) - (17)].doubleVal), (yyvsp[(15) - (17)].doubleVal),
            (yyvsp[(5) - (17)].doubleVal), (yyvsp[(11) - (17)].doubleVal), (yyvsp[(17) - (17)].doubleVal));
    ;}
    break;

  case 252:
#line 658 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 253:
#line 659 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 254:
#line 660 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 255:
#line 661 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 256:
#line 662 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 257:
#line 663 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 258:
#line 664 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 259:
#line 665 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 260:
#line 667 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addMatrix3fValue(
            (yyvsp[(1) - (17)].floatVal),  (yyvsp[(7) - (17)].floatVal), (yyvsp[(13) - (17)].floatVal),
            (yyvsp[(3) - (17)].floatVal),  (yyvsp[(9) - (17)].floatVal), (yyvsp[(15) - (17)].floatVal),
            (yyvsp[(5) - (17)].floatVal), (yyvsp[(11) - (17)].floatVal), (yyvsp[(17) - (17)].floatVal));
    ;}
    break;

  case 261:
#line 676 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 262:
#line 677 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 263:
#line 678 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 264:
#line 679 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 265:
#line 680 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 266:
#line 681 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 267:
#line 682 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 268:
#line 683 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 269:
#line 684 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 270:
#line 685 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 271:
#line 686 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 272:
#line 687 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 273:
#line 688 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 274:
#line 689 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 275:
#line 690 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 276:
#line 692 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addMatrix4dValue(Matrix4d(
            (yyvsp[(1) - (31)].doubleVal),  (yyvsp[(9) - (31)].doubleVal), (yyvsp[(17) - (31)].doubleVal), (yyvsp[(25) - (31)].doubleVal),
            (yyvsp[(3) - (31)].doubleVal), (yyvsp[(11) - (31)].doubleVal), (yyvsp[(19) - (31)].doubleVal), (yyvsp[(27) - (31)].doubleVal),
            (yyvsp[(5) - (31)].doubleVal), (yyvsp[(13) - (31)].doubleVal), (yyvsp[(21) - (31)].doubleVal), (yyvsp[(29) - (31)].doubleVal),
            (yyvsp[(7) - (31)].doubleVal), (yyvsp[(15) - (31)].doubleVal), (yyvsp[(23) - (31)].doubleVal), (yyvsp[(31) - (31)].doubleVal)));
    ;}
    break;

  case 277:
#line 702 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 278:
#line 703 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 279:
#line 704 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 280:
#line 705 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 281:
#line 706 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 282:
#line 707 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 283:
#line 708 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 284:
#line 709 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 285:
#line 710 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 286:
#line 711 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 287:
#line 712 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 288:
#line 713 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 289:
#line 714 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 290:
#line 715 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 291:
#line 716 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 292:
#line 718 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addMatrix4fValue(Matrix4f(
            (yyvsp[(1) - (31)].floatVal),  (yyvsp[(9) - (31)].floatVal), (yyvsp[(17) - (31)].floatVal), (yyvsp[(25) - (31)].floatVal),
            (yyvsp[(3) - (31)].floatVal), (yyvsp[(11) - (31)].floatVal), (yyvsp[(19) - (31)].floatVal), (yyvsp[(27) - (31)].floatVal),
            (yyvsp[(5) - (31)].floatVal), (yyvsp[(13) - (31)].floatVal), (yyvsp[(21) - (31)].floatVal), (yyvsp[(29) - (31)].floatVal),
            (yyvsp[(7) - (31)].floatVal), (yyvsp[(15) - (31)].floatVal), (yyvsp[(23) - (31)].floatVal), (yyvsp[(31) - (31)].floatVal)));
    ;}
    break;

  case 294:
#line 729 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->nullNode(); ;}
    break;

  case 295:
#line 732 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 296:
#line 733 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 297:
#line 734 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 298:
#line 736 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addRotationValue(Vec3f((yyvsp[(1) - (7)].floatVal), (yyvsp[(3) - (7)].floatVal), (yyvsp[(5) - (7)].floatVal)), (yyvsp[(7) - (7)].floatVal));
    ;}
    break;

  case 299:
#line 743 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addStringValue((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 300:
#line 747 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { /* Not VRML conformant */
        SKEL->addStringValue((yyvsp[(1) - (1)].stringVal));
    ;}
    break;

  case 301:
#line 751 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { /* Not VRML conformant */
        SKEL->addBufferAsStringValue();
    ;}
    break;

  case 302:
#line 757 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->addTimeValue((yyvsp[(1) - (1)].doubleVal));
    ;}
    break;

  case 303:
#line 762 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 304:
#line 764 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec2dValue(Vec2d((yyvsp[(1) - (3)].doubleVal), (yyvsp[(3) - (3)].doubleVal)));
    ;}
    break;

  case 305:
#line 770 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 306:
#line 772 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec2fValue(Vec2f((yyvsp[(1) - (3)].floatVal), (yyvsp[(3) - (3)].floatVal)));
    ;}
    break;

  case 307:
#line 778 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 308:
#line 779 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 309:
#line 780 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 310:
#line 781 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec3dValue(Vec3d((yyvsp[(1) - (6)].doubleVal), (yyvsp[(3) - (6)].doubleVal), (yyvsp[(5) - (6)].doubleVal)));
    ;}
    break;

  case 311:
#line 787 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 312:
#line 788 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 313:
#line 789 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 314:
#line 790 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec3fValue(Vec3f((yyvsp[(1) - (6)].floatVal), (yyvsp[(3) - (6)].floatVal), (yyvsp[(5) - (6)].floatVal)));
    ;}
    break;

  case 315:
#line 796 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 316:
#line 797 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 317:
#line 798 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 318:
#line 799 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 319:
#line 800 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec4dValue(Vec4d((yyvsp[(1) - (8)].doubleVal), (yyvsp[(3) - (8)].doubleVal), (yyvsp[(5) - (8)].doubleVal), (yyvsp[(7) - (8)].doubleVal)));
    ;}
    break;

  case 320:
#line 806 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 321:
#line 807 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 322:
#line 808 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 323:
#line 809 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 324:
#line 810 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec4fValue(Vec4f((yyvsp[(1) - (8)].floatVal), (yyvsp[(3) - (8)].floatVal), (yyvsp[(5) - (8)].floatVal), (yyvsp[(7) - (8)].floatVal)));
    ;}
    break;

  case 409:
#line 986 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 410:
#line 987 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 411:
#line 988 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 412:
#line 990 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addColor4iValue(Color4ub(static_cast<UInt8>((yyvsp[(1) - (7)].intVal)), static_cast<UInt8>((yyvsp[(3) - (7)].intVal)),
                                       static_cast<UInt8>((yyvsp[(5) - (7)].intVal)), static_cast<UInt8>((yyvsp[(7) - (7)].intVal))));
    ;}
    break;

  case 413:
#line 997 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 414:
#line 999 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addPnt2fValue(Pnt2f((yyvsp[(1) - (3)].floatVal), (yyvsp[(3) - (3)].floatVal)));
    ;}
    break;

  case 415:
#line 1005 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 416:
#line 1006 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 417:
#line 1008 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addPnt3fValue(Pnt3f((yyvsp[(1) - (5)].floatVal), (yyvsp[(3) - (5)].floatVal), (yyvsp[(5) - (5)].floatVal)));
    ;}
    break;

  case 418:
#line 1014 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 419:
#line 1015 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 420:
#line 1016 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 421:
#line 1018 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addPnt4fValue(Pnt4f((yyvsp[(1) - (7)].floatVal), (yyvsp[(3) - (7)].floatVal), (yyvsp[(5) - (7)].floatVal), (yyvsp[(7) - (7)].floatVal)));
    ;}
    break;

  case 422:
#line 1024 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 423:
#line 1025 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 424:
#line 1026 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 425:
#line 1028 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addPlaneValue(Plane(Vec3f((yyvsp[(1) - (7)].floatVal), (yyvsp[(3) - (7)].floatVal), (yyvsp[(5) - (7)].floatVal)), (yyvsp[(7) - (7)].floatVal)));
    ;}
    break;

  case 426:
#line 1034 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 427:
#line 1035 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 428:
#line 1036 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 429:
#line 1037 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 430:
#line 1038 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->appendValue(); ;}
    break;

  case 431:
#line 1040 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        BoxVolume bv((yyvsp[(1) - (11)].floatVal), (yyvsp[(3) - (11)].floatVal), (yyvsp[(5) - (11)].floatVal), (yyvsp[(7) - (11)].floatVal), (yyvsp[(9) - (11)].floatVal), (yyvsp[(11) - (11)].floatVal));
        
        SKEL->addVolumeValue(bv);
    ;}
    break;

  case 432:
#line 1048 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    { SKEL->beginValue(); ;}
    break;

  case 433:
#line 1050 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"
    {
        SKEL->appendValue();
        SKEL->addVec2iValue(Vec2i((yyvsp[(1) - (3)].intVal), (yyvsp[(3) - (3)].intVal)));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3410 "build.linux.g++/type-debug--arch-x64/Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.cpp"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 1095 "Source/System/FileIO/ScanParseSkel/OSGScanParseSkelParser.yy"


int OSGScanParseSkel_lex(YYSTYPE *lvalp, void *pSkel)
{
    return SKEL->lex(lvalp);
}

