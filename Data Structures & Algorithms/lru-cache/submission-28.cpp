// Doubly linked list & map
//      use dummy head/tail
//
//  O(1) for get/put
//  O(N) space
//
// Mistakes:
//  - forgot tail->next update for placeFront
//  - remove existing from list before placeFront
class LRUCache {
    struct LRUNode {
        int key = 0;
        int val = 0;
        LRUNode* next = this;
        LRUNode* prev = this;
    };
    int cap;
    LRUNode* recency_list = nullptr;
    unordered_map<int, LRUNode*> hash;
public:
    LRUCache(int capacity) :
        cap(capacity)
    {
        recency_list = new LRUNode;
    }

    ~LRUCache() {
        LRUNode* tmp = recency_list->next;
        while (tmp != recency_list) {
            tmp = tmp->next;
            delete tmp->prev;
        }
        delete recency_list;
    }
    
    int get(int key) {
        if (!hash.contains(key))
            return -1;
        
        auto* target = hash[key];
        if (recency_list->next != target)
            moveToFront(target);
        return recency_list->next->val;
    }

    void put(int key, int value) {
        if (!hash.contains(key)) {
            if (hash.size() == cap) {
                auto* tail = recency_list->prev;
                hash.erase(tail->key);
                unlink(tail);
                delete tail;
            }
            LRUNode* node = new LRUNode;
            node->key = key;
            hash[key] = node;
            placeFront(node);
        }
        else if (hash[key] != recency_list->next)
            moveToFront(hash[key]);
        
        recency_list->next->val = value;
    }

    void moveToFront(LRUNode* node) {
        unlink(node);
        placeFront(node);
    }

    void placeFront(LRUNode* node) {
        node->next = recency_list->next;
        node->next->prev = node;
        recency_list->next = node;
        node->prev = recency_list;
    }
    
    void unlink(LRUNode* node) {
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
    }
};