#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll INF = 1e12;
const int MaxNM = 1000;
int N, M;
int start, goal;
vector<pii> list[MaxNM], can[MaxNM];
ll dist[MaxNM];
int t, c;
bool init;

inline bool cmp(const int u, const int v) {
    if (dist[u] != dist[v])
        return dist[u] < dist[v];
    return u < v;
}

set<int, bool(*)(const int, const int)> S(cmp);

inline void relax(const int u, const int v, const int w) {
    if (dist[u] + w < dist[v]) {
        S.erase(v);
        dist[v] = dist[u] + w;
        S.insert(v);
    }
}

inline void dijkstra(const int s, vector<pii> *list) {
    for (int i = 0; i < N; i ++)
        dist[i] = INF;

    dist[s] = 0;
    S.insert(s);

    while (!S.empty()) {
        int v = *S.begin();
        S.erase(S.begin());

        if (init && dist[v] <= t)
            can[s].push_back(pii(v, c));

        for (int i = 0; i < (int) list[v].size(); i ++)
            relax(v, list[v][i].first, list[v][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> start >> goal; start --; goal --;
    for (int i = 0; i < M; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --; v --;
        list[u].push_back(pii(v, w));
        list[v].push_back(pii(u, w));
    }

    init = true;
    for (int i = 0; i < N; i ++) {
        cin >> t >> c;
        dijkstra(i, list);
    }

    init = false;
    dijkstra(start, can);

    cout << (dist[goal] == INF ? -1 : dist[goal]) << endl;

    return 0;
}
