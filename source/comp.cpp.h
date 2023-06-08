/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


