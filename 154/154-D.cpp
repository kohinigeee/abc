#include<iostream>
#include<vector>
#include<algorithm>

typedef unsigned long long ll;

using namespace std;

int main()
{
  vector<int> lis = vector<int>(1441,0);
  for ( int i = 1; i < 1441; ++i ) {
    lis[i] = lis[i-1]+i;
  }

  int n,k;
  vector<int> p = vector<int>();

  cin >> n >> k;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    p.push_back(tmp);
  }

  ll goukei = 0;
  ll kakuritu = 1;
  double ans;

  for ( int i = 0; i < k; ++i ) {
    goukei *= p[i];
    goukei += kakuritu*lis[p[i]];
    kakuritu *= p[i];
  }

  ans = goukei/kakuritu;
  int i = 1;
  while(i+k <= n) {
    int pos = i+k-1;
  //  cout << "i = " << i << endl;
    kakuritu /= p[i-1];
      goukei -= kakuritu*lis[p[i-1]];
      goukei /= p[i-1];

      goukei *= p[pos];
      goukei += kakuritu*lis[p[pos]];
      kakuritu *= p[pos];

      ans = max(ans, double(goukei)/kakuritu);
      i += 1;
  }

cout << ans << endl;
}
