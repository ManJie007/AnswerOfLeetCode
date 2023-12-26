#include <cstddef>
#include <vector>

using namespace std;

struct ListNode
{
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
class Solution
{
public:
    ListNode *initListNode(const vector<int>& vec, int n)
    {
        ListNode dummy(-1);
        ListNode *ptr = &dummy;
        ListNode *cycle = nullptr;
        for (size_t i = 0; i < vec.size(); i++)
        {
            ListNode *node = new ListNode(vec[i]);
            if (i == n)
            {
                cycle = node;
            }
            
            ptr->next = node;
            ptr = ptr->next;
        }
        ptr->next = cycle;

        return dummy.next;
    }

    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *fast = head, *slow = head;

        //判断是否有环
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
            
        }
        
        //如果没有环返回nullptr
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }

        //将一个指针重新指向头部
        slow = head;
        
        //找到环的启始节点
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> vec{3, 2, 0, 4};
    vector<int> vec{1, 2};
    Solution solution;
    solution.detectCycle(solution.initListNode(vec, 0));
    return 0;
}