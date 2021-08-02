
/**
 * Main module. 
 * This program is for calculating and saving data. For animations please use animate.cpp
 */
#include "Body.h"
#include "animate.h"
#include "random64.h"
#include "constants.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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

void start_animation(int animation)
{
    if (animation > 1)
    {
        if (animation == 3)
        {
            std::cout << "set terminal gif animate\n";
            std::cout << "set output 'movie01.gif'\n";
        }
        std::cout << "unset key\n";
        std::cout << "set xrange[0:" << 5 * Lx << "]\n";
        std::cout << "set yrange[0:" << 5 * Ly << "]\n";
        std::cout << "set size ratio -1\n";
        std::cout << "set parametric\n";
        std::cout << "set trange [0:7]\n";
        std::cout << "set isosamples 12" << std::endl;
    }
}
void begin_frame(int animation)
{
    if (animation > 1)
    {
        std::cout << "plot 0,0 ";
        //std::cout << " , " << Lx/7 << "*t,0";             // down wall
        //std::cout << " , " << Lx/7 << "*t," << Ly;        // up wall
        //std::cout << " , 0," << Ly/7 << "*t";             // left wall
        //std::cout << " , " << Lx << "," << Ly/7 << "*t";  // right wall
    }
}
void end_frame(int animation)
{
    if (animation > 1)
        std::cout << std::endl;
}

void plot_single_point(int animation, double x, double y)
{
    if (animation > 1)
        std::cout << " , '< echo " << x << ' ' << y << "' w points";
}