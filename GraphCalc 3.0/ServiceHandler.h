#ifndef _SERVICE_HANDLER_H
#define _SERVICE_HANDLER_H_

#include "AppComponent.h"


class ServiceHandler:
	public AppComponent
{
public:
	ServiceHandler(Application& parent);

	virtual void process() abstract;

};

#endif //_SERVICE_HANDLER_H_
