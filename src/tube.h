#ifndef TUBE_H
#define TUBE_H

#include "shipping_item.h"

class Tube : public ShippingItem
{
private:
    double circumference_;

public:
    static const double kPi;

    //two constructors and a destructor
    Tube();
    Tube(Address address, double weight, double length, double circumference);
    ~Tube(){}

    //one getter
    double get_circumference() const;

    //one setter
    void set_circumference(double circumference);

    //three other methods
    double Volume() const;
    double Girth() const;
    void Display(std::ostream &out) const;
};

#endif