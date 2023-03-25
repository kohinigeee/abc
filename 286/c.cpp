#include<iostream>
#include<deque>

using namespace std;

using ll = long long;

int calc(deque<char>& deq) {
    int cnt = 0;
    int l = 0; int r = deq.size()-1;
    while( l < r ) {
        if ( deq[l] != deq[r] ) ++cnt;
        ++l; --r;
    }
    return cnt;
}

int main()
{
    ll n, a, b;
    string s;
    deque<char> deq;
    ll ans = (1LL<<60);

    cin >> n >> a >> b;
    cin >> s;
    for ( char ch : s ) deq.push_back(ch);

    for ( int i = 0; i < n; ++i ) {
        ll tmp = a*i+calc(deq)*b;
        ans = min(ans, tmp);
        deq.push_back(deq.front());
        deq.pop_front();
    }

    cout << ans << endl;
}