#ifndef FIELD_H
#define FIELD_H

#include <iostream>

class Field
{
protected:
    double *value; // Array for the three field components

public:
    // Default constructor
    Field()
    {
        value = new double[3]; // Allocate memory

        value[0] = 0.0; // Set x-component
        value[1] = 0.0; // Set y-component
        value[2] = 0.0; // Set z-component
    }

    // Constructor with three components
    Field(double x, double y, double z)
    {
        value = new double[3]; // Allocate memory

        value[0] = x; // Set x-component
        value[1] = y; // Set y-component
        value[2] = z; // Set z-component
    }

    // Copy constructor
    Field(const Field &other)
    {
        value = new double[3]; // Allocate new memory

        value[0] = other.value[0]; // Copy x-component
        value[1] = other.value[1]; // Copy y-component
        value[2] = other.value[2]; // Copy z-component
    }

    // Assignment operator
    Field& operator=(const Field &other)
    {
        if (this != &other)
        {
            value[0] = other.value[0]; // Copy x-component
            value[1] = other.value[1]; // Copy y-component
            value[2] = other.value[2]; // Copy z-component
        }

        return *this;
    }

    // Destructor
    virtual ~Field()
    {
        delete[] value; // Free allocated memory
    }

    // Get x-component
    double getX() const
    {
        return value[0];
    }

    // Get y-component
    double getY() const
    {
        return value[1];
    }

    // Get z-component
    double getZ() const
    {
        return value[2];
    }

    // Print field components
    void printMagnitude() const
    {
        std::cout << "(" << value[0] << ", "
                  << value[1] << ", "
                  << value[2] << ")" << std::endl;
    }
};

#endif
