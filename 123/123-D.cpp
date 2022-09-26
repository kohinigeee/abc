#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

#define INF 100000000000LL

using namespace std;

long long dif ( vector<long long> vec, int i ) {
  if ( i+1 >= vec.size() ) return -INF;
  return vec[i]-vec[i+1];
}

int main()
{
  vector<long long> A = vector<long long>(), B = vector<long long>(), C = vector<long long>();
  int x, y, z, k;
  int apos, bpos, cpos;
  apos = bpos = cpos = 0;

  cin >> x >> y >> z >> k;

  while(x--) {
    int tmp;
    scanf("%d", &tmp);
    A.push_back(tmp);
  }

  while(y--) {
    int tmp;
    scanf("%d", &tmp);
    A.push_back(tmp);
  }

  while(z--) {
    int tmp;
    scanf("%d", &tmp);
    A.push_back(tmp);
  }

  sort(A.begin(), A.end(), greater<long long>());
  sort(B.begin(), B.end(), greater<long long>());
  sort(C.begin(), C.end(), greater<long long>());

  
}
