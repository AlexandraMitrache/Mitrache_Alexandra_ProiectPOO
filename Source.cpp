#include <iostream>
using namespace std;

class Magazin {
public:
    string nume;
    int nrmagazine;
    static float TVA;
    const int anInfintare;
    char* adresa;

    void afisare() {
        cout << "Numele magazinului este: " << this->nume << "\nnumarul de magazine este: " << this->nrmagazine << "\nadresa magazinului este: " << this->adresa;
        cout << "\nanul infintarii magazinului este: " << this->anInfintare << endl;
    }

    Magazin() : anInfintare(2022) {
        this->nume = "La2Pasi";
        this->nrmagazine = 4;
        adresa = new char[strlen("Aleea Pascani") + 1];
        strcpy_s(this->adresa, strlen("Aleea Pascani") + 1, "Aleea Pascani");
    }

    Magazin(string nume, const int an, int nrmagazine, char* adresa) : anInfintare(an) {
        this->nume = nume;
        this->nrmagazine = nrmagazine;
        this->adresa = new char[strlen(adresa) + 1];
        strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
    }
    Magazin(string nume,  char* adresa) :anInfintare()
    {this->nume = nume;
        this->nrmagazine = nrmagazine;
        this->adresa = new char[strlen(adresa) + 1];
        strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
    }
    Magazin(string nume, const int an) : anInfintare(an) {
        this->nume = nume;
        this->nrmagazine = nrmagazine;
        this->adresa = new char[strlen(adresa) + 1];
        strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
    }
   
    ~Magazin() {
        if (this->adresa != NULL) {
            delete[] this->adresa;
        }
    }

    static void setTVA(float TVAnou) {
        TVA = TVAnou;
    }

    Magazin initializareMagazin() {
        Magazin magazin;
        magazin.nume = "Lidl";
        magazin.adresa = new char[strlen("AleeaPascani") + 1];
        strcpy_s(magazin.adresa, strlen("AleeaPascani") + 1, "Aleea Pascani");
        return magazin;
    }
};

float Magazin::TVA = 0.19;

class Acadea {
public:
   
   int nrAcadele;
   string culoareAmbalaj;
    const int  nrBat;
    static float codDeBare;


    char* aroma;
    Acadea() : nrBat(1) {
        this->nrAcadele = 5;
        this->culoareAmbalaj = 'rosu';
        aroma = new char [strlen("Capsuni") + 1];
        strcpy_s(this->aroma, strlen("Capsuni") + 1, "Capsuni");
    }
    void afisareAcadea() {
        cout << "\nNumarul de bete " << this->nrBat << "\ncodul de bare este " << this->codDeBare<<"\nNumarul de acadele din magazin este "<<this->nrAcadele<<"\nculoareambalaj "<<this->culoareAmbalaj;
    }
    Acadea(int nrAcadele,char *aroma,string culoareAmbalaj) : nrBat(1) {
        this->nrAcadele= nrAcadele;
        this->culoareAmbalaj = culoareAmbalaj;
        this->aroma = new char[strlen(aroma) + 1];
        strcpy_s(this->aroma, strlen(aroma) + 1, aroma);
    }
    Acadea(int nrAcadele, string culoareAmbalaj) : nrBat(1) {
        this->nrAcadele = nrAcadele;
        this->culoareAmbalaj = culoareAmbalaj;
        this->aroma = new char[strlen(aroma) + 1];
        strcpy_s(this->aroma, strlen(aroma) + 1, aroma);
    }
    Acadea(int nrAcadele, char* aroma) : nrBat(1) {
        this->nrAcadele = nrAcadele;
        this->culoareAmbalaj = culoareAmbalaj;
        this->aroma = new char[strlen(aroma) + 1];
        strcpy_s(this->aroma, strlen(aroma) + 1, aroma);
    }
    ~Acadea() {
        if (this->aroma != NULL) {
            delete[] this->aroma;
        }
    }
    static void schimbareCodBare(float  codNou) {
        codDeBare = codNou;
    }
    

    
};
float Acadea::codDeBare = 1345678;
class Croissant {
public:
    
    int nrcorn;
    string aromaCorn;
    const int  nrambalaj;
    static float calorii;
    char* marca;
    Croissant() : nrambalaj(1) {
        this->nrcorn = 5;
        this->aromaCorn = "cioco";
        marca = new char[strlen("7days") + 1];
        strcpy_s(this->marca, strlen("7days") + 1, "7days");
    }
    void afisareCorn() {
        cout << "aroma corn"<<this->aromaCorn<<"\nNumarul de ambalaj " << this->nrambalaj << "\nnumarul de cornuri " << this->nrcorn <<"\nmarca"<<this->marca;
    }
    Croissant(int nrcorn, char* marca, string aromaCorn) : nrambalaj(1) {
        this->nrcorn = nrcorn;
        this->aromaCorn = aromaCorn;
        this->marca = new char[strlen(marca) + 1];
        strcpy_s(this->marca, strlen(marca) + 1, marca);
    }
    Croissant(int nrcorn, string aroma) : nrambalaj(1) {
        this->nrcorn = nrcorn;
        this->aromaCorn = aromaCorn;
       
    }
   
    ~Croissant() {
        if (this->marca != NULL) {
            delete[] this->marca;
        }
    }
    static void caloriiSchimbare(float  altecalorii) {
        calorii = altecalorii + 40;
       
    }
    Croissant initializareCroissant() {
        Croissant croissant1;
            croissant1.nrcorn= 5;
            croissant1.aromaCorn = "cioco";
            croissant1.marca = new char[strlen("7days") + 1];
            strcpy_s(croissant1.marca, strlen("7days") + 1, "7days");
            return croissant1;
    }
};float Croissant:: calorii=320;

int main() {
    Magazin magazin1;
    Acadea acadea1;
    Croissant croissant2;
    char aroma1[]="Vanilie";

    char aroma2[] = "Ciocolata";
    char adresa1[] = "Aleea Pascani";
    char adresa2[] = "Ghencea";
    char marca2[] = "Boromir";
    magazin1.afisare();
    {
        Magazin magazin3("Kaufland", 2000, 3, adresa1);
        magazin3.afisare();
    }
    {
        Magazin magazin2("Lidl",  adresa2);
        magazin2.afisare();
    }
    {
        Acadea acadea1(6, aroma2, "galben");
        acadea1.afisareAcadea();
    }
    {
        Croissant croissant2(3,marca2);
        croissant2.afisareCorn();

    }
    Magazin::setTVA(21);
    Acadea::schimbareCodBare(123);
    Acadea* pacadea = new Acadea();
    delete pacadea;
    Magazin* pmagazin = new Magazin();
    delete pmagazin;
    return 0;
}