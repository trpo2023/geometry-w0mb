<<<<<<< HEAD
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
||||||| parent of f0ab874 (sdf)
// #include <libgeometry/intersect.h>
=======
#include <stdio.h>
#include <libgeometry/intersect.h>
>>>>>>> f0ab874 (sdf)

void intersection(struct circle* Circle, struct circle2* Circle2)
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
        printf("circles are intersection\n");
        // return 1;
    }

<<<<<<< HEAD
//     else
//     {
//         return 0;
//     }
// }
>>>>>>> 2d1f361 (test on calculate)
||||||| parent of f0ab874 (sdf)
//     else
//     {
//         return 0;
//     }
// }
=======
    else
    {
        printf("circles are unintersection:\nx1=%f  y1=%f\nx2=%f   y2=%f\n", x1, y1, x2, y2);
        // return 0;
    }
}
>>>>>>> f0ab874 (sdf)
