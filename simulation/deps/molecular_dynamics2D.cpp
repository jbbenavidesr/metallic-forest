#include "constants.h"
#include "vector3D.h"
#include "molecular_dynamics2D.h"
#include "Body.h"
#include "random64.h"

#include <fstream>
/*
 * Initializes a MD system with lattice arrangement and random velocities within a maximum value per component.
 * 
 * @param CRandom ran64: Random number generator for initial velocities.
 * @param double vmax: Each velocity component starts somewhere in (-vmax, vmax)
 */
void MolecularDynamics2D::init(Body *Molecules, unsigned long long seed)
{
    double x, y, z, vx, vy, vz;

    // Initial configuration
    for (int k = 0; k < N; k++) // Run through every molecule
    {
        // Initial positions uniformly in center
        x = Lx / 2;
        y = Ly / 2;
        z = 0;

        // Initial velocities to 0
        vx = 0;
        vy = 0;
        vz = 0;

        Molecules[k].init(x, y, z, vx, vy, vz, m0);
    }

    Molecules[0].is_aggregated = true; // randomly selected

    // Initial force
    calculateForces(Molecules);

    // initial velocity
    for (int k = 0; k < N; k++) // Run through every molecule
    {
        Molecules[k].v = (-0.5 * dt / m0) * Molecules[k].F;
    }

    rand.init(seed);
}

void MolecularDynamics2D::calculateForces(Body *molecules)
{
    for (int k = 0; k < N; k++) // Run through every molecule
    {
        // Reset all forces
        molecules[k].resetForce();

        if(molecules[k].is_aggregated) continue;

        // Add langevin force to each molecule
        molecules[k].addForce(
            langevinForce(rand, sigma, molecules[k].getV(), lambda));
    }
}

/** 
 * Checks if two molecules are in contact, and if one of them is aggregated, the other one becomes 
 *  aggregated as well
 */
void MolecularDynamics2D::checkAggregation(Body *molecules)
{
    double R2 = molecules[0].R*molecules[0].R;

    for (int i=0; i<N; i++)
        for (int j=i+1; j<N; j++)
        {
            double dr = vec3d::norm2(molecules[i].r - molecules[j].r);

            if(dr <= R2 && molecules[i].is_aggregated+molecules[j].is_aggregated == 1){
                molecules[i].is_aggregated = true;
                molecules[j].is_aggregated = true;
            }
        }
}

void MolecularDynamics2D::runSimulation(Body *molecules, int t_steps)
{
    // Open file to save info
    std::ofstream file("../data/difusion.csv");

    file << "t,x,y,z,v_x,v_y,v_z,u\n";
    double t;
    for (int step = 1; step <= t_steps; step++)
    {
        t = step * dt;

        for (int k = 0; k < N; k++)
        {
            molecules[k].printState(t, file);
            // Calc velocity
            molecules[k].moveV(dt);
            // Move particle
            molecules[k].moveR(dt);

            // New force
            molecules[k].resetForce();

            if(molecules[k].is_aggregated) continue;

            molecules[k].addForce(langevinForce(rand, sigma, molecules[k].getV(), lambda));
        }
    }
    // Make sure to close the file
    file.close();
}

Vector3D langevinForce(CRandom &rand, double sigma, Vector3D velocity, double coeff)
{
    Vector3D eta(
        rand.gauss(0, sigma),
        rand.gauss(0, sigma),
        0);

    return -coeff * velocity + eta;
}