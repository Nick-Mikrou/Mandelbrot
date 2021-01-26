#pragma once
#include <SFML/Graphics.hpp>

static const int IMAGE_W = 1280;
static const int IMAGE_H = 720;

class Mandelbrot
{
	private:
		int Max_Iteration = 1024;
		double min_Real = -2.5, max_Real = 1;
		double min_Imag = -1, max_Imag = 1;

		sf::Image Image;
		sf::Texture Texture;
		sf::Sprite Sprite;

	public:
		Mandelbrot() noexcept;
		// Constructor
		
		void DrawMandlebrot()		 noexcept;
		void Zoom(const double&, const double&, const double&) noexcept;
		
		sf::Sprite getSprite() const noexcept;

		void Multi_max_Iteration()	 noexcept;
		void Div_max_Iteration()	 noexcept;
		int getmax_Iteration() const noexcept;
		double getmin_Real()   const noexcept;
		double getmax_Real()   const noexcept;
		double getmin_Imag()   const noexcept;
		double getmax_Imag()   const noexcept;

		void setmaxIteration(const int&) noexcept;
};