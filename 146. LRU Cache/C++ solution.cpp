class LRUCache {
private:
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> buf;
    int cap;
public:
    LRUCache(int capacity):cap(capacity) { }
    
    int get(int key) {
        if(!buf.count(key))
            return -1;
        int res = buf[key]->second;
        data.splice(data.begin(), data, buf[key]);
        return res;
    }
    
    void put(int key, int value) {
        if(buf.count(key)){
            buf[key]->second = value;
            data.splice(data.begin(), data, buf[key]);
            return ;
        }
        if(data.size()>=cap){
            int keyNum = data.back().first;
            data.pop_back();
            buf.erase(keyNum);
        }
        data.push_front({key, value});
        buf[key] = data.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
