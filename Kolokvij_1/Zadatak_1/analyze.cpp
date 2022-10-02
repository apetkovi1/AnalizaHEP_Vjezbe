#include<iostream>
#include<fstream>
#include<cstdlib>
#include <string>
#include "PDFGenerator.h"
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
using namespace std ;
int main()
{
	ofstream file;
	int i;
	srand(time(NULL));
	file.open("analysis.txt");
	for(i=0;i<10000;i++)
	{
		PDFGenerator *object=new PDFGenerator();
		file<<object->GenerateQuadraticPDF()<<endl;
	}
	PDFGenerator *object2=new PDFGenerator();
	object2->ConvertTxtToRootFile("analysis.txt");
}
