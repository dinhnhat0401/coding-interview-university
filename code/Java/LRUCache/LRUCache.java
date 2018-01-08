import java.util.HashMap;

class LRUCache {
    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        public Node(int k, int v) {
            this.key = k;
            this.value = v;
            this.prev = null;
            this.next = null;
        }
    }
    private int capacity;
    Node head = null;
    Node tail = null;
    HashMap<Integer, Node> map;
    public LRUCache(int capacity) {
        if (capacity <= 0) {
            System.out.println("Capacity must be an positive integer!");
            return;
        }
        this.capacity = capacity;
        map = new HashMap<Integer, Node>();
    }

    public int get(int key) {
        Node n = map.get(key);
        // if key not exist -> return -1
        if (n == null) return -1;

        temporaryRemoveNode(n);
        setNode(n);

        return n.value;
    }

    public void debug() {
        Node current = head;
        while (current != null) {
            System.out.printf("[%d, %d]->", current.key, current.value);
            current = current.next;
        }
        System.out.println("");
    }

    public void put(int key, int value) {
        Node n = map.get(key);

        // create new node
        Node newNode = new Node(key, value);

        // if key exist in hash table -> update value
        if (n != null) {
            n.value = value;
            temporaryRemoveNode(n);
            setNode(n);
        } else {
             // if reach capacity -> remove least recently used element
            if (map.size() == this.capacity) {
                map.remove(head.key);
                head = head.next;
                if (head != null) head.prev = null;
            }
            setNode(newNode);
            // add new (key, value) to hash map
            map.put(key, newNode);
        }
    }

    void temporaryRemoveNode(Node n) {
        // if n is head
        if (n.prev == null) {
            head = n.next;
        }

        // if n is tail
        if (n.next == null) {
            tail = n.prev;
        }

        // remove node from current position
        if (n.prev != null) n.prev.next = n.next;
        if (n.next != null) n.next.prev = n.prev;
    }

    void setNode(Node newNode) {
        // add new node to DLL
        if (head == null) head = newNode;

        newNode.prev = tail;
        newNode.next = null;
        if (tail != null) tail.next = newNode;
        tail = newNode;
    }
}
