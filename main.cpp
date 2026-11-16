#include <iostream>
#include "field.h"
#include "electric_field.h"
#include "magnetic_field.h"

int main()
{
    // Create electric field objects
    Electric_Field e1(1.0, 2.0, 3.0);
    Electric_Field e2(4.0, 5.0, 6.0);

    // Create magnetic field objects
    Magnetic_Field b1(2.0, 4.0, 6.0);
    Magnetic_Field b2(1.0, 3.0, 5.0);

    // Print electric field components
    std::cout << "Electric Field Components:" << std::endl;
    e1.printMagnitude();

    // Print magnetic field components
    std::cout << "\nMagnetic Field Components:" << std::endl;
    b1.printMagnitude();

    // Calculate electric field using Gauss' Law
    double Q = 2e-6; // Charge in Coulombs
    double r = 0.05; // Distance in meters

    double E = e1.calculateElectricField(Q, r);

    std::cout << "\nElectric Field Calculation:" << std::endl;
    std::cout << "Charge: " << Q << " C" << std::endl;
    std::cout << "Distance: " << r << " m" << std::endl;
    std::cout << "Electric Field: " << E << " N/C" << std::endl;

    // Calculate magnetic field using Ampere's Law
    double I = 5.0; // Current in Amps
    double distance = 0.02; // Distance in meters

    double B = b1.calculateMagneticField(I, distance);

    std::cout << "\nMagnetic Field Calculation:" << std::endl;
    std::cout << "Current: " << I << " A" << std::endl;
    std::cout << "Distance: " << distance << " m" << std::endl;
    std::cout << "Magnetic Field: " << B << " T" << std::endl;

    // Demonstrate electric field addition
    Electric_Field e3;
    e3 = e1 + e2;

    std::cout << "\nElectric Field Addition:" << std::endl;
    std::cout << "e1 + e2 = " << e3 << std::endl;

    // Demonstrate magnetic field addition
    Magnetic_Field b3;
    b3 = b1 + b2;

    std::cout << "\nMagnetic Field Addition:" << std::endl;
    std::cout << "b1 + b2 = " << b3 << std::endl;

    // Demonstrate electric field copy constructor
    Electric_Field e4(e1);

    std::cout << "\nElectric Field Copy:" << std::endl;
    std::cout << "e4 = " << e4 << std::endl;

    // Demonstrate magnetic field copy constructor
    Magnetic_Field b4(b1);

    std::cout << "\nMagnetic Field Copy:" << std::endl;
    std::cout << "b4 = " << b4 << std::endl;

    return 0; // End program
}
