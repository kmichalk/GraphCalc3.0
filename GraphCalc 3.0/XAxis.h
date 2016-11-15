#ifndef _XAXIS_H_
#define _XAXIS_H_

#include "Axis.h"


class XAxis:
	public Axis
{
	virtual void actualizeCache_() override;

protected:
	virtual void refreshAxis_() override;
	virtual void refreshNumbers_() override;
	virtual void refreshGridLines_() override;

public:
	XAxis(
		Grid const& parent,
		Parameters const& parameters = Parameters::DEFAULT);

};

#endif //_XAXIS_H_
