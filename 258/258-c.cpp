#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string s;
    int n, q;

    int xcnt = 0;

    cin >> n >> q;
    cin >> s;

    while(q--) {
        int cmd, x;
        cin >> cmd >> x;

        if ( cmd == 1 ) {
            xcnt += x;
            xcnt %= n;
        } else {
            --x;
            x -= xcnt;
            if ( x < 0 ) x+= n;
            x %= n;
            cout << s[x] << endl;
        }
    }
}