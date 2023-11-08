#include<bits/stdc++.h>

using namespace std;

int main() {
    constexpr long long MOD = 1000000007;
    vector<int> cnts(26, 0);
    long long inversions = 0,N{};
    string s{};
    cin>>s;
    cin>>N;
    for (char c : s) {
        int idx = c - 'a';
        inversions += accumulate(cnts.begin() + idx + 1, cnts.end(), 0);
        ++cnts[idx];
    }

    inversions *= N;
    long long g = 0;
    for (int c_1 = 0; c_1 < 26; ++c_1) {
        for (int c_2 = c_1 + 1; c_2 < 26; ++c_2) {
        g += (((cnts[c_1] * cnts[c_2])%MOD)%MOD)%MOD;
        g%=MOD;
        }
    }

    inversions +=( g * N * (N - 1) / 2)%MOD;

    cout << (inversions % MOD)<< '\n';

    return 0;
}
