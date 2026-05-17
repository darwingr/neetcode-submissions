// Mistakes:
//  - forgot tail->next update for placeFront
//  - 
class LRUCache {
    struct LRUNode {
        int key = 0;
        int val = 0;
        LRUNode* next = this;
        LRUNode* prev = this;
    };
    int cap;
    int size = 0;
    LRUNode* recency_list = nullptr;
    unordered_map<int, LRUNode*> hash;
public:
    LRUCache(int capacity) :
        cap(capacity)
    {}
    
    int get(int key) {
        if (!recency_list || !hash.contains(key))
            return -1;
        
        auto* target = hash[key];
        if (target != recency_list) {// skip at front
            // remove from position
            auto* pred = target->prev;
            auto* next = target->next;
            pred->next = next;
            next->prev = pred;

            // place at front
            placeFront(target);
        }
        return recency_list->val;
    }

    void placeFront(LRUNode* node) {
        if (recency_list) {
            auto* tail = recency_list->prev;
            tail->next = node;

            node->next = recency_list;
            node->prev = tail;
            recency_list->prev = node;
        }
        recency_list = node;
    }
    
    void put(int key, int value) {
        // make room
        if (size == cap && !hash.contains(key)) {
            auto* tail = recency_list->prev;
            hash.erase(tail->key);
            size--;

            recency_list->prev = tail->prev;
            tail->prev->next = recency_list;
            delete tail;
        }

        // Remove from LL
        if (hash.contains(key)) {
            if (hash[key] == recency_list) {
                recency_list->val = value;
                return;
            } else
                unlink(hash[key]);
        }
        // Make new
        else {
            hash[key] = new LRUNode;
            size++;
        }
        // Update
        auto* node = hash[key];
        node->val = value;
        node->key = key;

        // place at front
        placeFront(node);
    }

    void unlink(LRUNode* node) {
        if (!node || !hash.contains(node->key))
            return;
        if (node == recency_list)
            recency_list = nullptr;
        auto* pred = node->prev;
        auto* next = node->next;
        pred->next = next;
        next->prev = pred;
    }
};
