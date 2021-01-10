#include "dataset/weights/TMVAClassification_TMlpANN.h"
#include <cmath>

double TMVAClassification_TMlpANN::Value(int index,double in0,double in1,double in2,double in3) {
   input0 = (in0 - 26.6337)/23.6129;
   input1 = (in1 - 1.78212)/2.23196;
   input2 = (in2 - 0.372556)/0.364844;
   input3 = (in3 - 2.09501)/3.2347;
   switch(index) {
     case 0:
         return neuron0x12f5ad50();
     default:
         return 0.;
   }
}

double TMVAClassification_TMlpANN::Value(int index, double* input) {
   input0 = (input[0] - 26.6337)/23.6129;
   input1 = (input[1] - 1.78212)/2.23196;
   input2 = (input[2] - 0.372556)/0.364844;
   input3 = (input[3] - 2.09501)/3.2347;
   switch(index) {
     case 0:
         return neuron0x12f5ad50();
     default:
         return 0.;
   }
}

double TMVAClassification_TMlpANN::neuron0x11721290() {
   return input0;
}

double TMVAClassification_TMlpANN::neuron0x1156da00() {
   return input1;
}

double TMVAClassification_TMlpANN::neuron0x117199e0() {
   return input2;
}

double TMVAClassification_TMlpANN::neuron0x11677be0() {
   return input3;
}

double TMVAClassification_TMlpANN::input0x117182c0() {
   double input = -4.93851;
   input += synapse0x11681860();
   input += synapse0x1156d6f0();
   input += synapse0x11715d40();
   input += synapse0x11688dd0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x117182c0() {
   double input = input0x117182c0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x12f59240() {
   double input = 5.93849;
   input += synapse0x1171c520();
   input += synapse0x12f5de60();
   input += synapse0x12f5dd90();
   input += synapse0x1156dd40();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x12f59240() {
   double input = input0x12f59240();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x11724fe0() {
   double input = 3.93784;
   input += synapse0x116714c0();
   input += synapse0x11725320();
   input += synapse0x11725360();
   input += synapse0x117253a0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x11724fe0() {
   double input = input0x11724fe0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x1167bbb0() {
   double input = 9.22131;
   input += synapse0x1167bef0();
   input += synapse0x1167bf30();
   input += synapse0x1167bf70();
   input += synapse0x117253e0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x1167bbb0() {
   double input = input0x1167bbb0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x1167e500() {
   double input = -4.18229;
   input += synapse0x1167e840();
   input += synapse0x1167bfb0();
   input += synapse0x11718570();
   input += synapse0x11719c90();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x1167e500() {
   double input = input0x1167e500();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x116769e0() {
   double input = 1.03317;
   input += synapse0x11719cd0();
   input += synapse0x11676c90();
   input += synapse0x11676cd0();
   input += synapse0x11676d10();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x116769e0() {
   double input = input0x116769e0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x1167c700() {
   double input = 1.54705;
   input += synapse0x1167ca40();
   input += synapse0x1167ca80();
   input += synapse0x1167cac0();
   input += synapse0x1167cb00();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x1167c700() {
   double input = input0x1167c700();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x11719e60() {
   double input = -4.11182;
   input += synapse0x1171a1a0();
   input += synapse0x1171a1e0();
   input += synapse0x1171a220();
   input += synapse0x1171a260();
   input += synapse0x11677f20();
   input += synapse0x11677f60();
   input += synapse0x1167e880();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x11719e60() {
   double input = input0x11719e60();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x1171d3e0() {
   double input = -1.07308;
   input += synapse0x11676de0();
   input += synapse0x12f59580();
   input += synapse0x12f595c0();
   input += synapse0x12f59600();
   input += synapse0x12f59640();
   input += synapse0x11677530();
   input += synapse0x11677570();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x1171d3e0() {
   double input = input0x1171d3e0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x116775b0() {
   double input = -3.96635;
   input += synapse0x116778f0();
   input += synapse0x11677930();
   input += synapse0x1171f9f0();
   input += synapse0x1171fa30();
   input += synapse0x1171fa70();
   input += synapse0x1171fab0();
   input += synapse0x1171faf0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x116775b0() {
   double input = input0x116775b0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x1171fb30() {
   double input = 2.43315;
   input += synapse0x12f5ab90();
   input += synapse0x12f5abd0();
   input += synapse0x12f5ac10();
   input += synapse0x12f5ac50();
   input += synapse0x12f5ac90();
   input += synapse0x12f5acd0();
   input += synapse0x12f5ad10();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x1171fb30() {
   double input = input0x1171fb30();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x12f5ad50() {
   double input = 8.43336;
   input += synapse0x1171fde0();
   input += synapse0x1171fe20();
   input += synapse0x11673010();
   input += synapse0x11673050();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x12f5ad50() {
   double input = input0x12f5ad50();
   return (input * 1)+0;
}

double TMVAClassification_TMlpANN::synapse0x11681860() {
   return (neuron0x11721290()*-5.04996);
}

double TMVAClassification_TMlpANN::synapse0x1156d6f0() {
   return (neuron0x1156da00()*0.868378);
}

double TMVAClassification_TMlpANN::synapse0x11715d40() {
   return (neuron0x117199e0()*1.45242);
}

double TMVAClassification_TMlpANN::synapse0x11688dd0() {
   return (neuron0x11677be0()*-0.121687);
}

double TMVAClassification_TMlpANN::synapse0x1171c520() {
   return (neuron0x11721290()*7.27903);
}

double TMVAClassification_TMlpANN::synapse0x12f5de60() {
   return (neuron0x1156da00()*-5.25659);
}

double TMVAClassification_TMlpANN::synapse0x12f5dd90() {
   return (neuron0x117199e0()*4.86285);
}

double TMVAClassification_TMlpANN::synapse0x1156dd40() {
   return (neuron0x11677be0()*-1.70482);
}

double TMVAClassification_TMlpANN::synapse0x116714c0() {
   return (neuron0x11721290()*2.62143);
}

double TMVAClassification_TMlpANN::synapse0x11725320() {
   return (neuron0x1156da00()*-2.07847);
}

double TMVAClassification_TMlpANN::synapse0x11725360() {
   return (neuron0x117199e0()*2.05577);
}

double TMVAClassification_TMlpANN::synapse0x117253a0() {
   return (neuron0x11677be0()*0.0111319);
}

double TMVAClassification_TMlpANN::synapse0x1167bef0() {
   return (neuron0x11721290()*2.16336);
}

double TMVAClassification_TMlpANN::synapse0x1167bf30() {
   return (neuron0x1156da00()*17.0931);
}

double TMVAClassification_TMlpANN::synapse0x1167bf70() {
   return (neuron0x117199e0()*2.42852);
}

double TMVAClassification_TMlpANN::synapse0x117253e0() {
   return (neuron0x11677be0()*-0.27379);
}

double TMVAClassification_TMlpANN::synapse0x1167e840() {
   return (neuron0x11721290()*-3.2522);
}

double TMVAClassification_TMlpANN::synapse0x1167bfb0() {
   return (neuron0x1156da00()*2.02002);
}

double TMVAClassification_TMlpANN::synapse0x11718570() {
   return (neuron0x117199e0()*-2.07541);
}

double TMVAClassification_TMlpANN::synapse0x11719c90() {
   return (neuron0x11677be0()*-0.0309509);
}

double TMVAClassification_TMlpANN::synapse0x11719cd0() {
   return (neuron0x11721290()*1.81274);
}

double TMVAClassification_TMlpANN::synapse0x11676c90() {
   return (neuron0x1156da00()*-4.81647);
}

double TMVAClassification_TMlpANN::synapse0x11676cd0() {
   return (neuron0x117199e0()*-0.0393276);
}

double TMVAClassification_TMlpANN::synapse0x11676d10() {
   return (neuron0x11677be0()*0.742318);
}

double TMVAClassification_TMlpANN::synapse0x1167ca40() {
   return (neuron0x11721290()*1.85664);
}

double TMVAClassification_TMlpANN::synapse0x1167ca80() {
   return (neuron0x1156da00()*0.0521624);
}

double TMVAClassification_TMlpANN::synapse0x1167cac0() {
   return (neuron0x117199e0()*1.09479);
}

double TMVAClassification_TMlpANN::synapse0x1167cb00() {
   return (neuron0x11677be0()*3.82923);
}

double TMVAClassification_TMlpANN::synapse0x1171a1a0() {
   return (neuron0x117182c0()*-5.21717);
}

double TMVAClassification_TMlpANN::synapse0x1171a1e0() {
   return (neuron0x12f59240()*-6.05932);
}

double TMVAClassification_TMlpANN::synapse0x1171a220() {
   return (neuron0x11724fe0()*3.85308);
}

double TMVAClassification_TMlpANN::synapse0x1171a260() {
   return (neuron0x1167bbb0()*10.275);
}

double TMVAClassification_TMlpANN::synapse0x11677f20() {
   return (neuron0x1167e500()*-2.29619);
}

double TMVAClassification_TMlpANN::synapse0x11677f60() {
   return (neuron0x116769e0()*0.0426602);
}

double TMVAClassification_TMlpANN::synapse0x1167e880() {
   return (neuron0x1167c700()*-4.34669);
}

double TMVAClassification_TMlpANN::synapse0x11676de0() {
   return (neuron0x117182c0()*6.51077);
}

double TMVAClassification_TMlpANN::synapse0x12f59580() {
   return (neuron0x12f59240()*7.30188);
}

double TMVAClassification_TMlpANN::synapse0x12f595c0() {
   return (neuron0x11724fe0()*0.760056);
}

double TMVAClassification_TMlpANN::synapse0x12f59600() {
   return (neuron0x1167bbb0()*-11.8791);
}

double TMVAClassification_TMlpANN::synapse0x12f59640() {
   return (neuron0x1167e500()*8.25014);
}

double TMVAClassification_TMlpANN::synapse0x11677530() {
   return (neuron0x116769e0()*-0.500592);
}

double TMVAClassification_TMlpANN::synapse0x11677570() {
   return (neuron0x1167c700()*5.10151);
}

double TMVAClassification_TMlpANN::synapse0x116778f0() {
   return (neuron0x117182c0()*-1.73657);
}

double TMVAClassification_TMlpANN::synapse0x11677930() {
   return (neuron0x12f59240()*0.284036);
}

double TMVAClassification_TMlpANN::synapse0x1171f9f0() {
   return (neuron0x11724fe0()*-2.10944);
}

double TMVAClassification_TMlpANN::synapse0x1171fa30() {
   return (neuron0x1167bbb0()*5.7379);
}

double TMVAClassification_TMlpANN::synapse0x1171fa70() {
   return (neuron0x1167e500()*-4.21127);
}

double TMVAClassification_TMlpANN::synapse0x1171fab0() {
   return (neuron0x116769e0()*-0.742953);
}

double TMVAClassification_TMlpANN::synapse0x1171faf0() {
   return (neuron0x1167c700()*-1.78706);
}

double TMVAClassification_TMlpANN::synapse0x12f5ab90() {
   return (neuron0x117182c0()*1.18682);
}

double TMVAClassification_TMlpANN::synapse0x12f5abd0() {
   return (neuron0x12f59240()*4.81102);
}

double TMVAClassification_TMlpANN::synapse0x12f5ac10() {
   return (neuron0x11724fe0()*3.82237);
}

double TMVAClassification_TMlpANN::synapse0x12f5ac50() {
   return (neuron0x1167bbb0()*-3.5631);
}

double TMVAClassification_TMlpANN::synapse0x12f5ac90() {
   return (neuron0x1167e500()*3.2009);
}

double TMVAClassification_TMlpANN::synapse0x12f5acd0() {
   return (neuron0x116769e0()*-2.74525);
}

double TMVAClassification_TMlpANN::synapse0x12f5ad10() {
   return (neuron0x1167c700()*0.273406);
}

double TMVAClassification_TMlpANN::synapse0x1171fde0() {
   return (neuron0x11719e60()*-6.62195);
}

double TMVAClassification_TMlpANN::synapse0x1171fe20() {
   return (neuron0x1171d3e0()*-6.19789);
}

double TMVAClassification_TMlpANN::synapse0x11673010() {
   return (neuron0x116775b0()*1.85344);
}

double TMVAClassification_TMlpANN::synapse0x11673050() {
   return (neuron0x1171fb30()*-2.20399);
}

