#ifndef _APP_CONSTANTS_H_
#define _APP_CONSTANTS_H_

#include "SFML\Graphics.hpp"


class AppConstants
{
	static sf::Font font_;

public:
	friend class AppInitializer;


	static inline sf::Font const& getFont()
	{
		return font_;
	}
};

#endif //_APP_CONSTANTS_H_
