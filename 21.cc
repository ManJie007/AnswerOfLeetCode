
struct ListNode
{
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // 下面就是list1和list2都不为空的情况
        ListNode *head = new ListNode();
        ListNode *p1 = list1, *p2 = list2, *tail = head;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                tail->next = p1;
                tail = tail->next;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                tail = tail->next;
                p2 = p2->next;
            }
        }

        if (p1 != nullptr)
        {
            tail->next = p1;
        }

        if (p2 != nullptr)
        {
            tail->next = p2;
        }

        tail = head->next;
        delete head;
        return tail;
        
        
    }
};