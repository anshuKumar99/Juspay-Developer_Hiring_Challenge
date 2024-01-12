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
