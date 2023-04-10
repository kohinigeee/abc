#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n;
    set<string> s;

    int no = -1, maxscore = -1;

    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        string tmps; cin >> tmps;
        int t; cin >> t;
        if ( s.find(tmps) != s.end() ) continue;
        s.insert(tmps);

        if ( maxscore < t ) {
            no = i;
            maxscore = t;
        }
    }

    cout << no+1 << endl;
}