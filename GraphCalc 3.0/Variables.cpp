#include "Variables.h"
#include "char_class.h"


void Variables::set(char identifier, Expr * variable)
{
	Expr*& varData = variablesMap_[identifier];
	if (varData) delete varData;
	varData = variable;
}

void Variables::unset(char identifier)
{
	set(identifier, nullptr);
}

Expr*& Variables::get(char identifier)
{
	return variablesMap_[identifier];
}

bool Variables::validate(char identifier)
{
	return x::is_upper(identifier);
}


Expr* Variables::variablesMap_[256] = {nullptr};