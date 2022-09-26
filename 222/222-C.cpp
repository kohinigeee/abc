#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>

using namespace std;

using vvi = vector<vector<int>>;
using pi = pair<int,int>;

enum { G, C, P };
enum { KATI, IGAI};

int janken(int x, int y ) {
  if ( x == y ) return IGAI;
  if ( (x+1)%3 == y ) return KATI;
  else return IGAI;
}

bool func(pi p1, pi p2 ) {
  if ( p1.first == p2.first ) return p1.second < p2.second;
  return p1.first > p2.first;
}

int main()
{
  int n, m;

  cin >> n >> m;
  n = 2*n;
  vvi mirai(n, vector<int>(m));
  vector<pi> ord(n);

  for ( int i = 0; i < n; ++i ) {
    string tmp; cin >> tmp;
    for ( int j = 0; j < m; ++j ) {
      if ( tmp[j] == 'G' ) mirai[i][j] = G;
      else if  ( tmp[j] == 'C' ) mirai[i][j] = C;
      else mirai[i][j] = P;
    }
  }

  for ( int i = 0; i < n; ++i ) ord[i] = make_pair(0, i);

  for ( int i = 0; i < m; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      int aite = j+1;
      if ( j%2 ) aite = j-1;

      int hand1 = mirai[ord[j].second][i];
      int hand2 = mirai[ord[aite].second][i];

      if ( janken(hand1, hand2) == KATI ) ord[j].first += 1;
    }

    sort(ord.begin(), ord.end(), func);
  }

  for ( int i = 0; i < n; ++i ) {
    cout << ord[i].second+1 << endl;
  }
}
