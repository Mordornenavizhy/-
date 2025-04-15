#pragma once

#include <cmath>;
class CalculatingMetod
{
	double pi = 3.1415;
	double formula(double x) {
		return (sqrt(x+1) - 2*cos((pi*x)/2));
	}
double rudeSearch()
{
	for (double x = -0.1; x <= 0.7; x += 0.01)
	{
		if (formula(x) * formula(x + 0.01) < 0) return x;
	}
}

public:
	CalculatingMetod();

	~CalculatingMetod();

	double metodIteraciy();

	double metodNewton();

	double metodHord();

	double metodDihotomii();
};
