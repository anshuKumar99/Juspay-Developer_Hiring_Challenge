//Approach 1

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> input[1000001];

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    for (int i=0;i<n;i++) {
        int id;
        cin>>id;
        mp[id]=INT_MAX;
    }
    int edge;
    cin>>edge;
    for (int i=0;i<edge;i++) {
        int follower,following,time;
        cin >>follower>>following>>time;
        input[follower].push_back({following,time});
    }

    int A,B;
    cin >>A>>B;

    set<pair<int,int>> s;
    mp[A] = 0;
    s.insert({0,A});

    while (!s.empty()) {
        pair<int, int> tmp = *(s.begin());
        s.erase(s.begin());

        int u = tmp.second;
        for (auto i=input[u].begin();i!=input[u].end();i++) {
            int v=(*i).first;
            int weight=(*i).second;

            if (mp[v]>mp[u] + weight) {
                if (mp[v]!=INT_MAX)
                    s.erase(s.find({mp[v],v}));

                mp[v]=mp[u]+weight;
                s.insert({mp[v],v});
            }
        }
    }

    if (mp[B] == INT_MAX)
        cout << "-1" << endl;
    else
        cout << mp[B] << endl;

    return 0;
}

//Approach 2

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int time;
};

void addEdge(vector<Edge> graph[], int u, int v, int time) {
    graph[u].push_back({v, time});
}

vector<int> dijkstra(vector<Edge> graph[], int N, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N, INT_MAX);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.to;
            int time = edge.time;

            if (dist[v] > dist[u] + time) {
                dist[v] = dist[u] + time;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<Edge> graph[N];

    for (int i = 0; i < E; i++) {
        int u, v, time;
        cin >> u >> v >> time;
        addEdge(graph, u, v, time);
    }

    int start; // ID of 'A'
    cin >> start;

    vector<int> shortestTimes = dijkstra(graph, N, start);

    // Output or process the shortest times as needed
    // For example, to find the shortest time to 'B', access shortestTimes[B's ID]

    return 0;
}

