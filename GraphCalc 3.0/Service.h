#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "AppComponent.h"


class Service:
	public AppComponent
{
public:
	Service(Application& parentApplication);

	virtual void process() abstract;
	//virtual void run() abstract;
};

#endif //_SERVICE_H_
