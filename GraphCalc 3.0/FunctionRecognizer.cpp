#include "FunctionRecognizer.h"
#include "CommandAnalizer.h"


FunctionRecognizer::FunctionRecognizer(CommandAnalizer & parentAnalizer)
	:
	AnalizerComponent(parentAnalizer)
{
}

void FunctionRecognizer::process(x::string & line) const
{
	if (auto firstBr = line.find_first('(')) {
		x::string funcName = line.substr(0, *firstBr - 1);
		if (!funcName.empty()) {
			parentAnalizer.plotBuffer.last()->funcName = funcName;
		}
	}
}
