#include <iostream>
#include <string>
#include<fstream>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
#include "Analyzer.h"
using namespace std;

Analyzer::Analyzer()
{
  
  
}

void Analyzer::Read()
{
   ifstream file;
   file.open("analysis.txt");
   string line;
   string name1;
   string name2;
   string name3;
   double a,b,c,d,e,f,g,h,x,y;
   if(file.is_open())
   {
     while(getline(file,line))
     {
       stringstream linestream(line);
       linestream >> name1 >> name3 >> a >> b >> c >> d >> x >> name2 >> e >> f >>  g >> h >> y;
       cout << c << endl;
     }
   }
}
/*void ConvertTxtToRootFile(fstream& file)
{
	
}*/
