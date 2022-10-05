#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tu;
typedef vector<int> vc;

int main() {
    ofstream cout("coin.out");
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ifstream cin("coin.inp");

    int dp[101][101][101], t, a, b, c;

    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            for(int k=0;k<101;k++)
                dp[i][j][k] = 1;

    auto check = [&](int i, int j, int k){
        for(int idx=1;idx<=3;idx++){
            if(i - idx >= 0 && dp[i - idx][j][k] == -1) return 1;
            if(j - idx >= 0 && dp[i][j - idx][k] == -1) return 1;
            if(k - idx >= 0 && dp[i][j][k - idx] == -1) return 1;
        }
        return -1;
    };

    dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[1][0][0] = -1;

    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            for(int k=0;k<101;k++)
                if(dp[i][j][k] != -1)
                    dp[i][j][k] = check(i, j, k);


    cin >> t;

    while(t--){
        cin >> a >> b >> c;

        cout << "(" << a << " " << b << " " << c << ") : ";
        cout << dp[a][b][c] << "\n";
    }

}