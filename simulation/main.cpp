
/**
 * Main module. 
 * This program is for calculating and saving data. For animations please use animate.cpp
 */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Body.h"
#include "animate.h"

std::string filename(int n);

int main(int argc, char *argv[])
{
    Body Molecule[N];
    CRandom rand(42);
    double mu = 0, sigma = 0.1;
    double move_x, move_y;
    Vector3D move;
    double tdibujo = 0;

    double x, y, z, vx, vy, vz, x0 = 2 * Lx, y0 = 2 * Ly;

    double dx = Lx / (Nx + 1);
    double dy = Ly / (Ny + 1);

    // Initial configuration
    for (int k = 0; k < N; k++) // Run through every molecule
    {
        // Initial positions in cubic lattice
        x = dx + (k % Nx) * dx + x0;
        y = dy + ((k / Nx) % Ny) * dy + y0;
        z = 0;

        // Initial null velocities
        vx = 0;
        vy = 0;
        vz = 0;

        Molecule[k].init(x, y, z, vx, vy, vz, m0);
    }

    // Open file to save info
    std::ofstream file("../data/difusion.csv");

    // Make sure to close the file
    file.close();
    return 0;
}

std::string filename(int n)
{
    std::string name;
    std::stringstream n_s;
    n_s << n;
    name = "./" + n_s.str() + ".csv";
    return name;
}
