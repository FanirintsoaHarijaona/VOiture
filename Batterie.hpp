#include <string>
//classe définissant une batterie
class Batterie
{
    private:
        float prix;
        float dureeDeVie;
//chaque batterie possède une charge après sa création
        float voltage;
    public:
        Batterie();
        Batterie(float couts,float duree,float nVoltage);
        ~Batterie();
//définition des accesseurs
        float getPrix() const;
        float getDureeDeVie() const;
        float getVoltage() const;
//la durée de vie d'une voiture diminue peu à peu chaque fois qu'on l'utilise
        void getDureeRestante(float tempsUtilise);
        void diminueVoltage();
        void chargerBatterie();
//mutateurs
        void setPrix(float nPrix);
        void setDureeDeVie(float nDuree);
        std::string toString() const;
        void afficherInfo() const;
};