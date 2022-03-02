#pragma once

#include <iostream>

/**
 * @brief Class representing vector of integers
 * 
 */
class vec{

private:

    /**
     * @brief Pointer to the first element of the vector 
     * 
     */
    int *_v;

    /**
     * @brief Size of the vector
     * 
     */
    int _size;

public:

    /**
     * @brief Construct a new vec object
     * 
     */
    vec() : _v(nullptr), _size(0) {}

    /**
     * @brief Destroy the vec object
     * 
     */
    ~vec(){

        if(_size != 0){
            
            delete [] _v;
            _size = 0;
        }
    }

    /**
     * @brief Add a new element to the end of the vector
     * 
     * @param x Structure respresenting integer
     */
    void push_back(Int_t x){

        _size += 1;

        int *temp = new int[_size];

        for(int i = 0; i < _size - 1; i++){

            temp[i] = _v[i];
        }

        temp[_size - 1] = x.get();

        delete [] _v;

        _v = temp;

    }

    /**
     * @brief get first element of the vector
     * 
     * @return pointer to the first element of the vector 
     */
    int *begin(){

        return _v;
    }

    /**
     * @brief get last element of the vector
     * 
     * @return pointer to the last element of the vector 
     */
    int *end(){

        return _v + _size;
    }

    /**
     * @brief Overloading array operator
     * 
     * @param n index of the array
     * @return address of expected element of the vector 
     */
    int &operator[](int n){

        return _v[n];
    }

};