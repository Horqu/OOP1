#pragma once

#include <iostream>
#include "zelazko.h"
#include "main.h"

/**
 * @brief Klasa dziedziczaca z klasy ubrania
 * 
 */
class KoszulaBawelniana : public Ubranie{

private:

    bool _rek;

public:

    KoszulaBawelniana(int cost, bool rek) : Ubranie("Koszula bawelniana", cost, 7, false), _rek(rek){}

    void Wypisz() const {

        std::cout << _name << " cena: " << _cost << ". ";
        if(_wyp) std::cout << "Wyprasowane. ";
        else std::cout << "pogniecione. ";

        if(_rek) std::cout << "Dlugi rekaw." << std::endl;
        else std::cout << "Krotki rekaw" << std::endl;
    }

    void SkrocRekawy() {

        _rek = false;
    }
};

/**
 * @brief Klasa dziedziczaca z klasy ubrania
 * 
 */
class KoszulaJedwabna : public Ubranie{

private:

    bool _rek;

public:

    KoszulaJedwabna(int cost, bool rek) : Ubranie("Koszula jedwabna", cost, 3, false), _rek(rek){}

    void Wypisz() const {

        std::cout << _name << " cena: " << _cost << ". ";
        if(_wyp) std::cout << "Wyprasowane. ";
        else std::cout << "Pogniecione. ";

        if(_rek) std::cout << "Dlugi rekaw." << std::endl;
        else std::cout << "Krotki rekaw" << std::endl;
    }

    void SkrocRekawy() {

        _rek = false;
    }
};

/**
 * @brief Klasa dziedziczaca z klasy ubrania
 * 
 */
class SpodnieBawelniane : public Ubranie{

private:

    bool _kanty;

public:

    SpodnieBawelniane(int cost) : Ubranie("Spodnie Bawelniane", cost, 3, false), _kanty(false){}

    void Wypisz() const {

        std::cout << _name << " cena: " << _cost << ". ";
        if(_wyp) std::cout << "Wyprasowane. ";
        else std::cout << "Pogniecione. ";

        if(_kanty) std::cout << "Kanty." << std::endl;
        else std::cout << "Brak kantow" << std::endl;
    }

    void PrasujKanty(Zelazko z) {

    }
};

/**
 * @brief Klasa dziedziczaca z klasy ubrania
 * 
 */
class SpodnieJedwabne : public Ubranie{

private:

    bool _kanty;

public:

    SpodnieJedwabne(int cost) : Ubranie("Spodnie Bawelniane", cost, 3, false), _kanty(false){}

    void Wypisz() const {

        std::cout << _name << " cena: " << _cost << ". ";
        if(_wyp) std::cout << "Wyprasowane. ";
        else std::cout << "Pogniecione. ";

        if(_kanty) std::cout << "Kanty." << std::endl;
        else std::cout << "Brak kantow" << std::endl;
    }

    void PrasujKanty(Zelazko z) {

        if(_kanty){
            std::cout << "Ubranie ma kanty" << std::endl;
            return;
        }

        _kanty = true;

        std::cout << "---Prasuje nogawki " << _name << " zelazkiem o temp. " << z.getTemp() << std::endl;
    }
};
