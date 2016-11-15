#include "ExprParser.h"
#include "loops.h"


//Expr * ExprParser::matchExpr_(char const * text)
//{
//	return exprMap_[text];
//}
//
//Expr* ExprParser::matchOperator_(char ch)
//{
//	static x::vector<char> operators{operators_};
//
//	if (operators.contain(ch)) {
//		return matchExpr_(x::string(ch).cstr());
//	}
//	return nullptr;
//}
//
//Expr * ExprParser::parseAddSub_(x::string const & text)
//{
//	unsigned nesting = 0;
//	for (size_t ch = 0; ch < text.size(); ++ch) {
//		if (text[ch] == '(')
//			++nesting;
//		if (text[ch] == ')')
//			--nesting;
//		if (!nesting) {
//			if (text[ch] == '+') {
//				return new Func<2>{Functions::add,
//					parse_(text.substr(0, ch - 1)),
//					parse_(text.substr(ch + 1, text.last_pos()))};
//			}
//			if (text[ch] == '-') {
//				return new Func<2>{Functions::sub,
//					parse_(text.substr(0, ch - 1)),
//					parse_(text.substr(ch + 1, text.last_pos()))};
//			}
//		}
//	}
//}
//
//Expr * ExprParser::parseMultDiv_(x::string const & text)
//{
//	unsigned nesting = 0;
//	for (size_t ch = 0; ch < text.size(); ++ch) {
//		if (text[ch] == '(')
//			++nesting;
//		if (text[ch] == ')')
//			--nesting;
//		if (!nesting) {
//			if (text[ch] == '*') {
//				return new Func<2>{Functions::mult,
//					parse_(text.substr(0, ch - 1)),
//					parse_(text.substr(ch + 1, text.last_pos()))};
//			}
//			if (text[ch] == '/') {
//				return new Func<2>{Functions::div,
//					parse_(text.substr(0, ch - 1)),
//					parse_(text.substr(ch + 1, text.last_pos()))};
//			}
//		}
//	}
//}
//
//Expr * ExprParser::parseOperators_(size_t order, x::string const & text)
//{
//	/*unsigned nesting = 0;
//	for (size_t ch = 0; ch < text.size(); ++ch) {
//		if (text[ch] == '(')
//			++nesting;
//		if (text[ch] == ')')
//			--nesting;
//		if (!nesting) {
//			for (auto op : operatorOrder_[order]) {
//				if (text[ch] == op) {
//					if (auto resultExpr = matchExpr_(x::string{op}.cstr())) {
//						
//					},
//						parse_(text.substr(0, ch - 1)),
//						parse_(text.substr(ch + 1, text.last_pos()))};
//				}
//			}
//		}
//	}*/
//	return nullptr;
//}

///////////////////////////////////////////////////////////////////////////////

//Expr * ExprParser::parseOperator_(x::string const & text)
//{
//	parseAddSub_(text);
//	parseMultDiv_(text);
//	return nullptr;
//}

///////////////////////////////////////////////////////////////////////////////

//Expr * ExprParser::parsePowRest_(x::string const & text)
//{
//	unsigned nesting = 0;
//	for (size_t ch = 0; ch < text.size(); ++ch) {
//		if (text[ch] == '(')
//			++nesting;
//		if (text[ch] == ')')
//			--nesting;
//		if (!nesting) {
//			if (text[ch] == '^') {
//				return new Func<2>{Functions::div,
//					parse_(text.substr(0, ch - 1)),
//					parse_(text.substr(ch + 1, text.last_pos()))};
//			}
//		}
//	}
//}

//Expr * ExprParser::matchBracket_(x::string forward)
//{
//	unsigned nesting = 0;
//	for (size_t ch = 0; ch < forward.size(); ++ch) {
//		if (forward[ch] == '(') 
//			++nesting;
//		if (forward[ch] == ')' && !(--nesting)) {
//			return parse_(forward.substr(0, ch - 1));
//		}
//	}
//}

//Expr * ExprParser::parse_(x::string text)
//{
//	parseOperator_(text);
//	return nullptr;
//}

//ExprParser::ExprParser()
//{
//}

//Expr * ExprParser::parse(x::string const& line)
//{
//	//line_ = line;
//	//parse_(line);
//	//unsigned nesting = 0;
//	//char buffer[256];
//	//for (char const* ch = line; *ch; ++ch) {
//	//	if (*ch == '(') {
//
//	//	}
//	//}
//	return nullptr;
//}

ExprParser::ExprParser(CommandAnalizer const & parentAnalizer)
	:
	parentAnalizer{parentAnalizer}
{
}
