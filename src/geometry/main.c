#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <libgeometry/calculate.h>
#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>
#include <libgeometry/intersect.h>

#define SIZE 100

struct point center_search(char* arr, int* num) // ищем центр круга
{
    struct point Center; 

    Center.x = coordinat_x(arr, num);
    Center.y = coordinat_y(arr, num);

    return Center;
};

struct point2 center_search2(char* arr, int* num) // ищем центр круга
{
    struct point2 Center2; 

    Center2.x2 = coordinat_x(arr, num);
    Center2.y2 = coordinat_y(arr, num);

    return Center2;
};

struct circle circle_search(struct point* Center, char* arr, int* num)
{
    struct circle Circle; 

    float radius = radius_search(arr, num);

    Circle.Center.x = Center->x; 
    Circle.Center.y = Center->y; 
    Circle.radius = radius;
    Circle.perimeter = circle_perimeter(radius);
    Circle.area = circle_area(radius);

    return Circle;
};

 struct circle2 circle_search2(struct point2* Center2, char* arr, int* num)
 {
     struct circle2 Circle2; 

     float radius2 = radius_search(arr, num);

     Circle2.Center2.x2 = Center2->x2; 
     Circle2.Center2.y2 = Center2->y2; 
     Circle2.radius2 = radius2;
     Circle2.perimeter2 = circle_perimeter(radius2);
     Circle2.area2 = circle_area(radius2);

     return Circle2;
 };

void show_circle(struct circle* Circle)
{
    printf("\ncircle(%.2f %.2f, %.2f, %.2f, %.2f)\n",
           Circle->Center.x,
           Circle->Center.y,
           Circle->radius,
           Circle->perimeter,
           Circle->area);
};

void show_circle2(struct circle2* Circle2)
{
    printf("\ncircle2(%.2f %.2f, %.2f, %.2f, %.2f)\n",
           Circle2->Center2.x2,
           Circle2->Center2.y2,
           Circle2->radius2,
           Circle2->perimeter2,
           Circle2->area2);
};

int main()
{      
    char enter[SIZE], figure[SIZE];
    int num = 0;

    printf("Enter the first circle like that 'circle(x y,r)' or press enter to exit:\n");

    fgets(enter, SIZE, stdin);

    for (int i = 0; i < strlen(enter); i++) 
    {
        if (enter[i] == '(' || enter[i] == ' ') 
        {
            to_lower(figure, num);
            if (strcmp(figure, "circle") == 0) 
            {   
                struct point Center = center_search(enter, &num);
                struct Circle = circle_search(&Center, enter, &num);
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
        elseif (enter[i] == ')') 
        {
            show_error(ERROR_BRACKET, num, &enter[i]);
            exit(EXIT_FAILURE);
        }

        figure[num] = enter[i];
        num++;
    }
  
    char enter1[SIZE], figure1[SIZE];
    num = 0;

    printf("Enter the second circle:\n");
    fgets(enter1, SIZE, stdin);

    for (int i = 0; i < strlen(enter1); i++)
    {
        if (enter1[i] =='(' || enter1[i] == ' ')
    {
            to_lower(figure1, num);
            if (strcmp(figure1, "circle") == 0)
            {
                struct point2 Center2 = center_search2(enter1, &num);
                struct Circle2 = circle_search(&Center2, enter1, &num); 
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
    else if (enter1[i] == '(')
    {
        show_error(ERROR_BRACKET, num, &enter1[i]);
        exit(EXIT_FAILURE);
    }

        figure1[num] = enter1[i];
        num++;
    }
    intersection(Circle, Circle2);
    return 0;
}