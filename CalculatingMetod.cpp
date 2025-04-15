#include "pch.h"
#include "CalculatingMetod.h"

CalculatingMetod::CalculatingMetod() {}

CalculatingMetod::~CalculatingMetod() {}

double CalculatingMetod::metodDihotomii() {
    double a = 0.0, b = 2.0;
    double eps = 0.000001;
    int max_iter = 1000;
    int iter = 0;

    if (formula(a) * formula(b) >= 0) return NAN;

    while ((b - a) >= eps && iter < max_iter) {
        double c = (a + b) / 2;
        double fc = formula(c);

        if (fabs(fc) < eps) return c > 0 ? c : NAN;

        if (fc * formula(a) < 0) b = c;
        else a = c;

        iter++;
    }

    return (a + b) / 2 > 0 ? (a + b) / 2 : NAN;
}

double CalculatingMetod::metodNewton() {
    double x = 1.0;
    double eps = 0.000001;
    int max_iter = 1000;
    int iter = 0;


    auto derivative = [this](double x) {
        return 0.5 / sqrt(x + 1) + pi * sin((pi * x) / 2);
        };

    while (fabs(formula(x)) > eps && iter < max_iter) {
        double fx = formula(x);
        double dfx = derivative(x);

        if (fabs(dfx) < eps) break;

        x = x - fx / dfx;
        iter++;
    }

    return x > 0 ? x : NAN;
}

double CalculatingMetod::metodIteraciy() {
    
    double x = rudeSearch();
    double a = x;
    double b = x + 0.01;
    double eps = 0.0001;
    while (true)
    {
        double x1 = 2 * acos(sqrt(x + 1) / 2) / pi;
        if (fabs(x1 - x) < eps) return x1;
        x = x1;
    }
    return x;
}

double CalculatingMetod::metodHord() {
    double a = 0.0, b = 2.0; 
    double eps = 0.000001;
    int max_iter = 1000;
    int iter = 0;

    while (fabs(b - a) > eps && iter < max_iter) {
        double fa = formula(a);
        double fb = formula(b);
        double c = a - fa * (b - a) / (fb - fa);
        double fc = formula(c);

        if (fabs(fc) < eps) return c > 0 ? c : NAN;

        if (fa * fc < 0) b = c;
        else a = c;

        iter++;
    }

    return (a + b) / 2 > 0 ? (a + b) / 2 : NAN;
}



