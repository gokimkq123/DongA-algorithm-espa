#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<ll,ll,ll,ll> tu;
typedef vector<int> vc;

int ans[1001];
int n;

void Tree(int st, int en, vc &v, int deep){
    if(st > en) return;

    int MAX =  -1, idx;
    for(int i=st;i<=en;i++)
        if(MAX < v[i]) MAX = v[i], idx = i;

    ans[MAX] = deep;

    Tree(st, idx - 1, v, deep + 1);
    Tree(idx + 1, en, v, deep + 1);
}

int main() {
    ofstream cout("permutation.out");
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ifstream file("permutation.inp");
    int t;
    file >> t;

    while(t--){
        file >> n;
        vc v(n);

        for(auto &i : v)
            file >> i;

        Tree(0, n - 1, v, 0);

        for(auto &i : v)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
