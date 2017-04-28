#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "types.h"
#include "strmap.h"

class Variables
{
	static Expr* variablesMap_[256];

public:
	static void set(char identifier, Expr* variable);
	static void unset(char identifier);
	static Expr*& get(char identifier);
	static bool validate(char identifier);
};

#endif //_VARIABLES_H_
