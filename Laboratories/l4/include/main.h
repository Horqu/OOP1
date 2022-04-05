#pragma once

#include <iostream>

/**
 * @brief Klasa reprezentujaca zelazko
 * 
 */
class Zelazko{

protected:

    /**
     * @brief Nazwa, koszt, temperatura i temperatura maksymalna zelazka
     * 
     */
    std::string _name;
    int _cost;
    int _temp;
    int _temp_max;

public:

    /**
     * @brief Construct a new Zelazko object
     * 
     * @param n 
     * @param c 
     * @param t 
     * @param tm 
     */
    Zelazko(std::string n, int c, int t, int tm) : _name(n), _cost(c), _temp(t), _temp_max(tm){}

    /**
     * @brief Wypisywanie
     * 
     */
    void Wypisz() const {

        std::cout << _name << " cena: " << _cost << ". Temperatura: " << _temp;

        if(_name == "Philips")std::cout << std::endl;
        else std::cout << " Zakres: " << _temp_max << std::endl;
    }

    /**
     * @brief Ustawianie temperatury zelazka
     * 
     * @param n 
     */
    void UstawTemperature(int n){

        if(n > _temp_max){
            std::cout << "Ten model nie obsluguje takiego zakresu temperatur." << std::endl;
            return;
        }

        _temp = n;
    }

    /**
     * @brief Zwraca temperature
     * 
     * @return int 
     */
    int getTemp() const{

        return _temp;
    }

};

/**
 * @brief Klasa reprezentujaca ubranie
 * 
 */
class Ubranie{

protected:

    /**
    * @brief nazwa, koszt, maksymalna temperatura prasowania, czy wyprasowane 
    * 
    */
    std::string _name;
    int _cost;
    int _temp_max;
    bool _wyp;

public:

    /**
     * @brief Construct a new Ubranie object
     * 
     * @param n 
     * @param c 
     * @param t 
     * @param w 
     */
    Ubranie(std::string n, int c, int t, bool w) : _name(n), _cost(c), _temp_max(t), _wyp(w) {}

    /**
     * @brief Wypisywanie
     * 
     */
    void Wypisz() const{

        std::cout << _name << " cena: " << _cost << ". ";
        if(_wyp) std::cout << "Wyprasowane. ";
        else std::cout << "pogniecione. ";

    }

    /**
     * @brief Prasowanie ubrania
     * 
     * @param z 
     */
    void Prasuj(Zelazko z){

        if(_wyp){
            std::cout << "---Ubranie nie wymaga prasowania" << std::endl;
            return;
        }

        if(z.getTemp() > _temp_max){
            std::cout << "Zelazko za gorace" << std::endl; 
            return;
        }


        _wyp = true;
        std::cout << "---Prasuje " << _name << " zelazkiem o temp. " << z.getTemp() << "." << std::endl;

    }

    /**
     * @brief Gniecenie ubrania
     * 
     */
    void Pogniec(){

        _wyp = false;
    }
};