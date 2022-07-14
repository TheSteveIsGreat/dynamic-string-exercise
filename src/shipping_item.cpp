#include <stdexcept>
#include "shipping_item.h"

//three static constants of type double
const double ShippingItem::kMaxWeight = 70;
const double ShippingItem::kMaxSize = 108;
const double ShippingItem::kMinSize = .007;

//four getters
/**
 * @brief Gets the value of address_ and returns it
 *
 * @return the value of address_
 */
Address ShippingItem::get_address() const
{
    return address_;
}

/**
 * @brief Gets the value of weight_ and returns it
 *
 * @return the value of weight
 */
double ShippingItem::get_weight() const
{
    return item_weight_;
}

/**
 * @brief Gets the value of length_ and returns it
 *
 * @return the value of length_
 */
double ShippingItem::get_length() const
{
    return length_;
}

/**
 * @brief Gets the value of delivered_ and returns it
 *
 * @return the value of delivered_
 */
bool ShippingItem::get_delivered() const
{
    return delivered_;
}

//four setters
/**
 * @brief Sets the address to the value sent
 *
 * @param address - A struct passed by value
 */
void ShippingItem::set_address(Address address)
{
    address_ = address;
}

/**
 * @brief Sets the weight member to the value sent.
 *  If the weight sent is less than 0 or greater than kMaxWeight
 *  it throws an out_of_range exception.
 *
 * @param weight - a double passed by value
 */
void ShippingItem::set_weight(double weight)
{
    if (weight < 0 || weight > kMaxWeight)
    {
        throw std::out_of_range("Error: Weight must be between 0 and 70.");
    }
    item_weight_ = weight;
}

/**
 * @brief Sets the length member to the value sent.
 *  If the length sent is less than kMinSize or greater than kMaxSize
 *  it throws an out_of_range exception.
 *
 * @param length - a double passed by value
 */
void ShippingItem::set_length(double length)
{
    if (length < kMinSize || length > kMaxSize)
    {
        throw std::out_of_range("Error: Not an acceptable length.");
    }
    length_ = length;
}

/**
 * @brief Sets the delivered member to the value sent
 *
 * @param delivered - a boolean (initially set to false) passed by value.
 */
void ShippingItem::set_delivered(bool delivered)
{
    delivered_ = delivered;
}

//two constructors and a destructor
/**
 * @brief Default constructor. This method sets the name of the address to 'unknown'.
 * The other members of the address are left unassigned.
 * It sets the weight to 2.
 * It sets the length to 12.
 * It sets delivered to false.
 */
ShippingItem::ShippingItem()
{
    address_.name = "unknown";
    item_weight_ = 2;
    length_ = 12;
    delivered_ = false;
}

/**
 * @brief Non-default constructor.
 * Sets the data members to the values sent.
 *
 * @param address - A struct that sets the address to the value sent.
 * @param weight - a double that sets the weight to the value sent.
 * @param length - a double that sets the length to the value sent.
 */
ShippingItem::ShippingItem(Address address, double weight, double length)
{
    set_address(address);
    set_weight(weight);
    set_length(length);
}

/**
 * @brief This method sets the delivered data member to true.
 */
void ShippingItem::MarkDelivered()
{
    set_delivered(true);
}

