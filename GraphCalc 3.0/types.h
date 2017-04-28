#ifndef _TYPES_H_
#define _TYPES_H_

#include "crd.h"
#include "crd_cast.h"
#include "range.h"
#include "PackExpr.h"
#include "RefExpr.h"
#include "error.h"


using basic_t = double;

using Point = crd<basic_t>;

using Vector = crd<basic_t>;

using Size = crd<basic_t>;

using Expr = x::expr<basic_t>;

using Pack = packexpr<basic_t>;

using Ref = refexpr<basic_t>;

template<size_t _nArg> 
using Func = x::func<basic_t, _nArg>;

using Var = x::val<basic_t>;

using Const = x::cval<basic_t>;

template<size_t _nArg>
using FuncPtr = x::GenFuncPtr<basic_t, basic_t, _nArg>;

using FuncRange = x::range<basic_t>;

constexpr double e_const	= 2.71828'18284'59045;
constexpr double pi_const	= 3.14159'26535'89793;
constexpr double gr_const	= 1.61803'39887'49894;

#endif //_TYPES_H_
