
/**
 * Main module. 
 * This program is for calculating and saving data. For animations please use animate.cpp
 */
#include "Body.h"
#include "animate.h"
#include "random64.h"
#include "constants.h"
#include "molecular_dynamics2D.h"
#include "vector3D.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Vector3D getRandomForce2D(CRandom &rand);
std::string filename(int n);

int main(int argc, char *argv[])
{
    Body Molecule[N];
    MolecularDynamics2D world;

    double x, y, z, vx, vy, vz, x0 = 2 * Lx, y0 = 2 * Ly, t, t_dibujo = 0;
    Vector3D force(0, 0, 0);

    double dx = Lx / (Nx + 1);
    double dy = Ly / (Ny + 1);

    world.init(Molecule, seed);

    world.runSimulation(Molecule, t_steps);

    return 0;
}

Vector3D getRandomForce2D(CRandom &rand)
{
    Vector3D result(
        rand.gauss(mu, sigma),
        rand.gauss(mu, sigma),
        0);
    return result;
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