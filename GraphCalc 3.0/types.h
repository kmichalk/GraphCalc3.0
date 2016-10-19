#ifndef _TYPES_H_
#define _TYPES_H_

#include "crd.h"
#include "crd_cast.h"
#include "range.h"

using basic_t = double;
using Point = crd<basic_t>;
using Vector = crd<basic_t>;
using Size = crd<basic_t>;
using FuncRange = x::range<basic_t>;

#endif //_TYPES_H_
