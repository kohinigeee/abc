#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

pii move( pii& p, char ch ) {
    pii tmp = p;
    if ( ch == 'U' ) {
        tmp.first -= 1;
    } else if ( ch == 'D' ) tmp.first += 1;
    else if ( ch == 'L' ) tmp.second -= 1;
    else if ( ch == 'R' ) tmp.second += 1;
    return tmp;
}

int main()
{
    int h, w;
    vvi masu;
    vector<string> G;
    bool f = true;

    cin >> h >> w;
    for ( int i = 0; i < h; ++i ) {
        string tmp; cin >> tmp;
        G.push_back(tmp);
    }

    masu = vector<vector<int>>(h, vector<int>(w,0));
    pii p = make_pair(0,0);

    while(1) {
        masu[p.first][p.second] = 1;
        pii next = move(p, G[p.first][p.second]);
        if ( next.first < 0 || next.second < 0 || next.first >= h || next.second >= w ) break;
        if ( masu[next.first][next.second] == 1 ) { f = false; break; }
        p = next;
    }

    if ( f ) cout << p.first+1 << " " << p.second+1 << endl;
    else cout << -1 << endl;
}