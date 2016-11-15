#ifndef _EXPR_MAP_H_
#define _EXPR_MAP_H_

#include "types.h"
#include "xstring.h"


class ExprMap
{
public:
	virtual Expr* matchFunc(x::string const& funcName) const abstract;
};

#endif //_EXPR_MAP_H_
