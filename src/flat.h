#ifndef FLAT_H
#define FLAT_H

#include "shipping_item.h"

class Flat : public ShippingItem
{
private:
    double height_, thickness_;

public:
    //two constructors and a destructor
    Flat();
    Flat(Address address, double weight, double length, double height, double thickness);
    ~Flat(){}

    //two getters
    double get_height() const;
    double get_thickness() const;

    //three setters
    void set_length(double length);
    void set_height(double height);
    void set_thickness(double thickness);

    //two other methods -
    double Volume() const;
    void Display(std::ostream &out) const;
};

#endif