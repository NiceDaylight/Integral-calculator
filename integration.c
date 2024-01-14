#include "integration.h"
#include <math.h>
#include <stdio.h>


double f(double x) {
    // Задайте вашу функцію тут
    return 1/(sqrt(25+3*x)); // Приклад: x^2
}

double rectangle_method(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        integral += f(x);
    }
    integral *= h;
    return integral;
}

double trapezoidal_method(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        double x0 = a + i * h;
        double x1 = a + (i + 1) * h;
        integral += (f(x0) + f(x1)) / 2;
    }
    integral *= h;
    return integral;
}

double simpson_method(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Кількість проміжків повинна бути парною для методу Сімпсона.\n");
        return 0.0;
    }
    double h = (b - a) / n;
    double integral = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            integral += 2 * f(x);
        } else {
            integral += 4 * f(x);
        }
    }
    integral *= h / 3;
    return integral;
}

double midpoint_method(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * h;
        integral += f(x);
    }
    integral *= h;
    return integral;
}

int calculate_intervals(double a, double b, double epsilon, double (*method)(double, double, int)) {
    int n = 1;
    double I1, I2, error;

    I1 = method(a, b, n);

    do {
        n += 2;
        I2 = method(a, b, n);
        error = fabs(I1 - I2);
        I1 = I2;
    } while (error > epsilon);

    return n;
}