/**
 * 3D Vector helper class.
 * Author : Jose Daniel Munoz et al.
 * Modified : Juan Vanegas
 */
#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
    double v[3];

public:
    Vector3D(double = 0.0, double = 0.0, double = 0.0);
    void load(double x0, double y0, double z0);
    void show(void);
    /* @return x component*/
    inline double x(void) { return v[0]; };
    /* @return y component*/
    inline double y(void) { return v[1]; };
    /* @return z component*/
    inline double z(void) { return v[2]; };
    /* @return nth component*/
    double &operator[](int n) { return v[n]; };
    Vector3D operator=(Vector3D v2);
    Vector3D operator+(Vector3D v2);
    Vector3D operator+=(Vector3D v2);
    Vector3D operator-(Vector3D v2);
    Vector3D operator-=(Vector3D v2);
    Vector3D operator*(double a);
    Vector3D operator*=(double a);
    Vector3D operator/(double a);
    double operator*(Vector3D v2);
    Vector3D operator^(Vector3D v2);
    friend Vector3D operator*(double a, Vector3D v1);
    friend double norm2(Vector3D v1);
    friend double norm(Vector3D v1);
};

#endif
