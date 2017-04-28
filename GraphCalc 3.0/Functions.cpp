#include "Functions.h"


basic_t Functions::ctg_(basic_t x)
{
	return ::tan(PI / 2 - x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::sc_(basic_t x)
{
	return basic_t(1) / ::cos(x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::csc_(basic_t x)
{
	return basic_t(1) / ::sin(x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::actg_(basic_t x)
{
	return ::atan(basic_t(1)/x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::asc_(basic_t x)
{
	return ::acos(basic_t(1) / x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::acsc_(basic_t x)
{
	return ::asin(basic_t(1) / x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::ctgh_(basic_t x)
{
	double ex = pow(e_const, x);
	double enx = pow(e_const, -x);
	return (ex + enx) / (ex - enx);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::sch_(basic_t x)
{
	return basic_t(1) / ::cosh(x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::csch_(basic_t x)
{
	return basic_t(1) / ::sinh(x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::actgh_(basic_t x)
{
	return 0.5*::log((x+1.0)/(x-1.0));
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::asch_(basic_t x)
{
	return ::log(::sqrt(basic_t(1) / ::pow(x, 2.0) - basic_t(1)) + basic_t(1) / x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::acsch_(basic_t x)
{
	return ::log(::sqrt(basic_t(1) / ::pow(x, 2.0) + basic_t(1)) + basic_t(1) / x);
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::add_(basic_t x1, basic_t x2)
{
	return x1 + x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::sub_(basic_t x1, basic_t x2)
{
	return x1 - x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::mult_(basic_t x1, basic_t x2)
{
	return x1 * x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::div_(basic_t x1, basic_t x2)
{
	return x1 / x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::lw_(basic_t x1, basic_t x2)
{
	return x1 < x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::le_(basic_t x1, basic_t x2)
{
	return x1 <= x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::gt_(basic_t x1, basic_t x2)
{
	return x1 > x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::ge_(basic_t x1, basic_t x2)
{
	return x1 >= x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::eq_(basic_t x1, basic_t x2)
{
	return x1 == x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::ne_(basic_t x1, basic_t x2)
{
	return x1 != x2;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::x_(basic_t x)
{
	return x;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::neg_(basic_t x)
{
	return -x;
}

///////////////////////////////////////////////////////////////////////////////

basic_t Functions::log_(basic_t b, basic_t x)
{
	return ::log(x)/::log(b);
}

///////////////////////////////////////////////////////////////////////////////

Expr * Functions::matchFunc(x::string const & str, unsigned argnum)
{
	if (argnum >= sizeof(funcMap) || !funcMap[argnum]) return nullptr;
	return funcMap[argnum]->matchFunc(str);
}

///////////////////////////////////////////////////////////////////////////////


ExprMap* Functions::funcMap[4] = {
	nullptr,

	new FuncMap<1>{
		{"-", Functions::neg},

		{"sin", Functions::sin},
		{"cos", Functions::cos},
		{"tg", Functions::tg},
		{"ctg", Functions::ctg},
		{"sc", Functions::sc},
		{"csc", Functions::csc},

		{"asin", Functions::asin},
		{"acos", Functions::acos},
		{"atg", Functions::atg},
		{"actg", Functions::actg},
		{"asc", Functions::asc},
		{"acsc", Functions::acsc},

		{"sinh", Functions::sinh},
		{"cosh", Functions::cosh},
		{"tgh", Functions::tgh},
		{"ctgh", Functions::ctgh},
		{"sch", Functions::sch},
		{"csch", Functions::csch},

		{"asinh", Functions::asinh},
		{"acosh", Functions::acosh},
		{"atgh", Functions::atgh},
		{"actgh", Functions::actgh},
		{"asch", Functions::asch},
		{"acsch", Functions::acsch},

		{"ln", Functions::ln},
		{"log10", Functions::log10},
		{"log2", Functions::log2},
		{"sqrt", Functions::sqrt},
		{"cbrt", Functions::cbrt},
		{"exp", Functions::exp},

		{"abs", Functions::abs},
		{"sgn", Functions::sgn},
		{"floor", Functions::floor},
		{"ceil", Functions::ceil},
		{"mant", Functions::mant}
	},

	new FuncMap<2>{
		{"+", Functions::add},
		{"-", Functions::sub},
		{"*", Functions::mult},
		{"/", Functions::div},
		{"^", Functions::pow},

		{"log", Functions::log},
		{"rand", Functions::rand},
		{"min", Functions::min},
		{"max", Functions::max},
		{"hypot", Functions::hypot}
	},

	new FuncMap<3>{

	}
};