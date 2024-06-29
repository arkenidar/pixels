#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "types.h"

bool IsPointInsideTriangle(Point2d P, Point2d A, Point2d B, Point2d C)
{
    double det = (B.y - C.y) * (A.x - C.x) + (C.x - B.x) * (A.y - C.y);
    double factor_alpha = (B.y - C.y) * (P.x - C.x) + (C.x - B.x) * (P.y - C.y);
    double factor_beta = (C.y - A.y) * (P.x - C.x) + (A.x - C.x) * (P.y - C.y);

    bool inside = false;

    double alpha = 0.0;
    double beta = 0.0;
    double gamma = 0.0;

    if (det != 0)
    {
        alpha = factor_alpha / det;
        beta = factor_beta / det;
        gamma = 1.0 - alpha - beta;
    }
    else
    {
        alpha = 0.0;
        beta = 0.0;
        gamma = 0.0;
        inside = true;
        return inside;
    }

    //--------------------------------------------------------------------------------

    // if (((A.x == P.x) && (A.y == P.y)) || ((B.x == P.x) && (B.y == P.y)) || ((C.x == P.x) && (C.y == P.y))) inside = true; // Check if the point is a vertex of the triangle

    //--------------------------------------------------------------------------------

    // if ((alpha == 0) || (beta == 0) || (gamma == 0)) inside = true; // Check if the point lies on an edge of the triangle
    double epsilon = 0.0001;
    bool alpha_zero = (-epsilon <= alpha) && (alpha <= epsilon); // alpha == 0;
    bool beta_zero = (-epsilon <= beta) && (beta <= epsilon);    // beta == 0;
    bool gamma_zero = (-epsilon <= gamma) && (gamma <= epsilon); // gamma == 0;
    bool edges = alpha_zero || beta_zero || gamma_zero;          // Check if the point lies on an edge of the triangle
    // if(edges) return true; // inside = true;

    //--------------------------------------------------------------------------------

    // if (((0 <= alpha) && (alpha <= 1)) && ((0 <= beta) && (beta <= 1)) && ((0 <= gamma) && (gamma <= 1))) inside = true; // Check if the point is inside the triangle

    // Check if the point is inside the triangle
    bool alpha_in_range = (0 - epsilon <= alpha) && (alpha <= 1 + epsilon);
    bool beta_in_range = (0 - epsilon <= beta) && (beta <= 1 + epsilon);
    bool gamma_in_range = (0 - epsilon <= gamma) && (gamma <= 1 + epsilon);

    inside = alpha_in_range && beta_in_range && gamma_in_range; // Check if the point is inside the triangle

    //--------------------------------------------------------------------------------

    return inside;
}

#endif // TRIANGLE_H
