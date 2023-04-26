#include <../thirdparty/ctest.h>
#include <libgeometry/calculate.h>
#include <libgeometry/intersect.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 100

//calc-tests

CTEST(circle_area, correct_input)
{
    const float radius = 5.0;
    const float expected_area = 78.539816;

    const float result = circle_area(radius);

    ASSERT_DBL_NEAR(expected_area, result);
}
CTEST(circle_area, negative_radius)
{
    const float radius = -5.0;
    const float expected_area = 0.0;

    const float result = circle_area(radius);

    ASSERT_DBL_NEAR(expected_area, result);
}

CTEST(circle_perimeter, correct_input)
{
    const float radius = 5.0;
    const float expected_perimeter = 31.415928;

    const float result = circle_perimeter(radius);

    ASSERT_DBL_NEAR(expected_perimeter, result);
}

CTEST(circle_perimeter, negative_radius)
{
    const float radius = -5.0;
    const float expected_perimeter = 0.0;

    const float result = circle_perimeter(radius);

    ASSERT_DBL_NEAR(expected_perimeter, result);
}

// //intersection-tests

CTEST(intersection, correct_input)
{
    struct circle a;
    struct circle2 b;
    a.Center.x = 2;
    a.Center.y = 3; 
    a.radius = 1;
    b.Center2.x2 = 0;
    b.Center2.y2 = 0;
    b.radius2 = 1;

    int result = intersection(&a, &b);
    int expect = 0;
    ASSERT_EQUAL(expect, result);

    struct circle z;
    struct circle2 v;
    a.Center.x = 0;
    a.Center.y = 0; 
    a.radius = 1;
    b.Center2.x2 = 0;
    b.Center2.y2 = 0;
    b.radius2 = 1;
    
    int result = intersection(&z, &v);
    int expect = 1;
    ASSERT_EQUAL(expect, result);

    struct circle dead;
    struct circle2 kill;
    a.Center.x = 2;
    a.Center.y = 3; 
    a.radius = 1;
    b.Center2.x2 = 3;
    b.Center2.y2 = 2;
    b.radius2 = 1;
    
    int result = intersection(&dead, &kill);
    int expect = 1;
    ASSERT_EQUAL(expect, result);
    
}
