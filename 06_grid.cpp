#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll,ll> tu;
typedef vector<int> vc;

int main() {
    ofstream cout("grid.out");
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ifstream file("grid.inp");

    int n, m, k, a, t;
    file >> t;
    

    while(t--){
        ll sum1=0,sum2=0,c1=0,c2=0, end1, end2;
        file >> n >> m >> k;

        for(int i=0;i<k;i++){
            file >> a;

            ll col = a / n, row = a / m;
            if(col > 1)   sum1 += col;
            if(col > 2)   end1 = 1;
            if(row > 1)   sum2 += row;
            if(row > 2)   end2 = 1;

        }

        if((sum1 >= m && (m % 2 == 0 || end1 == 1))||(sum2 >= n &&(n % 2 == 0 || end2))) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    file.close();
    
}
