// DLL+hashmap, use dummy head/tail
class LRUCache {
    struct dll {
        int key = -2;
        int val = -2;
        dll* prev = this;
        dll* next = this;
    };
    using Key = int;
    unordered_map<Key, dll*> cache;
    dll order;
    const int cap = 1;

public:
    LRUCache(int capacity) : cap{capacity} {}
    ~LRUCache() { for (auto& [_, node] : cache) delete node; }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        dll* node = cache[key];
        if (order.next != node)
            move_front(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        if (cache.contains(key)) {
            dll* node = cache[key];
            if (order.next != node)
                move_front(node);
            node->val = value;
            return;
        }
        if (cache.size() == cap) {
            dll* lru = order.prev;
            unlink(lru);
            cache.erase(lru->key);
            delete lru;
        }
        dll* node = new dll{key, value};
        cache[key] = node;
        push_front(node);
    }
private:
    void move_front(dll* node) {
        unlink(node);
        push_front(node);
    }
    void unlink(dll* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void push_front(dll* node) {
        node->next = order.next;
        order.next->prev = node;
        order.next = node;
        node->prev = &order;
    }
};
