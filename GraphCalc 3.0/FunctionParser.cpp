#include "FunctionParser.h"
#include "Functions.h"
#include "CommandAnalizer.h"
#include "loops.h"


x::string::const_iterator FunctionParser::findLeftBracket_(
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

x::string::const_iterator FunctionParser::findRightBracket_(x::string::const_iterator begin) const
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

Expr * FunctionParser::makeFunc_(x::string const& funcName, x::vector<x::string>& args) const
{
	std::cout << args.size()<<" "<< args;
	if (ArgExpr* func = Functions::matchFunc(funcName, args.size())) {
		x::vector<Expr*> argsExprBuffer{args.size()};
		foreach(arg, args)
		{
			std::cout << "arg: " << *arg << std::endl;
			argsExprBuffer.push_back(parentAnalizer.parse(*arg));
		}
		if (func->setArgs(argsExprBuffer.data(), argsExprBuffer.size()))
			return func;
	}
	return nullptr;
}

///////////////////////////////////////////////////////////////////////////////

FunctionParser::FunctionParser(CommandAnalizer const& parentAnalizer)
	:
	Parser(parentAnalizer)
{
}

///////////////////////////////////////////////////////////////////////////////

Expr * FunctionParser::match(x::string const& text) const
{
	std::cout << "match func: " << text << std::endl;
	auto left = text.find_first('(');
	if (!left) 
		return nullptr;
	auto right = text.match_bracket(*left);
	if (!right) 
		return nullptr;

	return makeFunc_(
		text.substr(0, *left - 1),
		text.substr(*left + 1, *right - 1).separate(','));
}

bool FunctionParser::basicValidate(x::string const & text) const
{
	std::cout << "validate func: " << text << std::endl;
	return
		text.size() > 3 &&
		*text.last() == ')';
}
