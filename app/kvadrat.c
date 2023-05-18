#include <stdio.h>
#include <math.h>

#include "kvadrat.h"

//функция решения квадратного уравнения
//возаращаемое значение
//0 - 2 корня
//1 - нет решения
//2 - 1 корень
//3 - бесконечно много решении

int kvadrat(double a,double b, double c,double* res1,double* res2)
{
    if(a == b && b == c && c == 0)
        return 3;
    if(a == b && b == 0 && c != 0)
        return 1;
    if(((a == c && c == 0) && b != 0)||(b == c && c == 0 && a != 0))
    {
        *res1 = *res2 = 0;
        return 2;
    }

    double d = 0;
    d = b*b-4*a*c;
    if(d >= 0)
    {
        if(d == 0)
        {
            double x;
            x = -b/2*a;
            *res1 = *res2 = x;
            return 2;
        }
        else
        {
            double x1,x2;
            x1 = (-b+sqrt(d))/(2*a);
            x2 = (-b-sqrt(d))/(2*a);
            *res1 = x1;
            *res2 = x2;
            return 0;
        }
    }
    return 1;
}
