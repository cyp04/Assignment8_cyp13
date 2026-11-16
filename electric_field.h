#ifndef ELECTRIC_FIELD_H
#define ELECTRIC_FIELD_H

#include <iostream>
#include <cmath>
#include "field.h"

class Electric_Field : public Field
{
private:
    double electricField; // Store calculated electric field

public:
    // Default constructor
    Electric_Field() : Field()
    {
        electricField = 0.0; // Initialize electric field
    }

    // Constructor with three components
    Electric_Field(double x, double y, double z)
        : Field(x, y, z)
    {
        electricField = 0.0; // Initialize calculated field
    }

    // Copy constructor
    Electric_Field(const Electric_Field &other)
        : Field(other)
    {
        electricField = other.electricField; // Copy calculated field
    }

    // Calculate electric field using Gauss' Law
    double calculateElectricField(double Q, double r)
    {
        const double pi = 3.141592653589793;
        const double epsilon0 = 8.854e-12;

        if (r <= 0.0)
        {
            electricField = 0.0; // Prevent division by zero
        }
        else
        {
            electricField = Q / (4.0 * pi * r * r * epsilon0);
        }

        return electricField; // Return calculated value
    }

    // Overload the + operator
    Electric_Field operator+(const Electric_Field &other) const
    {
        Electric_Field result(
            value[0] + other.value[0],
            value[1] + other.value[1],
            value[2] + other.value[2]
        );

        return result; // Return added electric field
    }

    // Overload the assignment operator
    Electric_Field& operator=(const Electric_Field &other)
    {
        if (this != &other)
        {
            Field::operator=(other); // Copy base class components
            electricField = other.electricField; // Copy calculated field
        }

        return *this;
    }

    // Overload the << operator
    friend std::ostream& operator<<(std::ostream &output,
                                    const Electric_Field &E)
    {
        output << "(" << E.value[0] << ", "
               << E.value[1] << ", "
               << E.value[2] << ")";

        return output;
    }
};

#endif
