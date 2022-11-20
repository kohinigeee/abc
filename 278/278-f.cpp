#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    vector<string> words;
    vector<vector<int>> link_tail; //word[i]のつぎに出せるwordのindex

    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        string tmp; cin >> tmp;
        words.push_back(tmp);
    }

    link_tail = vector<vector<int>>(n);
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( i == j ) continue;
            if ( words[i].back() == words[j].back() ) link_tail[i].push_back(j);
        }
    }

    int lim = 1<<n;

    vector<vector<int>> dp(lim, vector<int>(n,0));

    for ( int i = 0; i < n; ++i ) {
        int sta = 1<<i;
        for ( int j = 0; j < n; ++j ) {
        }
    }


}