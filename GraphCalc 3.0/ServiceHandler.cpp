#include "ServiceHandler.h"
#include "loops.h"


ServiceHandler::ServiceHandler(Application & parent)
	:
	AppComponent(parent)
{
}

void ServiceHandler::run()
{

}

void ServiceHandler::addService(Service * service)
{
	services_.push_back(service);
}

void ServiceHandler::process()
{
	foreach(service, services_){
		service->process();
	}
}
