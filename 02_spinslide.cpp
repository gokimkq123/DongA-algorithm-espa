#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef pair<string,int> pa;
typedef tuple<string,string,string> tu;
typedef vector<tu> vc;

int main() {
    ofstream cout("spinslide.out");
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t, n, m;
    char board[101][101];

    auto rotate = [&](){
        char board_temp[101][101];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                board_temp[i][j] = board[i][j];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                board[i][j] = board_temp[n-1-j][i];
        }
    };

    auto down = [&](){
        for(int k=0;k<n;k++) {
            for (int i=n-2;i>=0;i--) {
                if(board[i][k] == '.') continue;

                for (int j=n-1;j>i;j--) {
                    if(board[j][k] == '.'){
                        board[j][k] = board[i][k];
                        board[i][k] = '.';
                        break;
                    }
                }
            }
        }
    };

    auto print = [&](int end){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << board[i][j];
            cout << "\n";
        }

    };

    auto INPUT = [&](){
        ifstream file("spinslide.inp");

        string temp;
        file >> t >> ws;

        for(int TestCase=1;TestCase<=t;TestCase++){
            file >> n >> m >> ws;

            for(int i=0;i<n;i++){
                file >> temp >> ws;

                for(int j=0;j<n;j++)
                    board[i][j] = temp[j];
            }
            while(m--) {
                rotate();
                down();
            }

            if(TestCase > 1) cout << "\n";
            cout << "Case #" << TestCase << ":\n";
            print(TestCase);
        }
        file.close();
    };

    INPUT();
}
