/**
 * Random number generator
 * Author : Jose Daniel Munoz et al.
 */
#ifndef RANDOM64_H
#define RANDOM64_H

class CRandom
{
    unsigned long long u, v, w;

public:
    void init(unsigned long long seed);
    unsigned long long int64();
    double r() { return 5.42101086242752217E-20 * int64(); }
    unsigned int int32() { return (unsigned int)int64(); };
    double exponencial(float tau);
    double gauss(float mu, float sigma);
};

#endif
