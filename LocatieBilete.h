#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class LocatieBilete
{
private:
	int NrCategorii; 
	int* Categorii; //vector numeric alocat dinamic
	int* nrRanduri;
	int* nrlocuri;
	int* pret;
	int* nrLocuriCategorie;
	
public:
	LocatieBilete() //constructorul fara parametrii
	{
		this->NrCategorii = 0;
		this->Categorii = NULL;
		this->nrRanduri = NULL;
		this->nrlocuri = NULL;
		this->pret = NULL;
		this->nrLocuriCategorie = NULL;
	}
	LocatieBilete(int nrCategorii, int* categorii, int* nrRanduri, int* nrlocuri, int* pret, int*nrLocuriCategorie)//costructorul cu toti parametrii
	{
	
		this->NrCategorii = nrCategorii;
		this->Categorii = new int[nrCategorii];
		this->nrRanduri = new int[nrCategorii];
		this->nrlocuri = new int[nrCategorii];
		this->pret = new int[nrCategorii];
		this->nrLocuriCategorie = new int[nrCategorii];
		for (int i = 0; i < nrCategorii; i++)
		{
			this->Categorii[i] = categorii[i];
			this->nrRanduri[i] = nrRanduri[i];
			this->nrlocuri[i] = nrlocuri[i];
			this->pret[i] = pret[i];
			this->nrLocuriCategorie[i] = this->nrRanduri[i] * this->nrlocuri[i];
		}
		
	
	}
	LocatieBilete(const LocatieBilete& l) //constructorul de copeiere
	{
		this->NrCategorii = l.NrCategorii;
		this->Categorii = new int[l.NrCategorii];
		this->nrRanduri = new int[l.NrCategorii];
		this->nrlocuri = new int[l.NrCategorii];
		this->pret = new int[l.NrCategorii];
		this->nrLocuriCategorie = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->Categorii[i] = l.Categorii[i];
			this->nrRanduri[i] = l.nrRanduri[i];
			this->nrlocuri[i] = l.nrlocuri[i];
			this->pret[i] = l.pret[i];
			this->nrLocuriCategorie[i] = l.nrLocuriCategorie[i];
		}
		
	}
	~LocatieBilete() //destructorul, dezaloca memoria alocata dinamic
	{
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
		if (this->nrLocuriCategorie != NULL)
		{
			delete[] this->nrLocuriCategorie;
		}
		
	}
	LocatieBilete& operator=(const LocatieBilete& l) //operatorul =
	{
		this->NrCategorii = l.NrCategorii;
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		this->Categorii = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->Categorii[i] = l.Categorii[i];
		}
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		this->nrRanduri = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->nrRanduri[i] = l.nrRanduri[i];
		}
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		this->nrlocuri = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->nrlocuri[i] = l.nrlocuri[i];
		}
		this->pret = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->pret[i] = l.pret[i];
		}
		if (this->nrLocuriCategorie != NULL)
		{
			delete[] this->nrLocuriCategorie;
		}
		this->nrLocuriCategorie = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->nrLocuriCategorie[i] = l.nrLocuriCategorie[i];
		}
		return *this; //*this si LocatieBilete& ajuta la apelul in cascada
	}
	friend ostream& operator<<(ostream& out, const LocatieBilete& l)//afisare
	{
		cout << "Numarul de categorii este: " << l.NrCategorii << endl;
		for (int i = 0; i < l.NrCategorii; i++)
		{
			cout  << "Categoria" << " " << i + 1 << " se numeste ";
			cout << l.Categorii[i] << endl;
			cout <<"Numarul de randuri este : ";
			cout << l.nrRanduri[i] << endl;
			cout << "Numarul de locuri pe rand este: ";
			cout <<l.nrlocuri[i] << endl;
			cout << "Pretul per bilet este: " ;
			cout <<l. pret[i]<<endl;
			cout << "Numarul de locuri totale/categorie este ";
			l.nrLocuriCategorie[i] =l. nrRanduri[i] * l.nrlocuri[i];
			cout <<l. nrLocuriCategorie[i]<<endl<<endl;
			
		}
		cout << endl;
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, LocatieBilete& l)//citire
	{
		cout << "Numarul de categorii este: ";
		in >> l.NrCategorii;
		if (l.Categorii != NULL)
		{
			delete[] l.Categorii;
		}
		l.Categorii = new int[l.NrCategorii];
		cout << "Categoriile sunt: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.Categorii[i];
		}
		if (l.nrRanduri != NULL)
		{
			delete[] l.nrRanduri;
		}
		l.nrRanduri = new int[l.NrCategorii];
		cout << "Numarul de randuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.nrRanduri[i];
		}
		if (l.nrlocuri != NULL)
		{
			delete[] l.nrlocuri;
		}
		l.nrlocuri = new int[l.NrCategorii];
		cout << "Numarul de locuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.nrlocuri[i];
		}
		l.pret = new int[l.NrCategorii];
		cout << "Pretul este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.pret[i];
		}
		if (l.nrLocuriCategorie != NULL)
		{
			delete[] l.nrLocuriCategorie;
		}
		l.nrLocuriCategorie = new int[l.NrCategorii];
		cout << "Numarul de locuri totale pe categorie este: ";
		cout << endl;
	}
	// getteri+ setteri
	int getNrCategorii()
	{
		return this->NrCategorii;
	}
	int* getCategorii()
	{
		return this->Categorii;
	}
	int* getNrRanduri()
	{
		return this->nrRanduri;
	}
	int* getNrLocuri()
	{
		return this->nrlocuri;
	}
	int* getPret()
	{
		return this->pret;
	}
	int* getNrLocuriCategorie()
	{
		for (int i = 0; i < NrCategorii; i++)
		{
			this->nrLocuriCategorie[i] = this->nrRanduri[i] * this->nrlocuri[i];
		};
	}
	void setNrCategorii(int nrCategorii)
	{
		if (nrCategorii > 0) 
		{
			this->NrCategorii = nrCategorii;
		}
		
	}
	void setCategorii(int* categorii)
	{
		if (categorii != NULL)
		{
			if (this->Categorii != NULL)
			{
				delete[] this->Categorii;
			}
			this->Categorii = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->Categorii[i] = categorii[i];
			}
		}
	}
	void setNrRanduri(int* nrRanduri)
	{
		if (nrRanduri != NULL)
		{
			if (this->nrRanduri != NULL)
			{
				delete[] this->nrRanduri;
			}
			this->nrRanduri = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->nrRanduri[i] = nrRanduri[i];
			}
		}
	}
	void setNrLocuri(int* nrLocuri)
	{
		if (nrLocuri != NULL)
		{
			if (this->nrlocuri != NULL)
			{
				delete[] this->nrlocuri;
			}
			this->nrlocuri = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->nrlocuri[i] = nrLocuri[i];
			}
		}
	}
	void setPret(int* pret)
	{
		if (pret != NULL)
		{
			if (this->pret != NULL)
			{
				delete[] this->pret;
			}
			this->pret = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->pret[i] = pret[i];
			}
		}
	}
	void setNrLocuriCategorie(int* nrLocuriCategorie)
	{
		if (nrLocuriCategorie != NULL)
		{
			if (this->nrLocuriCategorie != NULL)
			{
				delete[] this->nrLocuriCategorie;
			}
			this->nrLocuriCategorie = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->nrLocuriCategorie[i] = nrLocuriCategorie[i];
			}
		}
	}
	

	void citire() //citire
	{
		cout << "Numarul de categorii este: ";
		cin >> this->NrCategorii;
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		this->Categorii = new int[this->NrCategorii];
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		this->nrRanduri = new int[this->NrCategorii];
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		this->nrlocuri = new int[this->NrCategorii];
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
		this->pret = new int[this->NrCategorii];
		if (this->nrLocuriCategorie != NULL)
		{
			delete[] this->nrLocuriCategorie;
		}
		this->nrLocuriCategorie = new int[this->NrCategorii];
		for (int i = 0; i < this->NrCategorii; i++)
		{	
			cout << "Categoria" << " "<<i + 1 << " se numeste ";
			cin >> this->Categorii[i];
			cout << "Categoria" << " " << i + 1 << " are numarul de randuri: ";
			cin >> this->nrRanduri[i];
			cout << "Categoria" << " " << i + 1 << " are numarul de locuri pe rand ";
			cin >> this->nrlocuri[i];
			cout << "Categoria" << " " << i + 1 << " are pretul/bilet ";
			cin >> this->pret[i];
			
			
		}
		cout << endl;
		
		
	
	}
	void afisare()//afisare
	{
		cout << "Numarul de categorii este: " << this->NrCategorii << endl;
		for (int i = 0; i < this->NrCategorii; i++)
		{
			cout  << "Categoria" << " " << i + 1 << " se numeste ";
			cout << this->Categorii[i] << endl;
			cout <<"Numarul de randuri este : ";
			cout << this->nrRanduri[i] << endl;
			cout << "Numarul de locuri pe rand este: ";
			cout << this->nrlocuri[i] << endl;
			cout << "Pretul per bilet este: " ;
			cout << this->pret[i]<<endl;
			cout << "Numarul de locuri totale/categorie este ";
			this->nrLocuriCategorie[i] = this->nrRanduri[i] * this->nrlocuri[i];
			cout << this->nrLocuriCategorie[i]<<endl<<endl;
			
		}
		cout << endl;
	}
	void SchimbaPretul(int* pretnou) //metoda generica
	{
		if (pretnou != NULL)
		{
			if (this->pret != NULL)
			{
				delete[] this->pret;
			}
			this->pret = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->pret[i] = pretnou[i];
			}
		}
	}
	
	int NrLocuriTotale(int* nrLocuriCategorie) //metoda generica
	{
		int suma = 0;
		for (int i = 0; i < this->NrCategorii; i++)
		{
			suma += this->nrLocuriCategorie[i];
		}
		return suma;
	}
	void AfisareLocuriDisponibile()
	{
		for (int i = 0; i < this->NrCategorii; i++)
		{
			cout << "Categoria" << " " << i + 1 << " are locuri disponibile: ";
			cout << this->nrLocuriCategorie[i] << endl;
		}
	}
	int& operator[] (int index) //operator [] index
	{
		if (index >= 0 && index < this->NrCategorii) {
			return this->Categorii[index];
		}
		else {
			throw "Index gresit"; 
		}

	}
	LocatieBilete& operator +=(int NrCategoriii_inplus) //operator +=
	{
		this->NrCategorii = this->NrCategorii + NrCategoriii_inplus;
		return *this;
		
	}
	void scrieBinar()

};
