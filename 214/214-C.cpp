#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<utility>


using namespace std;

template<class T>
class pri_queue {
private:
  vector<T> v;
  function<bool(T,T)> comp;

  void change(int x, int y ) {
    T tmp = v[x]; v[x] = v[y]; v[y] = tmp;
  }

  void upmove(int x) {
    if ( x >= v.size() || x < 0) return;
    while( x > 0 ) {
      int p = (x-1)/2;
      if ( comp(v[x], v[p]) ) change(p,x);
      else break;
      x = p;
    }
  }

  void downmove(int x) {
    if ( x < 0 ) return;
    while( x < v.size() ) {
      int l = x*2+1, r = x*2+2;
      int minp = x;
      if ( l < v.size() && comp(v[l], v[minp]) ) minp = l;
      if ( r < v.size() && comp(v[r], v[minp]) ) minp = r;
      if ( minp == x ) break;
      change(minp,x);
      x = minp;
    }
  }

public:

  pri_queue(function<bool(T,T)> f1 ) { comp = f1; } //比較関数の決定

  pri_queue() { comp = less<int>(); }

  void add(T x) {
    v.push_back(x);
    upmove(v.size()-1);
  }

  T pop() {
    T tmp = v[0];
    change(0,v.size()-1);
    v.pop_back();
    downmove(0);
    return tmp;
  }

  bool empty() { return v.empty(); }
};

bool compf( pair<int,int> p1, pair<int,int> p2 ) {
  return p1.second < p2.second;
}

int main()
{
  int n;
  vector<int> time = vector<int>();
  pri_queue<pair<int,int>> q = pri_queue<pair<int,int>>( compf );
  vector<int> ans;
  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    time.push_back(tmp);
  }

  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    q.add(pair<int,int>(i,tmp));
  }

  ans = vector<int>(n, -1);
  int cnt = n;

  while(cnt > 0 ) {
    pair<int,int> tmp = q.pop();
    if ( ans[tmp.first] == -1 ) {
      ans[tmp.first] = tmp.second;
      --cnt;
      int no, t;
      no = (tmp.first+1)%n;
      t = tmp.second+time[tmp.first];
      q.add(pair<int,int>(no, t));
    }
  }

  for ( int i = 0; i < n; ++i ) {
    cout << ans[i] << endl;
  }
}
