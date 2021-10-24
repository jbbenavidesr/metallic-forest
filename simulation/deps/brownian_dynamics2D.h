#ifndef BROWNIAN_DYNAMICS_H
#define BROWNIAN_DYNAMICS_H

#include<string>

#include "constants.h"
#include "Body.h"
#include "random64.h"
#include "forces.h"

class BrownianDynamics2D
{
private:
    CRandom rand;

public:
    void init(Body *Molecules, unsigned long long seed);
    void calculateForces(Body *molecules);
    void checkAggregation(Body *molecules);
    void runSimulation(Body *molecules, int t_steps, std::string filename);
    Vector3D calculateMotion(Body molecule);
};

#endif