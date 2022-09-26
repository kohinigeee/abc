#include<iostream>
#include<string>

using namespace std;

string func(int x ) {
  if ( x == 1 ) return "1";
  string tmp = func(x-1);
  return tmp+" "+to_string(x)+" "+tmp;
}

int main()
{
  int n;
  cin >> n;
  cout << func(n) << endl;
}
