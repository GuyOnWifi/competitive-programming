#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;

        if (height > h)
            ans += 2;
        else
            ans++;
    }

    cout << ans << "\n";
}
