#include <map>

using namespace std;

struct Node
{
    int key;
    int value;
    struct Node *pre;
    struct Node *next;

    Node() : key(0), value(0), pre(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
};

class DoubleList
{
private:
    struct Node *head, *tail;

public:
    DoubleList();
    ~DoubleList();

    void addLast(Node *node);
    Node *remove(Node *node);
    Node *removeFirst();
};

DoubleList::DoubleList()
{

    this->head = new Node(-1, -1);
    this->tail = new Node(-1, -1);
    this->head->next = this->tail;
    this->tail->pre = this->head;
}

DoubleList::~DoubleList()
{
    delete head;
    delete tail;
}

void DoubleList::addLast(Node *node)
{
    node->pre = tail->pre;
    node->next = tail;
    tail->pre->next = node;
    tail->pre = node;
}

Node *DoubleList::remove(Node *node)
{
    node->pre->next = node->next;
    node->next->pre = node->pre;
    return node;
}

Node *DoubleList::removeFirst()
{
    if (head->next == tail)
    {
        return nullptr;
    }
    Node *first = head->next;
    return DoubleList::remove(first);
}

class LRUCache
{
private:
    int size;
    int capacity;
    DoubleList *dl;
    map<int, struct Node *> keyNode_map;

public:
    LRUCache(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        dl = new DoubleList();
    }

    int get(int key)
    {
        if (keyNode_map.find(key) == keyNode_map.end())
        {
            return -1;
        }
        // 将node重新加入链表的最后
        Node *node = keyNode_map[key];
        this->dl->remove(node);
        this->dl->addLast(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (keyNode_map.find(key) != keyNode_map.end())
        {
            Node *node = keyNode_map[key];
            node->value = value;
            this->dl->remove(node);
            this->dl->addLast(node);
            return;
        }

        Node *newNode = new Node(key, value);

        if (this->size == this->capacity)
        {
            // deleteFirst
            Node *first = this->dl->removeFirst();
            keyNode_map.erase(first->key);
            delete first;
            this->dl->addLast(newNode);
            keyNode_map[key] = newNode;
            return;
        }

        this->dl->addLast(newNode);
        keyNode_map[key] = newNode;
        this->size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */