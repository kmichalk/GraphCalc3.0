#include "PackParser.h"
#include "PackExpr.h"
#include "CommandAnalizer.h"



PackParser::PackParser(
	CommandAnalizer const& parentAnalizer,
	char leftDelim,
	char rightDelim,
	char separator)
	:
	Parser(parentAnalizer),
	leftDelim_{leftDelim},
	rightDelim_{rightDelim},
	separator_{separator}
{
}

Expr * PackParser::match(x::string const & text) const
{
	if (*text.first() == leftDelim_ && *text.last() == rightDelim_) {
		x::vector<x::string> pack{text.substr(1,text.lastpos() - 1).separate(separator_)};
		x::vector<Expr*> exprPack(pack.size());
		foreach(str, pack)
			exprPack.push_back(parentAnalizer.parse(*str));
		return new Pack{exprPack};
	}
	return nullptr;
}

bool PackParser::basicValidate(x::string const & text) const
{
	return text.size() >= 3;
}

PackParser::~PackParser()
{
}
