#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define ALSIZE 26

typedef long long ll;

using namespace std;

int ctoi(char c) {
  return int(c-'a');
}

char itoc(int x) {
  return char(x+int('0'));
}

int main()
{
  string s1,s2,s3;
  vector<int> v = vector<int>();
  vector<int> nos = vector<int>{0,1,2,3,4,5,6,7,8,9};
  bool f = false;
  ll v1,v2,v3;
  int chs[ALSIZE];

  for ( int i = 0; i < ALSIZE; ++i ) {
    chs[i] = -1;
  }

  cin >> s1;
  cin >> s2;
  cin >> s3;

  for ( int i = 0; i < s1.size(); ++i) {
    chs[ctoi(s1[i])] = 1;
  }

  for ( int i = 0; i < s2.size(); ++i ) {
    chs[ctoi(s2[i])] = 1;
  }

  for ( int i = 0; i < s3.size(); ++i ) {
    chs[ctoi(s3[i])] = 1;
  }

  for ( int i = 0; i < ALSIZE; ++i ) {
    if (chs[i] > 0) v.push_back(i);
  }

  if ( v.size() <= 10 ) {

    do {
      for ( int i = 0; i < v.size(); ++i ) chs[v[i]] = nos[i];

      string tmp1 = "", tmp2 = "", tmp3 = "";
      for ( int i = 0; i < s1.size(); ++i ) tmp1 = tmp1+ itoc(chs[ctoi(s1[i])]);
      for ( int i = 0; i < s2.size(); ++i ) tmp2 = tmp2+ itoc(chs[ctoi(s2[i])]);
      for ( int i = 0; i < s3.size(); ++i ) tmp3 = tmp3+ itoc(chs[ctoi(s3[i])]);

      if ( tmp1[0] == '0' || tmp2[0] == '0' || tmp3[0] == '0' ) continue;
      v1 = stoll(tmp1);
      v2 = stoll(tmp2);
      v3 = stoll(tmp3);

      if ( v3 == v1+v2 ) {
        f = true;
        break;
      }
    } while( next_permutation(nos.begin(), nos.end()));
  }

  if ( f ) {
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
  } else {
    cout << "UNSOLVABLE" << endl;
  }

}
