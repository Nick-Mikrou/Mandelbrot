#include "Application.h"
#include <iostream>

Application::Application(const std::string& title, const unsigned int& width, const unsigned int& height)
	:Title(title), Width(width), Height(height), Window({ width,height }, title)
{
	SetWindowPosition();
	mb.DrawMandlebrot();
}	// Constructor

void Application::SetWindowPosition() noexcept
{
	Window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - Window.getSize().x / 2,
									sf::VideoMode::getDesktopMode().height / 2 - Window.getSize().y / 2));
}	// Set window's position

void Application::Run() noexcept
{
	while (Window.isOpen())
	{
		sf::Event e;
		while (Window.pollEvent(e))
		{
			double cR = mb.getmin_Real() + (mb.getmax_Real() - mb.getmin_Real()) * e.mouseButton.x / Width;
			double cI = mb.getmin_Imag() + (mb.getmax_Imag() - mb.getmin_Imag()) * e.mouseButton.y / Height;
			switch (e.type)
			{
				case sf::Event::Closed:
					Window.close();
					break;

				case sf::Event::MouseButtonPressed:
					switch (e.mouseButton.button)
					{						
						case sf::Mouse::Left:
							mb.Zoom(cR, cI, 3);													
							break;

						case sf::Mouse::Right:							
							mb.Zoom(cR, cI, 1.0 / 3);
							break;
					}

				case sf::Event::MouseWheelScrolled:
					switch (e.mouseWheelScroll.wheel)
					{
						case sf::Mouse::VerticalWheel:
							if (mb.getmax_Iteration() < 0) mb.setmaxIteration(1);
							e.mouseWheelScroll.delta > 0 ? mb.Multi_max_Iteration() : mb.Div_max_Iteration();
							break;					
					}
					mb.DrawMandlebrot();
			}
		}
		Window.draw(mb.getSprite());
		Window.display();
	}
}	// Start the application