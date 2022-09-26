#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

const bool comppair(pair<int,int> p1, pair<int,int> p2) {
  return p1.first > p2.first;
}

int main()
{
  multiset<int> s;
  int n;
  vector<pair<int,int>> vec = vector<pair<int, int>>();
  long long ans = 0;

  cin >> n;
  s = multiset<int>{0,0,n+1, n+1};
  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    vec.push_back(pair<int,int>(tmp, i+1));
  }

  sort(vec.begin(), vec.end(), comppair );

  for ( int i = 0; i < n; ++i ) {
    long long w,x,y,z;
    int j = vec[i].second;
    s.insert(j);
    auto it = s.find(j);
    x = *(--it);
    w = *(--it);
    ++it;
    ++it;
    y = *(++it);
    z = *(++it);
    //cout << "( " << w << ", " << x << ", " << y << ", " << z << " )" << endl;
    ans += ((x-w)*(y-j)+(j-x)*(z-y))*vec[i].first;
    //cout << "ans = " << ans << endl;
  }

  cout << ans << endl;
}
