#include<iostream>
#include<deque>
#include<vector>
#include<random>
#include<cstdio>

#define MAXN 1000000

using namespace std;

using ll = unsigned long long;

vector<int> v(MAXN+1, 0);

int func( int x ) {
  int tmp = 1;
  while( tmp <= x ) tmp *= 10;
  tmp /= 10;
  int tmp1 = x%10;

  return tmp1*tmp+(x-tmp1)/10;
}

int ord ( ll x ) {
  int cnt = 0;
  while( x > 0 ) {
    x /= 10;
    ++cnt;
  }
  return cnt;
}

int func2( int a, int n ) {
  // cout << "func2" << ", a = " << a << ", n = " << n << endl;
  for ( int i = 0; i < v.size(); ++i ) v[i] = 0;
  deque<int> deq;
  deq.push_front(1);
  v[1] = 0;
  int ordn = ord(n);
  int ans = -1;

  // cout << "ordn = " << ordn << endl;
  while( !deq.empty() ) {
    int f = deq.front(); deq.pop_front();
    ll tmp1 = f*a;

    if ( ( ord(tmp1) <= ordn ) && (v[tmp1] == 0) ) {
      if ( tmp1 == n ) { ans = v[f]+1; break; }

      v[tmp1] = v[f]+1;
      deq.push_back(tmp1);
    }

    // cout << "test2" << endl;
    if ( (f % 10 != 0)  &&  ( f >= 11 ) ) {
      int tmp2 = func(f);
      if ( v[tmp2] != 0 ) continue;
      if ( tmp2 == n ) { ans = v[f]+1; break; }
      v[tmp2] = v[f]+1;
      deq.push_back(tmp2);
    }
  }

  return ans;
}

int main()
{
  int a, n;

  // std::random_device rnd;     // 非決定的な乱数生成器を生成
  // std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
  //  std::uniform_int_distribution<> rand100(2, 100000);        // [0, 99] 範囲の一様乱数
  //  for (int i = 0; i < 100; ++i) {
  //    a = rand100(mt);
  //    n = rand100(mt);
  //    // printf("a = %d, n = %d\n", a, n);
  //    printf("a = %d, n = %d, ans = %d\n", a, n, func2(a,n) );
  //  }
  // // cout << ans << endl;
  cin >> a >> n;

  cout << func2(a,n) << endl;
}
