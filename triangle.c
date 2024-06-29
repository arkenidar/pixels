#include <stdio.h>
#include "triangle.h"

void print_point(Point2d p)
{
    printf("(%g, %g)\n", p.x, p.y);
}

void print_triangle(Point2d A, Point2d B, Point2d C)
{
    print_point(A);
    print_point(B);
    print_point(C);
}

void print_triangle_and_point(Point2d A, Point2d B, Point2d C, Point2d P)
{
    print_triangle(A, B, C);
    print_point(P);
}

void print_triangle_and_point_inside(Point2d A, Point2d B, Point2d C, Point2d P)
{
    print_triangle_and_point(A, B, C, P);
    IsPointInsideTriangle(P, A, B, C) ? puts("in") : puts("out");
}

void test_point_inside()
{
    Point2d A = {0, 0}, B = {0, 10}, C = {10, 0};
    Point2d P1 = {2, 2}, P2 = {5, 5}, P3 = {10, 10};
    print_triangle_and_point_inside(A, B, C, P1);
    print_triangle_and_point_inside(A, B, C, P2);
    print_triangle_and_point_inside(A, B, C, P3);
}

int main(int argc, char *argv[])
{
    test_point_inside();
    return 0;
}
