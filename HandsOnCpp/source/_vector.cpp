#include<iostream>
using namespace std;
#include "_vector.h"

template<typename T>
_vector<T>::_vector() :_data(nullptr), _size(0), _capacity(0) {};

template<typename T>
_vector<T>::_vector(T* iData, size_t iSize, size_t iCapacity)
{
    _size = iSize;
    _capacity = iCapacity;
    _data = new T[_capacity];
    for (int i = 0; i < size; i++)
        _data[i] = iData[i];
}

template<typename T>
_vector<T>:: ~_vector() { delete[] _data; }

template<typename T>
_vector<T>::_vector(const _vector& iVec)
{
    if (_size != 0)
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
        _capacity = 0;
    }
    _capacity = iVec.capacity + iVec.capacity;
    _size = iVec->_size;
    _data = new T[_capacity];
    for (int i = 0; i < size; i++)
        _data[i] = iVec.data[i];
}

template<typename T>
_vector<T>::_vector(_vector<T>&& iVec)noexcept : _capacity(iVec._capacity),
                    _size(iVec._size), _data(iVec._data)
{
    iVec._capacity = 0;
    iVec._size = 0;
    iVec._data = NULL;
}

template<typename T>
_vector<T>& _vector<T>::operator=(const _vector<T>& iVec)
{
    if (this == &iVec)
        return *this;
    delete[] _data;
    _capacity = iVec.capacity;
    _size = iVec.size;
    _data = new T[_capacity];
    for (int i = 0; i < size; i++)
        _data[i] = iVec.data[i];
    return *this;
}

template<typename T>
_vector<T>& _vector<T>::operator=(_vector<T>&& iVec)noexcept
{
    if (this == &iVec)
        return *this;
    delete[] _data;
    _capacity = iVec.capacity;
    _data = iVec.data;
    _size = iVec.size;
    iVec.data = NULL;
    iVec.size = 0;
    iVec.capacity = 0;
    return *this;
}