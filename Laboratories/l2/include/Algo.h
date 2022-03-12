#pragma once

#include <iostream>
#include "Argumenty.h"

class Algo{

public:

    virtual Argumenty wykonaj(const Argumenty &args) const{

        return args;
    }

    virtual Algo *sklonuj() const{

        return new Algo;
    }

};