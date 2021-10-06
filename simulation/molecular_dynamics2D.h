#ifndef MOLECULAR_DYNAMICS_2D_H
#define MOLECULAR_DYNAMICS_2D_H

#include "constants.h"
#include "Body.h"
#include "random64.h"

class MolecularDynamics2D
{
private:
    CRandom rand;

public:
    void init(Body *Molecules, unsigned long long seed);
    void calculateForces(Body *molecules);
    void checkAggregation(Body *molecules);
    void runSimulation(Body *molecules, int t_steps);
};

Vector3D langevinForce(CRandom &rand, double sigma, Vector3D velocity, double coeff);

#endif