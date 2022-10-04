#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tu;
typedef vector<pa> vc;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ofstream cout("stairs.out");
    int t, m, f, n;

    ifstream file("stairs.inp");

    file >> t;

    while(t--){

        file >> m >> f >> n;

        cout << (n - 1) / (m - 1) + 1 << "\n";
    }

    file.close();
}

