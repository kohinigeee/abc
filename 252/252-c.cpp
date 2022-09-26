#include<iostream>
#include<vector>
#include<string>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vvi cnt = vvi( 10, vi(10, 0) );
int ans = 10000;

int main()
{
  cin >> n;
  while(n--) {
    string s; cin >> s;
    for ( int i = 0; i < 10; ++i ) {
      cnt[s[i]-'0'][i] += 1;
    }
  }


  for ( int i = 0; i < 10; ++i ) {
    int no = 0;
    for ( int j = 0; j < 10; ++j ) {
      if ( cnt[i][j] >= cnt[i][no] ) no = j;
    }
    int tmpans = 10*(cnt[i][no]-1)+no;
    if ( tmpans < ans) ans = tmpans;
    // cout << i << " : " << tmpans << endl;
  }

  cout << ans << endl;
}
