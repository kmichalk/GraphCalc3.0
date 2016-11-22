#include "IllegalCharRule.h"
#include "error.h"
#include "loops.h"


IllegalCharRule::IllegalCharRule(std::initializer_list<char> illegalChar)
	:
	illegalChar_{0}
{
	for (char ch : illegalChar)
		illegalChar_[ch] = true;
}

void IllegalCharRule::validate(x::string const & str) const
{
	x::string found;
	const_foreach(ch, str){
		if (illegalChar_[*ch]) 
			found += x::string{*ch} += x::string{" "};
	}
	if (!found.empty())
		throw x::error<IllegalCharRule>{x::string{"Following illegal characters found: "} +found};
}
