/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "../frontend/IT.y" /* yacc.c:339  */

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "src/lex/scanner.h" // for yylex
#include "src/yacc/parser.h"
#include "src/common/errors.h"
#include "../common-libs/utils/utility.h"

void yyerror(const char *msg); // standard error-handling routine

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Program = 258,
    Tuple = 259,
    Task = 260,
    Function = 261,
    Coordinator = 262,
    New = 263,
    Execute = 264,
    S_Define = 265,
    S_Environment = 266,
    S_Initialize = 267,
    S_Stages = 268,
    S_Computation = 269,
    S_Partition = 270,
    T_Integer = 271,
    T_Character = 272,
    T_Real = 273,
    T_Boolean = 274,
    T_String = 275,
    T_Index = 276,
    T_Range = 277,
    T_Array = 278,
    T_List = 279,
    Of = 280,
    Single = 281,
    Double = 282,
    Format = 283,
    Reduction = 284,
    T_Space = 285,
    Repeat = 286,
    Epoch = 287,
    Where = 288,
    For = 289,
    Foreach = 290,
    While = 291,
    C_Sub_Partition = 292,
    In = 293,
    Step = 294,
    Current = 295,
    If = 296,
    Else = 297,
    Range = 298,
    Local = 299,
    Index = 300,
    Do = 301,
    Sequence = 302,
    Reduce = 303,
    Return = 304,
    Extern = 305,
    Language = 306,
    Header_Includes = 307,
    Library_Links = 308,
    Link = 309,
    Create = 310,
    Link_or_Create = 311,
    Dynamic = 312,
    P_Sub_Partition = 313,
    Ordered = 314,
    Unordered = 315,
    Replicated = 316,
    Padding = 317,
    Relative_To = 318,
    Divides = 319,
    Sub_Partitions = 320,
    Partitions = 321,
    Unpartitioned = 322,
    Ascends = 323,
    Descends = 324,
    New_Line = 325,
    Integer = 326,
    Dimensionality = 327,
    Dimension_No = 328,
    V_Dimension = 329,
    Character = 330,
    Space_ID = 331,
    Real_Single = 332,
    Real_Double = 333,
    Boolean = 334,
    Type_Name = 335,
    Variable_Name = 336,
    String = 337,
    Native_Code = 338,
    O_OR = 339,
    O_AND = 340,
    O_EQ = 341,
    O_NE = 342,
    O_LTE = 343,
    O_GTE = 344,
    O_SB_RANGE = 345,
    O_LSH = 346,
    O_RSH = 347,
    O_POWER = 348,
    At = 349,
    Field = 350
  };
#endif
/* Tokens.  */
#define Program 258
#define Tuple 259
#define Task 260
#define Function 261
#define Coordinator 262
#define New 263
#define Execute 264
#define S_Define 265
#define S_Environment 266
#define S_Initialize 267
#define S_Stages 268
#define S_Computation 269
#define S_Partition 270
#define T_Integer 271
#define T_Character 272
#define T_Real 273
#define T_Boolean 274
#define T_String 275
#define T_Index 276
#define T_Range 277
#define T_Array 278
#define T_List 279
#define Of 280
#define Single 281
#define Double 282
#define Format 283
#define Reduction 284
#define T_Space 285
#define Repeat 286
#define Epoch 287
#define Where 288
#define For 289
#define Foreach 290
#define While 291
#define C_Sub_Partition 292
#define In 293
#define Step 294
#define Current 295
#define If 296
#define Else 297
#define Range 298
#define Local 299
#define Index 300
#define Do 301
#define Sequence 302
#define Reduce 303
#define Return 304
#define Extern 305
#define Language 306
#define Header_Includes 307
#define Library_Links 308
#define Link 309
#define Create 310
#define Link_or_Create 311
#define Dynamic 312
#define P_Sub_Partition 313
#define Ordered 314
#define Unordered 315
#define Replicated 316
#define Padding 317
#define Relative_To 318
#define Divides 319
#define Sub_Partitions 320
#define Partitions 321
#define Unpartitioned 322
#define Ascends 323
#define Descends 324
#define New_Line 325
#define Integer 326
#define Dimensionality 327
#define Dimension_No 328
#define V_Dimension 329
#define Character 330
#define Space_ID 331
#define Real_Single 332
#define Real_Double 333
#define Boolean 334
#define Type_Name 335
#define Variable_Name 336
#define String 337
#define Native_Code 338
#define O_OR 339
#define O_AND 340
#define O_EQ 341
#define O_NE 342
#define O_LTE 343
#define O_GTE 344
#define O_SB_RANGE 345
#define O_LSH 346
#define O_RSH 347
#define O_POWER 348
#define At 349
#define Field 350

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "../frontend/IT.y" /* yacc.c:355  */

        int 				intConstant;
        bool 				booleanConstant;
	float				floatConstant;
        double 				doubleConstant;
	char				characterConstant;
	char 				*stringConstant;

	VariableDef 			*var;
	List<VariableDef*>		*varList;
	CoordinatorDef			*coordinator;
	ProgramDef			*program;
	TaskDef 			*task;
	FunctionArg			*fnArg;
	List<FunctionArg*>		*fnArgList;
	FunctionDef			*fn;
	TupleDef			*tuple;	
	
	Node				*node;
	List<Node*>			*nodeList;
	Identifier			*id;
	List<Identifier*>		*idList;
	List<int>			*intList;
	List<const char*>		*strList;

	Type				*type;
	NamedType			*nType;
	ArrayType			*aType;
	ListType			*lType;

	Expr				*expr;
	NamedArgument			*namedArg;
	List<NamedArgument*>		*namedArgList;
	NamedMultiArgument		*namedMultArg;
	List<NamedMultiArgument*>	*namedMultArgList;
	List<Expr*>			*exprList;
	Stmt				*stmt;
	List<Stmt*>			*stmtList;
	ConditionalStmt			*condStmt;
	List<ConditionalStmt*>		*condStmtList;
	IndexRangeCondition		*rangeCond;
	SLoopAttribute                  *sloopAttr;
	List<IndexRangeCondition*>	*rangeCondList;

	DefineSection			*defineSection;	
	InitializeSection 		*initSection;
	LinkageType			linkageType;
	List<EnvironmentLink*>		*envLinks;
	EnvironmentSection		*envSection;
	StageDefinition			*stageDef;
	List<StageDefinition*>		*stageDefList;
	StagesSection			*stagesSection;

	RepeatControl			*repeatControl;
	FlowPart			*flowPart;
	List<FlowPart*>			*flowPartList;
	ComputationSection		*computeSection;

	PartitionOrder			order;
	PartitionInstr			*pInstr;
	List<PartitionInstr*>		*pInstrList;
	PartitionArg			*pArg;
	List<PartitionArg*>		*pArgList;
	SpaceLinkage			*sLink;
	List<IntConstant*>		*iConList;
	VarDimensions			*vDims;
	List<VarDimensions*>		*vDimsList;
	List<DataConfigurationSpec*>	*dConSpecList;
	SubpartitionSpec		*subPartSpec;
	PartitionSpec			*partSpec;
	List<PartitionSpec*>		*partSpecList;
	PartitionSection		*partitionSection;

#line 385 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 414 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   843

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  245
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  503

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   350

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   106,     2,     2,     2,   102,    90,     2,
     111,   114,   103,   100,    84,   101,   109,   104,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   112,   117,
      93,    85,    94,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   110,     2,   113,    89,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,    88,   116,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    86,
      87,    91,    92,    95,    96,    97,    98,    99,   105,   107,
     108
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   249,   249,   254,   255,   256,   257,   258,   259,   262,
     263,   264,   265,   266,   267,   268,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   282,   283,   287,
     298,   299,   300,   301,   302,   303,   307,   307,   308,   309,
     311,   311,   315,   316,   317,   318,   319,   320,   321,   325,
     326,   327,   328,   331,   332,   333,   335,   334,   339,   339,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   351,
     353,   354,   355,   356,   358,   359,   362,   363,   364,   365,
     367,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   388,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     414,   414,   415,   416,   417,   418,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   429,   431,   432,   433,
     434,   435,   436,   437,   438,   440,   441,   442,   446,   447,
     448,   449,   450,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   521,   521,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   539,   539,
     542,   543,   544,   545,   546,   549,   553,   554,   554,   556,
     557,   558,   559,   559,   561,   562
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Program", "Tuple", "Task", "Function",
  "Coordinator", "New", "Execute", "S_Define", "S_Environment",
  "S_Initialize", "S_Stages", "S_Computation", "S_Partition", "T_Integer",
  "T_Character", "T_Real", "T_Boolean", "T_String", "T_Index", "T_Range",
  "T_Array", "T_List", "Of", "Single", "Double", "Format", "Reduction",
  "T_Space", "Repeat", "Epoch", "Where", "For", "Foreach", "While",
  "C_Sub_Partition", "In", "Step", "Current", "If", "Else", "Range",
  "Local", "Index", "Do", "Sequence", "Reduce", "Return", "Extern",
  "Language", "Header_Includes", "Library_Links", "Link", "Create",
  "Link_or_Create", "Dynamic", "P_Sub_Partition", "Ordered", "Unordered",
  "Replicated", "Padding", "Relative_To", "Divides", "Sub_Partitions",
  "Partitions", "Unpartitioned", "Ascends", "Descends", "New_Line",
  "Integer", "Dimensionality", "Dimension_No", "V_Dimension", "Character",
  "Space_ID", "Real_Single", "Real_Double", "Boolean", "Type_Name",
  "Variable_Name", "String", "Native_Code", "','", "'='", "O_OR", "O_AND",
  "'|'", "'^'", "'&'", "O_EQ", "O_NE", "'<'", "'>'", "O_LTE", "O_GTE",
  "O_SB_RANGE", "O_LSH", "O_RSH", "'+'", "'-'", "'%'", "'*'", "'/'",
  "O_POWER", "'!'", "At", "Field", "'.'", "'['", "'('", "':'", "']'",
  "')'", "'{'", "'}'", "';'", "$accept", "program", "components",
  "component", "tuple", "element_defs", "element_def", "names",
  "static_type", "scalar_type", "numeric_type", "static_array",
  "static_dims", "task", "define", "definitions", "definition",
  "dynamic_type", "list", "dynamic_array", "format", "environment",
  "linkages", "linkage", "mode", "initialize", "arguments", "stages",
  "stage_list", "compute_stage", "$@1", "computation", "$@2",
  "compute_flow", "flow_part", "lps_transition", "repeat_cycle",
  "repeat_control", "condition_block", "epoch_block", "stage_invoke",
  "partition", "partition_specs", "partition_spec", "dynamic", "divides",
  "main_dist", "data_spec", "var_list", "var", "dimensions", "instr_list",
  "instr", "partition_args", "partition_arg", "relativity", "sub_dist",
  "nature", "data_sub_dist", "data_sub_spec", "ordered_instr_list",
  "ordered_instr", "order", "code", "$@3", "stmt_block", "new_lines",
  "stmt", "return_stmt", "reduction", "sequencial_loop", "sloop_attr",
  "parallel_loop", "index_ranges", "index_range", "restrictions",
  "if_else_block", "else_block", "else", "else_if", "step_expr", "expr",
  "constant", "field", "array_index", "function_call", "arg", "args",
  "epoch_lag", "id", "coordinator", "$@4", "meta_code", "create_obj",
  "obj_args", "named_args", "named_arg", "task_invocation", "multi_args",
  "multi_arg", "invoke_args", "function", "$@5", "function_args",
  "function_arg", "extern_block", "header_includes", "$@6", "includes",
  "extern_links", "$@7", "library_links", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     335,   336,   337,   338,    44,    61,   339,   340,   124,    94,
      38,   341,   342,    60,    62,   343,   344,   345,   346,   347,
      43,    45,    37,    42,    47,   348,    33,   349,   350,    46,
      91,    40,    58,    93,    41,   123,   125,    59
};
# endif

#define YYPACT_NINF -407

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-407)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     278,  -407,   -40,   -38,  -407,   122,   278,  -407,  -407,  -407,
    -407,  -407,    23,    37,    60,   119,  -407,  -407,   125,   129,
     174,   118,   111,  -407,   129,  -407,   -36,   123,   222,    87,
     130,  -407,   155,   199,   129,   132,   226,  -407,   166,   -49,
    -407,    65,  -407,  -407,  -407,   182,  -407,  -407,  -407,   139,
    -407,  -407,  -407,  -407,  -407,    33,   129,  -407,   129,   141,
     245,  -407,    87,   151,   352,   177,   178,  -407,  -407,  -407,
      -8,   179,   285,   153,  -407,  -407,  -407,  -407,  -407,  -407,
     180,  -407,   103,   285,   285,   285,  -407,   202,  -407,  -407,
    -407,  -407,  -407,   614,  -407,   114,  -407,  -407,   160,  -407,
    -407,  -407,  -407,  -407,   225,    -5,   352,  -407,    36,   129,
    -407,   129,   183,   186,  -407,  -407,  -407,   274,   277,   192,
    -407,  -407,  -407,   228,   285,   263,    65,   230,   614,   261,
     196,  -407,  -407,  -407,   207,   568,   419,   202,    65,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   205,
     -11,   242,  -407,   209,   361,   254,  -407,   297,  -407,   136,
    -407,   -46,  -407,   246,   316,   318,   218,    65,   199,   310,
     255,   229,    10,  -407,   449,   223,   221,   258,   262,   269,
     614,  -407,   -43,   285,  -407,  -407,  -407,   614,   635,   655,
     674,   692,   709,   724,   724,   734,   734,   734,   734,   326,
     326,   157,   157,   207,   207,   207,   207,   307,  -407,  -407,
    -407,   591,   236,  -407,  -407,   237,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,   244,   246,  -407,   141,  -407,   247,  -407,
    -407,  -407,   199,   249,   243,   255,  -407,   285,  -407,   228,
     250,    65,   165,   291,   202,   272,   196,  -407,   539,   284,
     273,   285,  -407,  -407,   129,  -407,   276,   -22,   362,   285,
    -407,  -407,   614,   305,  -407,    65,   281,   129,   285,   308,
     341,   313,  -407,  -407,   327,  -407,   614,    49,   369,   336,
     161,   306,   285,   312,   -22,  -407,  -407,  -407,  -407,  -407,
    -407,   345,  -407,   614,   285,   319,   400,   -23,   320,  -407,
     614,   285,  -407,   383,  -407,  -407,  -407,   363,   369,  -407,
     323,   359,   417,   285,   348,   -22,   357,   -31,   196,  -407,
    -407,   614,   423,   -11,   385,   129,   479,   353,  -407,   384,
     354,   377,  -407,   -22,   433,  -407,   614,   -22,   -14,   -22,
     285,    53,   -35,  -407,  -407,   423,   447,   -45,  -407,  -407,
     412,   381,   382,  -407,   116,    98,   285,   121,  -407,   126,
     388,  -407,   386,    65,  -407,   -11,   285,   426,  -407,  -407,
     -63,   418,  -407,   409,   407,   408,  -407,   315,  -407,  -407,
     -22,   285,   411,  -407,    77,   614,   429,   446,   202,  -407,
     -53,  -407,   414,   437,   285,  -407,   224,   509,  -407,   285,
    -407,  -407,  -407,  -407,   450,   202,   129,   474,   482,   614,
    -407,   440,   614,  -407,  -407,   -47,   463,   528,   444,    65,
    -407,  -407,   484,   480,   460,   147,   469,   -30,  -407,    48,
    -407,  -407,  -407,  -407,   511,   494,  -407,   472,   480,    80,
    -407,   -39,   517,  -407,  -407,  -407,   481,   -61,  -407,   516,
    -407,   497,   -32,    80,   543,  -407,  -407,   522,  -407,  -407,
      55,  -407,  -407,   587,   168,   -32,   556,   544,  -407,  -407,
     525,  -407,   510,  -407,   507,   -32,   480,    71,    81,   -69,
    -407,  -407,    80,  -407,  -407,   163,   552,  -407,  -407,  -407,
    -407,    80,  -407
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   212,     0,     0,   228,     0,     2,     3,     5,     6,
       8,     7,     0,     0,     0,     0,     1,     4,     0,     0,
       0,     0,     0,    13,     9,    10,     0,     0,     0,   230,
       0,    11,     0,     0,     0,     0,    49,   234,     0,     0,
     231,     0,    14,    21,    24,     0,    25,    18,    19,     0,
      20,    12,    15,    17,    16,     0,    30,    31,     0,    51,
       0,   233,     0,     0,     0,     0,     0,   209,   210,   211,
       0,     0,     0,     0,   184,   208,   191,   186,   188,   190,
     207,   192,     0,     0,     0,     0,   214,   122,   131,   132,
     128,   127,   129,   133,   177,   178,   179,   193,     0,   181,
     180,   130,    22,    23,     0,     0,     0,    32,     0,    42,
      43,     0,     0,     0,    58,   232,   120,     0,     0,     0,
     215,    36,    37,     0,     0,     0,     0,     0,   134,     0,
     202,   185,   187,   189,   172,     0,     0,   125,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,     0,     0,    34,    17,    33,     0,
      44,     0,   120,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,   223,     0,     0,     0,     0,     0,     0,
     201,   203,     0,     0,   183,   126,   124,   175,   168,   169,
     165,   164,   163,   170,   171,   166,   167,   174,   173,   160,
     161,   155,   156,   159,   157,   158,   162,     0,   207,   194,
     198,   196,     0,    28,    26,     0,    35,    46,    47,    48,
      45,    52,    50,     0,    53,    54,    51,    29,     0,   229,
     121,    38,     0,     0,     0,   218,   219,     0,   222,     0,
       0,     0,     0,     0,     0,     0,     0,   199,     0,   205,
       0,     0,   195,    27,     0,    55,     0,     0,    40,     0,
     216,   220,   226,   225,   224,     0,     0,     0,     0,     0,
     236,     0,   204,   176,     0,   182,   197,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    62,    63,    64,    65,
      66,     0,    39,   221,     0,     0,     0,     0,   139,   141,
     140,     0,   237,   241,   200,   206,    56,     0,    76,    77,
       0,     0,     0,     0,     0,     0,     0,   178,   202,    61,
      41,   227,   148,     0,     0,     0,     0,     0,   242,     0,
       0,     0,    78,     0,     0,    70,    71,     0,     0,     0,
       0,     0,     0,   147,   149,   148,     0,   145,   142,   135,
       0,     0,     0,   120,     0,     0,     0,     0,    74,     0,
       0,    75,     0,     0,   150,     0,     0,     0,   143,   239,
       0,     0,   235,     0,     0,     0,    67,   153,    68,    72,
       0,     0,     0,   136,   153,   146,   145,     0,     0,   244,
       0,    57,     0,    81,     0,    69,     0,     0,   151,     0,
     137,   144,   240,   238,     0,     0,     0,     0,    83,   154,
      73,     0,   138,   245,   243,     0,     0,     0,     0,     0,
      80,    82,     0,     0,     0,     0,    91,   107,    86,     0,
      89,   152,    85,    84,     0,     0,    87,     0,     0,     0,
      93,     0,     0,    79,    90,    97,     0,   105,    95,     0,
      92,     0,   100,     0,     0,    88,    94,     0,   104,   103,
       0,   101,    96,     0,     0,     0,    98,     0,   109,   110,
       0,   102,     0,   106,     0,   100,     0,     0,     0,     0,
     111,    99,     0,   108,   112,   117,   113,   114,   118,   119,
     116,     0,   115
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -407,  -407,  -407,   639,  -407,  -407,   623,   -34,   -60,   485,
     542,  -407,  -407,  -407,  -407,  -407,   594,   545,  -407,  -407,
    -407,  -407,  -407,   565,  -407,  -407,   461,  -407,  -407,   477,
    -407,  -407,  -407,  -289,  -244,  -407,  -407,  -407,  -407,  -407,
    -407,  -407,  -407,   402,  -407,  -407,  -407,   295,  -316,   293,
    -407,  -407,  -406,   267,   286,  -407,  -407,  -407,  -407,   282,
    -407,   279,  -407,  -169,  -407,  -125,  -135,  -407,  -407,  -407,
    -407,  -407,  -407,  -407,   454,   410,  -407,   443,  -407,  -407,
     421,   -58,  -407,  -263,  -407,  -407,   574,   493,  -407,  -155,
    -407,  -407,  -407,  -407,  -407,  -407,   595,  -407,  -407,   593,
    -407,  -407,  -407,  -407,   781,  -407,  -407,  -407,  -407,  -407,
    -407,  -407
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    24,    25,    26,    51,    52,
      53,    54,   105,     9,    28,    56,    57,   120,   121,   122,
     302,    36,   109,   110,   230,    60,   112,   114,   234,   235,
     340,   174,   175,   294,   295,   296,   297,   324,   298,   299,
     300,   237,   318,   319,   418,   428,   437,   438,   439,   440,
     451,   457,   495,   470,   471,   465,   447,   480,   489,   490,
     496,   497,   500,   176,   177,    86,   138,    87,    88,    89,
      90,   393,    91,   308,   309,   378,    92,   353,   354,   355,
     405,    93,    94,    95,   222,    96,   191,   192,   260,    97,
      10,    12,    98,    99,   244,   245,   246,   100,   182,   183,
     273,    11,    15,    39,    40,   101,   313,   337,   380,   339,
     361,   400
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      55,   186,   195,   232,   119,   219,   372,   350,   289,   290,
     291,   292,   436,   196,   128,   334,   289,   290,   291,   292,
     164,   397,    55,   463,   108,   134,   135,   136,   445,   327,
     125,   414,    67,    68,    69,    62,   348,    32,    32,   468,
      13,   256,   376,   458,    14,   459,   166,   493,    32,   469,
     329,   436,   240,   398,   365,   460,   464,   472,   367,   293,
     369,    32,    75,   415,   377,    63,   184,   293,   231,   430,
     218,   257,   190,    64,    65,   108,    33,   171,   160,   161,
     373,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   406,   368,   221,   329,   165,    66,   126,    67,    68,
      69,    70,   394,    71,    72,    73,   404,    32,   241,   280,
      32,   329,    16,   329,   248,   329,   276,   249,   289,   290,
     291,   292,   448,    32,    18,   258,    74,   256,    75,   475,
      76,   455,    77,    78,    79,   106,    80,    81,   169,    19,
     305,   289,   290,   291,   292,   475,   289,   290,   291,   292,
     449,   456,   329,   316,   409,   448,    82,   371,    37,   476,
     488,    83,    20,   488,   131,    84,    85,    38,   356,   293,
     132,   133,   268,   384,    27,   491,   160,   161,   385,   272,
     227,   228,   229,   492,   383,   321,   322,   323,   190,   277,
      21,   278,   293,   286,    64,    65,    22,   293,   102,   103,
      23,   303,   442,   443,   386,    43,    44,    45,    46,    47,
     310,    48,    49,   160,   161,    30,   189,   478,   479,    29,
     287,   498,   499,    35,   326,    34,    42,   388,    59,    67,
      68,    69,   389,   307,    58,    41,   331,    61,   392,   104,
      64,    65,   111,   336,   289,   290,   291,   292,   113,   155,
     156,   157,   158,   413,   159,   346,   116,    74,   129,    75,
     190,    76,   137,    77,    78,    79,   162,    80,    81,    50,
     424,     1,     2,     3,     4,    67,    68,    69,   123,   124,
     127,   130,   370,    64,    65,   172,   163,    82,   173,   178,
     179,   307,    83,   180,   434,   293,    84,    85,   387,   181,
     185,   187,   188,    74,   159,    75,   217,    76,   395,    77,
      78,    79,   223,    80,    81,   225,   226,   233,    67,    68,
      69,   236,   238,   407,   239,   242,   243,   252,   251,   220,
     420,   247,   253,    82,   254,   255,   419,   259,    83,   262,
     263,   422,    84,    85,   404,   264,    74,   270,    75,   267,
      76,   269,    77,    78,    79,   275,    80,    81,    43,    44,
      45,    46,    47,   279,    48,    49,   117,    43,    44,    45,
      46,    47,   425,    48,   281,   284,    82,   285,   288,   304,
     301,    83,   311,   312,   314,    84,    85,   306,   315,   317,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   320,   151,   152,   153,   154,   155,   156,   157,
     158,   325,   159,   328,   118,   330,   153,   154,   155,   156,
     157,   158,    50,   159,   333,   332,   338,   335,   343,   341,
     344,    50,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   345,   151,   152,   153,   154,   155,
     156,   157,   158,   347,   159,   352,   357,   362,   360,   363,
     364,   366,   349,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   375,   151,   152,   153,   154,
     155,   156,   157,   158,   379,   159,   381,   391,   382,   396,
     399,   402,   403,   390,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   376,   151,   152,   153,
     154,   155,   156,   157,   158,   401,   159,   408,   412,   416,
     417,   426,   423,   194,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   427,   151,   152,   153,
     154,   155,   156,   157,   158,   429,   159,   431,   432,   433,
     435,   436,   444,   250,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   441,   151,   152,   153,
     154,   155,   156,   157,   158,   450,   159,   452,   453,   461,
     466,   467,   462,   359,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   473,   151,   152,   153,
     154,   155,   156,   157,   158,   474,   159,   477,   482,   484,
     483,   485,   486,   421,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   501,   151,   152,   153,
     154,   155,   156,   157,   158,    17,   159,    31,   167,   224,
     107,   168,   283,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   193,   151,   152,   153,   154,
     155,   156,   157,   158,   170,   159,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   261,   151,
     152,   153,   154,   155,   156,   157,   158,   266,   159,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   265,   151,   152,   153,   154,   155,   156,   157,   158,
     342,   159,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   446,   151,   152,   153,   154,   155,   156,   157,
     158,   454,   159,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   487,   151,   152,   153,   154,   155,   156,   157,
     158,   481,   159,   143,   144,   145,   146,   147,   148,   149,
     150,   494,   151,   152,   153,   154,   155,   156,   157,   158,
     502,   159,   144,   145,   146,   147,   148,   149,   150,   358,
     151,   152,   153,   154,   155,   156,   157,   158,   374,   159,
     145,   146,   147,   148,   149,   150,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   410,   159,   147,   148,   149,
     150,   351,   151,   152,   153,   154,   155,   156,   157,   158,
     282,   159,   151,   152,   153,   154,   155,   156,   157,   158,
     271,   159,   274,   115
};

static const yytype_uint16 yycheck[] =
{
      34,   126,   137,   172,    64,   160,    41,    38,    30,    31,
      32,    33,    81,   138,    72,    38,    30,    31,    32,    33,
      25,    84,    56,    84,    58,    83,    84,    85,    58,   292,
      38,    84,    43,    44,    45,    84,   325,    84,    84,    71,
      80,    84,    87,   449,    82,    84,   106,   116,    84,    81,
     294,    81,   177,   116,   343,    94,   117,   463,   347,    81,
     349,    84,    73,   116,   109,   114,   124,    81,   114,   116,
      81,   114,   130,     8,     9,   109,   112,   111,   109,   110,
     115,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   390,   116,   161,   348,   110,    41,   115,    43,    44,
      45,    46,   375,    48,    49,    50,    39,    84,   178,   254,
      84,   365,     0,   367,   114,   369,   251,   117,    30,    31,
      32,    33,    84,    84,   111,   193,    71,    84,    73,    84,
      75,    61,    77,    78,    79,   112,    81,    82,   112,   112,
     275,    30,    31,    32,    33,    84,    30,    31,    32,    33,
     112,    81,   406,   114,    87,    84,   101,   114,    81,   114,
     486,   106,   112,   489,    71,   110,   111,    90,   333,    81,
      77,    78,   242,    67,    10,   114,   109,   110,    72,   247,
      54,    55,    56,   112,   363,    34,    35,    36,   256,    34,
      81,    36,    81,   261,     8,     9,    81,    81,    26,    27,
      81,   269,    65,    66,   116,    16,    17,    18,    19,    20,
     278,    22,    23,   109,   110,   114,    30,    59,    60,   111,
     264,    68,    69,    11,   292,   112,    81,   116,    12,    43,
      44,    45,   116,   277,   112,   115,   304,    81,   373,   110,
       8,     9,   111,   311,    30,    31,    32,    33,    13,   102,
     103,   104,   105,   398,   107,   323,   115,    71,   115,    73,
     328,    75,    70,    77,    78,    79,   116,    81,    82,    80,
     415,     3,     4,     5,     6,    43,    44,    45,   111,   111,
     111,   111,   350,     8,     9,   112,    71,   101,   112,    25,
      23,   335,   106,   111,   429,    81,   110,   111,   366,    81,
      47,    81,    51,    71,   107,    73,   111,    75,   376,    77,
      78,    79,   113,    81,    82,    71,    29,    81,    43,    44,
      45,    15,    14,   391,   116,    25,    81,   116,   115,    97,
     116,   112,    84,   101,    82,    76,   404,    40,   106,   113,
     113,   409,   110,   111,    39,   111,    71,   114,    73,   112,
      75,   112,    77,    78,    79,   115,    81,    82,    16,    17,
      18,    19,    20,    82,    22,    23,    24,    16,    17,    18,
      19,    20,   416,    22,   112,   101,   101,   114,   112,    84,
      28,   106,    84,    52,    81,   110,   111,   116,    71,    30,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    76,    98,    99,   100,   101,   102,   103,   104,
     105,   115,   107,   111,    72,    80,   100,   101,   102,   103,
     104,   105,    80,   107,    34,   116,    53,   117,   115,    76,
      81,    80,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    37,    98,    99,   100,   101,   102,
     103,   104,   105,   115,   107,    42,    81,    83,   115,   115,
      93,    38,   115,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    38,    98,    99,   100,   101,
     102,   103,   104,   105,    82,   107,   115,   111,   116,    73,
      82,    94,    94,   115,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    87,    98,    99,   100,
     101,   102,   103,   104,   105,   116,   107,   116,    82,   115,
      93,    57,    82,   114,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    64,    98,    99,   100,
     101,   102,   103,   104,   105,   115,   107,    94,    30,   115,
      76,    81,    93,   114,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   116,    98,    99,   100,
     101,   102,   103,   104,   105,    74,   107,    93,   116,    72,
      74,    94,   111,   114,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    63,    98,    99,   100,
     101,   102,   103,   104,   105,    93,   107,    30,    62,    94,
      76,   111,   115,   114,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    84,    98,    99,   100,
     101,   102,   103,   104,   105,     6,   107,    24,   106,   164,
      56,   106,   113,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   109,   107,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   236,   107,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   234,    98,    99,   100,   101,   102,   103,   104,   105,
     318,   107,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   437,    98,    99,   100,   101,   102,   103,   104,
     105,   448,   107,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   485,    98,    99,   100,   101,   102,   103,   104,
     105,   475,   107,    89,    90,    91,    92,    93,    94,    95,
      96,   489,    98,    99,   100,   101,   102,   103,   104,   105,
     501,   107,    90,    91,    92,    93,    94,    95,    96,   335,
      98,    99,   100,   101,   102,   103,   104,   105,   355,   107,
      91,    92,    93,    94,    95,    96,   396,    98,    99,   100,
     101,   102,   103,   104,   105,   394,   107,    93,    94,    95,
      96,   328,    98,    99,   100,   101,   102,   103,   104,   105,
     256,   107,    98,    99,   100,   101,   102,   103,   104,   105,
     245,   107,   249,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,   119,   120,   121,   122,   131,
     208,   219,   209,    80,    82,   220,     0,   121,   111,   112,
     112,    81,    81,    81,   123,   124,   125,    10,   132,   111,
     114,   124,    84,   112,   112,    11,   139,    81,    90,   221,
     222,   115,    81,    16,    17,    18,    19,    20,    22,    23,
      80,   126,   127,   128,   129,   125,   133,   134,   112,    12,
     143,    81,    84,   114,     8,     9,    41,    43,    44,    45,
      46,    48,    49,    50,    71,    73,    75,    77,    78,    79,
      81,    82,   101,   106,   110,   111,   183,   185,   186,   187,
     188,   190,   194,   199,   200,   201,   203,   207,   210,   211,
     215,   223,    26,    27,   110,   130,   112,   134,   125,   140,
     141,   111,   144,    13,   145,   222,   115,    24,    72,   126,
     135,   136,   137,   111,   111,    38,   115,   111,   199,   115,
     111,    71,    77,    78,   199,   199,   199,    70,   184,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    98,    99,   100,   101,   102,   103,   104,   105,   107,
     109,   110,   116,    71,    25,   110,   126,   128,   135,   112,
     141,   125,   112,   112,   149,   150,   181,   182,    25,    23,
     111,    81,   216,   217,   199,    47,   183,    81,    51,    30,
     199,   204,   205,    97,   114,   184,   183,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   111,    81,   207,
      97,   199,   202,   113,   127,    71,    29,    54,    55,    56,
     142,   114,   181,    81,   146,   147,    15,   159,    14,   116,
     183,   126,    25,    81,   212,   213,   214,   112,   114,   117,
     114,   115,   116,    84,    82,    76,    84,   114,   199,    40,
     206,    97,   113,   113,   111,   147,   144,   112,   126,   112,
     114,   214,   199,   218,   217,   115,   183,    34,    36,    82,
     184,   112,   204,   113,   101,   114,   199,   125,   112,    30,
      31,    32,    33,    81,   151,   152,   153,   154,   156,   157,
     158,    28,   138,   199,    84,   183,   116,   125,   191,   192,
     199,    84,    52,   224,    81,    71,   114,    30,   160,   161,
      76,    34,    35,    36,   155,   115,   199,   201,   111,   152,
      80,   199,   116,    34,    38,   117,   199,   225,    53,   227,
     148,    76,   161,   115,    81,    37,   199,   115,   151,   115,
      38,   205,    42,   195,   196,   197,   207,    81,   192,   114,
     115,   228,    83,   115,    93,   151,    38,   151,   116,   151,
     199,   114,    41,   115,   195,    38,    87,   109,   193,    82,
     226,   115,   116,   181,    67,    72,   116,   199,   116,   116,
     115,   111,   183,   189,   201,   199,    73,    84,   116,    82,
     229,   116,    94,    94,    39,   198,   151,   199,   116,    87,
     198,   193,    82,   184,    84,   116,   115,    93,   162,   199,
     116,   114,   199,    82,   184,   125,    57,    64,   163,   115,
     116,    94,    30,   115,   183,    76,    81,   164,   165,   166,
     167,   116,    65,    66,    93,    58,   165,   174,    84,   112,
      74,   168,    93,   116,   167,    61,    81,   169,   170,    84,
      94,    72,   111,    84,   117,   173,    74,    94,    71,    81,
     171,   172,   170,    63,    93,    84,   114,    30,    59,    60,
     175,   172,    62,    76,    94,   111,   115,   171,   166,   176,
     177,   114,   112,   116,   177,   170,   178,   179,    68,    69,
     180,    84,   179
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   120,   120,   121,   121,   121,   121,   122,
     123,   123,   124,   125,   125,   126,   126,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   129,   130,   130,   131,
     132,   133,   133,   134,   134,   134,   135,   135,   136,   137,
     138,   138,   139,   140,   140,   141,   142,   142,   142,   143,
     143,   144,   144,   145,   146,   146,   148,   147,   150,   149,
     151,   151,   152,   152,   152,   152,   152,   153,   154,   155,
     155,   155,   156,   156,   157,   158,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   163,   164,   164,   165,   166,
     166,   167,   167,   168,   168,   169,   169,   170,   170,   170,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   178,   178,   179,   180,   180,   180,
     182,   181,   183,   183,   183,   184,   184,   185,   185,   185,
     185,   185,   185,   185,   186,   187,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   195,   195,
     195,   196,   197,   198,   198,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   201,   201,   201,   202,   202,   202,   203,
     204,   204,   205,   205,   205,   206,   206,   207,   207,   207,
     207,   207,   209,   208,   210,   211,   211,   212,   212,   213,
     213,   214,   215,   216,   216,   217,   218,   218,   220,   219,
     221,   221,   221,   222,   222,   223,   224,   225,   224,   226,
     226,   227,   228,   227,   229,   229
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     4,
       1,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     4,     3,     9,
       3,     1,     2,     3,     3,     4,     1,     1,     3,     5,
       0,     2,     3,     1,     2,     3,     1,     1,     1,     0,
       4,     0,     3,     3,     1,     2,     0,     8,     0,     4,
       1,     2,     1,     1,     1,     1,     1,     5,     5,     5,
       2,     2,     5,     7,     4,     4,     4,     1,     2,    11,
       8,     0,     3,     0,     4,     4,     1,     2,     4,     1,
       3,     1,     4,     1,     3,     1,     3,     1,     4,     8,
       0,     1,     3,     1,     1,     0,     4,     0,    10,     1,
       1,     1,     2,     3,     1,     3,     2,     0,     1,     1,
       0,     2,     1,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     8,    10,     2,     3,     6,
       6,     1,     3,     4,     6,     0,     2,     8,     0,     1,
       2,     4,     8,     0,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     5,     1,     1,     1,
       1,     1,     5,     3,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     3,     4,     1,     3,     1,     4,
       4,     1,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     0,     8,     1,     2,     5,     0,     1,     1,
       2,     3,     4,     1,     3,     3,     1,     3,     0,     9,
       0,     1,     3,     2,     1,     9,     0,     0,     6,     1,
       3,     0,     0,     6,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 249 "../frontend/IT.y" /* yacc.c:1646  */
    {(yylsp[0]); // this is needed to make bison set up
							     	     // the location variable yylloc
								  ProgramDef *program = new ProgramDef((yyvsp[0].nodeList));
								  ProgramDef::program = program;				
								}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 254 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.nodeList) = new List<Node*>)->Append((yyvsp[0].node)); }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 255 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.nodeList) = (yyvsp[-1].nodeList))->Append((yyvsp[0].node)); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 256 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].tuple); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 258 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].fn); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 262 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.tuple) = new TupleDef(new Identifier((yylsp[-2]), (yyvsp[-2].stringConstant)), (yyvsp[0].varList)); }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 263 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.varList) = new List<VariableDef*>)->AppendAll((yyvsp[0].varList)); }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 264 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.varList) = (yyvsp[-1].varList))->AppendAll((yyvsp[0].varList)); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 265 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.varList) = VariableDef::DecomposeDefs((yyvsp[-2].idList), (yyvsp[0].type)); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 266 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.idList) = new List<Identifier*>)->Append(new Identifier((yylsp[0]), (yyvsp[0].stringConstant))); }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 267 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.idList) = (yyvsp[-2].idList))->Append(new Identifier((yylsp[0]), (yyvsp[0].stringConstant))); }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 269 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 270 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::stringType; }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::rangeType; }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 272 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = new NamedType(new Identifier((yylsp[0]), (yyvsp[0].stringConstant))); }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 273 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::intType; }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::floatType; }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 275 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::doubleType; }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 276 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::charType; }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 277 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = Type::boolType; }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 279 "../frontend/IT.y" /* yacc.c:1646  */
    { StaticArrayType *sa = new StaticArrayType((yylsp[-3]), (yyvsp[0].type), (yyvsp[-2].intList)->NumElements());
								  sa->setLengths((yyvsp[-2].intList)); 
								  (yyval.type) = sa; }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 282 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.intList) = (yyvsp[-3].intList))->Append((yyvsp[-1].intConstant)); }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 283 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.intList) = new List<int>)->Append((yyvsp[-1].intConstant)); }
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 293 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.node) = new TaskDef(new Identifier((yylsp[-7]), (yyvsp[-7].stringConstant)), 
									(yyvsp[-5].defineSection), (yyvsp[-4].envSection), (yyvsp[-3].initSection), (yyvsp[-2].stagesSection), (yyvsp[-1].computeSection), (yyvsp[0].partitionSection)); }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 298 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.defineSection) = new DefineSection((yyvsp[0].varList), (yylsp[-2])); }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 299 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.varList) = new List<VariableDef*>)->AppendAll((yyvsp[0].varList)); }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 300 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.varList) = (yyvsp[-1].varList))->AppendAll((yyvsp[0].varList)); }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 301 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.varList) = VariableDef::DecomposeDefs((yyvsp[-2].idList), (yyvsp[0].type)); }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 302 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.varList) = VariableDef::DecomposeDefs((yyvsp[-2].idList), (yyvsp[0].type)); }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 303 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.varList) = VariableDef::DecomposeDefs((yyvsp[-3].idList), (yyvsp[-1].type));
								  for (int i = 0; i < (yyval.varList)->NumElements(); i++) { 
								  	(yyval.varList)->Nth(i)->flagAsReduction();
								  } }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 308 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = new ListType((yylsp[-2]), (yyvsp[0].type)); }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 310 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.type) = new ArrayType((yylsp[-4]), (yyvsp[-1].type), (yyvsp[-4].intConstant)); }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 315 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.envSection) = new EnvironmentSection((yyvsp[0].envLinks), (yylsp[-2])); }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.envLinks) = (yyvsp[0].envLinks); }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 317 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.envLinks) = (yyvsp[-1].envLinks))->AppendAll((yyvsp[0].envLinks)); }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 318 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.envLinks) = EnvironmentLink::decomposeLinks((yyvsp[-2].idList), (yyvsp[0].linkageType)); }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 319 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.linkageType) = TypeLink; }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 320 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.linkageType) = TypeCreate; }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 321 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.linkageType) = TypeCreateIfNotLinked; }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.initSection) = NULL; }
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 326 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.initSection) = new InitializeSection((yyvsp[-2].idList), (yyvsp[0].stmtList), (yylsp[-3])); }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 327 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.idList) = new List<Identifier*>; }
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 328 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.idList) = (yyvsp[-1].idList); }
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 331 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stagesSection) = new StagesSection((yyvsp[0].stageDefList), (yylsp[-2])); }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 332 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.stageDefList) = new List<StageDefinition*>)->Append((yyvsp[0].stageDef)); }
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 333 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.stageDefList) = (yyvsp[-1].stageDefList))->Append((yyvsp[0].stageDef)); }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 335 "../frontend/IT.y" /* yacc.c:1646  */
    { BeginCode(); }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 335 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stageDef) = new StageDefinition(new Identifier((yylsp[-7]), (yyvsp[-7].stringConstant)), (yyvsp[-5].idList), new StmtBlock((yyvsp[-1].stmtList))); }
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 339 "../frontend/IT.y" /* yacc.c:1646  */
    { FlowPart::resetFlowIndexRef(); }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 340 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.computeSection) = new ComputationSection((yyvsp[0].flowPartList), (yylsp[-2])); }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 341 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.flowPartList) = new List<FlowPart*>)->Append((yyvsp[0].flowPart)); }
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 342 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.flowPartList) = (yyvsp[-1].flowPartList))->Append((yyvsp[0].flowPart)); }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 348 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.flowPart) = new LpsTransition((yyvsp[-3].characterConstant), (yyvsp[-1].flowPartList), Join((yylsp[-4]), (yylsp[0]))); }
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 350 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.flowPart) = new RepeatCycle((yyvsp[-3].repeatControl), (yyvsp[-1].flowPartList), Join((yylsp[-4]), (yylsp[0]))); }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 351 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.repeatControl) =  new ForRepeat(new RangeExpr(
										new Identifier((yylsp[-3]), (yyvsp[-3].stringConstant)), (yyvsp[-1].expr), (yyvsp[0].expr), Join((yylsp[-3]), (yylsp[-1]))), (yylsp[-4])); }
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 353 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.repeatControl) = new SubpartitionRepeat(Join((yylsp[-1]), (yylsp[0]))); }
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 354 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.repeatControl) = new WhileRepeat((yyvsp[0].expr), Join((yylsp[-1]), (yylsp[0]))); }
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 355 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.flowPart) = new ConditionalFlowBlock((yyvsp[-3].expr), (yyvsp[-1].flowPartList), Join((yylsp[-4]), (yylsp[0]))); }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 356 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.flowPart) = new ConditionalFlowBlock(new RangeExpr((yyvsp[-5].expr), (yyvsp[-3].expr), 
										Join((yylsp[-5]), (yylsp[-3]))), (yyvsp[-1].flowPartList), Join((yylsp[-6]), (yylsp[0]))); }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 358 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.flowPart) = new EpochBlock((yyvsp[-1].flowPartList), Join((yylsp[-3]), (yylsp[0]))); }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 359 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.flowPart) = new StageInvocation(new Identifier((yylsp[-3]), (yyvsp[-3].stringConstant)), (yyvsp[-1].exprList), Join((yylsp[-3]), (yylsp[0]))); }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 362 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.partitionSection) = new PartitionSection((yyvsp[-2].idList), (yyvsp[0].partSpecList), (yylsp[-3])); }
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 363 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.partSpecList) = new List<PartitionSpec*>)->Append((yyvsp[0].partSpec)); }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 364 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.partSpecList) = (yyvsp[-1].partSpecList))->Append((yyvsp[0].partSpec)); }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 366 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.partSpec) = new PartitionSpec((yyvsp[-9].characterConstant), (yyvsp[-7].intConstant), (yyvsp[-2].dConSpecList), (yyvsp[-5].booleanConstant), (yyvsp[-4].sLink), (yyvsp[-1].subPartSpec), (yylsp[-10])); }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 368 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.partSpec) = new PartitionSpec((yyvsp[-6].characterConstant), (yyvsp[-1].idList), (yylsp[-7])); }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 369 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.booleanConstant) = false; }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 370 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.booleanConstant) = true; }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 371 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sLink) = NULL; }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 372 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sLink) = new SpaceLinkage(LinkTypePartition, (yyvsp[-1].characterConstant), (yylsp[-3])); }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 373 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sLink) = new SpaceLinkage(LinkTypeSubpartition, (yyvsp[-1].characterConstant), (yylsp[-3])); }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 374 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.dConSpecList) = new List<DataConfigurationSpec*>)->AppendAll((yyvsp[0].dConSpecList)); }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 375 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.dConSpecList) = (yyvsp[-1].dConSpecList))->AppendAll((yyvsp[0].dConSpecList)); }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 376 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.dConSpecList) = DataConfigurationSpec::decomposeDataConfig((yyvsp[-3].vDimsList), (yyvsp[-1].pInstrList), (yyvsp[0].sLink)); }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 377 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.vDimsList) = new List<VarDimensions*>)->Append((yyvsp[0].vDims)); }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 378 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.vDimsList) = (yyvsp[-2].vDimsList))->Append((yyvsp[0].vDims)); }
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 379 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.vDims) = new VarDimensions(new Identifier((yylsp[0]), (yyvsp[0].stringConstant)), NULL); }
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 380 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.vDims) = new VarDimensions(new Identifier((yylsp[-3]), (yyvsp[-3].stringConstant)), (yyvsp[-1].iConList)); }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 381 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.iConList) = new List<IntConstant*>)->Append(new IntConstant((yylsp[0]), (yyvsp[0].intConstant))); }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 382 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.iConList) = (yyvsp[-2].iConList))->Append(new IntConstant((yylsp[0]), (yyvsp[0].intConstant))); }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 383 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.pInstrList) = new List<PartitionInstr*>)->Append((yyvsp[0].pInstr)); }
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 384 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.pInstrList) = (yyvsp[-2].pInstrList))->Append((yyvsp[0].pInstr)); }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 385 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pInstr) = new PartitionInstr((yylsp[0])); }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 386 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pInstr) = new PartitionInstr(
								    	new Identifier((yylsp[-3]), (yyvsp[-3].stringConstant)), (yyvsp[-1].pArgList), false, NULL, (yylsp[-3])); }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 389 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pInstr) = new PartitionInstr(new Identifier((yylsp[-7]), (yyvsp[-7].stringConstant)), (yyvsp[-5].pArgList), true, (yyvsp[-1].pArgList), (yylsp[-7])); }
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 390 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pArgList) = new List<PartitionArg*>; }
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 391 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.pArgList) = new List<PartitionArg*>)->Append((yyvsp[0].pArg)); }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 392 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.pArgList) = (yyvsp[-2].pArgList))->Append((yyvsp[0].pArg)); }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 393 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pArg) = new PartitionArg(new Identifier((yylsp[0]), (yyvsp[0].stringConstant))); }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 394 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pArg) = new PartitionArg(new IntConstant((yylsp[0]), (yyvsp[0].intConstant))); }
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 395 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sLink) = NULL; }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 396 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sLink) = new SpaceLinkage(LinkTypeUndefined, (yyvsp[0].characterConstant), (yylsp[-2])); }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 397 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.subPartSpec) = NULL; }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 399 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.subPartSpec) = new SubpartitionSpec((yyvsp[-7].intConstant), (yyvsp[-4].booleanConstant), (yyvsp[-1].dConSpecList), (yylsp[-9])); }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 400 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.booleanConstant) = true; }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 401 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.booleanConstant) = false; }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 402 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.dConSpecList) = new List<DataConfigurationSpec*>)->AppendAll((yyvsp[0].dConSpecList)); }
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 403 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.dConSpecList) = (yyvsp[-1].dConSpecList))->AppendAll((yyvsp[0].dConSpecList)); }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 404 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.dConSpecList) = DataConfigurationSpec::decomposeDataConfig((yyvsp[-2].vDimsList), (yyvsp[0].pInstrList), NULL);}
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 405 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.pInstrList) = new List<PartitionInstr*>)->Append((yyvsp[0].pInstr)); }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 406 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.pInstrList) = (yyvsp[-2].pInstrList))->Append((yyvsp[0].pInstr)); }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 407 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.pInstr) = (yyvsp[-1].pInstr); (yyval.pInstr)->SetOrder((yyvsp[0].order)); }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 408 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.order) = RandomOrder; }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 409 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.order) = AscendingOrder; }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 410 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.order) = DescendingOrder; }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 414 "../frontend/IT.y" /* yacc.c:1646  */
    {BeginCode();}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 414 "../frontend/IT.y" /* yacc.c:1646  */
    { EndCode(); (yyval.stmtList) = (yyvsp[0].stmtList); }
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 415 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[0].stmt)); }
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 416 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[-1].stmt)); }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 417 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[-2].stmt)); (yyval.stmtList)->AppendAll((yyvsp[0].stmtList)); }
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 425 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].expr); }
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 426 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReturnStmt((yyvsp[0].expr), Join((yylsp[-1]), (yylsp[0]))); }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 428 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReductionStmt(new Identifier((yylsp[-5]), (yyvsp[-5].stringConstant)), (yyvsp[-3].stringConstant), (yyvsp[-1].expr), Join((yylsp[-7]), (yylsp[0]))); }
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 430 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SLoopStmt((yyvsp[-2].id), (yyvsp[0].sloopAttr), new StmtBlock((yyvsp[-5].stmtList)), (yylsp[-9])); }
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 431 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sloopAttr) = new SLoopAttribute((yyvsp[-1].expr), (yyvsp[0].expr), NULL); }
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 432 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.sloopAttr) = new SLoopAttribute((yyvsp[-2].expr), NULL, (yyvsp[0].expr)); }
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 433 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = new PLoopStmt((yyvsp[0].rangeCondList), new StmtBlock((yyvsp[-3].stmtList)), (yylsp[-5])); }
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 434 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileStmt((yyvsp[0].expr), new StmtBlock((yyvsp[-3].stmtList)), (yylsp[-5])); }
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 435 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.rangeCondList) = new List<IndexRangeCondition*>)->Append((yyvsp[0].rangeCond)); }
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 436 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.rangeCondList) = (yyvsp[-2].rangeCondList))->Append((yyvsp[0].rangeCond)); }
#line 2773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 437 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.rangeCond) = new IndexRangeCondition((yyvsp[-3].idList), new Identifier((yylsp[-1]), (yyvsp[-1].stringConstant)), -1, (yyvsp[0].expr), Join((yylsp[-3]), (yylsp[0]))); }
#line 2779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 439 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.rangeCond) = new IndexRangeCondition((yyvsp[-5].idList), new Identifier((yylsp[-3]), (yyvsp[-3].stringConstant)), (yyvsp[-1].intConstant), (yyvsp[0].expr), Join((yylsp[-5]), (yylsp[0]))); }
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 440 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 441 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 442 "../frontend/IT.y" /* yacc.c:1646  */
    { List<ConditionalStmt*> *lca = new List<ConditionalStmt*>;
								  lca->Append(new ConditionalStmt((yyvsp[-5].expr), new StmtBlock((yyvsp[-2].stmtList)), (yylsp[-7])));
								  lca->AppendAll((yyvsp[0].condStmtList));	
								  (yyval.stmt) = new IfStmt(lca, (yylsp[-7])); }
#line 2806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 446 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.condStmtList) = new List<ConditionalStmt*>; }
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 447 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.condStmtList) = new List<ConditionalStmt*>)->Append((yyvsp[0].condStmt)); }
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 448 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.condStmtList) = new List<ConditionalStmt*>)->Append((yyvsp[-1].condStmt)); (yyval.condStmtList)->AppendAll((yyvsp[0].condStmtList)); }
#line 2824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 449 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.condStmt) = new ConditionalStmt(NULL, new StmtBlock((yyvsp[-1].stmtList)), (yylsp[-3])); }
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 450 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.condStmt) = new ConditionalStmt((yyvsp[-4].expr), new StmtBlock((yyvsp[-1].stmtList)), (yylsp[-7])); }
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 452 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 453 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 454 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), ADD, (yyvsp[0].expr), (yylsp[-1])); }
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 455 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), SUBTRACT, (yyvsp[0].expr), (yylsp[-1])); }
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 456 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), MULTIPLY, (yyvsp[0].expr), (yylsp[-1])); }
#line 2866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 457 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), DIVIDE, (yyvsp[0].expr), (yylsp[-1])); }
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 458 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), MODULUS, (yyvsp[0].expr), (yylsp[-1])); }
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 459 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), LEFT_SHIFT, (yyvsp[0].expr), (yylsp[-1])); }
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 460 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), RIGHT_SHIFT, (yyvsp[0].expr), (yylsp[-1])); }
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 461 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), POWER, (yyvsp[0].expr), (yylsp[-1])); }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 462 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), BITWISE_AND, (yyvsp[0].expr), (yylsp[-1])); }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 463 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), BITWISE_XOR, (yyvsp[0].expr), (yylsp[-1])); }
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 464 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArithmaticExpr((yyvsp[-2].expr), BITWISE_OR, (yyvsp[0].expr), (yylsp[-1])); }
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 465 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), LT, (yyvsp[0].expr), (yylsp[-1])); }
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 466 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), GT, (yyvsp[0].expr), (yylsp[-1])); }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 467 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), OR, (yyvsp[0].expr), (yylsp[-1])); }
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 468 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), AND, (yyvsp[0].expr), (yylsp[-1])); }
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 469 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), EQ, (yyvsp[0].expr), (yylsp[-1])); }
#line 2944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 470 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), NE, (yyvsp[0].expr), (yylsp[-1])); }
#line 2950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 471 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr(NULL, NOT, (yyvsp[0].expr), (yylsp[-1])); }
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 472 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), GTE, (yyvsp[0].expr), (yylsp[-1])); }
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 473 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new LogicalExpr((yyvsp[-2].expr), LTE, (yyvsp[0].expr), (yylsp[-1])); }
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 474 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignmentExpr((yyvsp[-2].expr), (yyvsp[0].expr), (yylsp[-1])); }
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 475 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexRange((yyvsp[-3].expr), (yyvsp[-1].expr), false, Join((yylsp[-4]), (yylsp[0]))); }
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 481 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new EpochExpr((yyvsp[-4].expr), (yyvsp[-1].intConstant)); }
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 482 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 483 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntConstant((yylsp[0]), (yyvsp[0].intConstant)); }
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 484 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntConstant((yylsp[-1]), (yyvsp[0].intConstant) * -1); }
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 485 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new FloatConstant((yylsp[0]), (yyvsp[0].floatConstant)); }
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 486 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new FloatConstant((yylsp[-1]), (yyvsp[0].floatConstant) * -1); }
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 487 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new DoubleConstant((yylsp[0]), (yyvsp[0].doubleConstant)); }
#line 3022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 488 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new DoubleConstant((yylsp[-1]), (yyvsp[0].doubleConstant) * -1); }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 489 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new BoolConstant((yylsp[0]), (yyvsp[0].booleanConstant)); }
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 490 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new CharConstant((yylsp[0]), (yyvsp[0].characterConstant)); }
#line 3040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 491 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringConstant((yylsp[0]), (yyvsp[0].stringConstant)); }
#line 3046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 492 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new FieldAccess(NULL, (yyvsp[0].id), (yylsp[0])); }
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 493 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new FieldAccess((yyvsp[-2].expr), (yyvsp[0].id), (yylsp[-1])); }
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 494 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrayAccess((yyvsp[-3].expr), (yyvsp[-1].expr), Join((yylsp[-2]), (yylsp[0]))); }
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 496 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexRange((yyvsp[-2].expr), (yyvsp[0].expr), true, Join((yylsp[-2]), (yylsp[0]))); }
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 497 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new IndexRange(NULL, NULL, true, (yylsp[0])); }
#line 3076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 498 "../frontend/IT.y" /* yacc.c:1646  */
    { 
									Identifier *id = new Identifier((yylsp[-3]), (yyvsp[-3].stringConstant));	
								  	if (LibraryFunction::isLibraryFunction(id)) {
										(yyval.expr) = LibraryFunction::getFunctionExpr(id, (yyvsp[-1].exprList), Join((yylsp[-3]), (yylsp[0])));	
								  	} else {
										(yyval.expr) = new FunctionCall(id, (yyvsp[-1].exprList), Join((yylsp[-3]), (yylsp[0])));
								  	} 
								}
#line 3089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 506 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ReductionVar((yyvsp[-2].characterConstant), (yyvsp[0].stringConstant), Join((yylsp[-3]), (yylsp[0]))); }
#line 3095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 507 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 508 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.exprList) = new List<Expr*>;}
#line 3107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 509 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.exprList) = new List<Expr*>)->Append((yyvsp[0].expr)); }
#line 3113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 510 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.exprList) = (yyvsp[-2].exprList))->Append((yyvsp[0].expr)); }
#line 3119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 511 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.intConstant) = 0; }
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 512 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.intConstant) = (yyvsp[0].intConstant); }
#line 3131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 513 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.id) = new Identifier((yylsp[0]), (yyvsp[0].stringConstant)); }
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 514 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.id) = new DimensionIdentifier((yylsp[0]), (yyvsp[0].intConstant)); }
#line 3143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 515 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.id) = new Identifier((yylsp[0]), Identifier::RangeId); }
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 516 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.id) = new Identifier((yylsp[0]), Identifier::LocalId); }
#line 3155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 517 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.id) = new Identifier((yylsp[0]), Identifier::IndexId); }
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 521 "../frontend/IT.y" /* yacc.c:1646  */
    {BeginProgram();}
#line 3167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 522 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.node) = new CoordinatorDef(new Identifier((yylsp[-4]), (yyvsp[-4].stringConstant)), (yyvsp[-1].stmtList), (yylsp[-7])); }
#line 3173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 523 "../frontend/IT.y" /* yacc.c:1646  */
    { EndProgram(); (yyval.stmtList) = (yyvsp[0].stmtList); }
#line 3179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 524 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ObjectCreate((yyvsp[0].type), new List<NamedArgument*>, (yylsp[-1])); }
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 525 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new ObjectCreate((yyvsp[-3].type), (yyvsp[-1].namedArgList), (yylsp[-4])); }
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 526 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.namedArgList) = new List<NamedArgument*>; }
#line 3197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 528 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.namedArgList) = new List<NamedArgument*>)->Append((yyvsp[0].namedArg)); }
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 529 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.namedArgList) = (yyvsp[-1].namedArgList))->Append((yyvsp[0].namedArg)); }
#line 3209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 530 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.namedArg) = new NamedArgument((yyvsp[-2].stringConstant), (yyvsp[0].expr), Join((yylsp[-2]), (yylsp[0]))); }
#line 3215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 531 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.expr) = new TaskInvocation((yyvsp[-1].namedMultArgList), Join((yylsp[-3]), (yylsp[0]))); }
#line 3221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 532 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.namedMultArgList) = new List<NamedMultiArgument*>)->Append((yyvsp[0].namedMultArg)); }
#line 3227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 533 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.namedMultArgList) = (yyvsp[-2].namedMultArgList))->Append((yyvsp[0].namedMultArg)); }
#line 3233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 534 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.namedMultArg) = new NamedMultiArgument((yyvsp[-2].stringConstant), (yyvsp[0].exprList), Join((yylsp[-2]), (yylsp[0]))); }
#line 3239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 535 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.exprList) = new List<Expr*>)->Append((yyvsp[0].expr)); }
#line 3245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 536 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.exprList) = (yyvsp[-2].exprList))->Append((yyvsp[0].expr)); }
#line 3251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 539 "../frontend/IT.y" /* yacc.c:1646  */
    {BeginCode();}
#line 3257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 541 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.fn) = new FunctionDef(new Identifier((yylsp[-6]), (yyvsp[-6].stringConstant)), (yyvsp[-4].fnArgList), new StmtBlock((yyvsp[-1].stmtList))); }
#line 3263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 542 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.fnArgList) = new List<FunctionArg*>; }
#line 3269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 543 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.fnArgList) = new List<FunctionArg*>)->Append((yyvsp[0].fnArg)); }
#line 3275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 544 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.fnArgList) = (yyvsp[-2].fnArgList))->Append((yyvsp[0].fnArg)); }
#line 3281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 545 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.fnArg) = new FunctionArg(new Identifier((yylsp[0]), (yyvsp[0].stringConstant)), REFERENCE_TYPE); }
#line 3287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 546 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.fnArg) = new FunctionArg(new Identifier((yylsp[0]), (yyvsp[0].stringConstant)), VALUE_TYPE);}
#line 3293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 552 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ExternCodeBlock((yyvsp[-5].stringConstant), (yyvsp[-3].strList), (yyvsp[-2].strList), (yyvsp[-1].stringConstant), (yylsp[-8])); }
#line 3299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 553 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.strList) = NULL; EndFreeString(); }
#line 3305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 554 "../frontend/IT.y" /* yacc.c:1646  */
    { BeginFreeString(); }
#line 3311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 555 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.strList) = (yyvsp[-2].strList); EndFreeString(); }
#line 3317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 556 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.strList) = new List<const char*>)->Append((yyvsp[0].stringConstant)); }
#line 3323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 557 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.strList) = (yyvsp[-2].strList))->Append((yyvsp[0].stringConstant)); }
#line 3329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 558 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.strList) = NULL; EndFreeString(); }
#line 3335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 559 "../frontend/IT.y" /* yacc.c:1646  */
    { BeginFreeString(); }
#line 3341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 560 "../frontend/IT.y" /* yacc.c:1646  */
    { (yyval.strList) = (yyvsp[-2].strList); EndFreeString(); }
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 561 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.strList) = new List<const char*>)->Append((yyvsp[0].stringConstant)); }
#line 3353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 562 "../frontend/IT.y" /* yacc.c:1646  */
    { ((yyval.strList) = (yyvsp[-2].strList))->Append((yyvsp[0].stringConstant)); }
#line 3359 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3363 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 564 "../frontend/IT.y" /* yacc.c:1906  */


/*----------------------------------------------------- Epilogue --------------------------------------------------------------*/

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 */
void InitParser() {
	PrintDebug("parser", "Initializing parser");
   	yydebug = false;
}

