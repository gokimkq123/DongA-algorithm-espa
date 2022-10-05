#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<ll,ll,ll,ll> tu;
typedef vector<pa> vc;

ofstream Out("gridpath.out");
ll board[201][201], n, m, path[201 * 201];

void route(ll x){
    if(x == 0){
        Out << "(0 0)"<< "\n";
        return;
    }

    route(path[x]);
    Out << "(" << x / m << " " << x % m << ")\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ifstream file("gridpath.inp");

    file >> n >> m;

    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            file >> board[i][j];

            if(board[i][j] == -1) board[i][j] = INF;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!i && !j) continue;
            else if(!i) board[i][j] += board[i][j - 1], path[i * m + j] = (i * m + (j - 1));   // 첫 행
            else if(!j) board[i][j] += board[i - 1][j], path[i * m + j] = ((i - 1) * m + j);   // 첫 열
            else{
                if(board[i - 1][j] > board[i][j - 1]) board[i][j] += board[i][j - 1], path[i * m + j] = (i * m + (j - 1));
                else board[i][j] += board[i - 1][j], path[i * m + j] = (i - 1) * m + j;
            }
        }
    }


    if(board[n - 1][m - 1] >= INF) Out << "No path.";
    else{
        Out << board[n - 1][m - 1] << "\n";
        route((n - 1) * m + (m - 1));
    }

}