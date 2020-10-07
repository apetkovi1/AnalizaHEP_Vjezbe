#include <iostream>
using namespace std;

void _my_cube_(double a)
{
  cout << a*a*a;
}

int main() {
  double x;
  cin >> x;
  _my_cube_(x);
  return 0;
} 
