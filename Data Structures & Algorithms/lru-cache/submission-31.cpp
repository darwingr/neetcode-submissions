// DLL + hashmap: use dummy head/tail
class LRUCache {
    struct dll {
        int key = -1;
        int val = -1;
        dll* prev = this;
        dll* next = this;
    };
    unordered_map<int, dll*> cache;
    dll order;
    const int cap = 0;
public:
    LRUCache(int capacity) :
        cap{capacity}
    {}
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        if (cache[key] != order.next)
            move_front(cache[key]);
        return order.next->val;
    }
    
    void put(int key, int value) {
        if (!cache.contains(key)) {
            if (cache.size() == cap) {
                dll* node = order.prev;
                cache.erase(node->key);
                unlink(node);
                delete node;
            }
            dll* node = new dll;
            node->key = key;
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
    void push_front(dll* node) {
        node->next = order.next;
        order.next->prev = node;
        order.next = node;
        node->prev = &order;
    }
    void unlink(dll* node) {
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
    }
};
