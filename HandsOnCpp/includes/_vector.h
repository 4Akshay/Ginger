#ifndef _vector_H
#pragma once
template<typename T>
class _vector
{
public:
    _vector(); //default constructor
    _vector(T* iData, size_t iSize, size_t iCapacity); // parameterized constructor
    _vector(const _vector& vec); //copy constructor
    _vector(_vector&& vec)noexcept; // move constructor
    _vector& operator=(const _vector& vec); // assignement operator
    _vector& operator=(_vector&& vec) noexcept; // move assignement operator
   ~_vector();
private:
    T* _data;
    size_t _size;
    size_t _capacity;
};
#endif // !_vector_H