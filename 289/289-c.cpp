#include<iostream>
#include<vector>

using namespace std;
int n, m;
vector<vector<int>> s;

bool isOk(int x) {
    vector<bool> includes(n, false);
    
    for ( int i = 0; i < m; ++i ) {
        int tmp = (x>>i)&1;
        if ( tmp == 0 ) continue; 
        for ( auto v : s[i] ) includes[v-1] = true;
    }
    for ( auto v : includes ) if (!v) return false;

    return true;
}

int main()
{
   cin >> n >> m;
   for ( int i = 0; i < m; ++i )  {
    int c; cin >> c;
    vector<int> tmps(c);
    for ( int j = 0; j < c; ++j ) {
        cin >> tmps[j];
    }
    s.push_back(tmps);
   }

   int sum = 1<<m;
   int ans = 0;
   for ( int i = 0; i < sum; ++i ) {
    if (isOk(i)) ++ans;
   }
   cout << ans << endl;
}