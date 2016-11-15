#ifndef _YAXIS_H_
#define _YAXIS_H_

#include "Axis.h"


class YAxis:
	public Axis
{
	virtual void actualizeCache_() override;

protected:
	virtual void refreshAxis_() override;
	virtual void refreshNumbers_() override;
	virtual void refreshGridLines_() override;

public:
	YAxis(
		Grid const& parent,
		Parameters const& parameters = Parameters::DEFAULT);

};

#endif //_YAXIS_H_
