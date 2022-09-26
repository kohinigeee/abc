#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

#define PINF 1000000001
#define MINF -1000000001

typedef long long ll;

#define pi pair<long long, long long >

using namespace std;


int main()
{
  int n;
  vector<pair<int,int>> colour;
  vector<pi> dpc;
  vector<pi> dpp;

  cin >> n;
  for ( int i = 0; i < n+1; ++i ) colour.push_back(pi(PINF,MINF));
  for ( int i = 0; i < n; ++i ) {
    int x, c;
    cin >> x >> c;
    colour[c].first = min(colour[c].first, x);
    colour[c].second = max(colour[c].second, x);
  }

  dpc.push_back(pi(0,0));
  dpp.push_back(pi(0,0));

  for ( int i = 1; i <= n+1; ++i ) {
    if (colour[i].first == PINF && colour[i].second == MINF) {
      dpc.push_back(dpc[i-1]);
      dpp.push_back(dpp[i-1]);
    } else {
      int l = colour[i].first, r = colour[i].second;
      ll prec = dpc[i-1].first, prep = dpp[i-1].first;
      ll tmp, tmp2;

      if ( prep >= r ) tmp = prep - l + prec;
      else tmp = r-prep + (r-l) + prec;

      prec = dpc[i-1].second; prep = dpp[i-1].second;
      if ( prep >= r ) tmp = min( tmp, prep - l + prec);
      else tmp = min(r-prep + (r-l) + prec, tmp);

      prec = dpc[i-1].first; prep = dpp[i-1].first;
      if ( prep <= l ) tmp2 = r-prep + prec;
      else tmp2 = prep-l+(r-l) + prec;

      prec = dpc[i-1].second; prep = dpp[i-1].second;
      if ( prep <= l ) tmp2 = min(tmp2,r-prep + prec);
      else tmp2 = min(tmp2, prep-l+(r-l) + prec);

      dpc.push_back(pi(tmp,tmp2));
      dpp.push_back(pi(l,r));
    }
  }


  cout << min( abs(dpp[n].first) + dpc[n].first, abs(dpp[n].second)+dpc[n].second) << endl;
}
