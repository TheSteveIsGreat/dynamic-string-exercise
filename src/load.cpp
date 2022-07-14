#include "load.h"
#include "flat.h"
#include "carton.h"
#include "tube.h"
#include <iostream>

//three getters
/**
 * @brief Returns the value of count_
 *
 * @return count_ - The amount of packages in the load
 */
int Load::get_count() const
{
    return count_;
}

/**
 * @brief Returns the value of volume_
 *
 * @return volume_ - The volume of the item
 */
double Load::get_total_volume() const
{
    return volume_;
}

/**
 * @brief Returns the value of weight_
 *
 * @return weight - The weight of the item
 */
double Load::get_total_weight() const
{
    return weight_;
}

//a constructor and a destructor
/**
 * @brief Default Constructor.
 * Sets index_, count_, weight_, and volume_ to 0
 */
Load::Load()
{
    index_ = 0;
    count_ = 0;
    weight_ = 0;
    volume_ = 0;
}

//Implement the FillLoad method.
/**
 * @brief Reads the data for each shipping item in the file.
 *
 * @param filename - The filename including the patch from the build folder
 */
void Load::FillLoad(std::string filename)
{
    std::ifstream in(filename);
    if (in.fail())
    {
        throw std::out_of_range("Unable to open file. Shutting down...");
        return;
    }

    std::string type;
    double weight, length, height, thickness, side1, side2, side3, circumference;
    const double kPi = 3.14159;
    Address address;

    while (in >> type)
    {
        if (type == "F")
        {
            in.ignore();
            std::getline(in,address.name);
            std::getline(in, address.street_address);
            std::getline(in, address.city);
            std::getline(in, address.state);
            std::getline(in, address.zip);
            in >> weight;
            in >> length;
            in >> height;
            in >> thickness;

            weight_ += weight;
            volume_ += (length * height * thickness);
            data_vector_.push_back(new Flat(address, weight, length, height, thickness));
            count_++;
        }

        else if (type == "T")
        {
            in.ignore();
            std::getline(in,address.name);
            std::getline(in, address.street_address);
            std::getline(in, address.city);
            std::getline(in, address.state);
            std::getline(in, address.zip);
            in >> weight;
            in >> length;
            in >> circumference;

            weight_ += weight;
            volume_ += (kPi*(circumference/(2*kPi))*(circumference/(2*kPi)))*length;
            data_vector_.push_back(new Tube(address, weight, length, circumference));
            count_++;
        }

        else if (type == "C")
        {
            in.ignore();
            std::getline(in,address.name);
            std::getline(in, address.street_address);
            std::getline(in, address.city);
            std::getline(in, address.state);
            std::getline(in, address.zip);
            in >> weight;
            in >> side1;
            in >> side2;
            in >> side3;

            weight_ += weight;
            volume_ += (side1*side2*side3);
            data_vector_.push_back(new Carton(address, weight, side1, side2, side3));
            count_ ++;
        }
    }
}

//Write the destructor
/**
 * @brief Delete the dynamic memory created from the FillLoad method
 */
Load::~Load()
{
    for (ShippingItem* &one_ptr : data_vector_)
    {
        delete one_ptr;
        one_ptr = NULL;
    }
}

//Implement the DisplayNextDelivery method.
/**
 * @brief This method is to output the address and the shipping item
 *
 * @param out - Specifies the file stream where the output will be sent
 */
void Load::DisplayNextDelivery(std::ofstream &out) const
{
    out << data_vector_[index_]->get_address().name << std::endl
    << data_vector_[index_]->get_address().street_address << std::endl
    << data_vector_[index_]->get_address().city << ", " << data_vector_[index_]->get_address().state
    << " " << data_vector_[index_]->get_address().zip << std::endl;
    data_vector_[index_]->Display(out);
}

//Implement the ItemDelivered method.
/**
 * @brief Sets the "is delivered" value of the current shipping item to true.
 * Then it changes the current item to the next item in the vector.
 */
void Load::ItemDelivered()
{
    data_vector_[index_]->MarkDelivered();
    index_++;
}

//Implement the NotDeliverable method.
/**
 * @brief Leaves the "is delivered" value of the current item as false.
 * Then it changes the current item to the next item in the vector.
 */
void Load::NotDeliverable()
{
    index_++;
}

//Implement the HowManyNotDelivered method
/**
 * @brief Loops through the shipping items and returns
 * how many have is delivered set to true
 *
 * @return delivered_items - the amount of delivered items
 */
int Load::HowManyDelivered() const
{
    int delivered_items = 0;
    for (ShippingItem* one_ptr : data_vector_)
    {
        if (one_ptr->get_delivered())
        {
            delivered_items++;
        }
    }
    return delivered_items;
}

//Implement the HowManyNotDelivered method.
/**
 * @brief Loops through the shipping items and returns
 * how many have is delivered set to false.
 *
 * @return un_delivered_items - the amount of un-delivered items
 */
int Load::HowManyNotDelivered() const
{
    int un_delivered_items = 0;
    for(ShippingItem* one_ptr : data_vector_)
    {
        if (!one_ptr->get_delivered())
        {
            un_delivered_items++;
        }
    }
    return un_delivered_items;
}
