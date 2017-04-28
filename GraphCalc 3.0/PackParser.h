#ifndef _PACK_PARSER_H_
#define _PACK_PARSER_H_

#include "Parser.h"


class PackParser:
	public Parser
{
	char leftDelim_;
	char rightDelim_;
	char separator_;

public:
	PackParser(CommandAnalizer const& parentAnalizer, char leftDelim, char rightDelim, char separator = ',');

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;

	virtual ~PackParser() override;
};

#endif //_PACK_PARSER_H_
