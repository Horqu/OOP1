#pragma once

#include <iostream>
#include <math.h>
#include "Argumenty.h"
#include "Algo.h"

class Pierwiastek : public Algo{

public:

    Argumenty wykonaj(const Argumenty &args) const override{

        Argumenty result(args.getArgs().size());

        for(int i = 0; i < args.getArgs().size(); i++){
            result(i, sqrt(args.getArgs()[i]));
        }

        return result;
    }

    Pierwiastek *sklonuj() const override{

        return new Pierwiastek;
    }
    

};