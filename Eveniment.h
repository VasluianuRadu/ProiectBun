#pragma once

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class Eveniment
{
private:
	char* numeEveniment; // vector de caractere alocat dinamic
	struct dataEveniment
	{
		int zi;
		int luna;
		int an;
	};
	dataEveniment data;
	struct oraEveniment
	{
		int ora;
		int minut;
	};
	oraEveniment o;
	string locatieEveniment;

public:
	Eveniment()//constructorul fara parametrii
	{
		this->numeEveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->numeEveniment, "Necunoscut");
		this->data.zi = 0;
		this->data.luna = 0;
		this->data.an = 0;
		this->o.ora = 0;
		this->o.minut = 0;
		this->locatieEveniment = "Necunoscut";
	}
	Eveniment(const char* numeEveniment, int zi, int luna, int an, int ora, int minut, string locatieEveniment)//costructorul cu toti parametrii
	{
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy(this->numeEveniment, numeEveniment);
		this->data.zi = zi;
		this->data.luna = luna;
		this->data.an = an;
		this->o.ora = ora;
		this->o.minut = minut;
		this->locatieEveniment = locatieEveniment;
	}
	Eveniment(const Eveniment& e) //constructorul de copeiere
	{
		this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
		strcpy(this->numeEveniment, e.numeEveniment);
		this->data.zi = e.data.zi;
		this->data.luna = e.data.luna;
		this->data.an = e.data.an;
		this->o.ora = e.o.ora;
		this->o.minut = e.o.minut;
		this->locatieEveniment = e.locatieEveniment;
	}
	~Eveniment()//destructorul
	{
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
	}
	Eveniment& operator=(const Eveniment& e)//operatorul =
	{
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
		strcpy(this->numeEveniment, e.numeEveniment);
		this->data.zi = e.data.zi;
		this->data.luna = e.data.luna;
		this->data.an = e.data.an;
		this->o.ora = e.o.ora;
		this->o.minut = e.o.minut;
		this->locatieEveniment = e.locatieEveniment;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Eveniment& e)//afisare
	{
		out << "Numele evenimentului: " << e.numeEveniment << endl;
		out << "Data evenimentului: " << e.data.zi << "." << e.data.luna << "." << e.data.an << endl;
		out << "Ora evenimentului: " << e.o.ora << ":" << e.o.minut << endl;
		out << "Locatia evenimentului: " << e.locatieEveniment << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Eveniment& e)//citire
	{
		cout << "Numele evenimentului: ";
		char buffer[500];
		in >> buffer;
		
		if (e.numeEveniment != NULL)
		{
			delete[] e.numeEveniment;
		}
		e.numeEveniment = new char[strlen(buffer) + 1];
		strcpy(e.numeEveniment, buffer);
		cout << "Data evenimentului: " << endl << "zi:";
		in >> e.data.zi;
		if (e.data.zi < 1 || e.data.zi>31)
		{
			cout << "Ziua introdusa nu este corecta, va rog reintroduceti ziua:";
			in >> e.data.zi;
		}
		
		cout << "luna:";
		in >> e.data.luna;
		if (e.data.luna < 1 || e.data.luna>12)
		{
			cout << "Luna introdusa nu este corecta, va rog reintroduceti luna:";
			cin >> e.data.luna;
		}
		
		cout << "an:";
		in >> e.data.an;
		if (e.data.an < 2000 || e.data.an>2050)
		{
			cout << "Anul introdus nu este corect, va rog reintroduceti anul:";
			in >> e.data.an;
		}
		cout << "Ora evenimentului: " << endl << "ora:";
		in >> e.o.ora;
		if (e.o.ora < 0 || e.o.ora>23)
		{
			cout << "Ora introdusa nu este corecta, va rog introduceti ora:";
			cin >> e.o.ora;
		}
		cout << "minut:";
		in >> e.o.minut;
		if (e.o.minut < 0 || e.o.minut>59)
		{
			cout << "Minutul introdusa nu este corecta, va rog introduceti minutul:";
			in >> e.o.minut;

		}
		cout << "Locatie evenimentului:";
		in >> e.locatieEveniment;
		return in;
		cout << endl;
	}

	//set + get
	void setNumeEveniment(char* numeEveniment)
	{
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy(this->numeEveniment, numeEveniment);
	}
	char* getNumeEveniment()
	{
		if (this->numeEveniment != NULL)
		{
			return this->numeEveniment;
		}
		else
		{
			return NULL;
		}
	}
	void setDataEveniment(int zi, int luna, int an)
	{
		if (zi < 1 || zi>31)
		{
			this->data.zi=zi;
		}
		if (luna < 1 || luna>12)
		{
			this->data.luna = luna;
		}
		if (an < 2000 || an>2050)
		{
			this->data.an = an;
		}
		
	}
	void getDataEveniment(int& zi, int& luna, int& an)
	{
		zi = this->data.zi;
		luna = this->data.luna;
		an = this->data.an;
	}
	void setOraEveniment(int ora, int minut)
	{
		if (ora < 0 || ora>23)
		{
			this->o.ora=ora;
		}
		if (minut < 0 || minut>59)
		{
			this->o.minut=minut;
		}
	}
	void getOraEveniment(int& ora, int& minut)
	{
		ora = this->o.ora;
		minut = this->o.minut;
	}
	void setLocatieEveniment(string locatieEveniment)
	{
		if (locatieEveniment.length() > 0)
		{
			this->locatieEveniment = locatieEveniment;
		}		
	}
	string getLocatieEveniment()
	{
		return this->locatieEveniment;
	}
	int verificareData()//metoda generica
	{
		if (this->data.zi < 1 || this->data.zi>31)
		{
			return 0;
		}
		if (this->data.luna < 1 || this->data.luna>12)
		{
			return 0;
		}
		if (this->data.an < 2000 || this->data.an>2050)
		{
			return 0;
		}
	
		return 1;
	}
	int verificareOra()//metoda generica
	{
		if (this->o.ora < 0 || this->o.ora>23)
		{
			return 0;
		}
		if (this->o.minut < 0 || this->o.minut>59)
		{
			return 0;
		}
		return 1;
	}
	bool operator>(Eveniment sursa)//operator >
	{
		if (this->data.an > sursa.data.an)
		{
			return true;
		}
		else if (this->data.an == sursa.data.an)
		{
			if (this->data.luna > sursa.data.luna)
			{
				return true;
			}
			else if (this->data.luna == sursa.data.luna)
			{
				if (this->data.zi > sursa.data.zi)
				{
					return true;
				}
				else if (this->data.zi == sursa.data.zi)
				{
					if (this->o.ora > sursa.o.ora)
					{
						return true;
					}
					else if (this->o.ora == sursa.o.ora)
					{
						if (this->o.minut > sursa.o.minut)
						{
							return true;
						}
					}
				}
			}
		}
		
		return false;
	}
	bool operator!() //operatorul de negatie !
	{
		if (this->data.an < 0) {
			return false;
		}
		else {
			return true;
		}
	}
	
	void afisare()//afisare
	{
		cout << "Numele evenimentului: " << this->numeEveniment << endl;
		cout << "Data evenimentului: " << this->data.zi << "." << this->data.luna << "." << this->data.an << endl;
		cout << "Ora evenimentului: " << this->o.ora << ":" << this->o.minut << endl;
		cout << "Locatia evenimentului: " << this->locatieEveniment << endl;
	}
	void citire()//citire
	{
		cout << "Numele evenimentului: ";
		char buffer[500];
		cin >> buffer;
		if (this->numeEveniment != NULL)
		{
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(buffer) + 1];
		strcpy(this->numeEveniment, buffer);
	
	
	
		cout << "Data evenimentului: "<<endl<<"zi:";
		cin >> this->data.zi;
		if (this->data.zi < 1 || this->data.zi>31)
		{
			cout << "Ziua introdusa nu este corecta, va rog reintroduceti ziua:";
			cin >> this->data.zi;
		}
		
		cout << "luna:";
		cin >> this->data.luna;
		if (this->data.luna < 1 || this->data.luna>12)
		{
			cout << "Luna introdusa nu este corecta, va rog reintroduceti luna:";
			cin >> this->data.luna;
		}
		
		cout << "an:";
		cin >> this->data.an;
		if (this->data.an < 2000 || this->data.an>2050)
		{
			cout << "Anul introdus nu este corect, va rog reintroduceti anul:";
			cin >> this->data.an;
		}
		cout << "Ora evenimentului: " << endl << "ora:";
		cin >> this->o.ora;
		if (this->o.ora < 0 || this->o.ora>23)
		{
			cout << "Ora introdusa nu este corecta, va rog introduceti ora:";
			cin >> this->o.ora;
		}
		cout << "minut:";
		cin >> this->o.minut;
		if (this->o.minut < 0 || this->o.minut>59)
		{
			cout << "Minutul introdusa nu este corecta, va rog introduceti minutul:";
			cin >> this->o.minut;

		}		
		cout << "Locatia evenimentului: ";
		cin >> this->locatieEveniment;
		
	}

};