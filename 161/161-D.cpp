#include<iostream>
#include<string>
#include<vector>

using namespace std;

int ctoi(char x) {
  return x-'0';
}

int main()
{
  vector<vector<int>> tab = vector<vector<int>>();
  string s;
  int n;
  int cnt = 0;

  cin >> s;
  n = s.size();
  for ( int i = 0; i < 9; ++i ) {
    tab.push_back(vector<int>(n,0));
  }

  for (int i = 0; i < 9; ++i ) {
    tab[i][0] = i+1;
    for ( int j = 1; j < n; ++j ) tab[i][j] = (tab[i][j-1]*10)%2019;
  }

  for ( int i = 0; i < n; ++i ) {
    int tmp = ctoi(s[n-i-1]);
    int ans = tmp;
    for ( int j = i+1; j < n; ++j ) {
      int tmp1 = ctoi(s[n-j-1]);
      ans += tab[tmp1-1][j-i];
      ans %= 2019;
      if ( ans == 0 ) cnt += 1;
    }
  }

  cout << cnt << endl;
}
