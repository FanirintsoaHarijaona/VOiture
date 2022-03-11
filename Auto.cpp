#include "Auto.hpp"
#include <iostream>
#include <string>
#include <vector>
//bibliothèque qui possède des propriétés avec lesquelles on peut convertir un entier en string
#include <sstream>
using namespace std;
Auto::Auto():batterie(0),nbPneus(4)
{
    batterie=new Batterie();
}
Auto::Auto(string nouvelleMarque,int pneus,float cout,float duree,float nVoltage):batterie(0)
{
    marque=nouvelleMarque;
    nbPneus=pneus;
    batterie=new Batterie(cout,duree,nVoltage);
}
Auto::~Auto()
{
    delete batterie;
}
void Auto::afficherInfoAuto()
{
    string result;
    result=ConversionString();
    cout<<result;
}
//fonction qui sert à convertir en châine l'affichage des infos d'un automobile
string Auto::ConversionString()
{
    string result,batt,strPneus;
//objet avec lequel on transforme un entier en châine
    stringstream ss;
    ss<<nbPneus;
    ss>>strPneus;
    batt=batterie->toString();
    result="Cette voiture "+marque+" a "+strPneus+" pneus\navec une "+batt;
    return result;
}
bool Auto::etatVoiture()
{
    return ((batterie->getDureeDeVie())>0,nbPneus>2);
}
void Auto::afficherMenu()
{
    choix.push_back("Tapez\n\t\t");
    choix.push_back("1:voir l'etat de cette voiture\n\t\t");
    choix.push_back("2:voir l'etat de votre batterie\n\t\t");
    choix.push_back("3:charger la batterie de cette voiture\n\t\t");
    for (int i=0,c=choix.size();i<c;i++)
        cout<<choix[i];
}
void Auto::getChoice()
{
    cout<<"votre choix SVP:";
    cin>>choice;
}
void Auto::manageChoice()
{
    switch(choice)
    {
        case 1:
            afficherInfoAuto();
            break;
        case 2:
            batterie->afficherInfo();
            break;
        case 3:
            batterie->chargerBatterie();
            afficherMenu();
            break;
    }
}
void Auto::rouler()
{   
    if(etat)
    {
    while(batterie->getVoltage()>0)
       batterie->diminueVoltage();
    }
    else
        cout<<"La batterie est a seche."<<endl;
}
bool Auto::getEtatVoiture()
{
    return batterie->getVoltage()>0;
}
void Auto::arreter()
{
    
}