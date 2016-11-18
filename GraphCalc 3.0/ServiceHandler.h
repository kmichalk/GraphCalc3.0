#ifndef _SERVICE_HANDLER_H
#define _SERVICE_HANDLER_H_

#include "AppComponent.h"
#include "Service.h"
#include "xvector.h"

class ServiceHandler:
	public AppComponent
{
	x::vector<Service*> services_;

public:
	ServiceHandler(Application& parent);

	virtual void run();
	//virtual void run_thread();
	virtual void process();
	virtual void addService(Service* service);
};

#endif //_SERVICE_HANDLER_H_
