#include "CommandSeparatorComponent.h"
#include "CommandAnalizer.h"
#include "loops.h"


CommandSeparatorComponent::CommandSeparatorComponent(
	CommandAnalizer & parentAnalizer, 
	char separator)
	:
	AnalizerComponent(parentAnalizer),
	separator_{separator}
{
}

void CommandSeparatorComponent::process(x::string & line) const
{
	auto commands = line.separate(separator_);
	foreach(command, commands){
		parentAnalizer.analize(*command);
	}
}
