class Solution {
public:
    double gain(int p,int q){
        return (double)(p+1)/(q+1)-(double)p/q;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it:classes){
            pq.push({gain(it[0],it[1]),{it[0],it[1]}});
        }
        while(extraStudents--){
            auto it=pq.top();
            pq.pop();
            int p=it.second.first;
            int q=it.second.second;
            p++;
            q++;
            pq.push({gain(p,q),{p,q}});
        }
        double ans=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans+=(double)(top.second.first)/top.second.second;
        }
        return ans/classes.size();
    }
};
