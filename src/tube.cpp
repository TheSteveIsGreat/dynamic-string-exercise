#include <stdexcept>
#include "tube.h"
#include <iomanip>

//Define the static data member
const double Tube::kPi = 3.14159;

//one getter
/**
 * @brief Returns the value of circumference_
 *
 * @return circumference_ - The circumference of the tube.
 */
double Tube::get_circumference() const
{
    return circumference_;
}

//one setter
/**
 * @brief sets the circumference member to the value sent.
 * If the circumference sent is less than kMinSize
 * or if the length + circumference is greater than kMaxSize
 * it throws an out_of_range exception.
 *
 * @param circumference - A double passed by value.
 */
void Tube::set_circumference(double circumference)
{
    if (circumference < kMinSize || (length_ + circumference) > kMaxSize)
    {
        throw std::out_of_range("Error: Circumference must be greater than .007, "
                                "and length + circumference must be less than 108.");
    }
    circumference_ = circumference;
}

//two constructors and a destructor
/**
 * @brief Default constructor. Adds to items already set by ShippingItem constructor.
 * Sets default circumference.
 */
Tube::Tube()
{
    circumference_ = 12;
}

/**
 * @brief This constructor is to call the base class constructor
 * with the values sent for address, weight, and length.
 * Then it is to call the setters in the Tube class to set the circumference.
 * The set methods throw out_of_range exceptions.
 *
 * @param address - a structure of strings containing all the address information
 * @param weight - the item weight
 * @param length - one dimension of the tube.
 * @param circumference - the circumference of the tube.
 */
Tube::Tube(Address address, double weight, double length, double circumference)
: ShippingItem(address, weight, length)
{
    try {
        set_circumference(circumference);
    }
    catch (std::out_of_range) {throw std::out_of_range ("Error: invalid circumference.");}
}

/**
 * @brief Formulates the volume of a tube.
 *
 * @return volume - The volume of the tube.
 */
double Tube::Volume() const
{
    double volume = (kPi*(circumference_/(2*kPi))*(circumference_/(2*kPi)))*length_;
    return volume;
}

/**
 * @brief Formulates the tube girth, which is the circumference.
 *
 * @return circumference_ - The circumference of the tube.
 */
double Tube::Girth() const
{
    return Tube::circumference_;
}

/**
 * @brief output the word Tube followed by
 * weight, length, and circumference using :, lbs., and x
 *
 * @param out - An output file stream
 */
void Tube::Display(std::ostream &out) const
{
    out << std::fixed << std::setprecision(1) << "Tube: " << get_weight() << " lbs. "
    << length_ << " x " << circumference_ << std::endl;
}