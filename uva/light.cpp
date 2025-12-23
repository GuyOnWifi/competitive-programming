#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned int n;
  while (cin >> n && n != 0) {

    long long root = round(sqrt(n));

    if (root * root == n) {
      cout << "yes" << "\n";

    } else {
      cout << "no" << "\n";
    }
  }
}
