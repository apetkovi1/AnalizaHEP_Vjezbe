// C++
#include <iostream>
#include <fstream>

// My own class
#include <Analyzer.h>

using namespace std;

int main()
{
  // Declare Analyzer
  Analyzer *analyzer;

  analyzer = new Analyzer();

  analyzer->GenerateMedian();
  analyzer->pValue();
  analyzer->CompareHypothesis();
  
  delete analyzer;

  return 0;
}
