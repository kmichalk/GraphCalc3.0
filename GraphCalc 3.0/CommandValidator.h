#ifndef _COMMAND_VALIDATOR_H_
#define _COMMAND_VALIDATOR_H_

#include "AnalizerComponent.h"


class ValidationRule;

class CommandValidator:
	public AnalizerComponent
{
	x::vector<ValidationRule*> validationRules_;

public:
	CommandValidator(CommandAnalizer& parentAnalizer);

	virtual void process(x::string& line) const override;
	void addRule(ValidationRule* rule);
	void clear();

	~CommandValidator();
};

#endif //_COMMAND_VALIDATOR_COMPONENT_H_
