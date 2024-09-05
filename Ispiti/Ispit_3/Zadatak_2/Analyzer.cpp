#include <Analyzer.h>
Analyzer::Analyzer()
{

}
Analyzer::~Analyzer()
{

}
void Analyzer::MakeFit()
{
    TFile* inputFile = new TFile("/home/public/data/QuadraticHisto.root", "READ");

    TH1F* histogram;
    inputFile->GetObject("histogram", histogram);

    for (int i = 1; i <= histogram->GetNbinsX(); ++i) {
        double binContent = histogram->GetBinContent(i);
        double binError = histogram->GetBinError(i);

        std::cout << "Bin " << i << ", Content = " << binContent << ", Error = " << binError << std::endl;
    }

     auto Likelihood_function = new TF1("Likelihood Function",
     "(-2)*(-10000*(x+9)/(125*x+45)+2274*TMath::Log(10000*(x+9)/(125*x+45)))+ \
      (-2)*(-10000*(7*x+9)/(125*x+45)+2245*TMath::Log(10000*(7*x+9)/(125*x+45)))+ \
      (-2)*(-10000*(19*x+9)/(125*x+45)+2110*TMath::Log(10000*(19*x+9)/(125*x+45)))+ \
      (-2)*(-10000*(37*x+9)/(125*x+45)+1798*TMath::Log(10000*(37*x+9)/(125*x+45)))+ \
      (-2)*(-10000*(61*x+9)/(125*x+45)+1573*TMath::Log(10000*(61*x+9)/(125*x+45)))",-0.1,0.1);

      //ln(r_i!) discarded because it is just a constant
     
    TCanvas* canvas1 = new TCanvas("canvas", "Canvas", 800, 600);
    Likelihood_function->Draw();
    canvas1->SaveAs("Likelihood.png");
    double a = Likelihood_function->GetMinimumX();
    double a_up2 = Likelihood_function->GetX(Likelihood_function->GetMinimum() + 25, a+0.01, 0.1);
    double a_dn2 =  Likelihood_function->GetX(Likelihood_function->GetMinimum() + 25, -0.1, a-0.01);
    std::cout<< "a = " <<Likelihood_function->GetMinimumX()<<std::endl;
    cout << "a_up = " << a_up2 << endl;
    cout << "a_dn = " << a_dn2 << endl;

    TCanvas* canvas2 = new TCanvas("canvas1", "Canvas1", 800, 600);
    auto fit_function = new TF1("quadratic","[0]*10000*([1]*x*x+3)",0,5);
    fit_function->SetTitle("Likelihood fit on histogram");
    double N = 1./(125.*a/3.+15);
    fit_function->SetParameter(0,N); //N je normalizacija
    fit_function->SetParameter(1,a);
    fit_function->Draw();
    histogram->Draw("SAME HISTO");
    canvas2->SaveAs("Fit.png");

    inputFile->Close();

}
