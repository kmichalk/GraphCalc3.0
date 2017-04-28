#ifndef _ASSIGN_ANALIZERR_H_
#define _ASSIGN_ANALIZERR_H_

#include "AnalizerComponent.h"


class AssignAnalizer:
	public AnalizerComponent
{
	char assignSign_;

	void analizeLeft_(x::string& left) const;
	void recognizeLeft_(x::string& left) const;

public:
	AssignAnalizer(CommandAnalizer& parentAnalizer, char assignSign = '=');

	virtual void process(x::string& line) const override;
};

#endif //_ASSIGN_ANALIZERR_H_
