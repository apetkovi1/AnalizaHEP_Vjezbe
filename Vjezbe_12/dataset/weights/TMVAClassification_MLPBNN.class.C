// Class: ReadMLPBNN
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLPBNN
TMVA Release   : 4.2.1         [262657]
ROOT Release   : 6.22/06       [398854]
Creator        : apetkovic
Date           : Sat Jan  9 15:31:11 2021
Host           : Linux buildvm-x86-05.iad2.fedoraproject.org 5.7.11-200.fc32.x86_64 #1 SMP Wed Jul 29 17:15:52 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /home/apetkovic/Vjezbe/Vjezbe_12
Training events: 2000
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "N+5" [Specification of hidden layer architecture]
NeuronType: "tanh" [Neuron activation function type]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "N" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "True" [Print method-specific help message]
TrainingMethod: "BFGS" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
TestRate: "5" [Test for overtraining performed at each #th epochs]
UseRegulator: "True" [Use regulator to avoid over-training]
# Default:
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
EstimatorType: "CE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
NeuronInputType: "sum" [Neuron input function type]
VerbosityLevel: "Default" [Verbosity level]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 4
ele_pt                        ele_pt                        ele_pt                        ele_pt                                                          'F'    [5.00599241257,306.198883057]
ele_ep                        ele_ep                        ele_ep                        ele_ep                                                          'F'    [0.000418868934503,20]
ele_fbrem                     ele_fbrem                     ele_fbrem                     ele_fbrem                                                       'F'    [-1,0.991997241974]
ele_eelepout                  ele_eelepout                  ele_eelepout                  ele_eelepout                                                    'F'    [0.0226789675653,20]
NSpec 0


============================================================================ */

#include <array>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadMLPBNN : public IClassifierReader {

 public:

   // constructor
   ReadMLPBNN( std::vector<std::string>& theInputVars )
      : IClassifierReader(),
        fClassName( "ReadMLPBNN" ),
        fNvars( 4 )
   {
      // the training input variables
      const char* inputVars[] = { "ele_pt", "ele_ep", "ele_fbrem", "ele_eelepout" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = -1;
      fVmax[0] = 1;
      fVmin[1] = -1;
      fVmax[1] = 0.99999988079071;
      fVmin[2] = -1;
      fVmax[2] = 1;
      fVmin[3] = -1;
      fVmax[3] = 1;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';

      // initialize constants
      Initialize();

      // initialize transformation
      InitTransform();
   }

   // destructor
   virtual ~ReadMLPBNN() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const override;

 private:

   // method-specific destructor
   void Clear();

   // input variable transformation

   double fOff_1[3][4];
   double fScal_1[3][4];
   void InitTransform_1();
   void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
   void InitTransform();
   void Transform( std::vector<double> & iv, int sigOrBgd ) const;

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   double fVmin[4];
   double fVmax[4];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[4];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)

   double ActivationFnc(double x) const;
   double OutputActivationFnc(double x) const;

   double fWeightMatrix0to1[10][5];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[1][10];   // weight matrix from layer 1 to 2

};

inline void ReadMLPBNN::Initialize()
{
   // build network structure
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -5.20310836645225;
   fWeightMatrix0to1[1][0] = 0.159845270926616;
   fWeightMatrix0to1[2][0] = -0.695623167585616;
   fWeightMatrix0to1[3][0] = 1.7214309265187;
   fWeightMatrix0to1[4][0] = -0.415296301729188;
   fWeightMatrix0to1[5][0] = -0.285698174709489;
   fWeightMatrix0to1[6][0] = -2.61061604117601;
   fWeightMatrix0to1[7][0] = 0.428188941123721;
   fWeightMatrix0to1[8][0] = -2.06761284418683;
   fWeightMatrix0to1[0][1] = 0.270170340750749;
   fWeightMatrix0to1[1][1] = 0.743254040055117;
   fWeightMatrix0to1[2][1] = -1.01360400180339;
   fWeightMatrix0to1[3][1] = -2.33688385586452;
   fWeightMatrix0to1[4][1] = 0.631490545764537;
   fWeightMatrix0to1[5][1] = 0.356824114608131;
   fWeightMatrix0to1[6][1] = -0.421650645013584;
   fWeightMatrix0to1[7][1] = 0.472491034760702;
   fWeightMatrix0to1[8][1] = 3.20641315593767;
   fWeightMatrix0to1[0][2] = -0.199460255528073;
   fWeightMatrix0to1[1][2] = 0.38734366811381;
   fWeightMatrix0to1[2][2] = -3.85099622039201;
   fWeightMatrix0to1[3][2] = 1.12399411664557;
   fWeightMatrix0to1[4][2] = 3.73255583212594;
   fWeightMatrix0to1[5][2] = 2.61780628506156;
   fWeightMatrix0to1[6][2] = 3.07728273386133;
   fWeightMatrix0to1[7][2] = -2.96760046218445;
   fWeightMatrix0to1[8][2] = -1.89204667241991;
   fWeightMatrix0to1[0][3] = 0.314678194379761;
   fWeightMatrix0to1[1][3] = -1.19847983354983;
   fWeightMatrix0to1[2][3] = -1.08271985685916;
   fWeightMatrix0to1[3][3] = -4.03530351834225;
   fWeightMatrix0to1[4][3] = 10.9308810320496;
   fWeightMatrix0to1[5][3] = -2.22387950253662;
   fWeightMatrix0to1[6][3] = 1.76149843890784;
   fWeightMatrix0to1[7][3] = 3.81583487564523;
   fWeightMatrix0to1[8][3] = -0.544284285759973;
   fWeightMatrix0to1[0][4] = -4.80298468948954;
   fWeightMatrix0to1[1][4] = 0.976039755499063;
   fWeightMatrix0to1[2][4] = -2.97658461628403;
   fWeightMatrix0to1[3][4] = -3.91730085948032;
   fWeightMatrix0to1[4][4] = 10.5156810712618;
   fWeightMatrix0to1[5][4] = 0.326444033024011;
   fWeightMatrix0to1[6][4] = -2.09973200040857;
   fWeightMatrix0to1[7][4] = 5.63914083272762;
   fWeightMatrix0to1[8][4] = -0.227269202498924;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = -9.48324664341971;
   fWeightMatrix1to2[0][1] = -5.2030717490518;
   fWeightMatrix1to2[0][2] = 9.37268432093344;
   fWeightMatrix1to2[0][3] = 6.55143773783002;
   fWeightMatrix1to2[0][4] = 8.17538894352833;
   fWeightMatrix1to2[0][5] = 7.09415367766142;
   fWeightMatrix1to2[0][6] = 5.23594942617967;
   fWeightMatrix1to2[0][7] = 6.0945449010332;
   fWeightMatrix1to2[0][8] = 4.57144364972657;
   fWeightMatrix1to2[0][9] = -7.72908511504484;
}

inline double ReadMLPBNN::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)4) {
      std::cout << "Input vector needs to be of size " << 4 << std::endl;
      return 0;
   }

   std::array<double, 10> fWeights1 {{}};
   std::array<double, 1> fWeights2 {{}};
   fWeights1.back() = 1.;

   // layer 0 to 1
   for (int o=0; o<9; o++) {
      std::array<double, 5> buffer; // no need to initialise
      for (int i = 0; i<5 - 1; i++) {
         buffer[i] = fWeightMatrix0to1[o][i] * inputValues[i];
      } // loop over i
      buffer.back() = fWeightMatrix0to1[o][4];
      for (int i=0; i<5; i++) {
         fWeights1[o] += buffer[i];
      } // loop over i
    } // loop over o
   for (int o=0; o<9; o++) {
      fWeights1[o] = ActivationFnc(fWeights1[o]);
   } // loop over o
   // layer 1 to 2
   for (int o=0; o<1; o++) {
      std::array<double, 10> buffer; // no need to initialise
      for (int i=0; i<10; i++) {
         buffer[i] = fWeightMatrix1to2[o][i] * fWeights1[i];
      } // loop over i
      for (int i=0; i<10; i++) {
         fWeights2[o] += buffer[i];
      } // loop over i
    } // loop over o
   for (int o=0; o<1; o++) {
      fWeights2[o] = OutputActivationFnc(fWeights2[o]);
   } // loop over o

   return fWeights2[0];
}

double ReadMLPBNN::ActivationFnc(double x) const {
   // fast hyperbolic tan approximation
   if (x > 4.97) return 1;
   if (x < -4.97) return -1;
   float x2 = x * x;
   float a = x * (135135.0f + x2 * (17325.0f + x2 * (378.0f + x2)));
   float b = 135135.0f + x2 * (62370.0f + x2 * (3150.0f + x2 * 28.0f));
   return a / b;
}
double ReadMLPBNN::OutputActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}

// Clean up
inline void ReadMLPBNN::Clear()
{
}
inline double ReadMLPBNN::GetMvaValue( const std::vector<double>& inputValues ) const
{
   // classifier response value
   double retval = 0;

   // classifier response, sanity check first
   if (!IsStatusClean()) {
      std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                << " because status is dirty" << std::endl;
   }
   else {
         std::vector<double> iV(inputValues);
         Transform( iV, -1 );
         retval = GetMvaValue__( iV );
   }

   return retval;
}

//_______________________________________________________________________
inline void ReadMLPBNN::InitTransform_1()
{
   double fMin_1[3][4];
   double fMax_1[3][4];
   // Normalization transformation, initialisation
   fMin_1[0][0] = 5.93200445175;
   fMax_1[0][0] = 294.071472168;
   fScal_1[0][0] = 2.0/(fMax_1[0][0]-fMin_1[0][0]);
   fOff_1[0][0] = fMin_1[0][0]*fScal_1[0][0]+1.;
   fMin_1[1][0] = 5.00599241257;
   fMax_1[1][0] = 306.198883057;
   fScal_1[1][0] = 2.0/(fMax_1[1][0]-fMin_1[1][0]);
   fOff_1[1][0] = fMin_1[1][0]*fScal_1[1][0]+1.;
   fMin_1[2][0] = 5.00599241257;
   fMax_1[2][0] = 306.198883057;
   fScal_1[2][0] = 2.0/(fMax_1[2][0]-fMin_1[2][0]);
   fOff_1[2][0] = fMin_1[2][0]*fScal_1[2][0]+1.;
   fMin_1[0][1] = 0.000418868934503;
   fMax_1[0][1] = 20;
   fScal_1[0][1] = 2.0/(fMax_1[0][1]-fMin_1[0][1]);
   fOff_1[0][1] = fMin_1[0][1]*fScal_1[0][1]+1.;
   fMin_1[1][1] = 0.0383437722921;
   fMax_1[1][1] = 20;
   fScal_1[1][1] = 2.0/(fMax_1[1][1]-fMin_1[1][1]);
   fOff_1[1][1] = fMin_1[1][1]*fScal_1[1][1]+1.;
   fMin_1[2][1] = 0.000418868934503;
   fMax_1[2][1] = 20;
   fScal_1[2][1] = 2.0/(fMax_1[2][1]-fMin_1[2][1]);
   fOff_1[2][1] = fMin_1[2][1]*fScal_1[2][1]+1.;
   fMin_1[0][2] = -1;
   fMax_1[0][2] = 0.988826096058;
   fScal_1[0][2] = 2.0/(fMax_1[0][2]-fMin_1[0][2]);
   fOff_1[0][2] = fMin_1[0][2]*fScal_1[0][2]+1.;
   fMin_1[1][2] = -1;
   fMax_1[1][2] = 0.991997241974;
   fScal_1[1][2] = 2.0/(fMax_1[1][2]-fMin_1[1][2]);
   fOff_1[1][2] = fMin_1[1][2]*fScal_1[1][2]+1.;
   fMin_1[2][2] = -1;
   fMax_1[2][2] = 0.991997241974;
   fScal_1[2][2] = 2.0/(fMax_1[2][2]-fMin_1[2][2]);
   fOff_1[2][2] = fMin_1[2][2]*fScal_1[2][2]+1.;
   fMin_1[0][3] = 0.0612740665674;
   fMax_1[0][3] = 20;
   fScal_1[0][3] = 2.0/(fMax_1[0][3]-fMin_1[0][3]);
   fOff_1[0][3] = fMin_1[0][3]*fScal_1[0][3]+1.;
   fMin_1[1][3] = 0.0226789675653;
   fMax_1[1][3] = 20;
   fScal_1[1][3] = 2.0/(fMax_1[1][3]-fMin_1[1][3]);
   fOff_1[1][3] = fMin_1[1][3]*fScal_1[1][3]+1.;
   fMin_1[2][3] = 0.0226789675653;
   fMax_1[2][3] = 20;
   fScal_1[2][3] = 2.0/(fMax_1[2][3]-fMin_1[2][3]);
   fOff_1[2][3] = fMin_1[2][3]*fScal_1[2][3]+1.;
}

//_______________________________________________________________________
inline void ReadMLPBNN::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 4;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) {
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
   }
   if ( indicesPut.empty() ) {
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
   }

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<4;ivar++) {
      double offset = fOff_1[cls][ivar];
      double scale  = fScal_1[cls][ivar];
      iv[indicesPut.at(ivar)] = scale*dv[ivar]-offset;
   }
}

//_______________________________________________________________________
inline void ReadMLPBNN::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLPBNN::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
