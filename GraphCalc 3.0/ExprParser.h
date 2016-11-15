#ifndef _EXPR_PARSER_H_
#define _EXPR_PARSER_H_

#include "types.h"
#include "strmap.h"
#include "functions.h"


class CommandAnalizer;

class ExprParser
{
public:
	CommandAnalizer const& parentAnalizer;

	ExprParser(CommandAnalizer const& parentAnalizer);

	virtual Expr* match(x::string const& text) const abstract;
	virtual bool basicValidate(x::string const& text) const abstract;
	//virtual Expr* parse(x::string const& text) const abstract;
	//Expr* parse(x::string const& line);
};

#endif //_EXPR_PARSER_H_
