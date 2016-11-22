#include "CommandValidator.h"
#include "ValidationRule.h"
#include "CommandAnalizer.h"
#include "Application.h"
#include "error.h"
#include "loops.h"


CommandValidator::CommandValidator(CommandAnalizer & parentAnalizer)
	:
	AnalizerComponent(parentAnalizer)
{
}

void CommandValidator::addRule(ValidationRule * rule)
{
	validationRules_.push_back(rule);
}

void CommandValidator::clear()
{
	validationRules_.erase<x::PTR_DELETE>();
}

CommandValidator::~CommandValidator()
{
	clear();
}

void CommandValidator::process(x::string & line) const
{
	try {
		const_foreach(rule, validationRules_){
			rule->validate(line);
		}
	}
	catch (x::error<>& e) {
		parentAnalizer.parentApplication.logStream << e;
		throw x::error<CommandValidator>{"Validation failed."};
	}
}
