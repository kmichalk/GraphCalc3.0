#ifndef _ILLEGAL_CHAR_RULE_H_
#define _ILLEGAL_CHAR_RULE_H_

#include "ValidationRule.h"


class IllegalCharRule:
	public ValidationRule
{
	bool illegalChar_[256];

public:
	IllegalCharRule(std::initializer_list<char> illegalChar);

	virtual void validate(x::string const& str) const override;
};

#endif //_ILLEGAL_CHARACTERS_RULE_H_
