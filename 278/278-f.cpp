#include<iostream>
#include<vector>
#include<queue>

#define FIRST 1
#define SECOND 2
#define NOTDEF 100

using namespace std;

int main()
{
    int n;
    vector<vector<int>> s;

    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        string tmp; cin >> tmp;
        s.push_back(vector<int>{tmp[0]-'a', tmp.back()-'a'});
    }

    int max_states = 1<<n;

    vector<vector<int>> dp(max_states, vector<int>(26, NOTDEF));
    queue<pair<int,int>> que;

    for ( int i = 0; i < 26; ++i ) dp[0][i] = SECOND;
    for ( int i = 0; i < n; ++i ) {
        int state = 1<<i;
        dp[state][s[i][0]] = FIRST;
        que.push(make_pair(state, s[i][0]));
    }

    while(!que.empty()) {
        pair<int,int> front = que.front(); que.pop();
        int state = front.first, head = front.second;

        for ( int i = 0; i < n; ++i ) {
            int bit = 1<<i;
            if ( bit & state ) continue;
            int next_state = bit|state;

            if ( dp[next_state][s[i][0]] == NOTDEF ) que.push(make_pair(next_state, s[i][0]));
            if ( head == s[i][1] ) {
                if ( dp[state][head] == SECOND ) dp[next_state][s[i][0]] = min(FIRST, dp[next_state][s[i][0]]);
                else dp[next_state][s[i][0]] = min(SECOND, dp[next_state][s[i][0]]);
            }
        }
    }

    string ans = "Second";

    for ( int i = 0; i < n; ++i ) {
        if ( dp[max_states-1][s[i][0]] == FIRST ) ans = "First";
    }

    cout << ans << endl;
}