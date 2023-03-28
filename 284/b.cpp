#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int cnt = 0;

        while(n--) {
            long long a; cin >> a;
            if ( a%2 ) ++cnt;
        }
        cout << cnt << endl;
    }
}