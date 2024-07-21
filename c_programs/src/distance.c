// C program to find the distance between two points x1,y1 and x2,y2

#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, x1, y1, x2, y2, dis;

    printf("Enter the values for x1, y1 and x2, y2: ");
    scanf("%f%f%f%f", &x1,&y1, &x2, &y2);

    x = pow(x2 - x1, 2);
    y = pow(y2 - y1, 2);
    dis = sqrt(x + y);

    printf("\nThe distance between the points (%.2f, %.2f) and (%.2f, %.2f) is %.2f\n", x1, y1, x2, y2, dis);

    return 0;
}
