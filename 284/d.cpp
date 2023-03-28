#include<iostream>
#include<vector>
#include<cmath>

#define M 3000000

using namespace std;
using ll = long long;

int is_prime[M+1];

int main()
{
    vector<ll> primes;
    for ( ll i = 0; i <=M; ++i ) is_prime[i] = 1; 
    for ( ll i = 2; i <= M; ++i ) {
        if ( is_prime[i] == 0 ) continue;
        primes.push_back(i);
        for ( ll j = i*2; j <= M; j += i ) is_prime[j] = 0; 
    }

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> ans;
        ll ansp, ansq;
        for ( auto p : primes ) {
            if ( n % p == 0 ) {
                ansp = p;
                n /= p;
                break;
            } 
        }

        if ( n % ansp == 0 ) {
            ansq = n/ansp;
        } else {
            ll tmpn = sqrt(n);
            for ( ll i = max(2LL, tmpn-5); i <= tmpn+5; ++i ) {
                if ( i*i == n ) {
                    ansq = i;
                    swap(ansp, ansq);
                    break;
                }
            }
        }
        cout << ansp << " " << ansq << endl;
    }
}