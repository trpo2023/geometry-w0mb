struct circle Circle1, Circle2;
printf("Enter the first circle:\n");
fgets(enter, SIZE, stdin);
Circle1 = get_circle(enter);

printf("Enter the second circle:\n");
fgets(enter, SIZE, stdin);
Circle2 = get_circle(enter);

double distance = sqrt(pow(Circle1.center.x - Circle2.center.x, 2) + pow(Circle1.center.y - Circle2.center.y, 2));
if (distance <= Circle1.radius + Circle2.radius)
{
    printf("The circles intersect.\n");
}
else
{
    printf("The circles do not intersect.\n");
}