#include <iostream>
#include <string>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include "ElementaryParticle.h"
using namespace std;
ElementaryParticle :: ElementaryParticle(string a,double b, bool c)
 {
	 ime=a;
	 masa=b;
	 jeli_bozon=c;
	 double P[4];
 }
 ElementaryParticle :: ElementaryParticle()
 {
	 ime=" ";
	 masa=0;
	 jeli_bozon=false;
	 double P[4];
 }
void ElementaryParticle :: printInfo() 
    { 
         cout << ime<<" "<< masa <<"Gev "<< jeli_bozon <<endl;
    }
void ElementaryParticle :: Energy()
{
	int i;
	double a[4];
	cout<<"Unesi redom x,y i z komponente kolicine gibanja za "<<ime<<" u GeV-ima: "<<endl;
	for(i=1;i<=3;i++)
	{
		cin>>a[i];
		P[i]=a[i];
	}
	P[0]=sqrt(P[1]*P[1]+P[2]*P[2]+P[3]*P[3]+masa*masa); //Izračun energije
	cout<<"Cetverovektor kolicine gibanja za "<< ime<<" je: ("<<P[0]<<", "<<P[1]<<", "<<P[2]<<", "<<P[3]<<") GeV"<<endl;
}
void ElementaryParticle :: p_T()
{
	cout<< "Transverzalna kolicina gibanja iznosi: "<<sqrt(P[1]*P[1]+P[2]*P[2])<<" GeV"<<endl;
}
void ElementaryParticle :: bosonDecay(ElementaryParticle object1, ElementaryParticle object2)
{
	int r,i,a[4];
	//srand (time(NULL));
	for(i=1;i<=3;i++)
	{
		P[i]=rand()%201-100; // nasumicne kolicine gibanja Higgsa u rasponu od -100 do 100 GeV-a
	}
	P[0]=sqrt(P[1]*P[1]+P[2]*P[2]+P[3]*P[3]+masa*masa); //Izračun energije
	if(jeli_bozon==false)
		cout<<"Raspad nije moguc"<<endl;
	if(jeli_bozon==true)
	{
	 //cout<<"Cestica je bozon"<<endl;
	 r = rand() % 1001; //random broj između 0 i 1000
	 if(r<=214)
	 {
		object1.ime=object2.ime="W bozon";
		object1.jeli_bozon=object2.jeli_bozon=true;
		object1.masa=object2.masa=80.38;
		for(i=1;i<=3;i++) // random generiranje kolicine gibanja
		{
			a[i] = rand()% 201-100; // nije zadano u zadatku ali stavim da se kol_gib za objekt 1 nasumično rasporede izmedu -100 i 100
			object1.P[i]=a[i];
			object2.P[i]=P[i]-object1.P[i]; //kol gib objekta2=kol gib pocetne cestice - kol gib objekta 1
		}
		
	 }
	 else if(r>214 && r<=278)
	 {
	    object1.ime=object2.ime="tau lepton";
		object1.jeli_bozon=object2.jeli_bozon=false; 
		object1.masa=object2.masa=1.78;
		for(i=1;i<=3;i++) // random generiranje kolicine gibanja
		{
			a[i] = rand()% 201-100; // nije zadano u zadatku ali stavim da se nasumično rasporede izmedu -100 i 100
			object1.P[i]=a[i];
			object2.P[i]=P[i]-object1.P[i]; //kol gib objekta2=kol gib pocetne cestice - kol gib objekta 1
		}
	 }
	 else if(r>278 && r<=304)
	 {
		object1.ime=object2.ime="Z bozon";
		object1.jeli_bozon=object2.jeli_bozon=true; 
		object1.masa=object2.masa=91.19;
		for(i=1;i<=3;i++) // random generiranje kolicine gibanja
		{
			a[i] = rand()% 201-100; // nije zadano u zadatku ali stavim da se nasumično rasporede izmedu -100 i 100
			object1.P[i]=a[i];
			object2.P[i]=P[i]-object1.P[i]; //kol gib objekta2=kol gib pocetne cestice - kol gib objekta 1
		}	 
	 }
	 else
	 {
		object1.ime="b kvark";
		object2.ime="anti-b kvark";
		object1.masa=object2.masa=4.18;
		object1.jeli_bozon=object2.jeli_bozon=false;
		for(i=1;i<=3;i++) // random generiranje kolicine gibanja
		{
			a[i] = rand()% 201-100; // nije zadano u zadatku ali stavim da se nasumično rasporede izmedu -100 i 100
			object1.P[i]=a[i];
			object2.P[i]=P[i]-object1.P[i]; //kol gib objekta2=kol gib pocetne cestice - kol gib objekta 1
		}
	 }
	//cout<<ime<<" se raspao na: "<< object1.ime<<" i "<< object2.ime<<endl;
	
		object1.P[0]=sqrt(object1.P[1]*object1.P[1]+object1.P[2]*object1.P[2]+object1.P[3]*object1.P[3]+object1.masa*object1.masa);
		object2.P[0]=sqrt(object2.P[1]*object2.P[1]+object2.P[2]*object2.P[2]+object2.P[3]*object2.P[3]+object2.masa*object2.masa);
		//cout<<"Cetverovektor kolicine gibanja za "<< object1.ime<<" je: ("<<object1.P[0]<<", "<<object1.P[1]<<", "<<object1.P[2]<<", "<<object1.P[3]<<") GeV"<<endl;
		//cout<<"Cetverovektor kolicine gibanja za "<< object2.ime<<" je: ("<<object2.P[0]<<", "<<object2.P[1]<<", "<<object2.P[2]<<", "<<object2.P[3]<<") GeV"<<endl;
		ofstream file;
        file.open ("analysis.txt",std::ios_base::app); //svaki put dodajem podatke u analysis.txt pa stavim app (append) jer inace izbrise podatke za prethodni Higgsov bozon
        file <<ime<<"      "<<object1.ime<<"      "<<object1.P[0]<<"  "<<object1.P[1]<<"  "<<object1.P[2]<<"  "<<object1.P[3]<<"  "<<object2.ime<<"      "<<object2.P[0]<<"  "<<object2.P[1]<<"  "<<object2.P[2]<<"  "<<object2.P[3]<<endl;
        file.close();
	}
		
}