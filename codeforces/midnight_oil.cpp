// https://codeforces.com/contest/165/problem/B

#include <bits/stdc++.h>

using namespace std;

long long calc(int v, int k) {
  long long factor = 1;
  long long sum = 0;
  while (true) {
    long long n = v / factor;
    if (n == 0)
      break;
    sum += n;
    factor *= k;
  }
  return sum;
}

int binary_search(int l, int r, int target, int k) {
  long long ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (calc(mid, k) >= target) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;

  cout << binary_search(1, n, n, k) << endl;
}
