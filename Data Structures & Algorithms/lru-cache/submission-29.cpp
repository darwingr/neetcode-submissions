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
    const int cap;
    unique_ptr<LRUNode> recency_list = make_unique<LRUNode>();
    unordered_map<int, LRUNode*> cache;
public:
    LRUCache(int capacity) :
        cap(capacity)
    {}

    ~LRUCache() {
        LRUNode* tmp = recency_list->next;
        while (tmp != recency_list.get()) {
            tmp = tmp->next;
            delete tmp->prev;
        }
    }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        
        auto* target = cache[key];
        if (recency_list->next != target)
            moveToFront(target);
        return recency_list->next->val;
    }

    void put(int key, int value) {
        if (!cache.contains(key)) {
            if (cache.size() == cap) {
                auto* tail = recency_list->prev;
                cache.erase(tail->key);
                unlink(tail);
                delete tail;
            }
            LRUNode* node = new LRUNode;
            node->key = key;
            cache[key] = node;
            placeFront(node);
        }
        else if (cache[key] != recency_list->next)
            moveToFront(cache[key]);
        
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
        node->prev = recency_list.get();
    }
    
    void unlink(LRUNode* node) {
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
    }
};