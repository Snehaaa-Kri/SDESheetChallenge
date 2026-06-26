class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp; //key, node*
public:

    void deleteNode(Node* node){
        Node* prevnode = node->prev;
        Node* nextnode = node->next;

        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    void insertafterhead(Node* node){
        Node* nextnode = head->next;
        head->next = node;
        node->prev = head;
        nextnode->prev = node;
        node->next = nextnode;
    }


    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mp.clear();
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* node = mp[key];
        deleteNode(node);
        insertafterhead(node);
        return node->val;

    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->val = value; //val update if node already present

            deleteNode(node);
            insertafterhead(node);
        }
        else{
            if(mp.size() == cap){
                Node* tobedeleted = tail->prev;
                mp.erase(tobedeleted->key);
                deleteNode(tobedeleted);
            }

            Node* newnode = new Node(key, value);
            mp[key] = newnode;
            insertafterhead(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */