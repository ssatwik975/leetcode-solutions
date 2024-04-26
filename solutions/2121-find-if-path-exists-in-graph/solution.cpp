//can do by usings pairs checking of second is someone else first and putting that in a vector and that way you can find?
const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int find(int parent[], int x) {

        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    void makeunion(int x, int y, int rank[], int parent[]) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset == yset) {
            return;
        }
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[yset] < rank[xset]) {
            parent[yset] = xset;
        } else {
            parent[xset] = yset;
            rank[xset]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        int parent[n], rank[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        };
        for (int i = 0; i < edges.size(); i++) {
            makeunion(edges[i][0], edges[i][1], rank, parent);
        }
        return find(parent, source) == find(parent, destination);
    }
};
