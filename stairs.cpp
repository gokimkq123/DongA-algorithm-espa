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

/*
F는 상관없다.
왜냐하면 엘리베이터를 한번 타서 1층으로 가서 M층까지 오르면 (M - 1)만큼 계단을 오른다.
이때 N을 (M - 1)으로 나눈 몫이 a이라 하자.
a는 엘리베이터를 탄 횟수이고, 현재 1층이기 때문에 무조건 F층에 간다.

수식 : N / (M - 1) <= ans
*/
