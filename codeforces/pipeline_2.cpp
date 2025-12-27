#include <iostream>

using namespace std;

// Using __int128 for GCC to handle 10^18 calculations safely
typedef __int128 int128;

long long binary_search(long long l, long long r, long long target) {
  while (l < r) {
    long long mid = l + (r - l) / 2;
    // Calculate sum of net gains from 1 to mid: (mid * (mid + 1)) / 2
    int128 sum_removed = (int128)mid * (mid + 1) / 2;

    if (sum_removed <= (int128)target) {
      l = mid + 1; // This amount can be removed, try to remove more
    } else {
      r = mid; // This amount is too much to remove
    }
  }
  return l;
}

int main() {
  long long n, k;
  if (!(cin >> n >> k))
    return 0;

  // Case 1: Already have enough pipes
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  // Maximum net gain using all splitters (2 to k)
  // Formula: 1 + (k-1) + (k-2) + ... + 1
  int128 max_total = (int128)k * (k - 1) / 2 + 1;

  if (max_total < n) {
    cout << -1 << endl;
    return 0;
  }

  // target is the "excess" pipes we don't need
  long long excess = (long long)(max_total - n);

  // We search for how many small splitters (starting from gain 1) we can remove
  long long l = binary_search(0, k - 1, excess);

  // The number of splitters used is (k - l)
  cout << k - l << endl;

  return 0;
}
