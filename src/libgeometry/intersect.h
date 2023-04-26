<<<<<<< HEAD
#pragma once

struct point //определение координаты по иксу игрику
{
    double x;
    double y;
};


struct point2 //определение координаты по иксу игрику
{
    double x2;
    double y2;
};

struct circle // определение радиуса
{
    struct point Center; // ?
    float radius;
    float perimeter;
    float area;
};


struct circle2 // определение радиуса
{
    struct point2 Center2; // ?
    float radius2;
    float perimeter2;
    float area2;
};



int intersection(struct circle* Circle, struct circle2* Circle2);
||||||| parent of f0ab874 (sdf)
=======
#pragma once

struct point //определение координаты по иксу игрику
{
    double x;
    double y;
};


struct point2 //определение координаты по иксу игрику
{
    double x2;
    double y2;
};

struct circle // определение радиуса
{
    struct point Center; // ?
    float radius;
    float perimeter;
    float area;
};


struct circle2 // определение радиуса
{
    struct point2 Center2; // ?
    float radius2;
    float perimeter2;
    float area2;
};



void intersection(struct circle* Circle, struct circle2* Circle2);
>>>>>>> f0ab874 (sdf)
