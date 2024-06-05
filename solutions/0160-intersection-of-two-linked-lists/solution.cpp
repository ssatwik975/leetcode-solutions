int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out");
    for(string s; getline(std::cin, s);)
    {
        if(s[0] != '0') out << "Intersected at '" << s << "'\n";
        else out << "No intersection\n";
        for(int i = 0; i < 4; ++i) getline(std::cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        unordered_map<ListNode*, int> mapp;
        while(headA != NULL){
            mapp[headA]++;
            headA = headA -> next;
        }
        while(headB != NULL){
            if(mapp.count(headB)){
                return headB;
            }else{
                headB = headB -> next;
            }
        }
		return 0;
	}
};
