#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>

using namespace std;
using ll = long long;

int main()
{
  vector<string> s, t;
  map<string, int> mp1, mp2;

  int h, w;

  cin >> h >> w;
  for ( int i = 0; i < h; ++i ) {
    string tmp; cin >> tmp;
    s.push_back(tmp);
  } 

  for ( int i = 0; i < h; ++i ) {
    string tmp; cin >> tmp;
    t.push_back(tmp);
  }

  for ( int i = 0; i < w; ++i ) {
    string tmp;
    for ( int j = 0; j < h; ++j ) {
        tmp += s[j][i];
    }
    if ( mp1[tmp] == 0 ) mp1[tmp] = 1;
    else mp1[tmp] += 1;
  }

  for ( int i = 0; i < w; ++i ) {
    string tmp;
    for ( int j = 0; j < h; ++j ) {
        tmp += t[j][i];
    }
    if ( mp2[tmp] == 0 ) mp2[tmp] = 1;
    else mp2[tmp] += 1;
  }

  if ( mp2 == mp1 ) cout << "Yes" << endl;
  else cout << "No" << endl;
}