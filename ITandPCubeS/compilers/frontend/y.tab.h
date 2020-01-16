/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 25 "../frontend/IT.y" /* yacc.c:1909  */

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

#line 318 "y.tab.h" /* yacc.c:1909  */
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
