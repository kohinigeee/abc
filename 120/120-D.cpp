//–¢‰ðŒˆ
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class unionSet {
private:
  std::vector<int> rank, p, points;

public:

  unionSet(int x) {
    rank = std::vector<int>();
    p = std::vector<int>();
    points = std::vector<int>();

    if ( x <= 0 ) x = 1;
    for ( int i = 0; i < x; ++i ) {
      rank.push_back(0);
      p.push_back(i);
      points.push_back(1);
    }
  }

  int findSet(int x ) {
    if( p[x] != x ) {
      p[x] = findSet(p[x]);
    }
    return p[x];
  }

  int findPoints(int x ) {
    return points[findSet(x)];
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
      points[pare] += points[ch];
      rank[pare]++;
      return pare;
    } else {
      int pare, ch;
      pare = rank[xp] < rank[yp] ? yp:xp;
      ch = ( pare == xp ) ? yp:xp;

      p[ch] = pare;
      points[pare] += points[ch];
      return pare;
    }
  }

  bool isSame(int x, int y) {
    return findSet(x) == findSet(y);
  }
};


int main() {
  int N,M;
  vector<long long> A = vector<long long >(), B = vector<long long>();
  vector<long long> sum = vector<long long >();
  int cnt = 0;

  cin >> N >> M;
  unionSet set = unionSet();

  for ( int i = 0; i < M; ++i) {
    int a,b;

    scanf("%d%d", &a,&b);
    A.push_back(a-1);
    B.push_back(b-1);
  }
  sum.push_back(N*(N-1)/2);

  for ( int i = M-1; i > 0; --i ) {
    if ( set.isSame(A[i],B[i]) ) {
      sum.push_back(sum[sum.size()-1]);
      continue;
    }
    sum.push_back(sum[sum.size()-1] - set.findPoints(A[i])*set.findPoints(B[i]));
    set.unite(A[i], B[i]);
  }

  for ( int i = sum.size()-1; i >= 0; --i ) {
    cout << sum[i] << endl;
  }
}
