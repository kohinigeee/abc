#include<iostream>

using namespace std;

int main()
{
  char A;

  cin >> A;

  if ( A == 'A' ) cout << "T\n";
  else if ( A == 'T') cout << "A\n";
  else if ( A == 'G') cout << "C\n";
  else cout <<"G\n";
}
