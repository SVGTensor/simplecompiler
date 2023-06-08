/*
 * Parser & Scanner Common Definitions
 */
#ifndef PARSER_H
#define PARSER_H

#ifdef MSWINDOWS
    /* Do not include unistd.h */
#   define YY_NO_UNISTD_H 1
#   define isatty(file) (((file) == 0)? 1 : 0)
#   pragma warning(disable: 4996)
#endif

#include <string>
#include "lextypes.h"
#include "nt.h"
#include "lt.h"
#include "icode.h"
#include "tree.h"

using std::string;

extern NameTable name_table;

/* The type of values associated with terminals and nonterminals */
struct yys {
    string name;
    int int_value;
    double double_value;
    TreeNode* tree;
    NameDef* nameDef;
    const Label* label1;
    const Label* label2;
    const Label* saved_label1;
    const Label* saved_label2;
};

#define YYSTYPE yys

#include "comp.cpp.h"   /* File generated automatically by bison: */
                        /* contains the definitions of terminals  */

extern FILE* yyin;      /* Scanner input */

int yylex();              /* Prototype of the scanner function "next lexeme" */
int yyerror(const char*); /* Prototype of the error diagnostics function     */

extern int yylineno;

#endif
