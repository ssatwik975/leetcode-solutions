const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node -> next;
    }
};
