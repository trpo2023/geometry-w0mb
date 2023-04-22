#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>

#define SIZE 100

struct point //определение координаты по иксу игрику
{
    double x;
    double y;
};

struct circle // определение радиуса
{
    struct point center; // ?
    double radius;
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

void show_circle(struct circle* Circle)
{
    printf("\ncircle(%.2f %.2f, %.2f)\n",
           Circle->center.x,
           Circle->center.y,
           Circle->radius);
};

int main()
{
    char enter[SIZE], figure[SIZE];
    int num = 0;

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

    return 0;
}