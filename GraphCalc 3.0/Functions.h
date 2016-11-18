#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <cmath>
#include "types.h"
#include "xrnd.h"
#include "FuncMap.h"
#include "xstring.h"


class Functions
{
	//static x::range<size_t> funcArgnum_;

	static basic_t ctg_(basic_t x);
	static basic_t sc_(basic_t x);
	static basic_t csc_(basic_t x);

	static basic_t actg_(basic_t x);
	static basic_t asc_(basic_t x);
	static basic_t acsc_(basic_t x);

	static basic_t ctgh_(basic_t x);
	static basic_t sch_(basic_t x);
	static basic_t csch_(basic_t x);

	static basic_t actgh_(basic_t x);
	static basic_t asch_(basic_t x);
	static basic_t acsch_(basic_t x);

	static basic_t add_(basic_t x1, basic_t x2);
	static basic_t sub_(basic_t x1, basic_t x2);
	static basic_t mult_(basic_t x1, basic_t x2);
	static basic_t div_(basic_t x1, basic_t x2);

	static basic_t lw_(basic_t x1, basic_t x2);
	static basic_t le_(basic_t x1, basic_t x2);
	static basic_t gt_(basic_t x1, basic_t x2);
	static basic_t ge_(basic_t x1, basic_t x2);
	static basic_t eq_(basic_t x1, basic_t x2);
	static basic_t ne_(basic_t x1, basic_t x2);

	static basic_t x_(basic_t x);
	static basic_t neg_(basic_t x);

	static basic_t log_(basic_t b, basic_t x);

public:
	static constexpr FuncPtr<1> sin = ::sin;
	static constexpr FuncPtr<1> cos = ::cos;
	static constexpr FuncPtr<1> tg = ::tan;
	static constexpr FuncPtr<1> ctg = ctg_;
	static constexpr FuncPtr<1> sc = sc_;
	static constexpr FuncPtr<1> csc = csc_;

	static constexpr FuncPtr<1> asin = ::asin;
	static constexpr FuncPtr<1> acos = ::acos;
	static constexpr FuncPtr<1> atg = ::atan;
	static constexpr FuncPtr<1> actg = actg_;
	static constexpr FuncPtr<1> asc = asc_;
	static constexpr FuncPtr<1> acsc = acsc_;

	static constexpr FuncPtr<1> sinh = ::sinh;
	static constexpr FuncPtr<1> cosh = ::cosh;
	static constexpr FuncPtr<1> tgh = ::tanh;
	static constexpr FuncPtr<1> ctgh = ctgh_;
	static constexpr FuncPtr<1> sch = sch_;
	static constexpr FuncPtr<1> csch = csch_;

	static constexpr FuncPtr<1> asinh = ::asinh;
	static constexpr FuncPtr<1> acosh = ::acosh;
	static constexpr FuncPtr<1> atgh = ::atanh;
	static constexpr FuncPtr<1> actgh = actgh_;
	static constexpr FuncPtr<1> asch = asch_;
	static constexpr FuncPtr<1> acsch = acsch_;

	static constexpr FuncPtr<1> ln = ::log;
	static constexpr FuncPtr<1> log10 = ::log10;
	static constexpr FuncPtr<1> log2 = ::log2;
	static constexpr FuncPtr<1> sqrt = ::sqrt;
	static constexpr FuncPtr<1> cbrt = ::cbrt;
	static constexpr FuncPtr<1> exp = ::exp;

	static constexpr FuncPtr<1> abs = ::abs;
	static constexpr FuncPtr<1> sgn = x::sgn<basic_t, basic_t>;
	static constexpr FuncPtr<1> floor = ::floor;
	static constexpr FuncPtr<1> ceil = ::ceil;
	static constexpr FuncPtr<1> mant = x::mant<basic_t>;
	//static constexpr basic_t(*rnd)(basic_t, basic_t) = ;

	static constexpr FuncPtr<1> gamma = ::lgamma;
	//static constexpr FuncPtr<1> zeta = ::sin;
	//static constexpr FuncPtr<1> fact = ::sin;

	static constexpr FuncPtr<1> x = x_;
	static constexpr FuncPtr<1> neg = neg_;

	static constexpr FuncPtr<2> hypot = ::hypot;

	static constexpr FuncPtr<1> sawtooth = nullptr;
	static constexpr FuncPtr<1> square = ::sin;
	static constexpr FuncPtr<1> triangle = ::sin;

	static constexpr FuncPtr<1> minkowski = ::sin;
	static constexpr FuncPtr<1> weierstrass = ::sin;
	
	static constexpr basic_t(*poly)(std::initializer_list<basic_t>) = nullptr;

	static constexpr FuncPtr<2> mod = ::fmod;
	static constexpr FuncPtr<2> pow = ::pow;
	static constexpr FuncPtr<2> log = log_;
	static constexpr FuncPtr<2> rand = x::random<basic_t>;
	static constexpr FuncPtr<2> min = x::min<basic_t, basic_t>;
	static constexpr FuncPtr<2> max = x::max<basic_t, basic_t>;
													  
	static constexpr FuncPtr<2> add = add_;
	static constexpr FuncPtr<2> sub = sub_;
	static constexpr FuncPtr<2> mult = mult_;
	static constexpr FuncPtr<2> div = div_;

	static constexpr FuncPtr<2> lw = lw_;
	static constexpr FuncPtr<2> le = le_;
	static constexpr FuncPtr<2> gt = gt_;
	static constexpr FuncPtr<2> ge = ge_;
	static constexpr FuncPtr<2> eq = eq_;
	static constexpr FuncPtr<2> ne = ne_;


	static x::strmap<FuncPtr<1>> oneArgFuncs;
	static x::strmap<FuncPtr<2>> twoArgFuncs;
	static x::strmap<FuncPtr<3>> threeArgFuncs;

	static ExprMap* funcMap[4];
	/*template<size_t _nArg>
	static inline enable_if<_nArg == 1,
		FuncPtr<1>> getFunc(char const* str)
	{
		return oneArgFuncs[str];
	}

	template<size_t _nArg>
	static inline enable_if<_nArg == 2,
		FuncPtr<2>> getFunc(char const* str)
	{
		return twoArgFuncs[str];
	}

	template<size_t _nArg>
	static inline enable_if<_nArg == 3,
		FuncPtr<3>> getFunc(char const* str)
	{
		return threeArgFuncs[str];
	}*/

	static ArgExpr* matchFunc(x::string const& str, unsigned argnum);
};

#endif //_FUNCTIONS_H_
