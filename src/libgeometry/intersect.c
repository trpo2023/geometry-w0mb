#include <libgeometry/intersect.h>
#include <stdio.h>

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
    if (((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
        <= (radius1 + radius2) * (radius1 + radius2)) {
        printf("\ncircles are intersection\n");
        return 1;
    }

    else {
        printf("\ncircles are unintersection\n");
        return 0;
    }
}