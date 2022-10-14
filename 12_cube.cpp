#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tu;
typedef vector<int> vc;

int dp[201][201][201];

int cube(int w, int l, int h){
    if(w == l && l == h) return 1;                       // 기저 사례 1 : 이미 정육면체
    if(w == 1 || l == 1 || h == 1) return w * h * l;     // 기저 사례 2 : 어떤 곳이 1일때 자를 경우는 부피 만큼임

    int &ret = dp[w][l][h], Min_w, Min_l, Min_h;
    if(ret != -1) return ret;

    Min_w = Min_l = Min_h = INF;

    for(int i=1;i<=w/2;i++)            // 가로
        Min_w = min(Min_w, cube(i, l, h) + cube(w - i, l, h));
    for(int i=1;i<=l/2;i++)              // 세로
        Min_l = min(Min_l, cube(w, i, h) + cube(w, l - i, h));
    for(int i=1;i<=h/2;i++)              // 높이
        Min_h = min(Min_h, cube(w, l, i) + cube(w, l, h - i));

    ret = min({Min_w, Min_l, Min_h});

    dp[w][l][h] = dp[w][h][l] = dp[l][w][h] = dp[l][h][w] = dp[h][w][l] = dp[h][l][w] = ret;

    return ret;
}


int main() {
    ofstream OUT("cube.out");
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ifstream INP("cube.inp");

    memset(dp, -1, sizeof(dp));

    int t, w, l, h;
    INP >> t;

    while(t--){
        INP >> w >> l >> h;

        OUT << cube(w, l, h) << "\n";
    }
}
