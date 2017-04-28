#include "ServiceHandler.h"
#include "loops.h"


ServiceHandler::ServiceHandler(Application & parentApplication)
	:
	AppComponent(parentApplication),
	TimedProcess()
{
}

ServiceHandler::ServiceHandler(
	Application & parentApplication,
	double processPeriod)
	:
	AppComponent(parentApplication),
	TimedProcess(processPeriod)
{
}

void ServiceHandler::task()
{
	foreach(service, services_) {
		service->process();
	}
}

void ServiceHandler::addService(Service * service)
{
	services_.push_back(service);
}

void ServiceHandler::clear()
{
	services_.clear<x::PTR_DELETE>();
}

ServiceHandler::~ServiceHandler()
{
	clear();
}
