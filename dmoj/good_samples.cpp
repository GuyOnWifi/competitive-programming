// CCC '22 S3 - Good Samples

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  int needed = K - N;
  if (needed < 0) {
    for (int i = 0; i < K; i++)
      cout << "1 ";
    for (int i = 0; i < N - K; i++)
      cout << "3 ";
    return 0;
  }

  if (needed % 2 == 1) {
    int more = (needed - 1) / 2;
    if (more > ceil((float)(N - 3) / 2)) {
      cout << -1;
      return 0;
    }

    cout << "2 1 ";
    for (int i = 0; i < more; i++) {
      cout << "2 1 ";
    }

    for (int i = 0; i < (N - 2 - 2 * more); i++) {
      cout << "1 ";
    }
  } else {
    int more = needed / 2;

    if (more > ceil((float)(N - 2) / 2)) {
      cout << -1;
      return 0;
    }

    cout << "1 ";
    for (int i = 0; i < more; i++) {
      cout << "2 1";
    }

    for (int i = 0; i < (N - 1 - 2 * more); i++) {
      cout << "1 ";
    }
  }
}
