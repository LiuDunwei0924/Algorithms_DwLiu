#include <iostream>

struct Node {
        int _value;
        Node *_next;
};

class link_list {
public:
        link_list() {_head = NULL;}
        ~link_list() {}

        Node* search(int value);
        bool find(int value);
        bool ins(int value);
        bool del(int value);
        void show();

private:
        Node *_head;
};

Node * link_list::search(int value) {
        if (NULL == _head) {
                return NULL;
        } 

        Node *curNode = _head;
        while (curNode && curNode->_value < value) {
                curNode = curNode->_next;
        }
        return curNode;
}

bool link_list::find(int value) {
        Node *tempNode = search(value);
        if (tempNode == NULL) return false;
        return tempNode->_value == value;
}

bool link_list::ins(int value) {
        //链表为空时
        if (_head == NULL) {
                _head = new Node();
                _head->_value = value;
                _head->_next = NULL;
                return true;
        }
        //链表不为空
        Node *prevNode = NULL;
        Node *curNode = _head;
        while (curNode && curNode->_value < value) {
                prevNode = curNode;
                curNode = curNode->_next;
        }
        //在末尾插入节点
        if (curNode == NULL) {
                curNode = new Node();
                curNode->_value = value;
                curNode->_next = NULL;
                prevNode->_next = curNode;
                return true;
        }

        if (curNode->_value == value) {
                return false;
        } else {
                //在头部插入节点
                if (curNode == _head) {
                        prevNode = new Node();
                        prevNode->_value = value;
                        prevNode->_next = curNode;
                        _head = prevNode;
                        return true;
                } else {
                        Node *newNode = new Node();
                        newNode->_value = value;
                        newNode->_next = curNode;
                        prevNode->_next = newNode;
                        return true;
                }
        }

        return false;
}

bool link_list::del(int value) {
        if (_head == NULL) {
                return false;
        }

        Node *prevNode = NULL;
        Node *curNode = _head;
        while (curNode && curNode->_value < value) {
                prevNode = curNode;
                curNode = curNode->_next;
        }
        //未找到节点
        if (curNode == NULL) {
                return false;
        } else {
                if (curNode->_value == value) {        
                        if (curNode == _head) { //删除头节点
                                _head = curNode->_next;
                                delete curNode;
                                curNode = NULL;
                                return true;
                        } else {
                                prevNode->_next = curNode->_next;
                                delete curNode;
                                curNode = NULL;
                                return true;
                        }
                }
        }

        return false;
}

void link_list::show() {
        Node *curNode = _head;

        while (curNode != NULL) {
                std::cout << curNode->_value << "->";
                curNode = curNode->_next;
        }
        std::cout << "NULL" << std::endl;
        return ;
}

int main() {
        link_list list;
        list.ins(2);
        list.show();
        list.ins(5);
        list.ins(3);
        list.show();
        list.ins(1);
        list.show();
        list.ins(4);
        list.show();
        list.ins(4);
        list.show();

        list.del(2);
        list.show();
        list.del(2);
        list.show();
        list.del(1);
        list.show();
        list.del(5);
        list.show();
        return 0;
}