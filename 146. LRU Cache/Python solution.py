from collections import Counter
class LRUCache:
    def __init__(self, capacity: int):
        self.data = []
        self.buf = Counter()
        self.cap = capacity

    def get(self, key: int) -> int:
        if self.buf[key]==0:
            return -1
        res = self.buf[key][1]
        self.data.append(self.buf[key])
        self.data.remove(self.buf[key])
        return res

    def put(self, key: int, value: int) -> None:
        if self.buf[key] != 0:
            self.buf[key][1] = value
            self.data.append(self.buf[key])
            self.data.remove(self.buf[key])
        else:
            if len(self.data)>=self.cap:
                del self.buf[self.data[0][0]]
                self.data.pop(0)
            self.data.append([key, value])
            self.buf[key] = self.data[-1]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
