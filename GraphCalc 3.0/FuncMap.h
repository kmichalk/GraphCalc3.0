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
	//virtual Expr* setArgs(Expr* base, x::vector<Expr*> const& args) const override;
};



template<unsigned _nArg>
Expr * FuncMap<_nArg>::matchFunc(x::string const & funcName) const
{
	if (auto funcPtr = (*x::rem_const(this))[funcName.data()])
		return new Func<_nArg>{*funcPtr};
	return nullptr;
}

//template<unsigned _nArg>
//inline Expr * FuncMap<_nArg>::setArgs(Expr * base, x::vector<Expr*> const & args) const
//{
//	static_cast<Func<_nArg>*>(base)->
//}


#endif //_FUNC_MAP_H_