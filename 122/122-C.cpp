#include<iostream>
#include<string>
#include<cstdio>
#include<vector>

#define MAXN 1000000

using namespace std;

int main()
{
  vector<int> vec = vector<int>(MAXN);
  string str;
  int N,Q,l,r;
  int pos = 0;

  cin >> N >> Q;
  cin >> str;

  while(pos < str.size()-1 ) {
    if ( str[pos] == 'A' && str[pos+1] == 'C' ) {
      vec[pos+1] = vec[pos]+1;
    } else {
      vec[pos+1] = vec[pos];
    }
    ++pos;
  }

  while(Q--) {
    cin >> l >> r;
    cout << vec[r-1]-vec[l-1] << endl;
  }
}
