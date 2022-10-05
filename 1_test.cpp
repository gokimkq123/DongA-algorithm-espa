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
    ofstream cout("test.out");
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    unordered_map<string,int> Map;
    vector<tuple<string,string,string>> temp;
    int n = 0, Maxspace = 0;
    string num, Fname, Lname, a;

    auto INPUT = [&](){
        ifstream file("test.inp");

        file >> n;

        while(!file.eof()){
            file >> num >> Fname >> Lname >> ws;
            temp.emplace_back(num, Fname, Lname);
            Map[Lname]++;
            Maxspace = max(int(Fname.size()), Maxspace);
        }
        file.close();

        sort(temp.begin(),temp.end());
    };

    auto Space = [&](int len){
        for(int i=0;i<abs(len - Maxspace);i++)
            cout << " ";
    };

    auto print = [&]() {
        for(auto &i : temp){
            tie(num, Fname, Lname) = i;

            cout << num << " " << Fname;
            Space(int(Fname.size()));
            cout << " " << Lname << "\n";
        }

        vector<pair<string, int>> ans;

        for (auto &i: Map)
            if (i.S >= 2) ans.emplace_back(i.F, i.S);


        if (!ans.empty()) {
            cout << "\n";
            sort(ans.begin(), ans.end());

            for(int i=0;i<ans.size();i++){
                if(ans.size() == i - 1)  cout << ans[i].F << " " << ans[i].S;
                else cout << ans[i].F << " " << ans[i].S << "\n";
            }
        }
    };

    INPUT();
    print();

}
