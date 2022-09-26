#include<iostream>
#include<vector>
#include<set>

#define WHITE 0
#define GOOD 1
#define BAD 2
#define MAXC 100000+1

using namespace std;

void dfs(const vector<vector<int>>& v, const vector<int>& color, vector<int>& used,
  vector<int>& s, int x) {
    if ( s[color[x]] == 0 ) used[x] = GOOD;
    else used[x] = BAD;

    s[color[x]] += 1;
    for ( int i = 0; i < v[x].size(); ++i ) {
      int to = v[x][i];
      if ( used[to] == WHITE ) dfs(v, color, used, s, to);
    }
    s[color[x]] -= 1;
  }

int main()
{
  int n;
  vector<vector<int>> v;
  vector<int> color = vector<int>();
  vector<int> used;
  vector<int> s = vector<int>(MAXC, 0);
  cin >> n;

  v = vector<vector<int>>(n);
  used = vector<int>(n,WHITE);

  for ( int i = 0; i < n; ++i ) {
    int tmp;
    cin >> tmp;
    color.push_back(tmp);
  }

  for ( int i = 0; i < n-1; ++i ) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(v,color, used, s,  0);
  for ( int i = 0; i < n; ++i ) {
    if (used[i] == GOOD) cout << i+1 << endl;
  }

}
