#ifndef _FUNCTION_RECOGNIZER_H_
#define _FUNCTION_RECOGNIZER_H_

#include "AnalizerComponent.h"


class FunctionRecognizer:
	public AnalizerComponent
{
public:
	FunctionRecognizer(CommandAnalizer& parentAnalizer);

	virtual void process(x::string& line) const override;
};

#endif //_FUNCTION_RECOGNIZER_H_