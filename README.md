# dynamic-string-exercise

Includes the following methods:

DynamicString() //Constructs an empty string. Allocating enough memory to store the null character
DynamicString(const char* str) //Constructs a string by copying the characters from the char array str to this object. You should dynamically allocate enough memory for the entire string.
int len() const //returns the length of this string (i.e. the number of characters in the array not including the null char)
const char* c_str() const // returns a pointer to the underlying char array
char char_at(int position) const // returns the char at the specified position
char& operator[](int position) // returns the char at the specified position
bool startsWith(const DynamicString& other) const //True if other is a prefix of this string
bool endsWith(const DynamicString& other) const //True if other is a suffix of this string
int compare(const DynamicString& other) const // negative if this is smaller than other, 0 if this is equal to other, positive if this is larger than other
int iCompare(const DynamicString& other) const // same as compare but is case-insensetive
DynamicString& toLower() // converts the string to lowercase
DynamicString& toUpper() // converts the string to uppercase
DynamicString& replace(char old, char new) //replace all instances of old with new
int find(char needle, int start=0) const //return the first index of the specified char or -1 if the char is not found starting from index start.
int reverseFind(char needle, int start) const //return the right-most index (less than or equal to start) of the specified char or -1 if the char is not found.
