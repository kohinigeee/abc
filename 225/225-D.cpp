#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
using vi = vector<int>;

vi front;
vi back;
int n, q;

void connect(int x, int y ) {
  front[y] = x;
  back[x] = y;
}

void disconnect(int x, int y ) {
  front[y] = y;
  back[x] = x;
}

void print(int x ) {
  stack<int> st;
  queue<int> q;

  if ( front[x] == back[x] ) { cout << 1 << " " << x+1 << endl; return; }
  if ( front[x] != x ) {
    int tmpx = x;
    while ( tmpx != front[tmpx] ) { tmpx = front[tmpx]; st.push(tmpx); }
  }
  if ( back[x] != x ) {
    int tmpx = x;
    while ( tmpx != back[tmpx] ) { tmpx = back[tmpx]; q.push(tmpx); }
  }

  cout << st.size()+1+q.size() << " ";
  while( !st.empty() ) { cout << st.top()+1 << " "; st.pop(); }
  cout << x+1 << " ";
  while( !q.empty() ) { cout << q.front()+1 << " "; q.pop(); }
  cout << endl;
}

int main()
{
  int n,q;

  cin >> n >> q;
  front = vi(n,0);
  back = vi(n,0);

  for ( int i = 0; i < n; ++i ) {
    front[i] = back[i] = i;
  }

  for ( int i = 0; i < q; ++i ) {
    int c,x,y;
    cin >> c;
    if ( c == 1 ) {
      cin >> x >> y;
      --x; --y;
      connect(x,y);
    } else if ( c == 2 ) {
      cin >> x >> y; --x; --y;
      disconnect(x,y);
    } else {
      cin >> x; --x;
      print(x);
    }
  }
  
}
