#ifndef FONCTIONS
#define FONCTIONS

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "classes.hpp"
#include "rapidjson/document.h"

template <typename T>
bool initListe(std::vector<std::string> *&listeNoms, std::map<std::string,T> *&listeStructs, const rapidjson::Value& obj)
{
    if (!obj.IsObject()) {return false;}
    std::string nom;
    for (int i{0}; i < obj["types"].Size(); i++) {
        nom = obj["types"][i]["nom"].GetString();
        listeStructs->insert({nom, T(obj["types"][i])});
        listeNoms->push_back(nom);
    }
    return true;
}

rapidjson::Document getData(std::string filename);

void mainCalcul();
#endif