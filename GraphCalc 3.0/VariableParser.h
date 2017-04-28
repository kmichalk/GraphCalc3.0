#ifndef _VARIABLE_PARSER_H_
#define _VARIABLE_PARSER_H_

#include "Parser.h"


class VariableParser:
	public Parser
{
public:
	VariableParser(CommandAnalizer const& parentAnalizer);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;

	virtual ~VariableParser() override;
};

#endif //_VARIABLE_PARSER_H_
