//Domeniul ales Mancare  
#include <iostream>
#include <fstream>
using namespace std;
class Restaurant {
private:
	 char* numeRestaurant;
	int numarMese;

	int numarChefi;
	int* varstaChef;
	static int sector;
	const int anInfiintare;

public:
	//constructor fara parametrii
	Restaurant() :anInfiintare()
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
	Restaurant(int numarMese):anInfiintare(2020) {
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
	Restaurant(const char* numeRestaurant, int numarMese, int numarChefi, int* varstaChef):anInfiintare(2020) {
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
	Restaurant(const Restaurant& r) :anInfiintare()
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
		out << "numarul de mese este " << r.numarMese << endl;
		out << "Numarul de chefi este " << r.numarChefi<<endl;
		for (int i = 0; i < r.numarChefi; i++)
			out << "varsta chefului   " << i + 1 << " este :" << r.varstaChef[i] << endl;
	

		return out;
	}
	friend istream& operator>>(istream& in, Restaurant& r) {
		cout << "Nume: ";
		in >> r.numeRestaurant;
		cout << "\nnumarul de mese este ";
		in >> r.numarMese;

		cout << "\n Numarul de chefi este ";
		in >> r.numarChefi;
		for (int i = 0; i < r.numarChefi; i++) {
			cout << "\nvarsta fiecarui chef este  " << i + 1 << ":";
			in >> r.varstaChef[i];
		}
		cout << "\n numarul de mese este ";
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
		if (this->numeRestaurant ) {
			delete[]this->numeRestaurant;
			
		}
		if (this->varstaChef )
		{
			delete[]this->varstaChef;
			
		}
	
	}

	static void setSector(int sectornou) {
		Restaurant::sector = sectornou;
	}


	void afisareRestaurant() {
		cout << "Numele restaurantului este:" << this->numeRestaurant << "\nbnumarul de mese din restaurant este:" << this->numarMese  <<
			"  \n numarul de chefi din restaurant este" << this->numarChefi << "\n vasrta chefului " << endl;
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
	
	void setNrmese(int numarMese) {
		if (numarMese < 20)
			cout << "restaurantul e prea mic" << endl;
		else
			this->numarMese = numarMese;
	}
	void setnrChefi(int numarChefi)
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
		this->nrAngajati =0 ;
		vechimeAngajati = nullptr;
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
		
		this->numeLant = new char[strlen(sm.numeLant) + 1];
		strcpy_s(this->numeLant, strlen(sm.numeLant) + 1, sm.numeLant);
		this->suprafata = sm.suprafata;
		this->nrAngajati = sm.nrAngajati;
		if (this->vechimeAngajati != nullptr)
			delete[]this->vechimeAngajati;
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
	Covrigarie(const char* numeCovrigarie, int nrCovrigi, float pretCovrig, int anDeschidere) :anDeschidere(anDeschidere) {//constructor cu toti parametrii;
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
//HAS A
class Oras {
private:
	int nrClientiFideli;
	Restaurant** p1;
public:
	Oras() {
		this->nrClientiFideli = 0;
		this->p1 = NULL;
	}

	Oras(int nrPersoane,Restaurant** p1) {
		this->nrClientiFideli = nrPersoane;
		this->p1 = new Restaurant * [this->nrClientiFideli];
		for (int i = 0; i < this->nrClientiFideli; i++) {
			this->p1[i] = p1[i];
		}
	}

	~Oras() {
		if (this->p1 != NULL) {
			delete[]this->p1;
		}
	}

	void afisareOras() {
		cout << "Afisare JURIU!!! " << endl;
		cout << "Numarul de Participanti: " << this->nrClientiFideli << endl;
		for (int i = 0; i < this->nrClientiFideli; i++) {
			this->p1[i]->afisareRestaurant();
		}
	}
};

class Cantina :public Restaurant//is a restaurant
{
private :
 int nrPortii;
 int* pretPortie; 

public:
	Cantina():Restaurant()
	{
		this->nrPortii = 0;
		this->pretPortie = nullptr;
	}
	Cantina(char* numeRestaurant, int numarMese, int numarChefi, int* varstaChef,int nrPortii):
		Restaurant(numeRestaurant, numarMese, numarChefi,  varstaChef)
	{
		this->nrPortii = nrPortii;
		this->pretPortie = new int[nrPortii];
			for (int i = 0;i < this->nrPortii;i++)
			{
				this->pretPortie[i] = pretPortie[i];

			}
	}
	~Cantina()
	{
		if (this->pretPortie != nullptr)
		{
			delete[]this->pretPortie;
		}
	}
	Cantina(const Cantina& c):Restaurant(c)
	{
		this->nrPortii = c.nrPortii;
		this->pretPortie = new int[c.nrPortii];
		for (int i = 0;i < c.nrPortii;i++)
		{
			this->pretPortie[i] = c.pretPortie[i];

		}

	}
	 Cantina operator= (const Cantina & c) 
	{
		 Restaurant ::operator=(c);
		 this->nrPortii = c.nrPortii;
		 if (this->pretPortie != nullptr)
			 delete[]pretPortie;
		 this->pretPortie = new int[c.nrPortii];
		 for (int i = 0;i < c.nrPortii;i++)
		 {
			 this->pretPortie[i] = c.pretPortie[i];

		 }

		 
		 return *this;
	}

	 friend ostream& operator<<(ostream& out,const  Cantina c)
	 {
		 //out<<(Restaurant)c;
		 out << "Numarul de portii este: " << c.nrPortii;
		 out << '\n';
		
		 for (int i = 0;i < c.nrPortii;i++)
		 {
			 out << "Prestul portiei :" << i + 1 << "este ";
			 out << c.pretPortie[i];
			 out << endl;
		 }
		 return out;
	 }
};
//crearea claselor virtuale
class RestaurantStrain:public Restaurant {
private:
	string tipRestaurant;
public:
	string getRestaurant() {
		return this->tipRestaurant;
	}

	virtual void calculMediaVarstaParticipanti() = 0;
};
class VechimeRestaurant {
public:
	virtual void maresteVechimeRestaurant() = 0;
	virtual void scadeVechimeRestaurant() = 0;
};

class RestaurantChinezesc :public RestaurantStrain, public VechimeRestaurant {
public:
	virtual void VechimeRestaurant() {
		cout << "Vechimea unui restaurant este " << endl;
	}
};
int main()
{
	//Testarea constructorului fara parametrii
	Restaurant r1;
	//testare constructor cu parametrii
	int* varstaChef = new int[50];
	for (int i = 0;i <= 50;i++)
		varstaChef[i] = i * 20 + 2;
	Restaurant r4("xChef", 34, 6, varstaChef);
	cout << r4;
	//testare getteri si setteri
	
	Restaurant r2("Bontea", 22, 3, varstaChef);
	cout<<r2.getNrmese()<<endl;
	//testare operatori<< si >>
	Restaurant r3;
	cin >>r3 ;
	cout << r3;
	//Testarea constructorului fara parametrii
	Covrigarie c1;
	cout << c1;
	cout << endl;
//testarea constructorului cu parametrii
	Covrigarie c2("Matei", 5, 2, 2010);
	cout << c2;
	//apelare constructor fara parametrii
	superMarket s2;
	cout << s2;
	//apelare constructor cu parametrii
	int vechimeAngajati[2] = { 1,3 };
	superMarket s1("profi", 20, 2020, 2, vechimeAngajati);
	cout << s1;


	int* vechimeAngajatilo = new int[3];
	for (int i = 0;i < 3;i++)
		vechimeAngajati[i] = i + 9;

	superMarket superl("Kaufland", 4, 2020, 3, vechimeAngajati);
	superl.afisareSup();
	int* varstaChefilor = new int[50];
	for (int i = 0;i <= 50;i++)
		varstaChef[i] = i * 20 + 2;
	Restaurant res4("ANA", 34, 6, varstaChef);
	Restaurant r8;
	cin >> r8;
	cout << r8 << endl;

	//r4.setVarsta(varstaChef,8);
	r4.afisareRestaurant();
	Restaurant restaurant2("Bontea", 20, 4, varstaChef);//afisare constructor fara parametrii
	Restaurant res = restaurant2;
	int numarMesenou = restaurant2(20);
	int numarChefi = (int)restaurant2;
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

	Restaurant res3 = ++r2;

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
	//Vectori de tipul claselor
	Restaurant vector[4];
	for (int i = 0;i < 4; i++)
	{
		cin >> vector[i];
	}
	for (int i = 0;i < 4; i++)
	{
		cout << vector[i];
	}
	superMarket vector2[6];
	for (int i = 0;i < 6; i++)
	{
		cin >> vector2[i];
	}
	for (int i = 0;i < 6;i++)
	{
		cout << vector2[i];
	}

	Covrigarie vector3[7];

	for (int i = 0;i < 7; i++)
	{
		cin >> vector3[i];
	}
	for (int i = 0;i < 7;i++)
	{
		cout << vector3[i];
	}
	Restaurant matriceJ[2][2];
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 2;j++) {
			cin >> matriceJ[i][j];
		}
	}

	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 2;j++) {
			cout << matriceJ[i][j];
			if (j == 1)
				cout << "--------";
		}
		cout << endl;
	}

	// Scriere intr-un fisier normal
	ofstream fileWrite;
	fileWrite.open("ALEXANDRA.txt", ios::out);
	fileWrite << "Rlk";
	fileWrite.close();

	//Scriere intr-un fisier binar
	ofstream fileWriteBin;
	fileWriteBin.open("fisier_binar.dat", ios::binary | ios::out);
	fileWriteBin << r4;
	fileWriteBin.close();

	// Citire din fisier normal
	ifstream fileRead;
	fileRead.open("ALEXANDRA.txt", ios::in);
		Restaurant r9;
	fileRead >> r9;
	cout << "Obiect citit din fisier: " << endl << r9;
	fileRead.close();

	// Citire din fisier binar
	ifstream fileReadBin;
	fileReadBin.open("fisier_bin.dat", ios::binary | ios::in);
     Restaurant  p21;
	fileReadBin >> p21;
	cout << "Obiect citit din fisier: " << endl << p21;
	fileReadBin.close();
}
