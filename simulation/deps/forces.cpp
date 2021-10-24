#include "forces.h"

const double K_col = 1.0;

Vector3D coloumbForce(Body molecule_i, Body molecule_j)
{
    Vector3D r = molecule_i.getR() - molecule_j.getR();
    double r3 = vec3d::norm(r)*vec3d::norm(r)*vec3d::norm(r);
    r3 = 1.0/r3;

    Vector3D F = K_col*molecule_i.getQ()*molecule_j.getQ()*r*r3;

    return F;
}