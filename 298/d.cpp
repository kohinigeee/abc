#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXV (200000+10)

int main()
{
    int n, q;

    cin >> n >> q;
    vector<set<int>> s(MAXV+1, set<int>()); // 番号iが入ってるbox
    vector<multiset<int>>  boxs(n+1); //box i に入ってる数

    for ( int i = 0; i < q; ++i ) {
        int cmd;

        cin >> cmd;
        if ( cmd == 1 ) {
            int a, b; cin >> a >> b;
            s[a].insert(b);
            boxs[b].insert(a);
        } else if ( cmd == 2 ) {
            int a; cin >> a;
            for ( auto it = boxs[a].begin(); it != boxs[a].end(); ++it ) cout << (*it) << " "; cout << endl; 
        } else if ( cmd == 3 ) {
            int a; cin >> a;
            for ( auto it = s[a].begin(); it != s[a].end(); ++it ) cout << (*it) << " "; cout << endl; 
        }
    }
}