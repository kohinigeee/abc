#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
  vector<int> v;
  priority_queue<int, vector<int>, greater<int>> q;
  int n,k;

  cin >> n >> k;
  for ( int i = 0; i < k; ++i ) {
    int tmp; cin >> tmp;
    q.push(tmp);
  }
  cout << q.top() << endl;

  for ( int i = k; i < n; ++i ) {
    int tmp; cin >> tmp;
    if ( tmp > q.top() ) {
      q.pop();
      q.push(tmp);
    }
    cout << q.top() << endl;
  }
}
