#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

vector<string> masu(9);

int main()
{
    set<set<pair<int,int>>> st;
    auto valid = [](int x, int y) {
        return ( min(max(x,0), 8) == x && min(max(y,0),8) == y && masu[x][y] == '#');
    };

    for ( auto& s : masu ) cin >> s;

    int ans = 0;

    for ( int i = 0; i < 9; ++i ) {
        for ( int j = 0; j < 9; ++j ) {
            for ( int dx = -8; dx < 9; ++dx ) {
                for ( int dy = -8; dy < 9; ++dy ) {
                    
                    if ( dx == 0 && dy == 0 ) continue;
                    // if ( !dx && !dy ) continue;

                    int i2 = i+dx, j2 = j+dy;
                    int i3 = i2-dy, j3 = j2+dx;
                    int i4 = i3-dx, j4 = j3-dy;
                    if ( valid(i, j) && valid(i2, j2) && valid(i3,j3) && valid(i4,j4) ) {
                        set<pair<int,int>> s;
                        s.insert(make_pair(i,j));
                        s.insert(make_pair(i2,j2));
                        s.insert(make_pair(i3,j3));
                        s.insert(make_pair(i4,j4));
                        st.insert(s);
                        ++ans;
                    } 
                }
            }
        }
    }
    // cout << st.size() << endl;
    cout << ans/4 << endl;
}