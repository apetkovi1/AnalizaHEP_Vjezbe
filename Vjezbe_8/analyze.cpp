#include <iostream>
#include <string>
#include<fstream>
#include <vector>
#include "Analyzer.h"
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
#include "Analyzer.h"
using namespace std;
int main()
{
  Analyzer* object1=new Analyzer();
  //object1->Loop();
    object1->PlotHistogram("/home/public/data/ggH125/ZZ4lAnalysis.root");
    object1->PlotHistogram("/home/public/data/qqZZ/ZZ4lAnalysis.root");
    object1->Chi_Square_Fit();
	object1->ML_Fit();
}
