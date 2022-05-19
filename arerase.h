#ifndef ARERASE_H
#define ARERASE_H

#include <algorithm>

template <class T>
class array_eraser
{
private:
    T *_array;
    int _capacity;
    int _size;

public:
    array_eraser(T *arr, int size) : _array(arr), _capacity(size), _size(size) {}

    int size() const
    {
        return _size;
    }

    void erase(const T &elem)
    {
        for (int i = _size - 1; i >= 0; i--)
        {

            if (_array[i] == elem)
            {
                erase_index(i);
            }
        }
    }

    void erase_index(int index)
    {
        
        if (index >= _size)
            return;

        T temp = _array[index];
        for (int i = index; i < _size - 1; i++)
        {
            _array[i] = _array[i + 1];
        }
        _array[_size - 1] = temp;
        _size--;
    }

    int count(const T& elem) const
    {
        int count = 0;

        for(int i = 0; i < _size; i++)
        {
            if(_array[i] == elem)
            {
                count++;
            }
        }

        return count;
    }

    typedef T* iterator;

    iterator begin()
    {
        return _array;
    }

    iterator end()
    {
        return _array + _size;
    }
};

#endif