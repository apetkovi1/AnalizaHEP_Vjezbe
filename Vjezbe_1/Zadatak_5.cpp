#include<iostream>
#include<cmath>
using namespace std;
float _my_cube(float x)
{
  return pow(x,3);
}
int main()
{
  float a;
  cout<<"Unesi realan broj:";
  cin>>a;
  cout<<_my_cube(a)<<endl;
}
