#ifndef _string_H
#pragma once
class _string
{
public:
    _string();
    _string(const char* ch);
    ~_string();
private:
    char* data;
    size_t size;
};
#endif // !_string_H