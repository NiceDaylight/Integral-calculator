//Шабанов Р.А.
//РС-з31
//Лабораторна робота №2

#include <stdio.h>
#include "integration.h"

int main() {
    double a, b;
    double epsilon = 0.00001; // Похибка
    double (*selected_method)(double, double, int); // Вибір методу

    // Зчитуємо вхідні данні
    printf("Введіть ліву межу інтегрування a: ");
    scanf("%lf", &a);
    printf("Введіть праву межу інтегрування b: ");
    scanf("%lf", &b);
    while (epsilon <= 0.00001 || epsilon > 0.001) {
        printf("Введіть похибку ε (між 0.00001 і 0.001): ");
        scanf("%lf", &epsilon);
    }
    // Вибір методу для розрахунку
    printf("Виберіть метод для розрахунку інтегралу:\n");
    printf("1. Метод прямокутників\n");
    printf("2. Метод трапецій\n");
    printf("3. Метод Сімпсона\n");
    printf("4. Метод середньої точки\n");
    printf("Ваш вибір: ");
    int method_choice;
    if (scanf("%d", &method_choice) != 1 || method_choice < 1 || method_choice > 4) {
        printf("Невірний вибір методу.\n");
        return 1; // Помилка виконання
    }

    double result;

    // Привласнюємо вибраний метод
    switch (method_choice) {
        case 1:
            selected_method = rectangle_method;
            break;
        case 2:
            selected_method = trapezoidal_method;
            break;
        case 3:
            selected_method = simpson_method;
            break;
        case 4:
            selected_method = midpoint_method;
            break;
        default:
            printf("Невірний вибір методу.\n");
            return 1; // Помилка виконання
    }

    result = selected_method(a, b, 30);
    printf("Значення інтегралу для n=30: %.6lf\n", result);

    result = selected_method(a, b, 100);
    printf("Значення інтегралу для n=100: %.6lf\n", result);

    result = selected_method(a, b, 1000);
    printf("Значення інтегралу для n=1000: %.6lf\n", result);

    result = selected_method(a, b, 10000);
    printf("Значення інтегралу для n=10000: %.6lf\n", result);

    int calculated_n = calculate_intervals(a, b, epsilon, selected_method);

    printf("Кількість проміжків N для заданої похибки ε: %d\n", calculated_n);

    // Розрахунок інтегралу з обраною кількістю проміжків
    result = selected_method(a, b, calculated_n);
    printf("Значення інтегралу з кількістю проміжків N: %.6lf\n", result);

    // Розрахунок інтегралу з кількістю проміжків N+2
    result = selected_method(a, b, calculated_n + 2);
    printf("Значення інтегралу з кількістю проміжків N+2: %.6lf\n", result);


    return 0;
}
