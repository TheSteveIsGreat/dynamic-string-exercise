#include <stdexcept>
#include "flat.h"
#include <iomanip>

//two getters
/**
 * @brief Returns the value of height.
 *
 * @return A double with the value of height.
 */
double Flat::get_height() const
{
    return height_;
}

/**
 * @brief Returns the value of thickness.
 *
 * @return A double with the value of thickness.
 */
double Flat::get_thickness() const
{
    return thickness_;
}

//three setters
/**
 * @brief Sets the length member to the value sent.
 * If the length sent is less than kMinSize or greater than 15
 * it throws an out_of_range exception.
 *
 * @param length - A double passed by value.
 */
void Flat::set_length(double length)
{
    if (length < kMinSize || length > 15)
    {
        throw std::out_of_range("Error: length must be between .007 and 15.");
    }
    length_ = length;
}

/**
 * @brief Sets the height member to the value sent.
 * If the height sent is less than kMinSize or greater than 12
 * it throws an out_of_range exception.
 *
 * @param height - A double passed by value.
 */
void Flat::set_height(double height)
{
    if (height < kMinSize || height > 12)
    {
        throw std::out_of_range("Error: height must be between .007 and 12.");
    }
    height_ = height;
}

/**
 * @brief Sets the thickness member to the value sent.
 * If the thickness sent is less than kMinSize or greater than .75
 * it throws an out_of_range exception.
 *
 * @param thickness - A double passed by value.
 */
void Flat::set_thickness(double thickness)
{
    if (thickness < kMinSize || thickness > 0.75)
    {
        throw std::out_of_range("Error: thickness must be between .007 and .75.");
    }
    thickness_ = thickness;
}

//two constructors and a destructor
/**
 * @brief Default Constructor. Adds to items already set by ShippingItem default constructor.
 * Sets height and thickness.
 */
Flat::Flat()
{
    set_height(8);
    set_thickness(0.4);
}

/**
 * @brief This constructor is to call the base class constructor with
 * the values sent for address, weight, and length.
 * Then it is to call the setters in the Flat class to set the length, height, and thickness.
 *
 * @param address - a structure of strings containing all the address information
 * @param weight - the item weight
 * @param length - one dimension of the flat.
 * @param height - one dimension of the flat.
 * @param thickness - one dimension of the flat.
 */
Flat::Flat(Address address, double weight, double length, double height, double thickness)
: ShippingItem(address, weight, length)
{
    try {
        set_length(length);
    }
    catch (std::out_of_range){throw std::out_of_range ("Error: Invalid length. "
                                                       "Length must be between .007 and 15.");}
    try {
        set_height(height);
    }
    catch (std::out_of_range){throw std::out_of_range ("Error: Invalid height. "
                                                       "Height must be between .007 and 12.");}
    try {
        set_thickness(thickness);
    }
    catch (std::out_of_range){throw std::out_of_range ("Error: Invalid thickness. "
                                                       "Thickness must be between .007 and .75.");}
}

//two other methods
/**
 * @brief Formulates the volume of a flat.
 *
 * @return volume - The volume of the flat.
 */
double Flat::Volume() const
{
    double volume = length_*height_*thickness_;
    return volume;
}

/**
 * @brief Outputs the word Flat followed by
 * weight, length, height, and thickness using :, lbs., and x
 *
 * @param out - an output file stream
 */
void Flat::Display(std::ostream &out) const
{
    out << std::fixed << std::setprecision(1) << "Flat: " << get_weight() << " lbs. "
    << length_ << " x " << height_ << " x " << thickness_ << std::endl;
}