#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> z_alg2(string s) {
  vector<int> d = vector<int>(s.size(), 0);

  int j = 0;
  int ans = 0;
  int i = 1;

  while ( i < s.size() ) {
    while(i+j < s.size() && s[j] == s[i+j] ) ++j;
    d[i] = j;

    if ( j == 0 ) {
      ++i;
      continue;
    }

    int k = 1;
    while( k < j && k+d[k] < j ) {
      d[i+k] = d[k];
      ans = max(d[i+k], ans);
      ++k;
    }

    i += k;
    j -= k;
  }

  d[0] = 0;
  return d;
}

int z_alg(string s, int x ) {
  vector<int> d = vector<int>(s.size(), 0);


  int j = 0;
  bool f = false;
  int ans = 0;

  for ( int i = x+1; i < s.size(); ++i ) {
    f = false;
    while(i+j < s.size() && x+j < i && s[j] == s[i+j] ) ++j;
    d[i] = j;
    if ( d[i] > ans ) ans = d[i];

    for ( int k = 1; k < j; ++k ) {
      if ( k + d[k] < j) d[i+k] = d[k];
      else {
        i = i+k-1;
        //j = d[k];
        j = j-k;
        f = true;
        break;
      }
    }

    if (!f) {
      if ( j != 0) i += j-1;
      j = 0;
    }
  }

  return ans;
}

int main()
{
  string s;
  vector<int> d;
  int ans = 0;

  cin >> s;
  cin >> s;

  for ( int i = 0; i < s.size(); ++i ) {
    auto d = z_alg2(s.substr(i));
    for ( int j = 0; j < d.size(); ++j ) {
      int l = min(d[j], j);
      ans = max(ans, l);
    }
  }

  cout << ans << endl;
}
