#include "Mandelbrot.h"

Mandelbrot::Mandelbrot() noexcept
{
	Image.create(IMAGE_W, IMAGE_H);
}	// Constructor

void Mandelbrot::DrawMandlebrot() noexcept
{
	for (int y = 0; y < IMAGE_H; y++)
	{
		for (int x = 0; x < IMAGE_W; x++)
		{
			double comR = min_Real + (max_Real - min_Real) * x / IMAGE_W;
			double comI = min_Imag + (max_Imag - min_Imag) * y / IMAGE_H;

			double Re = 0, Im = 0;
			int iteration;

			for (iteration = 0; iteration < Max_Iteration; ++iteration)
			{
				double temp = Re * Re - Im * Im + comR;
				Im = 2 * Re * Im + comI;
				Re = temp;

				if (Re * Re + Im * Im > 4.0) break;
			}

			int red = 6.5 * (Max_Iteration - iteration) / Max_Iteration * 255;
			int green = 18.5 * (Max_Iteration - iteration) / Max_Iteration * 255;
			int blue = 18.5 * (Max_Iteration - iteration) / Max_Iteration * 255;
	
			Image.setPixel(x, y, sf::Color(red,green,blue));
		}
		Texture.loadFromImage(Image);
		Sprite.setTexture(Texture);
	}
}	// Draw fractal

void Mandelbrot::Zoom(const double& cR, const double& cI, const double& z) noexcept
{
	double tempminReal = cR - ((max_Real - min_Real) / 2) / z;
	max_Real = cR + ((max_Real - min_Real) / 2) / z;
	min_Real = tempminReal;

	double tempminImag = cI - ((max_Imag - min_Imag) / 2) / z;
	max_Imag = cI + ((max_Imag - min_Imag) / 2) / z;
	min_Imag = tempminImag;
}	// Zoom in-out

void Mandelbrot::Multi_max_Iteration()   noexcept { Max_Iteration *= 2; }

void Mandelbrot::Div_max_Iteration()     noexcept { Max_Iteration /= 2; }

int Mandelbrot::getmax_Iteration() const noexcept { return Max_Iteration; }

sf::Sprite Mandelbrot::getSprite() const noexcept { return Sprite; }

double Mandelbrot::getmin_Real()   const noexcept { return min_Real; }

double Mandelbrot::getmax_Real()   const noexcept { return max_Real; }

double Mandelbrot::getmin_Imag()   const noexcept { return min_Imag; }

double Mandelbrot::getmax_Imag()   const noexcept { return max_Imag; }

void Mandelbrot::setmaxIteration(const int& t) noexcept { Max_Iteration = t; }