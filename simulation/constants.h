#ifndef CONSTANTS_H
#define CONSTANTS_H

// Geometry constants
const double Lx = 8, Ly = Lx;
const double V = Lx * Ly;

// PEFRL
const double Zi = 0.1786178958448091e0;
const double Lambda = 0.2123418310626054 * (-1);
const double Xi = 0.06626458266981849 * (-1);

const double coef1 = (1 - 2 * Lambda) / 2;
const double coef2 = (1 - 2 * (Xi + Zi));

// Implementation
const int Nx = 20, Ny = 20;
const int N = Nx * Ny;
const double m0 = 1.0;
const double lambda = 1.0;
const double dt = 0.01;
const int t_steps = 10000;

// Random number generator
const unsigned long long seed = 42;
const double mu = 0.0;
const double sigma = 0.1;

#endif