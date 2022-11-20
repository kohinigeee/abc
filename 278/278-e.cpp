#include<iostream>
#include<vector>

using namespace std;

using ll = long long;
using vii = vector<vector<int>>;

int main()
{
    int H, W, n, h, w;

    cin >> H >> W >> n >> h >> w;
    vector<int> sumn(n, 0);
    vii masu(H, vector<int>(W, -1));

    for ( int i = 0; i < H; ++i ) {
        for ( int j = 0; j < W; ++j ) {
            cin >> masu[i][j];
            --masu[i][j];
            sumn[masu[i][j]] += 1;
        }
    }

    for ( int i = 0; i <= H-h; ++i ) {
        vector<int> cnt(n, 0);
        for ( int k = 0; k < w; ++k ) {
            for ( int t = 0; t < h; ++t ) {
                cnt[masu[i+t][k]] += 1;
            }
        }
        ll ans = 0;
        for ( int i = 0; i < n; ++i ) {
            if ( sumn[i]-cnt[i] > 0 ) ans += 1;
        }
        cout << ans << " ";

        for ( int j = 0; j+w < W; ++j ) {
           ll ans = 0;
           for ( int k = 0; k < h; ++k ) {
            cnt[masu[i+k][j]] -= 1;
            cnt[masu[i+k][j+w]] += 1;
           } 
           for ( int i = 0; i < n; ++i ) {
            if ( sumn[i]-cnt[i] > 0 ) ans += 1;
           }
           cout << ans << " ";
        }
        cout << endl;
    }
}