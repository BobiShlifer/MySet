#include <iostream>
#include<algorithm>
#include "set.h"

template<typename T>
Set<T>::Set()
{
    _size = 0;
    capacity = 0;
    array = NULL;
}

template <typename T>
Set <T>::Set(const Set& set)
{
    _size = set._size;
    capacity = set.capacity;
    this->array = new T[capacity];
    for (int i = 0; i < set._size; ++i)
    {
        this->array[i] = set.array[i];
    }
}

template <typename T>
Set<T>& Set <T>::operator=(const Set<T>& set) {
    this->_size = set._size;
    this->capacity = set.capacity;
    if (this->array) {
        delete[] this->array;
    }
    this->array = new T[capacity];
    for (int i = 0; i < set._size; ++i) {
        this->array[i] = set.array[i];
    }
    return *this;
}

template<typename T>
void Set<T>::insert(const T& value)
{
    T value1 = value;
    int index;
    if (_size) {
        auto p = std::lower_bound(array, array + _size, value);  //возвращает итератор на значение в последовательности
        if (p)
        {
            if(*p == value1)
                 return;
            index = p - array;
        }
        else
        {
            index = _size;
        }
         
    }
    else
        index = 0;
    if (_size >= capacity) {
        if (capacity == 0)
            capacity = 1;
        else
            capacity *= 2;
        T* dest = new T[capacity];
        if (array) {
            for (int i = 0; i < _size; i++) {
                dest[i] = array[i];
            }
            delete[] array;
        }
        array = dest;
    }
   
    for (auto q = _size - 1; q >= index; q--) //сдвигаем массив, который после нашего значени€ p вправо
        array[q+1] = array[q];
    _size++;
    array[index]  = value; // вставл€ем значение. Ћ»Ќ≈…Ќјя —Ћќ∆Ќќ—“№
    
}

template<typename T>
void Set<T>::erase(const T& value)
{
    T value1 = value;
    if (!_size) 
        return;
    auto* p = std::lower_bound(array, array + _size, value);
    if (!p || *p != value)
        return;    
    for (auto* q = p; q < array + _size; q++) 
        *q = *(q + 1);
    _size--;
}

template<typename T>
bool Set<T>::find(const T& value) {
    T value1 = value;
    auto* p = std::lower_bound(array, array + _size, value);
    return (p && *p == value1);
}

template<typename T>
int Set<T>::size() {
    return _size;
}

template<typename T>
Set<T>& Set<T>::intersect(const Set <T>& s) {
        if (s._size == 0 || this->_size == 0)
        throw "Exception: intersect is empty!";
    Set<T>* Tmp = new Set <T>;
    for (int i = 0; i < s._size; i++) {
         if (find(s.array[i]))
            Tmp->insert(s.array[i]);
    }                      
    return *Tmp;
}

template<typename T>
Set<T>::~Set() {
    if (array)
        delete[] array;
}