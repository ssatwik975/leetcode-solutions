const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
 public:
  int consecutiveNumbersSum(int n) {
    int ans = 0;
    for (int i = 1, triangleNum = i; triangleNum <= n; ++i, triangleNum += i)
      if ((n - triangleNum) % i == 0)
        ++ans;
    return ans;
  }
};
