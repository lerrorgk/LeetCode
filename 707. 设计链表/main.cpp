class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode():val(0), next(nullptr){}
        LinkedNode(int val):val(val), next(nullptr){}
        LinkedNode(int val, LinkedNode* next):val(val), next(next){}
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode();
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > _size - 1){
            return -1;
        }
        LinkedNode* cur = _dummyHead;
        int idx = -1;
        while(cur){
            if(idx == index) return cur->val;
            cur = cur->next;
            idx++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val, _dummyHead->next);
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next) cur = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0;   
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        int idx = -1;
        while(cur){
            if(idx == index - 1) break;
            cur = cur->next;
            idx++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        LinkedNode* cur = _dummyHead;
        int idx = -1;
        while(cur){
            if(idx == index - 1) break;
            cur = cur->next;
            idx++;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp=nullptr;
        _size--;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */