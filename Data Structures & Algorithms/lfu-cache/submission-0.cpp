class LFUCache {
    struct dll {
        int key = -1;
        int val = -1;
        size_t freq = 1;
        dll* prev = this;
        dll* next = this;
    };

    unordered_map<int, dll*> cache;
    unordered_map<size_t, dll> fbuckets;
    const size_t cap = 1;
    size_t min_freq = 0;

public:
    LFUCache(size_t capacity) :
        cap{capacity}
    {}
    ~LFUCache() {
        for (auto& [_, node] : cache)
            delete node;
    }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        dll* node = cache[key];
        unlink(node);
        // remove bucket, change min?
        if (empty_bucket(node->freq)) {
            fbuckets.erase(node->freq);
            if (node->freq == min_freq)
                min_freq++;
        }
        node->freq++;
        push_front(fbuckets[node->freq], node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (cap == 0)  return;
        if (!cache.contains(key)) {
            if (cache.size() == cap) {
                dll* lfu = fbuckets[min_freq].prev;
                unlink(lfu);
                cache.erase(lfu->key);
                if (min_freq > 1 && empty_bucket(lfu->freq))
                    fbuckets.erase(lfu->freq);
                delete lfu;
            }
            dll* node = new dll(key);//, value};
            node->val = value;
            cache[key] = node;
            push_front(fbuckets[1], node);
            min_freq = 1;
        }
        else {
            dll* node = cache[key];
            unlink(node);
            // remove bucket, change min?
            if (empty_bucket(node->freq)) {
                fbuckets.erase(node->freq);
                if (node->freq == min_freq)
                    min_freq++;
            }
            node->freq++;
            push_front(fbuckets[node->freq], node);
            node->val = value;
        }
    }

private:
    void unlink(dll* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void push_front(dll& list, dll* node) {
        list.next->prev = node;
        node->next = list.next;
        list.next = node;
        node->prev = &list;
    }
    bool empty_bucket(size_t freq) const {
        return fbuckets.contains(freq)
            && fbuckets.at(freq).next == &fbuckets.at(freq);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */