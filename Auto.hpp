#include <string>
#include "Batterie.hpp"
#include <vector>
//classe définissant une classe qui permet de décrire une voiture
class Auto
{
    private:
//Une voiture peut être définie par sa marque,ses nombres de pneus et sa batterie 
        std::string marque;
        int nbPneus;
        std::vector <std::string> choix;
        int choice;
        bool etat;
//On manipule une inclusion entre classes pour pouvoir les manipuler plus souplement
        Batterie *batterie;
    public:
//constructeurs par défaut et affécté de cet arme
        Auto();
        Auto(std::string nouvelleMarque,int pneus,float couts,float duree,float nVoltage);
         ~Auto();
        std::string ConversionString();
//accesseurs
        bool getEtatVoiture();
        void afficherInfoAuto();
//afficher le menu que l'on peut offrir concernant la voiture 
        void afficherMenu();
        void getChoice();
        void manageChoice();
//méthode qui décrit ce que la voiture peut faire
        void rouler();
        void arreter();
        bool etatVoiture();
};
