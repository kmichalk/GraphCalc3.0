#ifndef _DRAW_HANDLER_H_
#define _DRAW_HANDLER_H_

#include "ServiceHandler.h"


class View;

class DrawHandler:
	public ServiceHandler
{
public:
	View& targetView;

	DrawHandler(View& targetView);

	virtual void prepare() override;
};

#endif //_DRAW_HANDLER_H_
