#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

using ll = long long;

vector<pair<int,int>> vec;
vector<bool> used;
ll score[16][16];
int n;


ll calc()
{
  ll ans = 0;
  if ( vec.size() == n ) {
    ll tmp = 0;
    for ( auto e : vec ) tmp ^= score[e.first][e.second];
    return tmp;
  }

  int l;
  for ( int i = 0; i < 2*n; ++i ) {
    if ( !used[i] ) {
      l = i;
      used[l] = true;
      break;
    }
  }

  for ( int i = 0; i < 2*n; ++i ) {
    if ( !used[i] ) {
      vec.push_back({l,i}), used[i] = true;
      ans = max(calc(), ans);
      vec.pop_back();
      used[i] = false;
    }
  }

  used[l] = false;
  return ans;
}

int main()
{
  cin >> n;
  used = vector<bool>(2*n, false);

  for ( int i = 0; i < 2*n; ++i ) {
    for ( int j = i+1; j < 2*n; ++j ) {
      cin >> score[i][j];
    }
  }

  cout << calc() << endl;
}
