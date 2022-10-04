#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll,ll> tu;
typedef vector<int> vc;

int main() {
    ofstream cout("snail.out");
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ifstream file("snail.inp");

    ll t, a, b, n, MAX = -1, x1, x2, y1, y2;

    auto solved = [&](ll A, ll B, ll N) -> tu {
        ll startVal, R = 0, L = n - 1, D = n - 1, U = 0, cur = 0, AX = -1, AY = -1, BX = -1, BY = -1;

        while (N > 0) {
            startVal = 4 * ((n * cur) - (cur * cur)) + 1;

            if (AX == -1 && AY == -1) {
                if (startVal + (N - 1) >= A) AX = R, AY = (A - startVal) + 2 * cur - R;
                else if (startVal + 2 * (N - 1) >= A) AX = (A - startVal) + 2 * cur - D, AY = D;
                else if (startVal + 3 * (N - 1) >= A) AX = L, AY = 2 * cur - L - (A - startVal) + (n - 1 - 2 * cur) * 4;
                else if (startVal + 3 * (N - 1) + (N - 2) >= A) AX = 2 * cur - U - (A - startVal) + (n - 1 - 2 * cur) * 4, AY = U;
            }

            if (BX == -1 && BY == -1) {
                if (startVal + (N - 1) >= B) BX = R, BY = (B - startVal) + 2 * cur - R;
                else if (startVal + 2 * (N - 1) >= B) BX = (B - startVal) + 2 * cur - D, BY = D;
                else if (startVal + 3 * (N - 1) >= B) BX = L, BY = 2 * cur - L - (B - startVal) + (n - 1 - 2 * cur) * 4;
                else if (startVal + 3 * (N - 1) + (N - 2) >= B) BX = 2 * cur - U - (B - startVal) + (n - 1 - 2 * cur) * 4, BY = U;
            }


            if ((AX != -1 && AY != -1) && (BX != -1 && BY != -1)) break;

            N -= 2, cur++, R++, L--, D--, U++;
        }

        return tie(AX, AY, BX, BY);
    };

    file >> t;

    while(t--) {
        file >> n >> a >> b;

        tie(x1, y1, x2, y2) = solved(a, b, n);

        if (llabs(x1 - x2) == llabs(y1 - y2)) cout << "YES\n";
        else cout << "NO\n";

    }
    file.close();


}
