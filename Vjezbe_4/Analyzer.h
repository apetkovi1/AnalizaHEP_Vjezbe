#include <iostream>
#include <string>
#include<sstream>
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TApplication.h"
class Analyzer
{
  public:
  Analyzer();
  void Read();
  void ConvertTxtToRootFile(std::string s); //ako nema using namespace treba stavit std :: string s
};
