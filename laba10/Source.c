#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

void task1();

double fa(double x);
double fb(double x);
double cos_n(double x, int N);
double cos_eps(double x, double eps);

int main() 
{
    setlocale(LC_ALL, "RUS");
    task1();
}
void task1()
{
    int task, menu, N;
    double x, eps;
    puts("Выберите задание: 1 — две функции, 2 — сравнение способов вычисления cos(x)");
    if (scanf("%d", &task) != 1) return 0;

    if (task == 1)
    {
        puts("Введите x");
        scanf("%lf", &x);
        printf("fa(x) = %lf, fb(x) = %lf\n", fa(x), fb(x));
        printf("произведение = %lf, разность квадратов = %lf, удвоенная сумма = %lf\n",
            fa(x) * fb(x), fa(x) * fa(x) - fb(x) * fb(x), 2 * (fa(x) + fb(x)));
        do {
            puts("Что посчитать?");
            puts("1 - fa(x)");
            puts("2 - fb(x)");
            puts("3 - произведение fa(x) * fb(x)");
            puts("4 - разность квадратов fa(x)^2 - fb(x)^2");
            puts("5 - удвоенная сумма 2 * (fa(x) + fb(x))");
            puts("6 - ввести другой x");
            puts("0 - выход");
            scanf("%d", &menu);
            switch (menu)
            {
            case 1:
                printf("fa(%g) = %lf\n", x, fa(x));
                break;
            case 2:
                printf("fb(%g) = %lf\n", x, fb(x));
                break;
            case 3:
                printf("произведение = %lf\n", fa(x) * fb(x));
                break;
            case 4:
                printf("разность квадратов = %lf\n", fa(x) * fa(x) - fb(x) * fb(x));
                break;
            case 5:
                printf("удвоенная сумма = %lf\n", 2 * (fa(x) + fb(x)));
                break;
            case 6:
                puts("Введите x");
                scanf("%lf", &x);
                break;
            case 0:
                break;
            default:
                puts("Нет такого пункта");
            }
        } while (menu != 0);
    }
    else if (task == 2)
    {
        puts("Введите x, число членов ряда N и точность eps");
        if (scanf("%lf %d %lf", &x, &N, &eps) != 3) return 0;
        if (N < 1 || eps <= 0) {
            puts("Нужно N > 0 и eps > 0");
            return 0;
        }
        printf("cos(x) из math.h: %.10f\n", cos(x));
        printf("cos_n(x, %d):    %.10f (разница %.2e)\n", N, cos_n(x, N), fabs(cos(x) - cos_n(x, N)));
        printf("cos_eps(x, %g): %.10f (разница %.2e)\n", eps, cos_eps(x, eps), fabs(cos(x) - cos_eps(x, eps)));
    }
    else {
        puts("Нет такого задания");
    }

    return 0;
}
    // F1(x) = x^2 - 3x + 9 при x <= 3, 1 / (x^3 + 3) при x > 3
    double fa(double x)
    {
        double y;
        if (x <= 3)
            y = x * x - 3 * x + 9;
        else
            y = 1 / (x * x * x + 3);
        return y;
    }

    // F2(x) = x * e^sin(x^2)
    double fb(double x)
    {
        double y;
        y = x * exp(sin(x * x));
        return y;
    }

    // Вариант 3
    double cos_n(double x, int N)
    {
        double part = 1, sum = 0;
        for (int k = 0; k < N; k++)
        {
            sum += part;
            part *= -x * x / ((2.0 * k + 1) * (2.0 * k + 2));
        }
        return sum;
    }

    double cos_eps(double x, double eps)
    {
        double part = 1, sum = 0;
        int k = 0;
        while (fabs(part) >= eps) {
            sum += part;
            part *= -x * x / ((2.0 * k + 1) * (2.0 * k + 2));
            k++;
        }
        return sum;
    }
