#ifndef URL_H
#define URL_H
#include <iostream>
#include "DynamicString.h"

using namespace std;

class Url : public DynamicString{
    string Scheme, Authority, Path;

public:
    Url(const char* str);
    int compare(const Url& other);

};

#endif //URL_H
