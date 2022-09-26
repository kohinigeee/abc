#include<iostream>
#include<vector>
#include<string>

#define MMM 1000000007

typedef uint64_t ll;

using namespace std;

int func13(int x,int y) {
  if ( x >= y ) return x-y;
  else return 13+x-y;
}

int ctoi(char ch) {
  return ch-'0';
}

/*
print (vector<vector<ll>>& lis ) {
  for ( ll i = 0; i < lis.size(); ++i ) {
    for ( ll j = 0; j < lis[i].size(); ++j ) {
      cout << lis[i][j] << " ";
    }
    cout << endl;
  }
}
*/

int main() {
  string s;
  vector<vector<ll>> lis;
  ll tmp;

  cin >> s;
  for ( ll i = 0; i < s.size(); ++i ) {
    lis.push_back(vector<ll>(13,0));
  }


  if (s[s.size()-1] != '?') lis[0][ctoi(s[s.size()-1])] += 1;
  else {
    for ( int i = 0; i < 10; ++i ) lis[0][i] += 1;
  }

  tmp = 1;
  for ( int i = 1; i < s.size(); ++i ) {
    ll j = s.size()-1-i;
    tmp *= 10;
    if (s[j] != '?') {
      ll tmp1 = ctoi(s[j])*tmp%13;
      for ( int k = 0; k < 13; ++k ) lis[i][k] = lis[i-1][func13(k,tmp1)];
    } else {
      for ( ll l = 0; l < 10; ++l ) {
        ll tmp1 = l*tmp%13;
        for ( int k = 0; k < 13; ++k ) {
          lis[i][k] = (lis[i][k]+lis[i-1][func13(k,tmp1)])%MMM;
        }
      }
      //for ( ll k = 0; k < 13; ++k ) lis[i][k] %= MMM;
    }

    /*
    cout << endl;
    cout << print(lis);
    cout << endl;
    */
  }
  cout << lis[s.size()-1][5]%MMM << endl;
}
