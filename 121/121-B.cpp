#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
  int N,M,C;
  vector<int> B = vector<int>();
  int cnt = 0;

  cin >> N >> M >> C;

  for ( int i = 0; i < M; ++i ) {
    int tmp;
    scanf("%d",&tmp);
    B.push_back(tmp);
  }

  for ( int i = 0; i < N; ++i ) {
    int sum = 0;
    for ( int j = 0; j < M; ++j ) {
      int tmp;
      scanf("%d", &tmp);
      sum += tmp*B[j];
    }
    if ( sum + C > 0 ) ++cnt;
  }

  cout << cnt << "\n";
}
