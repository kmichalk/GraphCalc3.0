#ifndef _FUNC_MAP_H_
#define _FUNC_MAP_H_

#include "strmap.h"
#include "types.h"
#include "ExprMap.h"

template<unsigned _nArg>
class FuncMap:
	public x::strmap<FuncPtr<_nArg>>,
	public ExprMap
{
public:
	using x::strmap<FuncPtr<_nArg>>::strmap;

	virtual Expr* matchFunc(x::string const& funcName) const override;
};



template<unsigned _nArg>
inline Expr * FuncMap<_nArg>::matchFunc(x::string const & funcName) const
{
	if (FuncPtr<_nArg> funcPtr = x::rem_const(this)->operator[](funcName.data()))
		return new Func<_nArg>{funcPtr};
	return nullptr;
}


#endif //_FUNC_MAP_H_