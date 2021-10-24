#include "Body.h"
#include "constants.h"

#include <fstream>
#include <cmath>

/**
 * Initializes the molecule in a given initial position, with a given velocity and a given mass
 * Force and potential start being 0.
 * 
 * @param double x, y, z: Initial position of the body.
 * @param double vx, vy, vz: Initial velocity of the body.
 * @param double m: Mass of the body. Defaults to 1.
 * @param double q0: Charge of the body. Defaults to 1
 */
void Body::init(double x, double y, double z, double vx, double vy, double vz, double mass, double q0)
{
    r.load(x, y, z);
    v.load(vx, vy, vz);
    m = mass;
    q = q0;
    resetForce();
    resetU();
}

/**
 * Prints the current state of the body in csv format. For the moment it uses cout
 * a future implementation is set to make it write in a given file directly.
 * 
 * @param double t: The current timestep in the simulation
 */
void Body::printState(double t, std::ofstream &File)
{
    File << t << "," << r.x() << "," << r.y() << "," << r.z() << "," << v.x() << "," << v.y() << "," << v.z() << "," << U << '\n';
}

/**
 * Calculates the minimum image distance of 2 bodies. This is based in the image
 * strategy for implementing periodic boundaries.
 * 
 * @param Body b1, b2: the 2 bodies whose minimum distance we want to calculate.
 * 
 * @return Vector3D: Returns the minimum distance between the bodies.
 */
Vector3D rMin(Body b1, Body b2)
{
    Vector3D dr;
    dr = b1.r - b2.r;
    double x, y, z;
    x = dr.x() - Lx * std::round(dr.x() / Lx);
    y = dr.y() - Ly * std::round(dr.y() / Ly);
    Vector3D rmin(x, y, z);
    return rmin;
}