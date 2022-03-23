#pragma once

#include <iostream>
#include <vector>
#include <functional>

/**
 * @brief class with the vector of functors
 * 
 */
class FilterCriteria{

private:

    std::vector<std::function<bool(int)>> _crit;

public:

    void add(std::function<bool(int)> f){

        _crit.push_back(f);

    }

    int size(){

        return _crit.size();
    }

    std::function<bool(int)> get(int i){

        return _crit[i];
    }

};