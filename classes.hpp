#ifndef CLASSES
#define CLASSES

#include <string>
#include "rapidjson/rapidjson.h"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"

class TypeVehicule
{
public:
    TypeVehicule(const rapidjson::Value& obj);
    ~TypeVehicule();

    const std::string nomVehicule () { return _nomVehicule; };
    const std::string poidsMoyen () { return _poidsMoyen; };
    const float note () { return _note; };

private:
    std::string _nomVehicule;
    std::string _poidsMoyen;
    float _note;
};

class TypeEnergie
{
public:
    TypeEnergie(const rapidjson::Value& obj);
    ~TypeEnergie();

    const std::string energie () { return _energie; };
    const float note () { return _note; };

private:
    std::string _energie;
    float _note;
};

class Kilometrage
{
public:
    Kilometrage(const rapidjson::Value& obj);
    ~Kilometrage();

    const std::string valeurKilometrage () { return _valeurKilometrage; };
    const float note () { return _note; };

private:
    std::string _valeurKilometrage;
    float _note;
};

class Annee
{
public:
    Annee(const rapidjson::Value& obj);
    ~Annee();

    const std::string valeurAnnee () { return _valeurAnnee; };
    const float note () { return _note; };

private:
    std::string _valeurAnnee;
    float _note;
};

#endif