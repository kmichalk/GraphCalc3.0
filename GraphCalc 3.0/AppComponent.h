#ifndef _APP_COMPONENT_H_
#define _APP_COMPONENT_H_


class Application;

class AppComponent
{
protected:

public:
	Application& parentApplication;

	AppComponent(Application& parentApplication);

};

#endif //_APP_COMPONENT_H_
