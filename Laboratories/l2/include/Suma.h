#pragma once

#include <iostream>
#include "Argumenty.h"
#include "Algo.h"

class Suma : public Algo{

public:

    Argumenty wykonaj(const Argumenty &args) const override{

        Argumenty result(1);

        double sum = 0;

        for(int i = 0; i < args.getArgs().size(); i++){
            sum += args.getArgs()[i];
        }

        result(0, sum);

        return result;
    }

    Suma *sklonuj() const override{

        return new Suma;
    }


};