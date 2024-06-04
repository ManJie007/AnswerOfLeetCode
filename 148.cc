#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

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
bool com_listNode(const ListNode *lhs, const ListNode *rhs) {
  return lhs->val > rhs->val;
}

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head) {
        return head; 
    }
    // auto com_listNode = [](const ListNode *lhs, const ListNode *rhs) -> bool
    // {
    //   return lhs->val > rhs->val;
    // };
    priority_queue<ListNode *, vector<ListNode *>, decltype(com_listNode)*> pq(com_listNode);
    ListNode *temp = head;
    while (temp) {
        pq.push(temp); 
        temp = temp->next;
    }


    ListNode dummy;
    ListNode *pre = &dummy;

    while (!pq.empty()) {
        ListNode *cur = pq.top();
        pq.pop();
        cur->next = nullptr;
        pre->next = cur;
        pre = cur;
    }

    return dummy.next;
  }
};

int main(int argc, char **argv) {

  // auto com_listNode = [](const ListNode *lhs, const ListNode *rhs) -> bool {
  //   return lhs->val > rhs->val;
  // };
  // priority_queue<ListNode *, vector<ListNode *>, decltype(com_listNode)>
  // pq(com_listNode);

   ListNode* node1 = new ListNode(4);
   ListNode* node2 = new ListNode(2);
   ListNode* node3 = new ListNode(1);
   ListNode* node4 = new ListNode(3);
  
   node1->next = node2;
   node2->next = node3;
   node3->next = node4;

   Solution s;
   ListNode* newNode = s.sortList(node1);
    while (newNode) {
        cout << newNode->val << " ";
        newNode = newNode->next;
    }

  // while (!pq.empty()) {
  //   ListNode* pop_node = pq.top();
  //   pq.pop();
  //   cout << pop_node->val << endl;
  // }

  return 0;
}
