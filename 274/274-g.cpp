#include<iostream>
#include<vector>
#include<utility>
#include<set>

#define INF (1LL<<60)

using namespace std;
using ll = long long;

class Edge {
    public:

    int to;
    ll cap; 

    Edge( int to, ll cap ): to(to), cap(cap) {} 
};

ll dfs(const vector<vector<Edge>>& g, vector<int>& visited, vector<int>& ord, int t, int x, ll mincost = INF ) {
    visited[x] = 1;
    ord.push_back(x);

    if ( x == t ) return mincost;

    for ( auto e : g[x] ) {
        if ( visited[e.to] ) continue;
        ll value = dfs( g, visited, ord, t, e.to, min(mincost, e.cap));
        if ( value != INF ) return value; 
    }
    ord.pop_back();
    return INF;
}

ll fordFulkerson( const vector<vector<Edge>>& g, vector<vector<ll>>& flow, int s, int t ) {
    flow = vector<vector<ll>>( g.size(), vector<ll>(g.size(), 0));
    vector<vector<ll>> caps( g.size(), vector<ll>(g.size(), 0));

    for ( int i = 0; i < g.size(); ++i ) for ( auto e : g[i] ) caps[i][e.to] = e.cap;

    ll maxflow = 0;

    while(1) {
        vector<vector<Edge>> tmpg(g.size());
        vector<int> ord;
        vector<int> visited(g.size(), 0);

        for ( int i = 0; i < g.size(); ++i ) {
            for ( int j = 0; j < g.size(); ++j ) {
                ll f = caps[i][j]-flow[i][j]+flow[j][i];
                if ( f > 0 ) tmpg[i].push_back(Edge(j, f));
            } 
        }
        ll mincost = dfs(tmpg, visited, ord, t, s);
        if ( mincost == INF ) break;
        maxflow += mincost;
        for ( int i = 0; i < ord.size()-1; ++i ) {
            int from = ord[i], to = ord[i+1];
            ll res = caps[from][to]-flow[from][to];
            flow[from][to] = min(flow[from][to]+mincost, caps[from][to]);
            ll tmpmin = max(mincost-res, 0LL);
            flow[to][from] -= tmpmin;
        } 
    }
    return maxflow;
}

class BipartiteGraph {
    int x, y;
    vector<pair<int,int>> edges; //first: x vertex, second: y vertex

    void dfs(const vector<vector<int>>& g, vector<int>& color, int x, const int WHITE, const int RED ) const; 
    
    public:
    BipartiteGraph(int x, int y, vector<pair<int,int>>& edges ) : x(x), y(y), edges(edges) {}
    vector<pair<int,int>> bipartiteMaxMatching () const ;
    vector<pair<int,int>> minCoverVertex() const;

};

void BipartiteGraph::dfs(const vector<vector<int>>& g, vector<int>& color, int x, const int WHITE, const int RED ) const {
    color[x] = RED;
    for ( auto to : g[x] ) {
        if ( color[to] == WHITE ) dfs(g, color, to, WHITE, RED);
    }
}

vector<pair<int,int>> BipartiteGraph::bipartiteMaxMatching() const {
    int s = x+y, t = s+1;
    vector<vector<Edge>> g(t+1);
    for ( const auto& e : edges ) {
        int y = e.second+x;
        g[e.first].push_back(Edge(y, 1)); 
    }
    for ( int i = 0; i < x; ++i ) g[s].push_back(Edge(i,1));
    for ( int i = 0; i < y; ++i ) {
        int y = x+i;
        g[y].push_back(Edge(t, 1));
    }

    vector<vector<ll>> flow;
    ll maxpairs;
    maxpairs = fordFulkerson(g, flow, s, t);
    vector<pair<int,int>> ans;
    for ( int i = 0; i < x; ++i ) {
        for ( int j = 0 ; j < y; ++j ) {
            int y = j+x;
            if ( flow[i][y] > 0 ) ans.push_back(make_pair(i, j));
        }
    }
    return ans;
}

vector<pair<int,int>> BipartiteGraph::minCoverVertex() const {
    const int WHITE = 0;
    const int RED = 1;
    const int XNO = 0;
    const int YNO = 1;
    vector<pair<int,int>> maxedges = bipartiteMaxMatching();
    set<pair<int,int>> s;
    vector<int> isMaxEdge(x+y, 0);
    vector<vector<int>> g(x+y);
    vector<int> color(x+y, WHITE);
    vector<int> isMatchV(x,0);
    
    for ( auto p : maxedges ) {
        s.insert(p);
        isMatchV[p.first] = 1;
    }
    for ( auto e : edges ) {
        int et1 = e.first, et2 = e.second+x;
        if ( s.find(e) != s.end() ) g[et2].push_back(et1);
        else g[et1].push_back(et2);
    }
    for ( int i = 0; i < x; ++i ) if ( isMatchV[i] == 0 ) this->dfs(g, color, i, WHITE, RED);

    vector<pair<int,int>> ans;
    for ( int i = 0; i < x; ++i ) if ( color[i] == WHITE ) ans.push_back(make_pair(XNO, i));
    for ( int i = 0; i < y; ++i ) if ( color[i+x] == RED ) ans.push_back(make_pair(YNO, i));
    return ans;
}

int main()
{
    int h, w;
    vector<string> masu;
    vector<vector<pair<int,int>>> p;

    cin >> h >> w;
    masu = vector<string>(h);
    p = vector<vector<pair<int,int>>>(h, vector<pair<int,int>>(w, make_pair(-1,-1)));

    for ( auto& s : masu ) cin >> s;
    int vercnt = 0, horcnt = 0;

    for ( int i = 0; i < h; ++i ) {
        for ( int j = 0; j < w; ++j ) {
            if ( masu[i][j] == '.' ) p[i][j].first = horcnt;
            else ++horcnt;
        }
        ++horcnt;
    }
    for ( int j = 0; j < w; ++j ) {
        for ( int i = 0; i < h; ++i ) {
            if ( masu[i][j] == '.' ) p[i][j].second = vercnt;
            else ++vercnt;
        }
        ++vercnt;
    }

    vector<pair<int,int>> edges;
    for ( auto vec : p ) {
        for ( auto v : vec ) {
            if ( v.first == -1 || v.second == -1 ) continue;
            edges.push_back(make_pair(v.first, v.second));
        }
    }

    BipartiteGraph bg(horcnt, vercnt, edges);
    cout << bg.minCoverVertex().size() << endl;
    

   
}