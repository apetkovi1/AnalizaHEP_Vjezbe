#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void Analyzer::GenerateMedian()
{
  TCanvas *c = new TCanvas("c","c",700,700);

  gStyle->SetOptStat(0);

  Median_H0 = new TH1F("Median_H0","Median_H0",100,0.4,1.0);
  Median_H1 = new TH1F("Median_H1","Median_H1",100,0.4,1.0);

  TRandom *rand = new TRandom();

  for(i=0;i<1e4;i++)
  {
    for(j=0;j<1e3;j++)
    {
      x0 = rand->Exp(1./0.9);
      v0.push_back(x0);
      x1 = rand->Exp(1./1.03);
      v1.push_back(x1);
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    N=v0.size();
    Median0 = (v0[(N - 1) / 2] + v0[N / 2]) / 2.0;
    Median_H0->Fill(Median0);
    Median1 = (v1[(N - 1) / 2] + v1[N / 2]) / 2.0;
    Median_H1->Fill(Median1);
    v0.clear();
    v1.clear();
  }

  Median_H0->Scale(1./Median_H0->Integral());
  Median_H1->Scale(1./Median_H1->Integral());

  Median_H0->SetLineColor(kRed);
  Median_H1->SetLineColor(kBlue);

  auto legend = new TLegend(0.7,0.8,0.9,0.9);
  legend->AddEntry(Median_H0,"H0(#alpha=0.9)");
  legend->AddEntry(Median_H1,"H1(#alpha=1.1)");

  Median_H1->SetTitle("Hypothesis comparison");
  Median_H1->GetXaxis()->SetTitle("Median");
  Median_H1->GetYaxis()->SetTitle("normalized");

  Median_H1->Draw("HIST");
  Median_H0->Draw("HIST SAME");

  legend->Draw();
  
  c->SaveAs("MedianHypothesis.pdf");

}

void Analyzer::pValue()
{

  Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   
      nbytes += nb;
      v.push_back(x);
   }

  sort(v.begin(), v.end());
  N=v.size(); 
  Median_obs = (v[(N - 1) / 2] + v[N / 2]) / 2.0;
  v.clear();
  std::cout<<Median_obs<<std::endl;
  
  double pValue = Median_H0->Integral(1, Median_H0->FindBin(Median_obs));
  std::cout<<"p value="<<pValue<<std::endl;

}

void Analyzer::CompareHypothesis()
{
  
  //std::cout<<Median_H0->Integral(Median_H0->FindBin(Median_obs),Median_H0->GetNbinsX())<<std::endl;
  //std::cout<<Median_H1->Integral(Median_H1->FindBin(Median_obs),Median_H1->GetNbinsX())<<std::endl;

  double p_H0 = Median_H0->Integral(Median_H0->FindBin(Median_obs), Median_H0->GetNbinsX());
  double p_H1 = Median_H1->Integral(Median_H1->FindBin(Median_obs),Median_H1->GetNbinsX());
  
  //cout<<p_H0<<" "<<p_H1<<endl;

  cout << "We can exclude alternative hypothesis at" <<" "<<(1-p_H1/p_H0)*100 << "\% CL." << endl;

}

