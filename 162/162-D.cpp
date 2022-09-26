#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Ele {
public:
  int r,g,b;

  Ele(int tmpr,int tmpg, int tmpb) {
    r = tmpr;
    g = tmpg;
    b = tmpb;
  }
};

int main() {
  int ar = 0, ag = 0, ab = 0;
  int r = 0, g = 0, b = 0;
  vector<Ele> eles = vector<Ele>();
  string s;
  int n;

  cin >> n;
  cin >> s;

  for ( int i = 0; i < n; ++i ) {
    if (s[i] =='R') ar += 1;
    else if (s[i] == 'G') ag += 1;
    else ab += 1;
  }

  for ( int i = 0; i < n; ++i ) {
    if (s[i] =='R') r += 1;
    else if (s[i] =='G') g += 1;
    else b += 1;
    Ele tmp  = Ele(ar-r,ag-g,ab-b);
    eles.push_back(tmp);
  }


  long long ans = 0;
  for ( int i = 0; i < n; ++i ) {
      if (s[i] == 'R') {
          for ( int j = i+1; j < n; ++j ) {
              if (s[j] == 'G') {
                  ans += eles[j].b;
                  int tmp = j*2-i;
                  if ( (tmp < n )&& (s[tmp] == 'B') ) ans -= 1;
                }
              if (s[j] == 'B') {
                  ans += eles[j].g;
                  int tmp = j*2-i;
                  if ( (tmp < n )&& (s[tmp] == 'G') ) ans -= 1;
                  }
                }
      }
      else if (s[i] == 'G') {
          for ( int j = i+1; j < n; ++j ) {
              if (s[j] == 'B') {
                  ans += eles[j].r;
                  int tmp = j*2-i;
                  if ( (tmp < n )&& (s[tmp] == 'R') ) ans -= 1;
                }
              if (s[j] == 'R') {
                  ans += eles[j].b;
                  int tmp = j*2-i;
                  if ( (tmp < n )&& (s[tmp] == 'B') ) ans -= 1;
                  }
                }
      }
      else {
          for ( int j = i+1; j < n; ++j ) {
              if (s[j] == 'R') {
                  ans += eles[j].g;
                  int tmp = j*2-i;
                  if ( (tmp < n )&& (s[tmp] == 'G') ) ans -= 1;
                }
              if (s[j] == 'G') {
                  ans += eles[j].r;
                  int tmp = j*2-i;
                  if ( (tmp < n )&& (s[tmp] == 'R') ) ans -= 1;
                  }
                }
      }
    }
  cout << ans << endl;
}
