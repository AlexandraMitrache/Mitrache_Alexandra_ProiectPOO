//Domeniul ales Mancare  
#include <iostream>
using namespace std;
class Restaurant {
private:
	char* numeRestaurant;
	int numarMese;

	int numarChefi;
	int* varstaChef;
	static int sector;
	const int id;

public:
	//constructor fara parametrii
	Restaurant() :id(numarChefi++)
	{

		this->numeRestaurant = new char[strlen("Xchef") + 1];
		strcpy_s(this->numeRestaurant, strlen("Xchef") + 1, "Xchef");
		this->numarMese = 50;
		this->numarChefi = 20;

		this->varstaChef = new int[this->numarChefi];
		for (int i = 0;i < this->numarChefi;i++) {
			this->varstaChef[i] = varstaChef[i];
		}

		cout << "S-a apelat constructorul fara parametrii" << endl;
	}
	//constructor cu un parametru
	Restaurant(int numarMese) :id(numarChefi++) {
		this->numeRestaurant = new char[strlen(numeRestaurant) + 1];
		strcpy_s(this->numeRestaurant, strlen(numeRestaurant) + 1, numeRestaurant);
		this->numarMese = numarMese;
		this->numarChefi = numarChefi;
		this->varstaChef = new int[this->numarChefi];
		for (int i = 0;i < this->numarChefi;i++)
			this->varstaChef[i] = varstaChef[i];

		cout << "S-a apelat constructorul cu un parametru" << endl;

	}
	//constructor cu toti parametrii
	Restaurant(const char* numeRestaurant, int numarMese, int numarChefi, int* varstaChef) :id(numarChefi++) {
		this->numeRestaurant = new char[strlen(numeRestaurant) + 1];
		strcpy_s(this->numeRestaurant, strlen(numeRestaurant) + 1, numeRestaurant);
		this->numarMese = numarMese;

		this->numarChefi = numarChefi;
		this->varstaChef = new int[this->numarChefi];
		for (int i = 0;i < numarChefi;i++) {
			this->varstaChef[i] = varstaChef[i];
		}
		cout << "S-a apelat constructorul cu un parametru" << endl;


	}
	Restaurant(const Restaurant& r) :id(id)
	{
		this->numeRestaurant = new char(strlen(r.numeRestaurant) + 1);
		strcpy_s(this->numeRestaurant, strlen(r.numeRestaurant) + 1, r.numeRestaurant);
		this->numarMese = r.numarMese;
		this->numarChefi = r.numarChefi;
		this->varstaChef = new int[r.numarChefi];
		for (int i = 0;i < this->numarChefi;i++)
			this->varstaChef[i] = r.varstaChef[i];

	}
	Restaurant& operator =(const Restaurant& r) {//operator egal
		if (this->numeRestaurant != NULL)
			delete[]this->numeRestaurant;
		this->numeRestaurant = NULL;
		this->numeRestaurant = new char(strlen(r.numeRestaurant) + 1);
		strcpy_s(this->numeRestaurant, strlen(r.numeRestaurant) + 1, r.numeRestaurant);
		this->numarMese = r.numarMese;
		this->numarChefi = r.numarChefi;
		this->varstaChef = new int[r.numarChefi];
		for (int i = 0;i < this->numarChefi;i++)
			this->varstaChef[i] = r.varstaChef[i];
		return *this;


	}
	friend ostream& operator<<(ostream& out, Restaurant& r) {
		out << "Nume: " << r.numeRestaurant << endl;
		out << "Numarul de chefi este " << r.numarChefi;
		for (int i = 0; i < r.numarChefi; i++)
			out << "varsta fiecarui chef este  " << i + 1 << ":" << r.varstaChef[i] << endl;
		out << "numarul de mese este " << r.numarMese << endl;

		return out;
	}
	friend istream& operator>>(istream& in, Restaurant& r) {
		cout << "Nume: ";
		in >> r.numeRestaurant;
		cout << "Numarul de chefi este ";
		in >> r.numarChefi;
		for (int i = 0; i < r.numarChefi; i++) {
			cout << "varsta fiecarui chef este  " << i + 1 << ":";
			in >> r.varstaChef[i];
		}
		cout << "numarul de mese este ";
		in >> r.numarMese;

		return in;
	}
	bool operator!()
	{
		return numarMese > 0;
	}
	Restaurant& operator++()
	{
		this->numarMese++;
		return *this;
	}
	Restaurant operator++(int i)
	{
		Restaurant  copie = *this;
		this->numarMese++;
		return copie;
	}
	int& operator[](int index)
	{
		if (index > 0 && index < numarChefi)
		{
			return varstaChef[index];
		}
		
	}
	explicit operator int()
	{
		return numarMese;
	}
	int operator()(int mese)
	{
		return numarMese + mese;
	}
	//destructor 
	~Restaurant() {
		if (this->numeRestaurant != NULL) {
			delete[]this->numeRestaurant;
			this->numeRestaurant = NULL;
		}
		if (this->varstaChef != NULL)
		{
			delete[]this->varstaChef;
			this->varstaChef = NULL;
		}
		cout << "S-a apelat destructor " << endl;
	}

	static void setSector(int sectornou) {
		Restaurant::sector = sectornou;
	}


	void afisareRestaurant() {
		cout << "Numele restaurantului este:" << this->numeRestaurant << "\nnumarul de mese din restaurant este:" << this->numarMese << "\nidiul este" << id <<
			"  numarul de chefi din restaurant este" << this->numarChefi << "\nvasrta chefului " << endl;
		for (int i = 0;i < this->numarChefi;i++)
		{
			cout << this->varstaChef[i] << ", ";
		}
		cout << endl;
	}
	Restaurant initializareRestaurant() {
		Restaurant restaurant;
		restaurant.numeRestaurant = new char[strlen("Xchef") + 1];
		strcpy_s(this->numeRestaurant, strlen("Xchef") + 1, "Xchef");
		restaurant.numarMese = 8;
		restaurant.numarChefi = 4;
		restaurant.varstaChef = new int[this->numarChefi];
		for (int i = 0;i < this->numarChefi - 1;i++)
			*restaurant.varstaChef = varstaChef[i];
		return restaurant;

	}
	bool validareNumar(const char* r) {
		for (int i = 0; i < strlen(r); i++)
			if (isdigit(r[i]) == false)
				return false;
			else return true;
	}
	//setter 
	void NumeRestaurant(const char* numenou) {
		while (validareNumar(numenou)) {
			cout << "Vezi  ca ai introdus cifre!" << endl;
			cin >> numeRestaurant;
		}
		this->numeRestaurant = new char[strlen(numenou) + 1];
		strcpy_s(this->numeRestaurant, strlen(numenou) + 1, numenou);


	} 
	
	void Nrmese(int numarMese) {
		if (numarMese < 20)
			cout << "restaurantul e prea mic" << endl;
		else
			this->numarMese = numarMese;
	}
	void nrChefi(int numarChefi)
	{
		if (numarChefi != 0)
			this->numarChefi = numarChefi;
		else
			cout << "nu are cine  sa gateasca";
	}
	void setVarsta(int* varstaChef, int numarChefi) {
		this->numarChefi = numarChefi;
		if (this->varstaChef != NULL)
			delete[]this->varstaChef;
		this->varstaChef = new int[numarChefi];
		for (int i = 0; i < numarChefi; i++)
			this->varstaChef[i] = varstaChef[i];
	}
	char* getNume()
	{
		return numeRestaurant;
	}
	int getNrmese()
	{
		return this->numarMese;
	}
	int getNumarChefi()
	{
		return this->numarChefi;
	}
	int* getVarstaChef()
	{
		return this->varstaChef;
	}
}; int Restaurant::sector = 6;
class superMarket {
private:
	const int anInfintare;
	static float TVA;
	char* numeLant;
	float suprafata;
	int nrAngajati;
	int* vechimeAngajati;
public:
	superMarket() :anInfintare(2020) {//constructor fara parametrii
		this->numeLant = new char[strlen("Lidl") + 1];
		strcpy_s(this->numeLant, strlen("Lidl") + 1, "Lidl");
		this->suprafata = 120;
		this->nrAngajati = 20;
		this->vechimeAngajati = new int[this->nrAngajati];
		for (int i = 0;i < nrAngajati;i++)
		{
			this->vechimeAngajati[i] = vechimeAngajati[i];
		}
	}
	superMarket(float suprafata, int anInfintare) :anInfintare(anInfintare)
	{
		this->numeLant = new char[strlen(numeLant) + 1];
		strcpy_s(this->numeLant, strlen(numeLant) + 1, numeLant);
		this->suprafata = suprafata;
		this->nrAngajati = nrAngajati;
		this->vechimeAngajati = new int[this->nrAngajati];

		for (int i = 0;i < nrAngajati;i++)
		{
			this->vechimeAngajati[i] = vechimeAngajati[i];
		}
	}
	superMarket(const char* numeLant, float suprafata, int AnInfintare, int nrAngajati, int* vechimeAngajati) :anInfintare(AnInfintare) {
		this->numeLant = new char[strlen(numeLant) + 1];
		strcpy_s(this->numeLant, strlen(numeLant) + 1, numeLant);
		this->suprafata = suprafata;
		this->nrAngajati = nrAngajati;
		this->vechimeAngajati = new int[this->nrAngajati];

		for (int i = 0;i < nrAngajati;i++)
		{
			this->vechimeAngajati[i] = vechimeAngajati[i];
		}
	}
	void afisareSup()
	{
		cout << "Numele lantului" << this->numeLant << "\nsuprafata" << this->suprafata << "\naninfiintare" << this->anInfintare << "\n numar angajati " << this->nrAngajati << "\n vechimea angajatilor";
		for (int i = 0;i < nrAngajati - 1;i++)
		{
			cout << this->vechimeAngajati[i] << " ,";
		}
		cout << vechimeAngajati[this->nrAngajati - 1];
	}
	superMarket(const superMarket& sm) :anInfintare(anInfintare) {
		this->numeLant = new char[strlen(sm.numeLant) + 1];
		strcpy_s(this->numeLant, strlen(sm.numeLant) + 1, sm.numeLant);
		this->suprafata = sm.suprafata;
		this->nrAngajati = sm.nrAngajati;
		this->vechimeAngajati = new int[sm.nrAngajati];
		for (int i = 0;i < sm.nrAngajati;i++)
		{
			this->vechimeAngajati[i] = vechimeAngajati[i];
		}
	}
	superMarket& operator=(const superMarket& sm) {
		if (this->numeLant != NULL)
			delete[]this->numeLant;
		this->numeLant = NULL;
		this->numeLant = new char[strlen(sm.numeLant) + 1];
		strcpy_s(this->numeLant, strlen(sm.numeLant) + 1, sm.numeLant);
		this->suprafata = sm.suprafata;
		this->nrAngajati = sm.nrAngajati;
		this->vechimeAngajati = new int[sm.nrAngajati];
		for (int i = 0;i < sm.nrAngajati;i++)
		{
			this->vechimeAngajati[i] = vechimeAngajati[i];
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, superMarket& s) {
		out << "Nume: " << s.numeLant << endl;
		out << "Numarul de angajati este " << s.nrAngajati;
		for (int i = 0; i < s.nrAngajati; i++)
			out << "vechimea fiecarui angajat " << i + 1 << ":" << s.vechimeAngajati[i] << endl;
		out << "suprafata" << s.suprafata << endl;

		return out;
	}
	friend istream& operator>>(istream& in, superMarket& s) {
		cout << "Nume: ";
		in >> s.numeLant;
		cout << "Numarul de angajati este ";
		in >> s.nrAngajati;
		for (int i = 0; i < s.nrAngajati; i++) {
			cout << "vechimea fiecarui angajat " << i + 1 << ":";
			in >> s.vechimeAngajati[i];
		}
		cout << "suprafata";
		in >> s.suprafata;

		return in;
	}
	int operator()(int angajatNou)
	{
		return nrAngajati + angajatNou;

	}
	superMarket operator++()
	{
		this->nrAngajati++;
		return *this;
	}
	operator int()
	{
		return suprafata;
	}
	static void setTva(int tvaNou)
	{
	superMarket:TVA = tvaNou;
	}
	
	~superMarket() {
		if (*numeLant != NULL)
			delete[]numeLant;
		numeLant = NULL;
	}
	void Nrangajati() {
		if (nrAngajati == 0)
			cout << "NU esista angajati da mai multi bani" << endl;
		else
			cout << nrAngajati;
	}
	void setVarsta(int* vechimeAngajati, int nrAngajati) {
		this->nrAngajati = nrAngajati;
		if (this->vechimeAngajati != NULL)
			delete[]this->vechimeAngajati;
		this->vechimeAngajati = new int[nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
			this->vechimeAngajati[i] = vechimeAngajati[i];
	}
	char* getnumeLant()
	{
		return this->numeLant;
	}
	float getsuprafata() {
		return this->suprafata;
	}
	float getnrAng()
	{
		return this->nrAngajati;
	}
	int* getvechimeAngajati() {
		return this->vechimeAngajati;
	}
	friend superMarket operator++(superMarket& t, int i);
};float superMarket::TVA = 0.20;
superMarket operator++(superMarket& s, int i)//operator posincrementare  functie globala
{
	superMarket copie = s;
	s.nrAngajati++;
	return copie;

}
class Covrigarie {
private:
	int nrCovrigi;


	float pretCovrig;
	static char aluat;
	char* numeCovrigarie;
	const int anDeschidere;
public:
	Covrigarie() :anDeschidere(1998) {//constructor fara parametrii

		this->numeCovrigarie = new char[strlen("Luca") + 1];
		strcpy_s(this->numeCovrigarie, strlen("Luca") + 1, "Luca");
		this->nrCovrigi = 20;
		this->pretCovrig = 2;


	}
	Covrigarie(char* numeCovrigarie, int nrCovrigi, float pretCovrig, int anDeschidere) :anDeschidere(anDeschidere) {//constructor cu toti parametrii;
		this->numeCovrigarie = new char[strlen(numeCovrigarie) + 1];
		strcpy_s(this->numeCovrigarie, strlen(numeCovrigarie) + 1, numeCovrigarie);
		this->nrCovrigi = nrCovrigi;
		this->pretCovrig = pretCovrig;


	}
	Covrigarie(int nrCovrigi) :anDeschidere(anDeschidere) {

		this->numeCovrigarie = new char[strlen("nume") + 1];
		strcpy_s(this->numeCovrigarie, strlen("nume") + 1, "nume");
		this->nrCovrigi = nrCovrigi;
		this->pretCovrig = pretCovrig;



	}
	static void setAluat(char aluatNou) {
	Covrigarie:aluat = aluatNou;
	}
	void afisare() {
		cout << "Numele covrigarieie este" << this->numeCovrigarie <<
			"\n numarul de covrigi este " << this->nrCovrigi << "\npretul unui covrig " << this->pretCovrig << "\n anul infintarii este " << this->anDeschidere << endl;


	}
	Covrigarie(const Covrigarie& co) :anDeschidere(anDeschidere) {
		this->numeCovrigarie = new char[strlen(co.numeCovrigarie) + 1];
		strcpy_s(this->numeCovrigarie, strlen(co.numeCovrigarie) + 1, co.numeCovrigarie);
		this->nrCovrigi = co.nrCovrigi;
		this->pretCovrig = co.pretCovrig;




	}
	Covrigarie operator&=(const Covrigarie& co) {

		this->nrCovrigi = co.nrCovrigi;
		this->pretCovrig = co.pretCovrig;


		this->numeCovrigarie = new char[strlen(co.numeCovrigarie) + 1];
		strcpy_s(this->numeCovrigarie, strlen(co.numeCovrigarie) + 1, co.numeCovrigarie);
		return *this;

	}
	friend ostream& operator<<(ostream& out, Covrigarie& c) {
		out << "Numarul covrigilor este " << c.nrCovrigi << endl;

		out << "Numele " << c.numeCovrigarie << endl;
		out << "Pretul unui covrig este: " << c.pretCovrig << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Covrigarie& c) {
		cout << "Numarul covrigilor:";
		in >> c.nrCovrigi;


		cout << "numele este:";
		in >> c.numeCovrigarie;
		cout << "\npretul unui covrig este:";
		in >> c.pretCovrig;
		return in;
	}
	Covrigarie operator++()
	{
		this->nrCovrigi++;
		return *this;
	}
	~Covrigarie() {
		if (*numeCovrigarie != NULL)
			delete[]numeCovrigarie;
		numeCovrigarie = NULL;
	}
	int getNrcovrigi() {
		return this->nrCovrigi;
	}
	float getpretCovrig() {
		return this->pretCovrig;

	}

	char* getnumeCovrigarie()
	{
		return this->numeCovrigarie;
	}
	friend Covrigarie operator+(int, Covrigarie);
	Covrigarie operator+(int x)
	{
		Covrigarie copie = pretCovrig;
		copie.pretCovrig = pretCovrig + x;
		return copie;
	}
};

Covrigarie operator+(int x, Covrigarie co)
{
	co.pretCovrig += x;
	return co;
}
class TakeAway {
private:
	Restaurant r;
	int *numarComenzi;
	int numarAccesari;
	string nume;
public:
	TakeAway()
	{
		
		
		this->r.getNume();
		this->r.getNumarChefi();
		this ->numarAccesari = this->numarAccesari;
		this->numarComenzi = new int[this->numarAccesari];
		for (int i = 0;i < this->numarAccesari;i++)
		{
			this->numarComenzi = numarComenzi;
		}
		this->nume = "Glovo";
	}
	~TakeAway() {

	}
	int getnumarAccesari()
	{
		return this->numarAccesari;
	}
	int* getNumarComenzi()
	{
		return this->numarComenzi;

	}
	string getNume()
	{
		return this->nume;
	}
	void setNume(string numeNou)
	{
		this->nume = numeNou;
	}
	void setNumarAccesari(int numarNou)
	{
		this->numarAccesari = numarNou;
	}

	

	
};
int main()
{
	
	int* vechimeAngajati = new int[3];
	for (int i = 0;i < 3;i++)
		vechimeAngajati[i] = i + 9;
	
	superMarket superl("Kaufland", 4, 2020, 3, vechimeAngajati);
	superl.afisareSup();
	int* varstaChef = new int[50];
	for (int i = 0;i <= 50;i++)
		varstaChef[i] = i * 20 + 2;
	Restaurant r4("ANA", 34,  6, varstaChef);
	Restaurant r8;
	cin >> r8;
	cout << r8 << endl;

	//r4.setVarsta(varstaChef,8);
	r4.afisareRestaurant();
	Restaurant restaurant2("Bontea", 20,  4, varstaChef);//afisare constructor fara parametrii
	Restaurant r2 = restaurant2;
	int numarMesenou = restaurant2(20);
	int numarChefi = (int) restaurant2;
	int valoare = r2[2];
	r2[2] = 8;
	r2.afisareRestaurant();
	if (!restaurant2)
	{
		cout << "are mese" << endl;
	}
	else
	{
		cout << "nu are mese" << endl;
	}

	Restaurant r3 = ++r2;

	r3.afisareRestaurant();
	r2.afisareRestaurant();

	Restaurant t4 = r2++;
	t4.afisareRestaurant();
	r2.afisareRestaurant();
	Covrigarie covrigarie2;

	Covrigarie covrigarie4(3);
	covrigarie4.afisare();
	covrigarie2.afisare();
	Covrigarie covrigarie3;
	covrigarie3.afisare();
	covrigarie3.operator+(3);
	Restaurant::setSector(3);
	restaurant2.afisareRestaurant();


}
