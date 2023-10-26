#!/usr/bin/env python3

MOD = 10**9 + 7
S = input()
N = int(input())
cnts = [0] * 26
inversions = 0
for c in S:
    idx = ord(c) - ord('a')
    inversions += sum(cnts[idx+1:])
    cnts[idx] += 1

inversions *= N
g = 0
for c_1 in range(26):
    for c_2 in range(c_1+1, 26):
        g += cnts[c_1] * cnts[c_2]

inversions += g * N * (N - 1) // 2

print(inversions % MOD)

# // int main(){
# //     const int MOD = pow(10,9) + 7;
# //     long long int n{},inversions{};
# //     string s{};
# //     int cnts[26],idx{};
# //     cin>>s;
# //     cin>>n;
# //     for(int i=0;i<s.length();i++){
# //         idx = (int)s[i]-(int)'a';
# //         for(int j =idx+1;j<26;j++){
# //             inversions+=s[j];
# //         }
# //         cnts[idx] += 1;
# //     }
# //     inversions*=n;
# //     int g{};

# //     for(int i=0;i<26;i++){
# //         for(int j=1;j<26;j++){
# //             g+=cnts[i]*cnts[j];
# //         }
# //     }
# //     inversions +=g*n*(n-1)/2;
# //     cout<<inversions%MOD; 
# //     return 0;
# // }