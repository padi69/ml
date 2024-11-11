#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dst, wt;
};

void bellmanFord(int V, int E, vector<Edge> &edges)
{
    vector<int> dist(V, INT_MAX);
    dist[0] = 0; // Source vertex (node 0)

    // Relax edges V-1 times
    for (int i = 1; i < V; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            int u = edges[j].src;
            int v = edges[j].dst;
            int wt = edges[j].wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative-weight cycle
    for (int j = 0; j < E; ++j)
    {
        int u = edges[j].src;
        int v = edges[j].dst;
        int wt = edges[j].wt;
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Output the shortest distances in one-indexed format
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "0 -> " << i + 1 << " : Unreachable" << endl; // Note the "+1"
        }
        else
        {
            cout << "0 -> " << i + 1 << " : " << dist[i] << endl; // Note the "+1"
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter num of vertices & edges: ";
    cin >> V >> E; // Number of vertices and edges
    vector<Edge> edges(E);

    cout << "Enter Source , dist,weight";
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].src >> edges[i].dst >> edges[i].wt;
    }

    bellmanFord(V, E, edges);
    return 0;
}