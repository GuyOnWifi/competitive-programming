// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=353

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cout << fixed << setprecision(6);

  while (cin >> N && N != 0) {
    vector<int> arr;
    for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      arr.push_back(num);
    }

    int num_coprime = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        if (gcd(arr[i], arr[j]) == 1) {
          num_coprime++;
        }
      }
    }
    int total = N * (N - 1) / 2;

    if (num_coprime == 0) {
      cout << "No estimate for this data set." << "\n";
      continue;
    }
    double pi = sqrt((double)total * 6.0 / num_coprime);
    cout << pi << "\n";
  }
}
