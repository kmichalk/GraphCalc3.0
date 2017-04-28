#include "AssignAnalizer.h"
#include "CommandAnalizer.h"


void AssignAnalizer::analizeLeft_(x::string & left) const
{
	auto leftBr = left.find_first('(');
	auto rightBr = left.find_last(')');
	if (leftBr && rightBr && *rightBr - *leftBr > 1) {
		parentAnalizer.notify.foundFuncName(left.substr(0, *leftBr - 1));
		parentAnalizer.notify.foundArgName(left.substr(*leftBr + 1, left.lastpos() - 1));
	}
	else if (!leftBr && !rightBr) {
		
	}
}

void AssignAnalizer::recognizeLeft_(x::string & left) const
{
	
}

AssignAnalizer::AssignAnalizer(
	CommandAnalizer & parentAnalizer, 
	char assignSign)
	:
	AnalizerComponent(parentAnalizer),
	assignSign_{assignSign}
{
}

void AssignAnalizer::process(x::string & line) const
{
	if (line.empty()) return;
	if (auto assignPos = line.find_first(assignSign_))
		analizeLeft_(line.substr(0,*assignPos - 1));
}
