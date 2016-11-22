#ifndef _ANALIZER_COMPONENT_H_
#define _ANALIZER_COMPONENT_H_

#include "xstring.h"


class CommandAnalizer;

class AnalizerComponent
{
public:
	CommandAnalizer& parentAnalizer;

	AnalizerComponent(CommandAnalizer& parentAnalizer);
	
	virtual void process(x::string& line) const abstract;
	virtual ~AnalizerComponent();
};

#endif //_ANALIZER_COMPONENT_H_
