#pragma once

#include <iostream>
#include <utility>


class MyNode{

public:

    int _value;

    MyNode() : _value(0){}

    int val() const{

        return _value;
    }

};

class MyList{

private:

    int *_begin;

    int *_end;

    int _size;

public:

    MyList() : _size(0), _begin(nullptr), _end(nullptr){

        std::cout << "KONST: Domyslny" << std::endl;
    }

    MyList(int n) : _size(n){

        std::cout << "KONST: Domyslny" << std::endl << "KONST: Jednoargumentowy" << std::endl;

        int *temp = new int[n];

        for(int i = 0; i < n; i++){

            *(temp + i) = i;
        }

        _begin = temp;
        _end = temp + _size - 1;

    }

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


    MyList(const MyList &l) : _begin(l._begin), _end(l._end), _size(l._size){
        
        std::cout << "KONST: Domyslny" << std::endl << "KONST: kopiujacy" << std::endl;
    }

    MyList(MyList &&l) : _size(std::exchange(l._size, 0)), _begin(std::move(l._begin)), _end(std::move(l._end)){

        std::cout << "KONST: przenoszacy" << std::endl;
    }

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

    ~MyList(){

        std::cout << "DESTRUKTOR (rozmiar = " << _size << ")" << std::endl;

        this->clear();
    }

    void clear(){

        if(_size == 0) return;

        delete [] _begin;

        _size = 0;

        _begin = nullptr;

        _end = nullptr;

    }

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

    bool empty() const{

        if(_size > 0) return false;

        return true;
    }

    int size() const{

        return _size;
    }

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
