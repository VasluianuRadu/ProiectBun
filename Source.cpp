#include"Bilete.h"
#include"Eveniment.h"
#include"LocatieBilete.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


int main()
{
	Eveniment Even;
	Bilete Bilet;
	LocatieBilete loc;

	Eveniment e1("Concert Tudor Gheorhe",10 , 4, 2023, 20, 30, "Bucuresti");
	cout << e1<<endl;
	LocatieBilete l1(2, new int[2] {1, 2}, new int[2]{ 7, 8 }, new int[2] {10, 10},new int[2]{100,150},new int[2]{70,80});
	cout << l1;

	
	cin >> Even;
	cout << endl;
	Even.afisare();
	cout<< endl;
	loc.citire();
	cout << endl;
	cout << loc;
	cout << endl;

	cout << "Introduceti datele biletului:"<<endl;
	cin >> Bilet;
	cout << endl;
	cout << Bilet;
	

	

}
