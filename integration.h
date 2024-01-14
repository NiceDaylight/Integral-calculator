#ifndef INTEGRATION_H
#define INTEGRATION_H

// Оголошення підінтегральної функції
double f(double x);

// Оголошення функцій для різних методів обчислення інтегралу
double rectangle_method(double a, double b, int n);
double trapezoidal_method(double a, double b, int n);
double simpson_method(double a, double b, int n);
double midpoint_method(double a, double b, int n);

// Функція для обчислення кількості проміжків згідно з алгоритмом
int calculate_intervals(double a, double b, double epsilon, double (*method)(double, double, int));


#endif