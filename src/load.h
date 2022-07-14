#ifndef LOAD_H
#define LOAD_H

#include "shipping_item.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Load
{
private:
    std::vector<ShippingItem*> data_vector_;
    int index_;
    int count_;
    double weight_, volume_;

public:
    //a constructor and a destructor
    Load();
    ~Load();

    //three getters
    int get_count() const;
    double get_total_volume() const;
    double get_total_weight() const;

    //six other methods
    void FillLoad(std::string filename);
    void DisplayNextDelivery(std::ofstream &out) const;
    void ItemDelivered();
    void NotDeliverable();
    int HowManyDelivered() const;
    int HowManyNotDelivered() const;
};

#endif