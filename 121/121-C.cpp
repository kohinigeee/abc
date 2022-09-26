#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

struct Set{
  int a,b;

  Set(int aa, int bb ) {
    a = aa;
    b = bb;
  }

  Set() {
    a = 0;
    b = 0;
  }
};

bool operator< ( Set x, Set y ) {
  return x.a < y.a;
}

int main() {
  vector<Set> vec = vector<Set>();
  int N,M;  
  long long  sum = 0;
  int cnt = 0;

  cin >> N >> M;
  while(N--) {
    int a,b;
    scanf("%d%d", &a,&b);
    vec.push_back(Set(a,b));
  }

  sort(vec.begin(), vec.end());

  for ( int i = 0; i < vec.size(); ++i ) {
    if ( cnt + vec[i].b < M ) {
      sum += (long long)vec[i].a * vec[i].b;
      cnt += vec[i].b;
    } else {
      sum += (long long)(M-cnt) * vec[i].a;
      break;
    }
  }

  cout << sum << endl;
}
