#include<iostream>
#include<string>
#include<vector>

#define M 1000000007

using namespace std;

typedef long long ll;

vector<int> pre = vector<int>(27, 0);
vector<ll> lis;

int getno( char c) {
  return c-'a';
}

int main() {
  string s;
  ll sum = 0;

  cin >> s;
  // lis = vector<ll>(s.size()+1, 0);

  lis = vector<ll>(s.size()+2, 0);
  lis[0] = 1;
  lis[1] = 1;
  // pre[getno(s[0])] = 1;
  // sum += 1;

  for ( int i = 2; i < s.size()+2; ++i ) {
    int no = getno(s[i-2]);
    int st;
    // cout << "no = " << no << endl;
    st = pre[no];
    pre[no] = i-1;
    // lis[i] = lis[i-2];
    lis[i] = lis[i-2];
    if ( st-1 >= 0 ) lis[i] -= lis[st-1];
    if ( lis[i] < 0 ) lis[i] += M;
    sum += lis[i];
    sum %= M;
    lis[i] = (lis[i]+lis[i-1])%M;
    // if ( st-1 >= 0 ) lis[i] = (lis[i] - lis[st-1]);
    // if ( lis[i] < 0 ) lis[i] += M;
    // lis[i] = (lis[i]+lis[i-1])%M;
  }

  // for ( int i = 0; i < s.size(); ++i ) {
  //   // int no = getno(s[i-1]);
  //   // int st;
  //   // if ( pre[no] == -1 ) st = 0;
  //   // else st = pre[no];
  //   // pre[no] = i+1;
  //   // for ( int j = st; j < i; ++j ) {
  //   //   lis[i+1] = (lis[i+1] + lis[j])%M;
  //   // }
  //   // sum += lis[i+1];
  //   // sum %= M;
  //
  //   for ( int j = i-1; ; --j ) {
  //     lis[i+2] = (lis[i+2]+lis[j+1])%M;
  //     if ( j == -1 || s[i] == s[j] ) break;
  //   }
  //   sum += lis[i+2];
  //   sum %= M;
  // }

  cout << sum << endl;
}
