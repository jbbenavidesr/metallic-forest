#ifndef BODY_H
#define BODY_H

#include "vector3D.h"

#include <fstream>
#include <iostream>

// ----- Class Declarations -----
class Body
{
private:
    // It has a position r, velocity v and a total force F acts on it.
    Vector3D r, v, F;
    // It has a mass and a total potential energy U.
    double m, U;
    // For this first implementation I'll ignore the geometry and assume it as a point mass.

public:
    void init(double x, double y, double z, double vx, double vy, double vz, double mass = 1.0);
    void printState(double t, std::ofstream &File);

    // --Inline Functions --

    // Makes the total force equal to 0 for recalculation.
    inline void resetForce(void) { F.load(0, 0, 0); };

    // Adds a force to the total force on the body
    inline void addForce(Vector3D dF) { F += dF; };

    // Makes the total potential equal to 0 for recalculation.
    inline void resetU(void) { U = 0; };

    // Adds a potential to the total  Potential energy of the body
    inline void addU(double dU) { U += dU; };

    // update of velocity
    inline void moveV(double dt, double coef = 1.0) { v += (dt * coef / m) * F; };

    // update of position
    inline void moveR(double dt, double coef = 1.0) { r += (dt * coef) * v; };

    // Get position
    inline Vector3D getR(void) { return r; };

    // Get velocity
    inline Vector3D getV(void) { return v; };

    // Set position
    inline void setR(Vector3D newR) { r = newR; };

    // Set velocity
    inline void setV(Vector3D newV) { v = newV; };

    //Get kinetic energy
    inline double getK() { return 0.5 * m * norm2(v); };

    // print gnuplot animation
    inline void print() { std::cout << "," << r.x() << "+0.2*cos(t)," << r.y() << "+0.2*sin(t)"; };

    //-- Friends --

    friend Vector3D rMin(Body b1, Body b2);
    friend class MolecularDynamics2D;
};

#endif