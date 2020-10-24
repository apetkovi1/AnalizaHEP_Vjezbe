#include <iostream>
#include <string>
#include<fstream>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
#include "Analyzer.h"
using namespace std;
int main()
{
  
  Analyzer object1;
  object1.Read();
  object1.ConvertTxtToRootFile("analysis.txt");
}
