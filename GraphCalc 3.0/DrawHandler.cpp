#include "DrawHandler.h"
#include "Application.h"
#include "loops.h"


DrawHandler::DrawHandler(View & targetView)
	:
	ServiceHandler(targetView.parentApplication),
	targetView{targetView}
{
}

void DrawHandler::prepare()
{
	parentApplication.initView();
}