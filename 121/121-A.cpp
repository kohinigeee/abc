#include<iostream>

using namespace std;

int main()
{
  int H,W,h,w;
  int sum;

  cin >> H >> W >> h >> w;

  sum = W*h+(H-h)*w;
  cout << H*W-sum << endl;
}
