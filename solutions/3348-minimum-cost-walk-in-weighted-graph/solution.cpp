class DSU {
    private:
        vector<int> parent, rank, weights;
        public:
            DSU(int n) {
                    parent = vector<int>(n);
                            rank = vector<int>(n, 0);
                                    weights = vector<int>(n, 131071);
                                            for (int i = 0; i < n; ++i)
                                                        parent[i] = i;
                                                            }
                                                                int find(int x) {
                                                                        if (x != parent[x])
                                                                                    parent[x] = find(parent[x]);
                                                                                            return parent[x];
                                                                                                }
                                                                                                    void union_(int x, int y, int weight) {
                                                                                                            int xx = find(x);
                                                                                                                    int yy = find(y);
                                                                                                                            if (rank[xx] < rank[yy])
                                                                                                                                        parent[xx] = yy;
                                                                                                                                                else
                                                                                                                                                            parent[yy] = xx;
                                                                                                                                                                    weights[xx] = weights[yy] = weights[xx] & weights[yy] & weight;
                                                                                                                                                                            if (rank[xx] == rank[yy])
                                                                                                                                                                                        rank[xx]++;
                                                                                                                                                                                            }
                                                                                                                                                                                                int minimumCostOfWalk(int x, int y) {
                                                                                                                                                                                                        if (x == y) return 0;
                                                                                                                                                                                                                if (find(x) != find(y)) return -1;
                                                                                                                                                                                                                        return weights[find(x)];
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                            };

                                                                                                                                                                                                                            class Solution {
                                                                                                                                                                                                                            public:
                                                                                                                                                                                                                                vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
                                                                                                                                                                                                                                        DSU uf(n);
                                                                                                                                                                                                                                                for (auto& edge : edges)
                                                                                                                                                                                                                                                            uf.union_(edge[0], edge[1], edge[2]);
                                                                                                                                                                                                                                                                    vector<int> result;
                                                                                                                                                                                                                                                                            for (auto& q : query)
                                                                                                                                                                                                                                                                                        result.push_back(uf.minimumCostOfWalk(q[0], q[1]));
                                                                                                                                                                                                                                                                                                return result;
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                };

       


