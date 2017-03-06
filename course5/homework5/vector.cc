#include "vector.h"
#include <iostream>
#include <cmath>

#define Pi 3.14159265

namespace vector{

    Vector2D::Vector2D(double x, double y) : x(x), y(y) {}
    Vector2D::Vector2D(const Vector2D& src) : x(src.x), y(src.y)  {}
    Vector2D& Vector2D::operator=(const Vector2D& src)
    { 
        x = src.x;
        y = src.y;
        return *this;
    }

    double Vector2D::GetX() const { return x;}
    double Vector2D::GetY() const { return y;}

    void Vector2D::SetX(double x)
    {
        this->x = x;
    }

    void Vector2D::SetY(double y)
    {
        this->y = y;
    }

    double Vector2D::GetR() const { return sqrt(x*x + y*y); }
    double Vector2D::GetAngle() const { return atan( y / x); }

    Vector2D Vector2D::operator+(const Vector2D& src)
    {
        Vector2D v( x + src.x, y + src.y );
        return v;
    }

    Vector2D Vector2D::operator-(const Vector2D& src)
    {
        Vector2D v( x - src.x, y - src.y );
        return v;
    }

    Vector2D& Vector2D::operator+=(const Vector2D& src)
    {
        x += src.x;
        y += src.y;
        return *this;
    }
    Vector2D& Vector2D::operator-=(const Vector2D& src)
    {
        x -= src.x;
        y -= src.y;
        return *this;
    }

    bool Vector2D::operator==(const Vector2D& src)
    {
        if ( x == src.x && y == src.y )
            return true;
        else
            return false;
    }

    bool Vector2D::operator!=(const Vector2D& src)
    {
        return !(*this == src);
    }

    

    std::ostream& operator<<(std::ostream& s, const Vector2D& V) 
    {
        s << "(" << V.GetX() << ", " << V.GetY() << ")";
        return s;
    }

    Vector2D operator "" _x(long double x)
    {
        Vector2D X(x, 0);
        return X;
    }

    Vector2D operator "" _y(long double y)
    {
        Vector2D Y(0, y);
        return Y;
    }

    Vector2D operator "" _phi(long double phi) // user can provide phi in degree
    {
        phi = phi * Pi /180;
        Vector2D U(cos(phi), sin(phi));
        return U;
    }

    Vector2D operator*(double r, const Vector2D& V)
    {
        Vector2D W(r * V.GetX(), r * V.GetY());
        return W;
    }

}