#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll solve(int N, const vector<int>& f, int min1, int min2, int min3) {
    if (1 == N) {
        ll sum{ 0 };
        auto max = f[0];
        for (const auto& v : f)
        {
            sum += v;

            if (max < v) {
                max = v;
            }
        }

        sum -= max;

        return sum;
    }

    ll c3{ 4 };
    ll c2{ 4LL * ((N - 2) + (N - 1)) };
    ll c1{ static_cast<ll>(N - 2) * (4LL * (N - 1) + (N - 2)) };

    return c1 * min1 + c2 * min2 + c3 * min3;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> f(6);
    for (int i = 0; i < 6; ++i)
    {
        cin >> f[i];
    }

    auto min1 = f[0];
    for (const auto& v : f)
    {
        if (v < min1) {
            min1 = v;
        }
    }

    auto min2 = f[0] + f[1];
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if ((i != j) && !(5 == i + j)) {
                auto v = f[i] + f[j];
                if (v < min2) {
                    min2 = v;
                }
            }
        }
    }

    int min3{ 0 };
    min3 += min(f[0], f[5]);
    min3 += min(f[1], f[4]);
    min3 += min(f[2], f[3]);

    cout << solve(N, f, min1, min2, min3);

    return 0;
}