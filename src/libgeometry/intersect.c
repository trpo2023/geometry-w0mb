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