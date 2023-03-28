#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int r = 0;
    map<long long,long long> mp;

    mp[r] = 1;
    for ( int i = 0; i < s.size(); ++i ) {
        int no = s[i]-'0';
        r = r^(1<<no);
        
        if ( mp.find(r) == mp.end() ) mp[r] = 0;
        mp[r] += 1;
    }

    long long ans = 0;
    for ( auto it = mp.begin(); it != mp.end(); ++it ) {
        long long cnt = it->second;
        ans += cnt*(cnt-1)/2;
    }
    cout << ans << endl;
}