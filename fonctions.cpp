#include "fonctions.hpp"

/*template <typename T>
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
}*/
rapidjson::Document getData(std::string filename) {
    std::ifstream json;
    json.open(filename);
    std::stringstream buffer;
    buffer << json.rdbuf();
    rapidjson::Document doc;
    std::string const _{buffer.str()};
    rapidjson::ParseResult ok = doc.Parse(_.c_str());
    if (!ok) {
        printf("Erreur");
        exit(-1);
    }
    return doc;
}

void mainCalcul() {
    rapidjson::Document doc = getData("data.json");
    std::map<std::string,TypeVehicule>* listeStructVehicules = new std::map<std::string,TypeVehicule>;
    std::vector<std::string>* listeTypeVehicules = new std::vector<std::string>;
    std::map<std::string,TypeEnergie>* listeStructEnergies = new std::map<std::string,TypeEnergie>;
    std::vector<std::string>* listeEnergies = new std::vector<std::string>;
    std::map<std::string,Kilometrage>* listeStructKilometrages = new std::map<std::string,Kilometrage>;
    std::vector<std::string>* listeKilometrages = new std::vector<std::string>;
    std::map<std::string,Annee>* listeStructAnnees = new std::map<std::string,Annee>;
    std::vector<std::string>* listeAnnees = new std::vector<std::string>;

    bool r1 = initListe(listeTypeVehicules, listeStructVehicules, doc["donnees vehicules"][0]);
    bool r2 = initListe(listeEnergies, listeStructEnergies, doc["donnees vehicules"][1]);
    bool r3 = initListe(listeKilometrages, listeStructKilometrages, doc["donnees vehicules"][2]);
    bool r4 = initListe(listeAnnees, listeStructAnnees, doc["donnees vehicules"][3]);

    if (r1 && r2 && r3 && r4) {
        int note = 0;
        std::cout << "Quel est le type de voiture que vous souhaitez acheter ? Choississez le numero correspondant." << std::endl;
        for (int i{1}; i <= listeTypeVehicules->size(); i++) {
            std::cout << std::to_string(i) << " : " << listeStructVehicules->at(listeTypeVehicules->at(i-1)).nomVehicule() << " (poids moyen : " << listeStructVehicules->at(listeTypeVehicules->at(i-1)).poidsMoyen() << ")" << std::endl;
        }
        std::string choix;
        int choixInt;
        do
        {
            std::cout << "Votre choix : ";
            std::cin >> choix;
            try
            {
                choixInt = std::stoi(choix);
            }
            catch(const std::invalid_argument & e)
            {   
                std::cout << "Veuillez saisir un entier" << std::endl;
            }
        } while (choixInt < 1 or choixInt > listeTypeVehicules->size());
        note += listeStructVehicules->at(listeTypeVehicules->at(choixInt-1)).note();
        
        
        std::cout << "Quelle est l'énergie utilisée par la voiture que vous souhaitez acheter ? Choississez le numero correspondant." << std::endl;
        for (int i{1}; i <= listeEnergies->size(); i++) {
            std::cout << std::to_string(i) << " : " << listeStructEnergies->at(listeEnergies->at(i-1)).energie() << std::endl;
        }
        do
        {
            std::cout << "Votre choix : ";
            std::cin >> choix;
            try
            {
                choixInt = std::stoi(choix);
            }
            catch(const std::invalid_argument & e)
            {   
                std::cout << "Veuillez saisir un entier" << std::endl;
            }
        } while (choixInt < 1 or choixInt > listeEnergies->size());
        note += listeStructEnergies->at(listeEnergies->at(choixInt-1)).note();

        std::cout << "Combien de kilometres comptez vous parcourir chaque année avec votre vehicule ? Choississez le numero correspondant." << std::endl;
        for (int i{1}; i <= listeKilometrages->size(); i++) {
            std::cout << std::to_string(i) << " : " << listeStructKilometrages->at(listeKilometrages->at(i-1)).valeurKilometrage() << std::endl;
        }
        do
        {
            std::cout << "Votre choix : ";
            std::cin >> choix;
            try
            {
                choixInt = std::stoi(choix);
            }
            catch(const std::invalid_argument & e)
            {   
                std::cout << "Veuillez saisir un entier" << std::endl;
            }
        } while (choixInt < 1 or choixInt > listeKilometrages->size());
        note += listeStructKilometrages->at(listeKilometrages->at(choixInt-1)).note();

        std::cout << "De quelle année date le modèle que vous souhaitez acheter ? Choississez le numero correspondant." << std::endl;
        for (int i{1}; i <= listeAnnees->size(); i++) {
            std::cout << std::to_string(i) << " : " << listeStructAnnees->at(listeAnnees->at(i-1)).valeurAnnee() << std::endl;
        }
        do
        {
            std::cout << "Votre choix : ";
            std::cin >> choix;
            try
            {
                choixInt = std::stoi(choix);
            }
            catch(const std::invalid_argument & e)
            {   
                std::cout << "Veuillez saisir un entier" << std::endl;
            }
        } while (choixInt < 1 or choixInt > listeAnnees->size());
        note += listeStructAnnees->at(listeAnnees->at(choixInt-1)).note();

        std::cout << "Combien serez vous de personnes à utiliser cette voiture ? Au dela de 4, indiquer 4." << std::endl;
        do
        {
            std::cout << "Votre choix : ";
            std::cin >> choix;
            try
            {
                choixInt = std::stoi(choix);
            }
            catch(const std::invalid_argument & e)
            {   
                std::cout << "Veuillez saisir un entier" << std::endl;
            }
        } while (choixInt < 1 or choixInt > 4);
        float taux{doc["donnes bancaires"][1]["valeurs"][choixInt-1]["bonus"].GetFloat()};

        for (int i{0}; i< doc["donnes bancaires"][0]["valeurs"].Size(); i++) {
            if (note >= doc["donnes bancaires"][0]["valeurs"][i]["min"].GetInt() && note <= doc["donnes bancaires"][0]["valeurs"][i]["max"].GetInt()) {
                taux += doc["donnes bancaires"][0]["valeurs"][i]["taux"].GetFloat();
                break;
            }
        }
        std::cout << "Votre taux d'emprunt est de : " << std::to_string(taux) << "%" << std::endl;
    }
    
    delete listeStructVehicules;
    delete listeTypeVehicules;
    delete listeStructEnergies;
    delete listeEnergies;
    delete listeStructKilometrages;
    delete listeKilometrages;
    delete listeStructAnnees;
    delete listeAnnees;
}