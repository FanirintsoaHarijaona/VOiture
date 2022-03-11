#include <iostream>
#include "Batterie.hpp"
//pour convertir un entier en chaîne de caractères
#include <sstream>
using namespace std;
Batterie::Batterie()
{
    dureeDeVie=365;
    voltage=12;
}
Batterie::Batterie(float couts,float duree,float nVoltage)
{
    voltage=nVoltage;
    prix=couts;
    dureeDeVie=duree;
}
//fonction qui sert à convertir en nombre l'affichage des infos de la batterie
string Batterie::toString() const
{
    string result,strPrix,strDuree,strVoltage;
    stringstream ss;
    ss<<voltage;
    ss>>strVoltage;
    strPrix=to_string(prix);
    strDuree=to_string(dureeDeVie);
    result="Batterie\n\tprix:"+strPrix+"Ar\n\tvoltage:"+strVoltage+" V\n\tDuree de vie:"+strDuree;
    result+=" jours\n";
    return result;
}
//affiche les informations concernant la voiture
void Batterie::afficherInfo() const
{
    cout<<toString();
}
//destructeur
Batterie::~Batterie()
{
}
void Batterie::getDureeRestante(float tempsUtilise)
//tempsUtilise spécifie le temps écoulé depuis la première utilisation de la voiture
{
    if(tempsUtilise<365&&tempsUtilise>0)
    {
        dureeDeVie-=tempsUtilise;
        cout<<"Vous devez faire reparer votre voiture ou en acheter une nouvelle dans ";
        cout<<dureeDeVie<<" jours";
    }
    else 
    {
        cout<<"Aucune batterie ne peut atteindre ce temps de vie de"<<endl;
        cout<< tempsUtilise<<" jours";
    }
    cout<<endl;
}
float Batterie::getPrix() const
{
    return prix;
}
float Batterie::getDureeDeVie() const
{
    return dureeDeVie;
}
float Batterie::getVoltage() const
{
    return voltage;
}
void Batterie::setPrix(float nPrix)
{
    prix=nPrix;
}
void Batterie::setDureeDeVie(float nDuree)
{
    dureeDeVie=nDuree;
}
void Batterie::diminueVoltage()
{
    voltage--;
}
void Batterie::chargerBatterie()
{
    if(voltage<5&&voltage>0)
    {
        while(voltage<13)
        voltage++;
    }
}