class Node:
    def __init__(self, key: int, value: int):
        self.p = None
        self.n = None
        self.k = key
        self.v = value

class LRUCache:
    def __init__(self, capacity: int):
        self.head = None
        self.tail = None
        self.capacity = capacity
        self.keys = {}

    def get(self, key: int) -> int:
        print("GET", key)
        print(self)
        if key not in self.keys:
            return -1
        self.useKey(key)
        return self.keys[key].v


    def put(self, key: int, value: int) -> None:
        print("PUT", key, value)
        print(self)
        # move to end if already in cache
        if key in self.keys:
            self.useKey(key)
            self.keys[key].v = value
            return

        curNode = Node(key, value)
        if len(self.keys) == self.capacity:
            curHead = self.head
            self.head = self.head.n
            if self.head:
                self.head.p = None
            if self.tail == curHead:
                self.tail = None
            del self.keys[curHead.k]
            del curHead

        print(self)
        if len(self.keys) == 0:
            self.head = curNode
            self.tail = curNode
        else:
            self.tail.n = curNode
            curNode.p = self.tail
            self.tail = curNode
        self.keys[key] = curNode

    def useKey(self, key: int) -> None:
        if self.keys[key] == self.tail:
            return
        node = self.keys[key]
        if node == self.head and self.head.n:
            self.head = self.head.n
        if node.p:
            node.p.n = node.n
        if node.n:
            node.n.p = node.p
        node.p = self.tail
        if self.tail:
            self.tail.n = node
        self.tail = node
        node.n = None

    def __str__(self) -> str:
        cur = self.head
        nodes = []

        while cur:
            if self.head == cur:
                nodes.append("HEAD: ")
            if self.tail == cur:
                nodes.append("TAIL: ")
            nodes.append(str(cur.v))
            cur = cur.n
        return " ".join(nodes)
