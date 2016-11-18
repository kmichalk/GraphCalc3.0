#ifndef _PREDEF_CONST_MAP_H_
#define _PREDEF_CONST_MAP_H_

#include "ExprMap.h"


class PredefConstMap :
	public ExprMap
{
public:
	virtual ArgExpr* matchFunc(x::string const& funcName) const override;
};

#endif //_PREDEF_CONST_MAP_H_
