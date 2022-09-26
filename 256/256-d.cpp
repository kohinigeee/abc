#include<iostream>
#include<vector>

using namespace std;

#define R 200000

int main()
{
    int n;
    vector<int> d(R+2, 0);

    vector<int> l;
    vector<int> r;

    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;

        d[x] += 1;
        d[y] -= 1;
    }

    for ( int i = 1; i <= R; ++i ) {
        d[i] += d[i-1];
    }

    for ( int i = 1; i <= R+1; ++i ) {
        if ( d[i-1] == 0 && d[i] > 0 ) {
            l.push_back(i);
        }
    }

    for ( int i = 1; i <= R+1; ++i ) {
        if ( d[i-1] > 0 && d[i] == 0 ) {
            r.push_back(i);
        }
    }

    for ( int i = 0; i < l.size(); ++i ) {
        cout << l[i] << " " << r[i] << endl;
    }
}