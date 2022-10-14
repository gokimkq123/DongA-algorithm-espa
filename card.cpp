#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tu;
typedef vector<int> vc;

ofstream OUT("card.out");
ifstream INP("card.inp");

int cost[1001], dp[1001][2];

int solved(int n, bool check){
    if(n <= 0) return -INF;
    if(dp[n][check]) return dp[n][check];

    int a = -INF,b,c;
    if(!check) a = solved(n - 2, true);  // (i - 2) -> (i - 2)를 선택하면 (i - 2), (i - 3), (i - 4)중 (i - 2), (i - 4) 두개를 선택해버린다.
    b = solved(n - 3, false);
    c = solved(n - 4, false);

    return dp[n][check] = cost[n] + max({a, b, c});
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, t;
    INP >> t;

    while(t--) {
        memset(dp,0,sizeof(dp));
        INP >> n;

        for (int i = 1; i <= n; i++)
            INP >> cost[i];

        dp[1][0] = dp[1][1] = cost[1], dp[2][0] = dp[2][1] = cost[2], dp[3][0] = dp[3][1] = cost[3];
        OUT << solved(n, false) << "\n";

    }
}
