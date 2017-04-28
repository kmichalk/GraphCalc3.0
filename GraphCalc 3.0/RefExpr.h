#ifndef _REF_EXPR_H_
#define _REF_EXPR_H_

#include "expr.h"
#include "loops.h"


template<class _Type>
class refexpr:
	public x::expr<_Type>
{
	x::expr<_Type>*& var_;

	__forceinline void assertVar_() const
	{
		if (!var_) throw x::error<refexpr<_Type>>{"Variable was nullptr."};
	}

public:
	refexpr(x::expr<_Type>*& var):
		var_{var}
	{
	}


	virtual _Type operator()(_Type arg) const override
	{
		assertVar_();
		return (*var_)(arg);
	}

	virtual x::expr<_Type>* copy() const override
	{
		return new refexpr<_Type>{*this};
	}

	virtual size_t argnum() const override
	{
		assertVar_();
		return var_->argnum();
	}

	virtual x::result<void> set_args(x::vector<expr<_Type>*> const& args) override
	{
		assertVar_();
		return var_->set_args(args);
	}
};

#endif //_REF_EXPR_H_
