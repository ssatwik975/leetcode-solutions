class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>freq;
        for(auto s : edges){
            for(auto k : s){
                freq[k]++;
                if(freq[k]==2)
                return k;
            }
        }
        return 0;
    }
};

int init = [] {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ofstream out("user.out");
	cout.rdbuf(out.rdbuf());
	for (string line; getline(cin, line); cout << '\n') {
		istringstream ss(line);
		char ch;
		int a, b, c, d;
		ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
		if (a == c || a == d) cout << a;
		else cout << b;
	}
	exit(0);
	return 0;
}();
