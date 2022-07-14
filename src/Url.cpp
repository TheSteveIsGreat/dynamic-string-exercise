#include "Url.h"

using namespace std;

Url::Url(const char* str) : DynamicString(str) {
    DynamicString myURL(str);
    int colonPos = myURL.find(':', 0);

    if (colonPos == -1
        || colonPos == 0
        || reinterpret_cast<const char *>(myURL.char_at(colonPos + 1)) != "/"
        || myURL.char_at(colonPos +2) != '/'
    || myURL.char_at(colonPos +3) == '\0'){
        throw std::invalid_argument("Invalid URL");
    }
}

int Url::compare(const Url& other) {
    int x = DynamicString::iCompare(other);

    if (x != 0) {
        return x;
    }
    return 0;


}
