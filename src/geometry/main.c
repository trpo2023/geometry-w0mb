#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>

#define SIZE 100
#define pi 3.14159265359

float circle_area(double radius) //площадь по дифолту перменных
{
    return pi * radius * radius;
}

float circle_perimeter(double radius) //периметр по дифолту перменных
{
    return 2 * pi * radius;
}

struct point //определение координаты по иксу игрику
{
    double x;
    double y;
};

struct circle // определение радиуса
{
    struct point center; // ?
    double radius;
    double perimeter;
    double area;
};

struct point center_search(char* arr, int* num) // ищем центр круга
{
    struct point Center; // ?

    Center.x = coordinat_x(arr, num);
    Center.y = coordinat_y(arr, num);

    return Center;
};

struct circle circle_search(struct point* Center, char* arr, int* num)
{
    struct circle Circle; // ?

    Circle.center.x = Center->x; // ?
    Circle.center.y = Center->y; // ?
    Circle.radius = radius_search(arr, num);

    return Circle;
};

struct point2 //определение координаты по иксу игрику
{
    double x2;
    double y2;
};
struct circle2
{
    struct point2 center2; // ?
    double radius2;
    double perimeter2;
    double area2;
};

struct point2 center_search2(char* arr, int* num) // ищем центр круга
{
    struct point2 Center2; // ?

    Center2.x2 = coordinat_x(arr, num);
    Center2.y2 = coordinat_y(arr, num);

    return Center2;
};

struct circle2 circle_search2(struct point2* Center2, char* arr, int* num)
{
    struct circle2 Circle2; // ?

    double radius2 = radius_search(arr, num);

    Circle2.center2.x2 = Center2->x2; // ?
    Circle2.center2.y2 = Center2->y2; // ?
    Circle2.radius2 = radius2;
    Circle2.perimeter2 = circle_perimeter(radius2);
    Circle2.area2 = circle_area(radius2);

    return Circle2;
};


void show_circle(struct circle* Circle)
{
    printf("\ncircle(%.2f %.2f, %.2f, %.2f, %.2f)\n",
           Circle->center.x,
           Circle->center.y,
           Circle->radius,
           Circle->perimeter,
           Circle->area);
};


void show_circle2(struct circle2* Circle2)
{
    printf("\ncircle2(%.2f %.2f, %.2f, %.2f, %.2f)\n",
           Circle2->center2.x2,
           Circle2->center2.y2,
           Circle2->radius2,
           Circle2->perimeter2,
           Circle2->area2);
};

int intersection(struct circle* circle_1, struct circle2* circle_2)
{
    double x1 = circle_1->center.x;
    double y1 = circle_1->center.y;
    double radius1 = circle_1->radius;
    //во второй структуре хранится первый круг
    double x2 = circle_2->center2.x2;
    double y2 = circle_2->center2.y2;
    double radius2 = circle_2->radius2;
    //(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) > (r1+r2)*(r1+r2)
    if (((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) >= (radius1+radius2)*(radius1+radius2))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    char enter[SIZE], figure[SIZE];
    int num = 0;
    struct circle circle_1;
    struct circle2 circle_2;
    printf("Enter a geometric figure (or press Enter for exit):\n");
    fgets(enter, SIZE, stdin);

    for (int i = 0; i < strlen(enter); i++)
    {
        if (enter[i] == '(' || enter[i] == ' ')
        {
            to_lower(figure, num);
            if (strcmp(figure, "circle") == 0)
            {
                struct point Center = center_search(enter, &num); // ?
                struct circle Circle = circle_search(&Center, enter, &num); // ?
                is_end_empty(enter, &num);
                show_circle(&Circle);
                break;
            }
            else
            {
                show_error(ERROR_NAME, 0, NULL);
                exit(EXIT_FAILURE);
            }
        }
        
        else if (enter[i] == ')')
        {
            show_error(ERROR_BRACKET, num, &enter[i]);
            exit(EXIT_FAILURE);
        }

        figure[num] = enter[i];
        num++;
    }

    char enter1[SIZE], figure1[SIZE];
    num = 0;
    printf("Enter an another geometric figure (or press Enter for exit):\n");
    fgets(enter1, SIZE, stdin);

    for (int i = 0; i < strlen(enter1); i++)
    {
        if (enter1[i] == '(' || enter1[i] == ' ')
        {
            to_lower(figure1, num);
            if (strcmp(figure1, "circle") == 0)
            {
                struct point2 Center2 = center_search2(enter1, &num); // ?
                struct circle2 Circle2 = circle_search2(&Center2, enter1, &num); // ?
                is_end_empty(enter1, &num);
                show_circle2(&Circle2);
                break;
            }
            else
            {
                show_error(ERROR_NAME, 0, NULL);
                exit(EXIT_FAILURE);
            }
        }
        
        else if (enter1[i] == ')')
        {
            show_error(ERROR_BRACKET, num, &enter1[i]);
            exit(EXIT_FAILURE);
        }

        figure1[num] = enter1[i];
        num++;
    }
    
    int a = intersection(&circle_1, &circle_2);
    if(a == 1){printf("circles are intersection");}
    else{printf("circles are unintersection");}

    return 0;
}
