#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<string> v= {"and", "not", "that", "the", "you"};

    int n;
    cin >> n;

    string ans = "No";
    for ( int i = 0; i < n; ++i ) {
        string s; cin >> s;
        for ( auto tmp : v ) if ( s == tmp ) ans = "Yes"; 
    }

    cout << ans << endl;
}