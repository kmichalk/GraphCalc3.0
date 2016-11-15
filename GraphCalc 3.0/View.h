#ifndef _VIEW_H_
#define _VIEW_H_

#include "SFML\Graphics.hpp"
#include "types.h"
#include "abstract.h"


class Application;

class View
{
	enum ErrorNum
	{
		ALREADY_INITIALIZED
	};

	static constexpr Size DEFAULT_SCALE = {100.0, -100.0};
	static const sf::Color DEFAULT_BACKGROUND_COLOR;
	static constexpr double DEFAULT_CALC_DENSITY = 0.5;
	static const x::error<View> ALREADY_INITIALIZED_ERROR;
	/*Point viewMin_;
	Point viewMax_;*/

	sf::Color backgroundColor_;
	sf::Vector2f offset_;
	sf::Vector2f crdBegin_;
	double calcDensity_;
	mutable bool changed_;
	//bool revY_;

public:
	Size scale;

	struct Parameters
	{
		static const Parameters DEFAULT;

		sf::VideoMode videoMode;
		char const* winName;
		Size scale;
		sf::Color backgroundColor;

		Parameters(
			sf::VideoMode const& videoMode,
			char const* winName,
			Size const& scale,
			sf::Color backgroundColor);
	};

	Application const& parentApp;
	sf::RenderWindow* window;
	/*View(
	sf::RenderTarget const*	target,
	Point	viewMin = {0.0,0.0},
	Point	viewMax = {0.0,0.0},
	bool	revY_	= false);*/

	View(Application const& parentApp);

	View(
		Application const& parentApp,
		sf::RenderWindow* target,
		Size scale = DEFAULT_SCALE);

	//View& operator=(View const& other);	
	void init(Parameters const& parameters);

	void display();
	void clear();

	sf::Vector2f convert(Point pos) const;
	//void setTarget(sf::RenderWindow* target);
	void setViewRange(Point const& viewMin, Point const& viewMax);
	//void setReverseY(bool value);
	x::range<basic_t> calcFuncRange() const;
	void move(sf::Vector2f vec);
	void setOffset(sf::Vector2f offset);
	sf::Vector2f getOffset() const;
	sf::Vector2f getCrdBegin() const;
	void center();
	void setCalcDensity(double value);
	bool changed() const;
	void clearFlags() const;

	~View();
};

#endif //_COORDINATE_CONVERTER_H_
