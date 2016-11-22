#ifndef _COMMAND_SEPARATOR_COMPONENT_H_
#define _COMMAND_SEPARATOR_COMPONENT_H_

#include "AnalizerComponent.h"


class CommandSeparatorComponent:
	public AnalizerComponent
{
	char separator_;

public:
	CommandSeparatorComponent(CommandAnalizer& parentAnalizer, char separator);

	virtual void process(x::string& line) const override;
};

#endif //_COMMAND_SEPARATOR_COMPONENT_H_
