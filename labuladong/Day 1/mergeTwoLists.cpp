#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 虚拟头结点 dummy
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;
		ListNode* p1 = list1;
		ListNode* p2 = list2;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val <= p2->val) {
				p->next = p1;
				p1 = p1->next;
			} else {
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1 != NULL) {
			p->next = p1;
		} 
		if (p2 != NULL) {
			p->next = p2;
		}
		return dummy->next;
    }
};