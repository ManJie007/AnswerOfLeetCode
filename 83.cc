 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* tmpPtr = head, *tmpPtr2 = head;
        while (tmpPtr != nullptr)
        {
            tmpPtr2 = tmpPtr->next;
            while (tmpPtr2 != nullptr && tmpPtr2->val == tmpPtr->val)
            {
                ListNode *tmpNode = tmpPtr2;
                tmpPtr->next = tmpPtr2->next;
                tmpPtr2 = tmpPtr2->next;
                delete tmpNode;
            }
                    

            tmpPtr = tmpPtr->next;
        }

        return head;
    }
};