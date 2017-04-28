#ifndef _CURSOR_H_
#define _CURSOR_H_

#include "DrawTask.h"
#include "types.h"
#include "SFML\Graphics.hpp"


class Cursor:
	public DrawTask
{
protected:
	sf::Vector2f position_;

	virtual void refreshPosition_();

public:
	View& targetView;

	Cursor(View& targetView);

	virtual void refresh() abstract override;
	virtual void draw(View& targetView) abstract override;
};

#endif //_CURSOR_H_
