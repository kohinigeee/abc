#include<iostream>
#include<set>

using namespace std;

int main() {
  set<int> s;

  int l,q;
  cin >> l >> q;
  s.insert(0);
  s.insert(l);

  for ( int i = 0; i < q; ++i ) {
    int c,x;
    cin >> c >> x;
    if ( c == 1 ) s.insert(x);
    else {
      s.insert(x);
      auto it = s.find(x);
      cout << *(++it) - *(--(--it)) << endl;
      ++it;
      s.erase(it);
    }
  }
}
