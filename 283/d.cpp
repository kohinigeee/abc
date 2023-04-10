#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    string s; cin >> s;
    int balls[26];
    vector<vector<int>> histories;

    for ( int i = 0; i < 26; ++i ) balls[i] = 0;

    int ans = 0;
    for ( ans = 0; ans < s.size(); ans++ ) {
        if ( s[ans] == '(' ) {
            histories.push_back(vector<int>(26,0));
        } else if ( s[ans] == ')') {
            vector<int> back = histories.back();
            histories.pop_back();
            for ( int i = 0; i < 26; ++i ) {
                if ( back[i] == 1 ) balls[i] = 0; 
            }
            if ( histories.size() > 0 ) {
                vector<int>& tmp = histories.back();
                for ( int i = 0; i < 26; ++i ) {
                    tmp[i] = tmp[i]|back[i];
                }
            }
        } else {
            int val = s[ans]-'a';
            if ( balls[val] ) break;
            balls[val] = 1;
            if ( histories.size() > 0 ) {
                histories.back()[val] = 1;
            }
        }
    }

    if ( ans == s.size() ) cout << "Yes" << endl;
    else cout << "No" << endl;
}