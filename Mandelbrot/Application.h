#pragma once
#include "Mandelbrot.h"

class Application
{
	private:
		sf::RenderWindow Window;
		int Width, Height;
		std::string Title;

		Mandelbrot mb;

	public:
		Application(const std::string&, const unsigned int&, const unsigned int&);
		// Constructor

		void SetWindowPosition() noexcept;
		void Run()				 noexcept;	
};