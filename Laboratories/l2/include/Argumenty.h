#pragma once

#include <iostream>
#include <string>
#include <vector>

class Argumenty{

private:

    std::vector<double> _args;

public:

    Argumenty(int);

    ~Argumenty(){}

    Argumenty &operator()(int, double);

    void print(std::string) const;

    void print(std::string, std::ostream &) const;

    std::vector<double> getArgs() const;

};