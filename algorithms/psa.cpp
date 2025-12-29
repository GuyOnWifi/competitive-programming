#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> arr;
  vector<int> psa(arr.size() + 1, 0);
  for (int i = 1; i <= arr.size(); i++) {
    psa[i] = psa[i - 1] + arr[i - 1];
  }

  int l = 1, r = 3; // 1-indexed
  int sum = psa[r] - psa[l - 1];
}
