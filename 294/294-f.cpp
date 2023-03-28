#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

#define EXE_NO 100

int main()
{
    long long n, m, k;
    vector<long long> A, B, C, D;

    cin >> n >> m >> k;
    A = B = vector<long long>(n);
    C = D = vector<long long>(m);

    for ( int i = 0; i < n; ++i ) {
        cin >> A[i] >> B[i];
    }
    for ( int i = 0; i < m; ++i ) {
        cin >> C[i] >> D[i];
    }

    double minx = 0;
    double maxx = 1;
    for ( int i = 0; i < EXE_NO; ++i ) {
        double x = (minx+maxx)/2;

        vector<double> w(n);
        for ( int i = 0; i < n; ++i ) {
            w[i] = A[i]-B[i]*(x/(1-x));
        }

        long long cnt = 0;
        sort(w.begin(), w.end());
        for ( int i = 0; i < m; ++i ) {
            double wm = C[i]-D[i]*(x/(1-x));
            // cnt += w.end()-lower_bound(w.begin(), w.end(), -wm);
            cnt += n-(lower_bound(w.begin(), w.end(), -wm)-w.begin());
        }

        if ( cnt < k ) maxx = x;
        else minx = x;
    }

    printf("%.20lf\n", maxx*100);    
}