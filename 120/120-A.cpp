#include <iostream>

using namespace std;

int main() {
  int a,b,c;

  cin >> a >> b >> c;
  std::cout << ((b/a) >= c ? c : b/a) << "\n";
}
