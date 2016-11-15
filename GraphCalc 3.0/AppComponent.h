#ifndef _APP_COMPONENT_H_
#define _APP_COMPONENT_H_


class Application;

class AppComponent
{
protected:
	Application& parent_;

public:
	AppComponent(Application& parent);

};

#endif //_APP_COMPONENT_H_
