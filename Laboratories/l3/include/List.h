#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include "Functors.h"
#include <iterator>


/**
 * @brief Class representing list of integers
 * 
 */
class List{

private:

    /**
     * @brief Vector of integers
     * 
     */
    std::vector<int> _data;

public:

    /**
     * @brief Insert data to the end of list
     * 
     * @param i - value to insert
     */
    void insert(int i){

        _data.push_back(i);
    }

    /**
     * @brief Print list with additional string in the beginning
     * 
     * @param s additional string
     */
    void print(std::string s) const{

        std::cout << s << " [ ";
        for(int i = 0; i < _data.size(); i++){
            std::cout << _data[i] << " ";
        }
        std::cout << "]\n";
    }

    /**
     * @brief Print list
     * 
     */
    void print() const{

        std::cout <<"[ ";
        for(int i = 0; i < _data.size(); i++){
            std::cout << _data[i] << " ";
        }
        std::cout << "]\n";

    }

    /**
     * @brief Operator []
     * 
     * @param i - index of element
     * @return int& - reference to element of list
     */
    int &operator[](int i){

        return _data[i];
    }

    /**
     * @brief List filter by function
     * 
     * @param f filter
     * @return Filtered copy of list
     */
    List filter(std::function<bool(int)> f){

        List result;

        for(int i = 0; i < _data.size(); i++){
            if(f(_data[i]) == true) result._data.push_back(_data[i]);
        }

        return result;
    }

    /**
     * @brief List filter by class
     * 
     * @param gt class GreaterThan
     * @return Filtered copy of list
     */
    List filter(GreaterThan gt){

        List result;

        for(int i = 0; i < _data.size(); i++){
            if(_data[i] > gt._n) result._data.push_back(_data[i]);
        }
        return result;
    }

    /**
     * @brief List filter by class
     * 
     * @param db class DivisibleBy
     * @return Filtered copy of list
     */
    List filter(DivisibleBy db){

        List result;

        for(int i = 0; i < _data.size(); i++){
            if((_data[i] % db._n) == 0) result._data.push_back(_data[i]);
        }
        return result;
    }    


};