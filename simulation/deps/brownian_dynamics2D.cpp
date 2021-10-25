#include "brownian_dynamics2D.h"

void BrownianDynamics2D::init(Body *molecules, unsigned long long seed)
{
    double x, y, z, vx, vy, vz, q;

    // Initial configuration
    for (int i = 0; i < N; i++) // Run through every molecule
    {
        // Initial positions uniformly in center
        x = Lx / 2;
        y = Ly / 2;
        z = 0;

        // Initial velocities to 0
        vx = 0;
        vy = 0;
        vz = 0;

        // charge
        q = 1.0;

        molecules[i].init(x, y, z, vx, vy, vz, m0, q);
    }

    molecules[0].is_aggregated = true; // "randomly" selected

    rand.init(seed);
}

void BrownianDynamics2D::runSimulation(Body *molecules, int t_steps, std::string filename)
{
    // Open file to save info
    std::ofstream file("../data/" + filename);

    file << "t,x,y,z,v_x,v_y,v_z,u\n";
    double t;

    for (int step = 0; step < t_steps; step++)
    {
        t = step * dt;

        calculateForces(molecules);

        for (int i = 0; i < N; i++)
        {
            molecules[i].printState(t, file);

            if (molecules[i].is_aggregated)
                continue;

            // Move particle
            Vector3D dr = calculateMotion(molecules[i]);
            molecules[i].moveR(dr);
        }

        checkAggregation(molecules);
    }
    // Make sure to close the file
    file.close();
}

void BrownianDynamics2D::calculateForces(Body *molecules)
{
    for (int i = 0; i < N; i++)
        molecules[i].resetForce();

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            Vector3D dF = coloumbForce(molecules[i], molecules[j]);
            molecules[i].addForce(-1 * dF);
            molecules[j].addForce(dF);
        }

    for (int i = 0; i < N; i++)
        molecules[i].updateOldForce();
}

Vector3D BrownianDynamics2D::calculateMotion(Body molecule)
{
    double x = dtU2mGamma * (3 * molecule.F.x() - molecule.F_old.x()) + rand.gauss(0, sigma);
    double y = dtU2mGamma * (3 * molecule.F.y() - molecule.F_old.y()) + rand.gauss(0, sigma);

    Vector3D dr(x, y);
    return dr;
}

/** 
 * Checks if two molecules are in contact, and if one of them is aggregated, the other one becomes 
 *  aggregated as well
 */
void BrownianDynamics2D::checkAggregation(Body *molecules)
{
    double R2 = molecules[0].R * molecules[0].R;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            double dr = vec3d::norm2(molecules[i].r - molecules[j].r);

            if (dr <= R2 && molecules[i].is_aggregated + molecules[j].is_aggregated == 1)
            {
                molecules[i].is_aggregated = true;
                molecules[j].is_aggregated = true;
            }
        }
}