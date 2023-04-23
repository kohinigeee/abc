#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int func(string& s) {
    int cnt = 0;
    int ans = 0;
    for ( int i = 0; i < s.size(); ++i ) {
        if ( s[i] == 'o' ) ++cnt;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    return ans;
}

int main() {
   int n;
   string s;

   cin >> n;
   cin >> s;
   string rev = s;

   for ( int i = 0; i < s.size(); ++i ) rev[i] = s[s.size()-1-i];

   int ans = 0;
   ans = max(ans, func(s));
   ans = max(ans, func(rev));

   if (ans == 0 ) ans = -1;
   cout << ans << endl;
}