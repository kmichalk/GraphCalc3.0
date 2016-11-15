#ifndef _EXPR_MAKER_H_
#define _EXPR_MAKER_H_

#include "types.h"
#include "xstring.h"

class ExprMaker
{
public:
	static Expr* make(x::string const& funcName, x::vector<Expr*> const& args);
};

#endif //_EXPR_MAKER_H_
