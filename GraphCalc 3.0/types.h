#ifndef _TYPES_H_
#define _TYPES_H_

#include "crd.h"
#include "crd_cast.h"
#include "range.h"
#include "mathfn.h"

using basic_t = double;

using Point = crd<basic_t>;

using Vector = crd<basic_t>;

using Size = crd<basic_t>;

using Expr = x::math::expr<basic_t>;

using ArgExpr = x::math::argexpr<basic_t>;

template<size_t _nArg> 
using Func = x::math::func<basic_t, _nArg>;

using Var = x::math::val<basic_t>;

using Const = x::math::cval<basic_t>;

template<size_t _nArg>
using FuncPtr = x::math::GenFuncPtr<basic_t, basic_t, _nArg>;

using FuncRange = x::range<basic_t>;

constexpr double e_const	= 2.71828'18284'59045;
constexpr double pi_const	= 3.14159'26535'89793;
constexpr double gr_const	= 1.61803'39887'49894;

#endif //_TYPES_H_
