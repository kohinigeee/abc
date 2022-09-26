#include<vector>
#include<iostream>

#define WHITE 0
#define RED 1
#define BLUE 2
#define GREEN 3

using namespace std;

void dfs( int pos, int colour, vector<int>& used) {
  used[pos] = colour;
  for ( int i = 0; i < v[pos].size(); ++i ) {

  }
}
int main()
{
  vector<vector<int>> v;
  vector<int> used;
  int n,m;

  cin >> n >> m;
  v = vector<vector<int>>(n, vector<int>());
  used = vector<int>(n,WHITE);

  for ( int i = 0; i < m; ++i ) {
    int a,b;
    cin >> a >> b;
    --a, --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }


}
