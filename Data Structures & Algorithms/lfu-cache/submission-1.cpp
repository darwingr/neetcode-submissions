class LFUCache {
    struct dll {
        int key = -1;
        int val = -1;
        size_t freq = 0;
        dll* prev = this;
        dll* next = this;
    };

    unordered_map<int, dll*> cache;
    unordered_map<int, dll> freqs;
    const int cap = 1;
    int min_freq = 0;

public:
    LFUCache(int capacity) : cap{capacity} {}
    ~LFUCache() { for (auto [_, node] : cache) delete node; }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        promote(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        if (cache.contains(key)) {
            promote(cache[key]);
            cache[key]->val = value;
            return;
        }
        if (cache.size() == cap) {
            dll* lfu = freqs[min_freq].prev;
            unlink(lfu);
            if (min_freq > 1 && is_empty(freqs[min_freq]))
                freqs.erase(min_freq);
            cache.erase(lfu->key);
            delete lfu;
        }
        dll* node = new dll(key, value, 1);
        cache[key] = node;
        push_front(freqs[1], node);
        min_freq = 1;
    }

private:
    void promote(dll* node) {
        unlink(node);
        if (is_empty(freqs[node->freq])) {
            if (node->freq == min_freq)
                min_freq++;
            freqs.erase(node->freq);
        }
        node->freq++;
        push_front(freqs[node->freq], node);
    }
    void unlink(dll* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void push_front(dll& list, dll* node) {
        node->next = list.next;
        list.next->prev = node;
        list.next = node;
        node->prev = &list;
    }
    bool is_empty(const dll& list) const {
        return list.next == &list;
            //&& list.prev == &list;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */