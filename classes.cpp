#include "classes.hpp"

TypeVehicule::TypeVehicule(const rapidjson::Value& obj){
    _nomVehicule = obj["nom"].GetString();
    _poidsMoyen = obj["poids moyen"].GetString();
    _note = obj["note"].GetFloat();
};
TypeVehicule::~TypeVehicule(){};

Kilometrage::Kilometrage(const rapidjson::Value& obj){
    _valeurKilometrage = obj["nom"].GetString();
    _note = obj["note"].GetFloat();
};
Kilometrage::~Kilometrage(){};

Annee::Annee(const rapidjson::Value& obj){
    _valeurAnnee = obj["nom"].GetString();
    _note = obj["note"].GetFloat();
};
Annee::~Annee(){};

TypeEnergie::TypeEnergie(const rapidjson::Value& obj){
    _energie = obj["nom"].GetString();
    _note = obj["note"].GetFloat();
};
TypeEnergie::~TypeEnergie(){};
