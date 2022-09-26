#include <iostream>
#include <vector>
#include <string>

struct item {
//  int pos;
  int leng;
  char ch;
};

int main()
{
  int N, K;
  string str;
  char ch;
  int cnt = 0;
  vector<item> v;

  cin >> N >> K;
  cin >> str;

  ch = str[0];
  for ( int i = 0; i < n; ++i ) {
    if ( ch == str[i] ) ++cnt;
    else {
      v.push_back({cnt, ch});
      ch = str[i];
      cnt = 1;
    }
  }
  v.push_back({cnt, str[str.size()-1]});

  
}
