#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> a = vector<int>();
  int n;
  int ans = 0;
  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  for ( int i = 0; i < n; ++i ) {
    int minv = a[i];
    for ( int j = i; j < n; ++j ) {
      if ( minv > a[j] ) minv = a[j];
      int tmp = minv*(j-i+1);
      ans = (ans > tmp) ? ans : tmp;
    }
  }

  cout << ans << endl;

}
