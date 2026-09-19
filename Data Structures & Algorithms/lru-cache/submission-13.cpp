struct Node {
    int key = 0;
    int value = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
    void unlink();
};

class DLL {
    // invariant: either both or neither are nullptr
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    ~DLL();
    Node* insert(int key, int value);
    void moveToFront(Node* node);
    int tailKey() { if (!tail) return -1; return tail->key; }
    void deleteTail();
};

class LRUCache {
    const int cap = 0;
    unordered_map<int,Node*> cache_map;
    DLL order = DLL();

public:
    LRUCache(int capacity) :
        cap(capacity)
    {
    }
    
    int get(int key) {
        if (cache_map.contains(key)) {
            order.moveToFront(cache_map[key]);
            return cache_map[key]->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (cache_map.contains(key)) {
            cache_map[key]->value = value;
            order.moveToFront(cache_map[key]);
        } else {
            Node* node = order.insert(key, value);
            cache_map[key] = node;
            // evict last!
            if (cache_map.size() > cap) {
                cache_map.erase(order.tailKey());
                order.deleteTail();
            }
        }
    }
};

void Node::unlink() {
    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    prev = nullptr;
    next = nullptr;
}

DLL::~DLL() {
    while (head) {
        Node* next_node = head->next;
        delete head;
        head = next_node;
    }
}

Node* DLL::insert(int key, int value) {
    Node* node = new Node;
    node->key = key;
    node->value = value;
    if (!tail)
        tail = node;
    
    if (!head)
        head = node;
    else {
        head->prev = node;
        node->next = head;
        head = node;
    }
    return head;
}

void DLL::moveToFront(Node* node) {
    if (head && node == head || !node)
        return;
    
    if (tail == node)
        tail = tail->prev;
    node->unlink();
    head->prev = node;
    node->next = head;
    head = node;
}

void DLL::deleteTail() {
    if (!tail)
        return;
    if (head == tail)
        head = nullptr;
    Node* node = tail;
    if (tail->prev) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
        tail = nullptr;
    delete node;
}