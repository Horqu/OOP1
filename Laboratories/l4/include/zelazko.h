#pragma once

#include <iostream>
#include "main.h"

/**
 * @brief Klasa dziedziczaca z zelazka
 * 
 */
class ZelazkoPhilips : public Zelazko{

public:

    ZelazkoPhilips(int cost) : Zelazko("Philips", cost, 0, 5){}

};

/**
 * @brief Klasa dziedziczaca z zelazka
 * 
 */
class ZelazkoTefal : public Zelazko{

public:

    ZelazkoTefal(int cost) : Zelazko("Tefal", cost, 0, 7){}

};