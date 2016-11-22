#ifndef _VALIDATION_RULE_H_
#define _VALIDATION_RULE_H_

#include "xstring.h"


class ValidationRule
{
public:
	virtual void validate(x::string const& str) const abstract;
};

#endif //_VALIDATION_RULE_H_
