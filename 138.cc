#include <cstddef>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    using NodeMap = map<Node*, Node*>;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (!m_map.count(head)) {
            Node *newNode = new Node(head->val);

            m_map[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }

        return m_map[head];
    }

private:
    NodeMap m_map;
};
