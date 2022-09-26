#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;
  int N;
  int maxh = 0;
  int cnt = 0;

  cin >> N;

  for ( int i = 0; i < N; ++i ) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  for ( int i = 0; i < v.size(); ++i ) {
    if ( maxh <= v[i] ) {
      ++cnt;
      maxh = v[i];
    }
  }

  cout << cnt << endl;
}
