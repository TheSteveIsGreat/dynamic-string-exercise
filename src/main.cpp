#include <iostream>
#include "shipping_item.h"
#include "carton.h"
#include "flat.h"
#include "tube.h"
#include "load.h"

using namespace std;

int main() { 


  cout << "Part 2.2: Use the Carton Class in Main.cpp\n";

  // Create a Carton object using the new constructor.
  // When using this constructor, use try/catch blocks to handle
  // the exceptions.
  Address a1 {"Bart Smith", "64 South Main", "Ogden", "UT", "84408"};
  Carton c1 (a1, 12.8, 18, 18, 32);


  // Use the Carton object to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // When calling the setters, use try/catch blocks to handle the exceptions.

    cout << "Initial measurements: " << endl;
    cout << "Carton weight: " << c1.get_weight() << endl;
    cout << "Carton width: " << c1.get_width() << endl;
    cout << "Carton height: " << c1.get_height() << endl;
    cout << "Carton length: " << c1.get_length() << endl;

//    try {
//        c1.set_weight(75);
//    } catch (out_of_range){throw std::out_of_range("Error: Weight must be between 0 and 70.");}
//
//    try {
//    c1.set_length(5);
//    }
//    catch (out_of_range){throw out_of_range("Length must be the longest measurement");}
//    try {
//    c1.set_length(0);
//    }
//    catch (out_of_range){throw out_of_range("Length must be greater than zero");}
//
//    try {
//      c1.set_width(0);
//    } catch (out_of_range){throw out_of_range("Length must be greater than zero");}
//    try {
//      c1.set_width(35);
//    } catch (out_of_range){throw out_of_range("Width must be shorter or equal to length");}
//
//    try {
//        c1.set_height(0);
//    } catch (out_of_range){throw out_of_range("Height must be greater than zero");}
//    try {
//        c1.set_height(35);
//    } catch (out_of_range){throw out_of_range("Height must be shorter or equal to length");}

    c1.set_length(18);
    c1.set_width(15);
    c1.set_height(15);

    cout << endl;
    cout << "Set measurements: " << endl;
    cout << "Carton weight: " << c1.get_weight() << endl;
    cout << "Carton width: " << c1.get_width() << endl;
    cout << "Carton height: " << c1.get_height() << endl;
    cout << "Carton length: " << c1.get_length() << endl;


  // Use the Carton object to call the Display method to print to cout.
    cout << endl;
    c1.Display(cout);


    cout << "\nPart 3.3: Use the Flat Class in Main.cpp\n";
  // Create Flat objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
  Address a2 {"Jim Griffin", "85 South Main", "Ogden", "UT", "84408"};
  Flat f1;
  Flat f2 (a2, 4.1, 14.2, 11.3, .46);


  // Use the Flat objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.

    cout << "Flat 1 Initial measurements: " << endl;
    cout << "f1 weight: " << f1.get_weight() << endl;
    cout << "f1 height: " << f1.get_height() << endl;
    cout << "f1 length: " << f1.get_length() << endl;
    cout << "f1 thickness: " << f1.get_thickness() << endl;
    cout << endl;
    cout << "Flat 2 Initial measurements: " << endl;
    cout << "f2 weight: " << f2.get_weight() << endl;
    cout << "f2 height: " << f2.get_height() << endl;
    cout << "f2 length: " << f2.get_length() << endl;
    cout << "f2 thickness: " << f2.get_thickness() << endl;

//    try {
//        f1.set_weight(75);
//    } catch (out_of_range){throw std::out_of_range("Error: Weight must be between 0 and 70.");}
//    try {
//        f1.set_length(15);
//    }
//    catch (std::out_of_range){throw out_of_range("Error: length must be between .007 and 15.");}
//    try {
//        f1.set_height(10);
//    }
//    catch (std::out_of_range){throw out_of_range("Error: height must be between .007 and 12.");}
//    try {
//        f1.set_thickness(.6);
//    }
//    catch (std::out_of_range){throw std::out_of_range("Error: thickness must be between .007 and .75.");}



    // Use the Flat objects to call the Volume and Display methods.
  // Print out the results to cout.
  cout << endl;
  cout << "f1 volume: " << f1.Volume() << endl;
  cout << "f2 volume: " << f2.Volume() << endl;
  cout << endl;
  f1.Display(cout);
  f2.Display(cout);



    cout << "\nPart 4.3: Use the Tube Class in Main.cpp";

  // 1. Create Tube objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.

    Address a3 {"Terri Taylor", "143 South Main", "Ogden", "UT", "84408"};
    Tube t1;
    Tube t2 (a3, 3.6, 32, 8.6);

  // Use the Tube objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.

    cout << "Tube 1 Initial measurements: " << endl;
    cout << "t1 weight: " << t1.get_weight() << endl;
    cout << "f1 length: " << t1.get_length() << endl;
    cout << "f1 circumference: " << t1.get_circumference() << endl;
    cout << endl;
    cout << "Tube 2 Initial measurements: " << endl;
    cout << "t2 weight: " << t2.get_weight() << endl;
    cout << "t2 length: " << t2.get_length() << endl;
    cout << "t2 circumference: " << t2.get_circumference() << endl;

//    try {
//        t2.set_circumference(110);
//    } catch (out_of_range){ throw std::out_of_range("Error: Circumference must be greater than .007, "
//                                                    "and length + circumference must be less than 108.");}

  // Use the Tube objects to call the Volume, Girth and Display methods.
  // Print out the results to cout.

    cout << endl;
    cout << "t1 volume: " << t1.Volume() << endl;
    cout << "t2 volume: " << t2.Volume() << endl;
    cout << endl;
    t1.Display(cout);
    t2.Display(cout);



    cout << "\nPart 5.3: Use the Load Class in Main.cpp";

  // 1. Create a Load object.
    Load l1;
    cout << endl;
    cout << "Initial Load count: " << l1.get_count() << endl;
    cout << "Initial Total volume: " << l1.get_total_volume() << endl;
    cout << "Initial Total weight: " << l1.get_total_weight() << endl;
    cout << endl;
    l1.FillLoad("../../load_small.txt");

  // 2. Use the Load object to call the getter methods.
  // Print out the results to see how these getters are working.
  // Do this right after the Load object is created and after it
  // is filled from the file.
  cout << "Load count: " << l1.get_count() << endl;
  cout << "Total volume: " << l1.get_total_volume() << endl;
  cout << "Total weight: " << l1.get_total_weight() << endl;
  cout << endl;


  //3. Use the Load object to call the FillLoad method.
  // Then call the DisplayNextDelivery, ItemDelivered, NotDeliverable,
  // HowManyDelivered, and HowManyNotDelivered methods multiple times
  // to see how these work when making deliveries.
  Load l2;
  ofstream out("../../test.txt");
  l2.FillLoad("../../load_1.txt");
  l2.DisplayNextDelivery(out);
  l2.ItemDelivered();
  l2.NotDeliverable();
  cout << "How many delivered: " << l2.HowManyDelivered() << endl;
  cout << "How many not delivered: " << l2.HowManyNotDelivered() << endl << endl;

  l2.DisplayNextDelivery(out);
  l2.ItemDelivered();
  l2.NotDeliverable();
  cout << "How many delivered: " << l2.HowManyDelivered() << endl;
  cout << "How many not delivered: " << l2.HowManyNotDelivered() << endl << endl;

  l2.DisplayNextDelivery(out);
  l2.ItemDelivered();
  l2.NotDeliverable();
  cout << "How many delivered: " << l2.HowManyDelivered() << endl;
  cout << "How many not delivered: " << l2.HowManyNotDelivered() << endl << endl;

  return 0;
}