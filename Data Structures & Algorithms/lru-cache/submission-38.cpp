// DLL + Hashmap: dummy node of head/tail
class LRUCache {
    struct dll {
        int key = -2;
        int val = -2;
        dll* prev = this;
        dll* next = this;
    };

    unordered_map<int, dll*> cache;
    dll order;
    const size_t cap = 1;
public:
    LRUCache(size_t capacity) : cap{capacity} {}
    ~LRUCache() { for (auto& [_, node] : cache) delete node; }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        if (order.next != cache[key])
            move_front(cache[key]);
        return order.next->val;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        if (!cache.contains(key)) {
            if (cache.size() == cap) {
                dll* lru = order.prev;
                unlink(lru);
                cache.erase(lru->key);
                delete lru;
            }
            dll* node = new dll{key};
            cache[key] = node;
            push_front(node);
        } else if (order.next != cache[key])
            move_front(cache[key]);
        order.next->val = value;
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
