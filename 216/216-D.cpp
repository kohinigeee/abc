#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<queue<int>> tubes(m);
  vector<vector<int>> cnts(n, vector<int>());
  queue<int> next_tube;
  int sum = 0;

  for ( int i = 0; i < m; ++i ) {
    int k;
    cin >> k;
    for ( int j = 0; j < k; ++j ) {
      int a;
      cin >> a; --a;
      tubes[i].push(a);
    }
  }

  for ( int i = 0; i < m; ++i ) {
    int top = tubes[i].front();
    cnts[top].push_back(i);
    if ( cnts[top].size() == 2 ) {
      next_tube.push(top);
    }
  }

  while( !next_tube.empty() ) {
    int next = next_tube.front(); next_tube.pop();
    // cout << "next = " <<   next << endl;
    ++sum;
    int x1 = cnts[next][0];
    int x2 = cnts[next][1];
    tubes[x1].pop(); tubes[x2].pop();
    int a1 = -1;
    int a2 = -1;
    if ( !tubes[x1].empty() ) {
      int a1 = tubes[x1].front();
      cnts[a1].push_back(x1);
      if ( cnts[a1].size() == 2 ) next_tube.push(a1);
    }
    if ( !tubes[x2].empty() ) {
    int a2 = tubes[x2].front();
    cnts[a2].push_back(x2);
    if ( a2 != a1 && cnts[a2].size() == 2 ) next_tube.push(a2);
  }
  }

  if ( sum == n ) cout << "Yes" << endl;
  else cout << "No" << endl;
}
