#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;

DynamicString::DynamicString(){
    length_ = 0;
    cstr = new char[1] {'\0'} ;
}

DynamicString::DynamicString(const char* str){
    for (length_ = 0; str[length_] != '\0'; ++length_);
    cstr = new char[length_];
    for (int i = 0; i < length_; ++i) {
        cstr[i] = str[i];
    }
    cstr[length_] = '\0';
}

int DynamicString::len() const{
    return length_;
}

const char* DynamicString::c_str() const{
    return cstr;
}

char DynamicString::char_at(int position) const{
    if (position > length_ || position < 0) {
        throw std::out_of_range("Position out of range.");
    }
    return cstr[position];
}

char& DynamicString::operator[](int position){
    if (position > length_ || position < 0) {
        throw std::out_of_range("Position out of range.");
    }
   return cstr[position];
}

bool DynamicString::startsWith(const DynamicString& other) const{
    for (int i = 0; i < other.len(); ++i) {
        if (cstr[i] != other.char_at(i)) {
            return false;
        }
    }
   return true;
}

bool DynamicString::endsWith(const DynamicString& other) const{
    for (int i = other.len(), j=length_; i >= 0; --i, --j) {
        if (cstr[j] != other.char_at(i)) {
            return false;
        }
    }
   return true;
}

int DynamicString::compare(const DynamicString& other) const{
    for (int i = 0; i <= other.len(); ++i) {
        if (cstr[i] > other.char_at(i)) {
            return 1;
        } else if (cstr[i] < other.char_at(i)) {
            return -1;
        }
    }
   return 0;
}

int DynamicString::iCompare(const DynamicString& other) const{
    for (int i = 0; i <= other.len(); ++i) {
        if (std::tolower(cstr[i]) > std::tolower(other.char_at(i))) {
            return 1;
        } else if (std::tolower(cstr[i]) < std::tolower(other.char_at(i))) {
            return -1;
        }
    }
    return 0;
}

DynamicString& DynamicString::toLower(){
    for (int i = 0; i < length_ ; ++i) {
        cstr[i] = std::tolower(cstr[i]);
    }
   return *this;
}

DynamicString& DynamicString::toUpper(){
    for (int i = 0; i < length_ ; ++i) {
        cstr[i] = std::toupper(cstr[i]);
    }
   return *this;
}

DynamicString& DynamicString::replace(char old, char newCh){
    for (int i = 0; i < length_; ++i) {
        if (cstr[i] == old) {
            cstr[i] = newCh;
        }
    }
   return *this;
}

int DynamicString::find(char c, int start) const{
    for (int i = start; i < length_; ++i) {
//        std::cout << i << std::endl;
//        std::cout << cstr[i] << std::endl;
        if (cstr[i] == c) {
            return i;
        }
    }
   return -1;
}

int DynamicString::reverseFind(char c, int start) const{
    for (int i = start; i >= 0; --i) {
        if (cstr[i] == c) {
            return i;
        }
    }
   return -1;
}

int DynamicString::reverseFind(char c) const{
    for (int i = length_ -1; i >= 0; --i) {
        if (cstr[i] == c) {
            return i;
        }
    }
   return -1;
}

ostream& operator<<(ostream& out, const DynamicString& str){
    out << str.c_str();
   return out;
}

DynamicString::DynamicString(const DynamicString & other) {
    int count = 0;
    while (other.cstr[count] != '\0') {
        count++;
    }
    cstr = new char [count + 1];
    *cstr = *other.cstr;
}

DynamicString& DynamicString::operator=(const DynamicString & other) {
    if (this != &other) {
        delete cstr;
        int count = 0;
        while (other.cstr[count] != '\0') {
            count++;
        }
        cstr = new char [count + 1];
        for (int i = 0; i < count; ++i) {
            cstr[i] = other.cstr[i];
        }
        cstr[count] = '\0';
    }
    return *this;
}

DynamicString::~DynamicString() {
    delete cstr;
}