// hashmap with
//      list<pair<int, int>>::iterator
class LRUCache {
    using Node = pair<int,int>;

    unordered_map<int, list<Node>::iterator> cache;
    list<Node> order;
    const int cap;

public:
    LRUCache(int capacity) :
      cap{capacity}  
    {}
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        // move to front
        order.splice(order.begin(), order, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            cache[key]->second = value;
            order.splice(order.begin(), order, cache[key]);
            return;
        }
        if (cache.size()+1 > cap) {
            cache.erase(order.back().first);
            order.pop_back();
        }
        order.push_front({key, value});
        cache[key] = order.begin();
    }
};
