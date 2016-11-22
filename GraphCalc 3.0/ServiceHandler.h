#ifndef _SERVICE_HANDLER_H
#define _SERVICE_HANDLER_H_

#include "AppComponent.h"
#include "Service.h"
#include "threaded.h"
#include "xvector.h"


class ServiceHandler:
	public AppComponent,
	public TimedProcess
{
protected:
	x::vector<Service*> services_;

public:
	ServiceHandler(Application& parentApplication);
	ServiceHandler(Application& parentApplication, double processPeriod);
	//virtual void run_thread();
	virtual void task() override;
	virtual void addService(Service* service);
	virtual void clear();

	~ServiceHandler();
};

#endif //_SERVICE_HANDLER_H_
