#ifndef ___UNION_SET
#define ___UNION_SET

#include<iostream>
#include<vector>

class unionSet {
private:
  std::vector<int> rank, p;

public:
  unionSet(int x) {
    rank = std::vector<int>();
    p = std::vector<int>();

    if ( x <= 0 ) x = 1;
    for ( int i = 0; i < x; ++i ) {
      rank.push_back(0);
      p.push_back(i);
    }
  }

  int findSet(int x ) {
    if( p[x] != x ) {
      p[x] = findSet(p[x]);
    }
    return p[x];
  }

  int unite(int x, int y) {
    int xp,yp;
    xp = findSet(x);
    yp = findSet(y);
    if ( xp == yp ) return -1;

    if ( rank[xp] == rank[yp] ) {
      int pare,ch;
      pare = xp < yp ? xp : yp;
      ch = pare == xp ? yp : xp;

      p[ch] = pare;
      rank[pare]++;
      return pare;
    } else {
      int pare, ch;
      pare = rank[xp] < rank[yp] ? yp:xp;
      ch = ( pare == xp ) ? yp:xp;

      p[ch] = pare;
      return pare;
    }
  }

  bool isSame(int x, int y) {
    return findSet(x) == findSet(y);
  }

  int rank(int x) {
    if ( x < 0 || x > p.size() ) return -1;
    return rank[findSet(x)];
  }
};
#endif

int main() {
  unionSet u;
  int n;
  
}
