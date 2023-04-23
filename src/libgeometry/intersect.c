<<<<<<< HEAD
#include <stdio.h>
#include <libgeometry/intersect.h>

int intersection(struct circle* Circle, struct circle2* Circle2)
{
    // double x1 = circle_1->center.x;
    double x1 = Circle->Center.x;
    double y1 = Circle->Center.y;
    double radius1 = Circle->radius;
    //во второй структуре хранится первый круг
    double x2 = Circle2->Center2.x2;
    double y2 = Circle2->Center2.y2;
    double radius2 = Circle2->radius2;
    //(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) > (r1+r2)*(r1+r2)
    if (((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) <= (radius1+radius2)*(radius1+radius2))
    {
        printf("\ncircles are intersection\n");
        return 1;
    }

    else
    {
        printf("\ncircles are unintersection\n");
        return 0;
    }
}
||||||| parent of 2d1f361 (test on calculate)
=======
// #include <libgeometry/intersect.h>

// int intersection(struct circle* circle_1, struct circle2* circle_2)
// {
//     double x1 = circle_1->center.x;
//     double y1 = circle_1->center.y;
//     double radius1 = circle_1->radius;
//     //во второй структуре хранится первый круг
//     double x2 = circle_2->Center2.x2;
//     double y2 = circle_2->Center2.y2;
//     double radius2 = circle_2->radius2;
//     //(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) > (r1+r2)*(r1+r2)
//     if (((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) > (radius1+radius2)*(radius1+radius2))
//     {
//         return 1;
//     }

//     else
//     {
//         return 0;
//     }
// }
>>>>>>> 2d1f361 (test on calculate)
