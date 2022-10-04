#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

int main() {
    ofstream cout("gain.out");

    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t, n;

    ifstream file("gain.inp");

    file >> t;

    while(t--){
        file >> n;
        vector<long long> v(n);

        for(auto &i : v)
            file >> i;

        sort(v.begin(),v.end());

        cout << -(v[0] + v[1]) + (v[n - 2] + v[n - 1]) << "\n";

    }
    file.close();
}
