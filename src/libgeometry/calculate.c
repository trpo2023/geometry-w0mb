#include <libgeometry/calculate.h>

float circle_area(float radius) //площадь по дифолту перменных
{
    if (radius > 0)
    {
        return pi * radius * radius;
    }
    
    else 
    {
        return 0;
    }
}

float circle_perimeter(float radius) //периметр по дифолту перменных
{
    if (radius > 0)
    {
        return 2 * pi * radius;
    }

    else 
    {
        return 0;
    }
}