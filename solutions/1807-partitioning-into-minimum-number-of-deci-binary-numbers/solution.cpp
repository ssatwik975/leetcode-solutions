const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(int i = 0; i<n.size(); i++){
            ans = max(ans,(n[i]-'0'));
        }
        return ans;
    }
};
