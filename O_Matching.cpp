#include<bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;
const int N = 22; // Adjusted according to the problem constraint (1≤N≤21)
vector<vector<int>> a(N, vector<int>(N));
vector<int> dp(1 << N, -1); // DP array to store intermediate results

int solve() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    function<int(int)> f = [&](int mask) {
        int index = __builtin_popcount(mask), answer = 0;
        if(index == N) return 1; //ie all have been paired succesfully
        if(dp[mask] != -1) return dp[mask]; // if alrady calculated, use it directly

        for(int i = 0; i < N; i++) { //go through all women
            if(!(mask & (1 << i)) && a[index][i] == 1) { //if compatible
                answer = (answer + f(mask | (1 << i))) % mod; //find number of pairs wrt remaining women
            }
        }

        return dp[mask] = answer; // dp[mask], each mask value is the index of a women, 
        //dp[mask] stores the number of ways to pair the remaining women with men
        //suppose we pair nth women, and 5 women left, and w ways to pair then, now when we
        //move to the n+1 th women, we still have 5 women left, and now there'll be some diff number of ways to pair them

    };

    return f(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }

    return 0;
}



