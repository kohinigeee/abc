#include<iostream>
#include<vector>

using namespace std;

vector<int> toBinay(int x) {
  int i = 1;
  vector<int> vec = vector<int>();
  while( i <= x ) {
    i *= 2;
  }
  i /= 2;

  while( i > 0 ) {
    vec.push_back(x/i);
    x %= i;
    i /= 2;
  }

  return vec;
}

int main() {
  long long A,B;
  long long  a = 0, b = 0;
  long long tmp;


  cin >> A >> B;
  if ( A % 2 == 1 ) {
    a = A;
    ++A;
  }
  if ( B % 2 == 0 ) {
    b = B;
    --B;
  }

  tmp = ((B-A+1)/2)%2;
  cout << ((a^b)^tmp) << endl;
}
