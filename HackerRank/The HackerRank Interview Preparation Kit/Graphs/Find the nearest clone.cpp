// O(V+E).
// V = 1e6, why not time limits??
// that's bfs magic. search each node. and early prune.
// when same color more node, return earlier.
// like O(N^2). but actually O(N). the node more. the time smaller

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    vector<int> g[graph_nodes+1];
    bool vis[graph_nodes+1];
    int m = graph_from.size();

    for(int i = 0; i < m; ++i){
        g[graph_from[i]].push_back(graph_to[i]);
        g[graph_to[i]].push_back(graph_from[i]);
    }

    auto bfs = [&](int st){
        memset(vis, 0, sizeof vis);
        queue<pair<int, int>> q;
        q.push({st, 0});
        while(q.size()){
            auto [u, d] = q.front(); q.pop();
            vis[u] = 1;
            for(int v: g[u]){
                if(!vis[v]){
                    if(ids[v-1] == val){
                        return d+1;
                    }
                    q.push({v, d+1});
                }
            }
        }
        return (int)1e9;
    };

    int mn = 1e9;
    for(int i = 1; i <= graph_nodes; ++i){
        if(ids[i-1] == val){
            mn = min(bfs(i), mn);
        }
    }

    return mn == 1e9 ? -1 : mn;
}

// One bfs. Optimal, use map to record. when counter in map then merge.
// and their parent must not same. Nice. O(V+E) faster.

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    vector<int> g[graph_nodes+1];
    int m = graph_from.size();

    for(int i = 0; i < m; ++i){
        g[graph_from[i]].push_back(graph_to[i]);
        g[graph_to[i]].push_back(graph_from[i]);
    }

    unordered_map<int, pair<int, int>> mp;
    queue<int> q;
    for(int i = 1; i <= graph_nodes; ++i){
        if(ids[i-1] == val){
            mp[i] = {i, 0};
            q.push(i);
        }
    }

    while(q.size()){
        int u = q.front(); q.pop();
        auto [par, len] = mp[u];
        for(int v: g[u]){
            if(!mp.count(v)){
                mp[v] = {par, len+1};
                q.push(v);
            }
            else{
                if(mp[v].first == par) continue;
                return len + mp[v].second + 1;
            }
        }
    }

    return -1;
}
