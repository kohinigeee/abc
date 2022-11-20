#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>

#define MAXN 500000

using namespace std;
using ll = long long;

int main()
{
    ll cnt = 0;
    vector<ll> v(MAXN+1), p(MAXN+1);
    map<ll, ll> book; 

    v[cnt] = -1;
    p[cnt++] = -1;

   ll q, now;
   now = 0;
   cin >> q;

   while(q--) {
    char cmd[10]; ll x;

    cin >> cmd;

    if ( cmd[0] == 'A' ) {
        cin >> x;
        p[++cnt] = now;
        v[cnt] = x;
        now = cnt;
    } else if ( cmd[0] == 'D' ) {
        if ( p[now] != -1 ) now = p[now];
    } else if ( cmd[0] == 'S' ) {
        cin >> x;
        book[x] = now;
    } else if ( cmd[0] == 'L' ) {
        cin >> x;
        ll tmp = 0;
        if ( book.find(x) != book.end() ) tmp = book[x]; 
        now = tmp; 
    }
    
    cout << v[now] << endl;
   } 
}