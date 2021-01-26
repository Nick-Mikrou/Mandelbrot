#include "Application.h"

int main(int argc, char *argv[])
{
	Application Mandelbrot("Mandelbrot", 1280, 720);

	Mandelbrot.Run();

	return 0;
}