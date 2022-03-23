#pragma once

#include <iostream>

/**
 * @brief Class functor
 * 
 */
class DivisibleBy{

public:

    int _n;

    DivisibleBy(int i) : _n(i){}

    bool operator()(int i){

        return ((i % _n) == 0);
    }    
};


/**
 * @brief class functor
 * 
 */
class GreaterThan{

public:

    int _n;

    GreaterThan(int i) : _n(i){}

    bool operator()(int i){

        return (i > _n);
    }
};

