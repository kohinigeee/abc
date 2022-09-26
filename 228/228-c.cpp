#include<iostream>
#include<vector>

using namespace std;

int arg[1201];
vector<int> v;

int main()
{
  for ( int i = 0; i <= 1200; ++i ) arg[i] = 0;
  int n,k;

  cin >> n >> k;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    int sum = 0;
    for ( int j = 0; j < 3; ++j ) { cin >> tmp; sum += tmp; }
    arg[sum] += 1;
    v.push_back(sum);
  }

  for ( int i = 1; i <= 1200; ++i ) {
    arg[i] += arg[i-1];
  }

  for ( auto x : v ) {
    int tmp = 0;
    if ( x+300 <= 1200 ) {
      tmp = arg[900]-arg[x+300];
    }

    if ( tmp < k ) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
