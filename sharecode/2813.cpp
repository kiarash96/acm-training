#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second

const int MaxN = 40;

int main() {
    ios::sync_with_stdio(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t ++) {
        map<pii, ll> ans;
        pii list[MaxN];

        int N;
        cin >> N;
        
        if (N == 0) {
           cout << 0 << endl;
           continue;
        }
        
        for (int i = 0; i < N; i ++)
            cin >> list[i].X >> list[i].Y;
        
        ans[pii(0, 0)] = 1;
        for (int i = 0; i < N; i ++) {
            vector<pair<pii, ll> > newv;
            for (map<pii, ll>::iterator iter = ans.begin(); iter != ans.end(); iter ++) {
                pii p = pii(iter->first.X + list[i].X, iter->first.Y + list[i].Y);
                newv.push_back(make_pair(p, ans[iter->first]));
            }
            
            for (int i = 0; i < newv.size(); i ++)
                ans[newv[i].first] += newv[i].second;
                
        }
                
        cout << ans[pii(0, 0)] - 1LL << endl;  
    }
    
    return 0;
}

