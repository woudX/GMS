/************************************************************************/
/*	llex.h
/*	Lexical Analyzer
/*	using this part to analysis .gms file
/************************************************************************/

#ifndef _H_GLEX
#define _H_GLEX

#include "gobject.h"
#include "gzio.h"

const int FIRST_RESERVED = 257;

enum RESERVED {
	TK_VAR = FIRST_RESERVED, TK_INCLUDE, TK_DEFINE, TK_BREAK, TK_DO, TK_LOOP,
	TK_WHILE, TK_CONTINUE, TK_FOR, TK_FUNCTION, TK_IF, TK_TRUE, TK_FALSE,
	TK_AND, TK_OR, TK_NOT, TK_REPEAT
};

/* number of reserved words */
const int NUM_RESERVED = cast<int>(TK_REPEAT - TK_VAR + 1);

/* lex structure */
class Token {
public:
	int token;
};

class Token_Str : public Token {
public:
	TString str;
};

class Token_Num : public Token {
public:
	Gms_Number num;
};

/* state of lexer plus state of parser when shared by all functions */
class LexState {
public:
	int current;	/* current charactor */
	int linenumber;	/* input line counter */
	int lastline;	/* line of last token 'consumed' */
	Token t;		/* current token */
	Token lookahead;	/* look ahead token */
	Zio *z;			/* input stream*/
	TString *source;	/* current source file name */
	TString *envn;	/* environment variable name */
	char decpoint;	/* locale decimal point */

	void init();
	void next();
	void ahead();
	void llex();
	void syntaxerror(string msg);
private:
	void lexerror(string msg, int token);

};


#endif // !_H_GLEX