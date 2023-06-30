#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include "class2.h"
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 400), "yappi!");

	ClassAnimatedText::AnimatedText texty("Hello, world!", 1);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)	{ window.close(); }
		}

		Text m_tex;
		Font m_font;

		m_font.loadFromFile("font/pixy.ttf");
		m_tex.setFont(m_font);
		m_tex.setFillColor(Color::Magenta);
		m_tex.setCharacterSize(100);

		m_tex.setString(texty.GetText());
		window.draw(m_tex);
		window.display();
		texty.SleepMode();
		window.clear(Color::White);

		texty.SleepMode();
	}
}