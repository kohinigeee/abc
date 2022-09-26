#include <iostream>

using namespace std;

int main()
{
  int a[5];
  int k;

  for ( int i = 0; i < 5; ++i ) cin >> a[i];
  cin >> k;

  if ( a[4]-a[0] > k ) cout << ":(" << endl;
  else cout << "Yay!" << endl;
}
