#include <bits/stdc++.h>

using namespace std;
typedef __int128_t int128;

long long binary_search(long long l, long long r, long long target) {
  while (l < r) {

    long long mid = l + (r - l) / 2;

    int128 total = (int128)mid * (mid + 1) / 2;
    if (total <= target) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  long long n, k;
  cin >> n >> k;

  if (n == 1) {
    cout << "0" << endl;
    return 0;
  }

  int128 total = (int128)(k) * (k - 1) / 2 + 1;
  if (total < n) {
    cout << "-1" << endl;
    return 0;
  }

  long long remove = binary_search(0, k - 1, total - n);
  cout << k - remove << endl;
}
