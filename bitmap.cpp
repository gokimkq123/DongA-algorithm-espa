#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<ll,ll,ll,ll> tu;
typedef vector<int> vc;

char Map;
string temp, board, ans;
int n, m, idx;

void B(int stRow, int stCol, int enRow, int enCol){
    if(stRow > enRow || stCol > enCol) return;
    int size = (enRow - stRow + 1) * (enCol - stCol + 1), cnt = 0;

    for(int i = stRow; i <= enRow; i++){
        for(int j = stCol; j <= enCol; j++){
            cnt += (board[i * m + j] - '0');
        }
    }

    if(cnt == size) ans += '1';
    else if(cnt == 0) ans += '0';
    else{
        ans += 'D';
        int Row = (stRow + enRow) / 2, Col = (stCol + enCol) / 2;
        B(stRow, stCol, Row, Col);
        B(stRow, Col + 1, Row, enCol);
        B(Row + 1, stCol, enRow, Col);
        B(Row + 1, Col + 1, enRow, enCol);
    }
}

void D(int stRow, int stCol, int enRow, int enCol) {
    if(stRow > enRow || stCol > enCol) return;
    char check = board[idx++];

    if(check == 'D'){
        int Row = (stRow + enRow) / 2, Col = (stCol + enCol) / 2;
        D(stRow, stCol, Row, Col);
        D(stRow, Col + 1, Row, enCol);
        D(Row + 1, stCol, enRow, Col);
        D(Row + 1, Col + 1, enRow, enCol);
    }
    else{
        for(int i = stRow; i <= enRow; i++)
            for(int j = stCol; j <= enCol; j++)
                ans[i * m + j] = check;
    }
}


int main() {
    ofstream cout("bitmap.out");

    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ifstream file("bitmap.inp");

    auto space = [&](int &x){
        int num = x;
        while(num < 1000){
            cout << " ";
            num *= 10;
        }
        return x;
    };

    while(1){
        file >> Map;
        if(Map != '#') return 0;

        file >> n >> m;
        file >> board;

        if(Map == 'B'){
            ans.clear();
            while(board.size() != n * m){
                file >> temp;
                board += temp;
            }
            B(0, 0, n - 1, m - 1);
        }
        else{
            idx = 0;
            ans.resize(n * m);
            D(0, 0, n - 1, m - 1);
        }
        cout << (Map == 'B'? "D" : "B") << space(n) << space(m);

        for(int i = 0; i < int(ans.size()); i++) {
            if (i % 50 == 0) cout << "\n";
            cout << ans[i];
        }
        cout << "\n";

    }
    file.close();
}