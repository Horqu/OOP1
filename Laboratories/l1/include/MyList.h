#pragma once

#include <iostream>
#include <utility>

/**
 * @brief Class representing node(unfinished, only to make MyList class work) 
 * 
 */
class MyNode{

private:

    int _value;

    MyNode() : _value(0){}

public:

    int val() const{

        return _value;
    }

    friend class MyList;

};

/**
 * @brief Class representing list
 * 
 */
class MyList{

private:

    int *_begin;

    int *_end;

    int _size;

public:

    /**
     * @brief Construct a new My List object
     * 
     */
    MyList() : _size(0), _begin(nullptr), _end(nullptr){

        std::cout << "KONST: Domyslny" << std::endl;
    }

    /**
     * @brief Construct a new My List object
     * 
     * @param n - size of created list
     */
    MyList(int n) : _size(n){

        std::cout << "KONST: Domyslny" << std::endl << "KONST: Jednoargumentowy" << std::endl;

        int *temp = new int[n];

        for(int i = 0; i < n; i++){

            *(temp + i) = i;
        }

        _begin = temp;
        _end = temp + _size - 1;

    }

    /**
     * @brief Construct a new My List object by using initializer list
     * 
     * @param n - initializer list
     */
    MyList(std::initializer_list<int> n){

        std::cout << "KONST: std::initializer_list" << std::endl;

        int *temp = new int[n.size()];

        for(int i = 0; i < n.size(); i++){
            *(temp + i) = *(n.begin() + i);
        }

        _begin = temp;

        _end = temp + n.size() - 1;

        _size = n.size();

    }

    /**
     * @brief Construct a new My List object
     * 
     * @param l - source object used to copy
     */
    MyList(const MyList &l) : _begin(l._begin), _end(l._end), _size(l._size){
        
        std::cout << "KONST: Domyslny" << std::endl << "KONST: kopiujacy" << std::endl;
    }

    /**
     * @brief Construct a new My List object
     * 
     * @param l - source object which is being moved
     */
    MyList(MyList &&l) : _size(std::exchange(l._size, 0)), _begin(std::move(l._begin)), _end(std::move(l._end)){

        std::cout << "KONST: przenoszacy" << std::endl;
    }

    /**
     * @brief Construct a new My List object
     * 
     * @param func - function from main.cpp which is returning integer number
     * @param n - size of a list
     */
    MyList(int (&func)(MyNode *), int n) : _size(n){

        std::cout << "KONST: funkcja generujaca" << std::endl;

        int *temp = new int[n];

        MyNode *node = nullptr;

        *temp = func(node);

        delete node;

        for(int i = 1; i < n; i++){

            MyNode *node = new MyNode;
            node->_value = *(temp + i - 1);
            *(temp + i) = func(node);
            delete node;
        }

        _begin = temp;
        _end = temp + n - 1;

    }

    /**
     * @brief Destroy the My List object
     * 
     */
    ~MyList(){

        std::cout << "DESTRUKTOR (rozmiar = " << _size << ")" << std::endl;

        this->clear();
    }

    /**
     * @brief Frees allocated memory for object without deleting it
     * 
     */
    void clear(){

        if(_size == 0) return;

        delete [] _begin;

        _size = 0;

        _begin = nullptr;

        _end = nullptr;

    }

    /**
     * @brief Add a new integer to the end of list
     * 
     * @param n - new added value
     */
    void add(int n){

        _size++;

        int *ptr = new int[_size];

        for(int i = 0; i < _size - 1; i++){

            *(ptr + i) = _begin[i]; 
        }

        *(ptr + _size - 1) = n;

        _begin = ptr;

        _end = ptr + _size - 1;

    }

    /**
     * @brief Check if list is empty
     * 
     * @return true - when empty
     * @return false - when there is at least one number in the list
     */
    bool empty() const{

        if(_size > 0) return false;

        return true;
    }

    /**
     * @brief Returns size of the list 
     * 
     * @return int - size
     */
    int size() const{

        return _size;
    }

    /**
     * @brief Print whole list
     * 
     */
    void print() const{

        std::cout << "[";

        if(_size == 0){
            std::cout << "]" << std::endl;
            return;
        }

        for(int i = 0; i < _size - 1; i++){

            std::cout << *(_begin + i) << ", ";
        }

        std::cout << *(_begin + _size - 1) << "]" << std::endl;

    }

};
