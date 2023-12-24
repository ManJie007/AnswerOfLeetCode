 #include <cstddef>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        do
        {
            fast = fast->next;
            if (fast == nullptr)
            {
                return false;
            }
            if (fast == slow)
            {
                return true;
            }
            fast = fast->next;
            if (fast == nullptr)
            {
                return false;
            }
            if (fast == slow)
            {
                return true;
            }
            slow = slow->next;
            
            
        } while (true);
    }
};