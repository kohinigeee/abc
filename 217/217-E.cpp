#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
  queue<int> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;

  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int c;
    cin >> c;
    switch (c) {
      case 1:
      int x; cin >> x;
      q.push(x);
      break;
      case 2:
        int ans;
        if ( !pq.empty() ) { ans = pq.top(); pq.pop(); }
        else { ans = q.front(); q.pop(); }
        cout  << ans << endl;
        break;
      case 3:
        while( !q.empty() ) { pq.push(q.front()); q.pop(); }
    }
  }
}
