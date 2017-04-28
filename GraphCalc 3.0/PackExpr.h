#ifndef _PACK_EXPR_H_
#define _PACK_EXPR_H_

#include "expr.h"
#include "loops.h"


template<class _Type>
class packexpr:
	public x::expr<_Type>
{
	x::vector<x::expr<_Type>*> values_;
	typename x::vector<x::expr<_Type>*>::const_iterator current_;

	void copyValues_(packexpr<_Type> const& other)
	{
		const_foreach(v, other.values_)
			values_.push_back(*v);
	}

public:
	packexpr(x::vector<x::expr<_Type>*> const& values):
		values_{values},
		current_{values, 0}
	{
	}

	packexpr(x::vector<x::expr<_Type>*>&& values):
		values_{values},
		current_{values, 0}
	{
	}

	packexpr(packexpr<_Type> const& other):
		values_(other.values_.size()),
		current_{values_, 0}
	{
		copyValues_(other);
	}

	virtual _Type operator()(_Type arg) const override
	{
		if (!current_) throw x::error<packexpr<_Type>>{"Iterator reached end of values pack."};
		return (**current_)(arg);
	}

	virtual x::expr<_Type>* copy() const override
	{
		return new packexpr<_Type>{*this};
	}

	virtual size_t argnum() const override
	{
		return values_.size();
	}

	virtual x::result<void> set_args(x::vector<expr<_Type>*> const& args) override
	{
		if (args.size() != values_.size()) 
			return x::result<void>::INVALID;
		//TODO: !!! clear !!!
		values_ = args;
		return x::result<void>{};
	}

	inline bool next()
	{
		return ++current_;
	}
};

#endif //_PACK_EXPR_H_
