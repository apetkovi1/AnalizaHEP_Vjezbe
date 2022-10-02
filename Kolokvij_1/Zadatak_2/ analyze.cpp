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
  object1->PlotHistogram();
}
