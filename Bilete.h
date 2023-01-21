#pragma once
#include"LocatieBilete.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class Bilete
{
private:
	const int idBilet; //camp constant
	static int contorBilet;//camp static
	int Categorii;
	int nrRanduri;
	int nrlocuri;


public:
	Bilete() :idBilet(contorBilet++)//constructorul fara parametrii
	{
		this->Categorii = 0;
		this->nrRanduri = 0;
		this->nrlocuri = 0;
	}
	Bilete(int Categorii, int nrRanduri, int nrlocuri) :idBilet(contorBilet++)//costructorul cu toti parametrii
	{
		this->Categorii = Categorii;
		this->nrRanduri = nrRanduri;
		this->nrlocuri = nrlocuri;
	}
	Bilete(const Bilete& b) :idBilet(contorBilet++)//constructorul de copiere
	{
		this->Categorii = b.Categorii;
		this->nrRanduri = b.nrRanduri;
		this->nrlocuri = b.nrlocuri;
	}
	Bilete operator=(const Bilete& b)//operatorul =
	{
		this->Categorii = b.Categorii;
		this->nrRanduri = b.nrRanduri;
		this->nrlocuri = b.nrlocuri;
		return *this;
	}
	//setteri si getteri
	void setCategorii(int Categorii)
	{
		if (Categorii > 0)
		{
			this->Categorii = Categorii;
		}
		
		
	}
	void setNrRanduri(int nrRanduri)
	{
		if (nrRanduri > 0) 
		{
			this->nrRanduri = nrRanduri;
		}
		
	}
	void setNrLocuri(int nrlocuri)
	{
		if (nrlocuri > 0) 
		{
			this->nrlocuri = nrlocuri;
		}
		
	}
	int getCategorii()
	{
		return this->Categorii;
	}
	int getNrRanduri()
	{
		return this->nrRanduri;
	}
	int getNrLocuri()
	{
		return this->nrlocuri;
	}
	
	void citire()
	{
		cout << "Categorie: ";
		cin >> this->Categorii;
		cout << "Rand: ";
		cin >> this->nrRanduri;
		cout << "Loc";
		cin >> this->nrlocuri;
	}
	void Afisare()
	{
		cout << "Categorie: " << this->Categorii << endl;
		cout << "Rand:" << this->nrRanduri << endl;
		cout << "Loc: " << this->nrlocuri << endl;
	}
	friend ostream& operator<<(ostream& out, Bilete& b)
	{
		out << "Categorie: " << b.Categorii << endl;
		out << "Rand:" << b.nrRanduri << endl;
		out << "Loc: " << b.nrlocuri << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Bilete& b)
	{
		cout << "Categorie: ";
		in >> b.Categorii;
		cout << "Rand: ";
		in >> b.nrRanduri;
		cout << "Loc: ";
		in >> b.nrlocuri;
		return in;
	}
	int getIdBilet()
	{
		return this->idBilet;
	}
	static int getContorBilet()
	{
		return contorBilet;
	}
	int verificareBilet() //metoda generica
	{
		if(Categorii<0||Categorii>10)
		{
			return 0;
		}
		if (nrRanduri < 0 || nrRanduri>50)
		{
			return 0;
		}
		if (nrlocuri < 0 || nrlocuri>100)
		{
			return 0;
		}
		return 1;
	}
	void schimbareBilet(int Categorii, int nrRanduri, int nrlocuri)//metoda generica
	{
		this->Categorii = Categorii;
		this->nrRanduri = nrRanduri;
		this->nrlocuri = nrlocuri;
	}
	Bilete operator++() //operatorul ++ pre 
	{
		this->Categorii++;
		this->nrRanduri++;
		this->nrlocuri++;
		return *this;
	}
	Bilete operator++(int)//operatorul ++ post
	{
		Bilete copie = *this;
		this->Categorii++;
		this->nrRanduri++;
		this->nrlocuri++;
		return copie;
	}
	Bilete operator+(int NrLoc)//operatorul +
	{
		Bilete copie = *this;
		copie.nrlocuri += NrLoc;
		return copie;
	}

	
};
int Bilete::contorBilet = 0;
