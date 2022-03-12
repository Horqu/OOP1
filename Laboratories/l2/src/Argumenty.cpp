#include <iostream>
#include "Argumenty.h"

Argumenty::Argumenty(int n){

    _args.resize(n);
}

Argumenty &Argumenty::operator()(int i, double val){

    _args[i] = val;
    return *this;
}

void Argumenty::print(std::string s) const{

    std::cout << s;

    for(int i = 0; i < _args.size(); i++){

        std::cout << " " << _args[i];
    }

    std::cout << std::endl;
}

void Argumenty::print(std::string s, std::ostream &o) const{

    o << s;

    for(int i = 0; i < _args.size(); i++){

        o << " " << _args[i];
    }

    o << std::endl;
}

std::vector<double> Argumenty::getArgs() const{

    return _args;
}