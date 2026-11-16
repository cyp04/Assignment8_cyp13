#ifndef MAGNETIC_FIELD_H
#define MAGNETIC_FIELD_H

#include <iostream>
#include <cmath>
#include "field.h"

class Magnetic_Field : public Field
{
private:
    double magneticField; // Store calculated magnetic field

public:
    // Default constructor
    Magnetic_Field() : Field()
    {
        magneticField = 0.0; // Initialize magnetic field
    }

    // Constructor with three components
    Magnetic_Field(double x, double y, double z)
        : Field(x, y, z)
    {
        magneticField = 0.0; // Initialize calculated field
    }

    // Copy constructor
    Magnetic_Field(const Magnetic_Field &other)
        : Field(other)
    {
        magneticField = other.magneticField; // Copy calculated field
    }

    // Calculate magnetic field using Ampere's Law
    double calculateMagneticField(double I, double r)
    {
        const double pi = 3.141592653589793;
        const double mu0 = 4.0 * pi * 1e-7;

        if (r <= 0.0)
        {
            magneticField = 0.0; // Prevent division by zero
        }
        else
        {
            magneticField = (mu0 * I) / (2.0 * pi * r);
        }

        return magneticField; // Return calculated value
    }

    // Overload the + operator
    Magnetic_Field operator+(const Magnetic_Field &other) const
    {
        Magnetic_Field result(
            value[0] + other.value[0],
            value[1] + other.value[1],
            value[2] + other.value[2]
        );

        return result; // Return added magnetic field
    }

    // Overload the assignment operator
    Magnetic_Field& operator=(const Magnetic_Field &other)
    {
        if (this != &other)
        {
            Field::operator=(other); // Copy base class components
            magneticField = other.magneticField; // Copy calculated field
        }

        return *this;
    }

    // Overload the << operator
    friend std::ostream& operator<<(std::ostream &output,
                                    const Magnetic_Field &B)
    {
        output << "(" << B.value[0] << ", "
               << B.value[1] << ", "
               << B.value[2] << ")";

        return output;
    }
};

#endif
