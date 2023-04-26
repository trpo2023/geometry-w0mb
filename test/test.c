<<<<<<< HEAD
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
    
    result = intersection(&z, &v);
    expect = 1;

    struct circle dead;
    struct circle2 kill;
    a.Center.x = 1;
    a.Center.y = 2; 
    a.radius = 1;
    b.Center2.x2 = 0;
    b.Center2.y2 = 0;
    b.radius2 = 5;
    
    result = intersection(&dead, &kill);
    expect = 1;
    
}
||||||| parent of 2d1f361 (test on calculate)
=======
#include <../thirdparty/ctest.h>
#include <libgeometry/calculate.h>
#include <libgeometry/intersect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//intersection-tests

CTEST(intersection, correct_input)
{
    

<<<<<<< HEAD
    ASSERT_EQUAL(3, sscanf(input, "circle(%f %f,%f)", &c_x, &c_y, &c_r));
    ASSERT_EQUAL(0, strncmp(input, "circle(", 7));
    ASSERT_EQUAL(0.0, c_x);
    ASSERT_EQUAL(0.0, c_y);
    ASSERT_EQUAL(1.5, c_r);
}
>>>>>>> 2d1f361 (test on calculate)
||||||| parent of 137aacd (REGISTER FIX)
    ASSERT_EQUAL(3, sscanf(input, "circle(%f %f,%f)", &c_x, &c_y, &c_r));
    ASSERT_EQUAL(0, strncmp(input, "circle(", 7));
    ASSERT_EQUAL(0.0, c_x);
    ASSERT_EQUAL(0.0, c_y);
    ASSERT_EQUAL(1.5, c_r);
}
=======
    const double result = coordinat_x(input, num);
    
}
>>>>>>> 137aacd (REGISTER FIX)
