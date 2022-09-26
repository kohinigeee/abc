#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef string ty;

class Item {
public:
  int cnt;
  int pos;
  ty s;

  Item(ty s1, int pos1, int cnt1) {
    s = s1;
    cnt = cnt1;
    pos = pos1;
  }
};

int main() {
  ty s;
  vector<Item> v = vector<Item>();
  int q;
  int revcnt = 0;
  string ans;

  cin >> s;
  cin >> q;
  for ( int i = 0; i < q; ++i ) {
    int que;
    cin >> que;
    if ( que == 1 ) revcnt += 1;
    else {
      ty tmp;
      int pos;
      cin >> pos >> tmp;

      //cout  << "pos= " << pos << ", tmp= " << tmp << endl;
      v.push_back(Item(tmp,pos, revcnt));
    }
  }

  if ( revcnt%2 == 1) ans = string(s.rbegin(), s.rend());
  else ans = s;

  for ( int i = 0; i < v.size(); ++i ) {
    if ( (revcnt-v[i].cnt)%2 == 1 ) {
      v[i].pos = 3-v[i].pos;
    }

    if (v[i].pos == 1 ) ans = v[i].s+ans;
    else ans = ans+v[i].s;
  }

  cout << ans << endl;
}
