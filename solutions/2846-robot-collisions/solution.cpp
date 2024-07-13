int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<array<int, 4>> robots;
        robots.reserve(positions.size());
        for (int i = 0; i < positions.size(); ++i) {
            robots.push_back({positions[i], healths[i], directions[i] == 'R' ? 1 : -1, i});
        }

        sort(robots.begin(), robots.end());

        vector<array<int, 4>> robo;
        robo.reserve(positions.size()); 

        for (auto& v : robots) {
            bool destroyed = false;
            while (!robo.empty() && robo.back()[2] > 0 && v[2] < 0) {
                if (robo.back()[1] < v[1]) {
                    robo.pop_back();
                    --v[1];
                    continue;
                } else if (robo.back()[1] > v[1]) {
                    destroyed = true;
                    --robo.back()[1];
                    break;
                } else {
                    destroyed = true;
                    robo.pop_back();
                    break;
                }
            }
            if (!destroyed) {
                robo.push_back(v);
            }
        }

        vector<pair<int, int>> survived;
        survived.reserve(robo.size());
        for (auto& r : robo) {
            survived.emplace_back(r[3], r[1]);
        }

        sort(survived.begin(), survived.end());

        vector<int> survivedHealths;
        survivedHealths.reserve(survived.size());
        for (auto& s : survived) {
            survivedHealths.push_back(s.second);
        }
        return survivedHealths;
    }
};

