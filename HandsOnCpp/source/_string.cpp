#include<iostream>
#include"_string.h"
using namespace std;


_string::_string() : size(1), data(new char[size]) { data[0] = '\0'; }

_string::_string(const char* ch)
{
    size = 0;
    while (ch[size] != '\0')
        size++;
    data = new char[size + 1];
    size_t  increment = 0;
    while (ch[increment] != '\0')
    {
        data[increment] = ch[increment];
        increment++;
    }
    data[size + 1] = '\0';
}
_string::~_string() {}
