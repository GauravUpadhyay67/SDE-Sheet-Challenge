// Problem: MST using Kruskal's Algorithm
// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Difficulty: Hard
// Approach: Sort all edges by weight and use Disjoint Set Union (Union-Find) to include an edge only if it doesn't form a cycle
// Time: O(E log E) | Space: O(V)



class DisjointSet{
public:
    vector<int> parent, sz;

    DisjointSet(int n){

        parent.resize(n);
        sz.resize(n, 1);

        for(int i=0; i<n; i++){

            parent[i] = i;
        }
    }

    int findUPar(int node){

        if(node == parent[node]){

            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){

        u = findUPar(u);
        v = findUPar(v);

        if(u == v){

            return;
        }

        if(sz[u] < sz[v]){

            swap(u, v);
        }

        parent[v] = u;
        sz[u] += sz[v];
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){

            return a[2] < b[2];
        });

        DisjointSet ds(V);

        int sum = 0;

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(ds.findUPar(u) != ds.findUPar(v)){

                sum += wt;
                ds.unionBySize(u, v);
            }
        }

        return sum;
    }
};

