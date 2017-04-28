#ifndef _ARGUMENT_PARSER_H_
#define _ARGUMENT_PARSER_H_

#include "Parser.h"


class ArgumentParser:
	public Parser
{
	static constexpr char const DEFAULT_VAR_NAME[] = "x";

	x::string varName_;

public:
	ArgumentParser(
		CommandAnalizer const& parentAnalizer, 
		x::string const& varName = DEFAULT_VAR_NAME);

	virtual Expr* match(x::string const& text) const override;
	virtual bool basicValidate(x::string const& text) const override;
};

#endif //_ARGUMENT_PARSER_H_
