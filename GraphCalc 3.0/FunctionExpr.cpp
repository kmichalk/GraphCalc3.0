#include "FunctionExpr.h"
#include "Functions.h"
#include "CommandAnalizer.h"


x::string::const_iterator FunctionExpr::findLeftBracket_(
	x::string::const_iterator begin) const
{
	auto ch{begin};
	for (; ch; ++ch) {
		if (*ch == '(')
			return ch;
	}
	return ch;
}

///////////////////////////////////////////////////////////////////////////////

x::string::const_iterator FunctionExpr::findRightBracket_(x::string::const_iterator begin) const
{
	int nesting = 0;
	auto ch{begin};
	for (; ch; ++ch) {
		if (*ch == '(') ++nesting;
		if (*ch == ')' && (--nesting) == 0)
			return ch;
		if (nesting < 0) return ch.obj.cend();
	}
	return ch;
}

///////////////////////////////////////////////////////////////////////////////

Expr * FunctionExpr::makeFunc_() const
{
	if (argPack_.size() == 1) {
		auto funcPtr = Functions::oneArgFuncs[funcName_.cstr()];
		return funcPtr.operator bool() ?
			new Func<1>{funcPtr, 
				parentAnalizer.parse(argPack_[0])} :
			nullptr;
	}
	
	if (argPack_.size() == 2){
		auto funcPtr = Functions::twoArgFuncs[funcName_.cstr()];	
		return funcPtr.operator bool() ? 
			new Func<2>{funcPtr,
				parentAnalizer.parse(argPack_[0]),
				parentAnalizer.parse(argPack_[1])}:
			nullptr;
		}

	/*else if (argPack_.size() == 3)
		if (FuncPtr<3> funcPtr = Functions::threeArgFuncs[funcName_.cstr()]) {
			return new Func<3>{funcPtr,
				parse(argPack_[0]),
				parse(argPack_[1]),
				parse(argPack_[2])
			};
		}*/

	return nullptr;
}

///////////////////////////////////////////////////////////////////////////////

FunctionExpr::FunctionExpr(CommandAnalizer const& parentAnalizer)
	:
	ExprParser(parentAnalizer),
	funcName_{},
	argPack_(3)
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * FunctionExpr::match(x::string const& text) const
{
	std::cout << "match func: " << text << std::endl;
	auto left = text.find_first('(');
	if (!left) return nullptr;
	auto right = text.match_bracket(left);
	if (!right) return nullptr;

	funcName_ = text.substr(0, left.value - 1).move();
	argPack_ = text.substr(left.value + 1, right.value - 1).separate(',').move();

	return makeFunc_();
}

bool FunctionExpr::basicValidate(x::string const & text) const
{
	std::cout << "validate func: " << text << std::endl;
	return
		text.size() > 3 &&
		text.last() == ')';
}
