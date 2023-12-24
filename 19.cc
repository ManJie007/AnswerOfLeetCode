 #include <cstddef>

 using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead;
        dummyHead.next = head;
        ListNode *tmpPtr = &dummyHead, *tmpPtr2 = &dummyHead, *prePtr = &dummyHead;
        
        for (size_t i = 0; i < n; i++)
        {
            tmpPtr = tmpPtr->next;
        }
        
        while (tmpPtr != nullptr)
        {
            tmpPtr = tmpPtr->next;
            prePtr = tmpPtr2;
            tmpPtr2 = tmpPtr2->next;
        }
        
        prePtr->next = tmpPtr2->next;
        delete tmpPtr2;
        
        return dummyHead.next;
    }
};