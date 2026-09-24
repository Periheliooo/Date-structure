#include <iostream>
#include <cstdio>

template<class T>
class LinkedList {
private:
    struct node {
        T data;
        node* next;
        node(const T& x, node* n = nullptr)
            : data(x), next(n) {}
        node() : next(nullptr){}
    };
    node* head;
    int length;

public:
    void pushFront(T val) {
        head->next = new node(val, head->next);
        length++;
    }

    void pushBack(T val) {
        node *p = head, *q;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = new node(val);
        length++;
    }

    T front() {
        if (head->next == nullptr)
            return T();
        return head->next->data;
    }

    T popFront() {
        if (head-> next == nullptr) {
            return T();
        }
        node* p = head->next;
        head->next = p->next;
        length--;
        T value = p->data;
        delete p;
        return value;
    }

    T popBack() {
        node *p = head;
        if (p-> next == nullptr) {
            return T();
        }
        node *q = p->next;
        while (q->next != nullptr) {
            p = q;
            q = q->next;
        }
        p->next = q->next;
        length--;
        T value = q->data;
        delete q;
        return value;
    }

    int size() {
        return length;
    }

    node* sentinel() {
        return head;
    }

    LinkedList() : head(new node()), length(0) {}

    virtual ~LinkedList() {
        node *p = head, *q;
        while (p != nullptr) {
            q = p->next;
            delete p;
            p = q;
        }
    }

    LinkedList(const LinkedList& other)
        : LinkedList() {
        node* tail = head;
        const node* p = other.head->next;

        while (p != nullptr) {
            tail->next = new node(p->data);
            tail = tail->next;
            p = p->next;
            ++length;
        }
    }

    void print() {
        if (length == 0){
            return;
        }

        node *p = head->next;
        while (p->next != nullptr) {
            std::cout << p->data << ' ';
            p = p->next;
        }
        std::cout << p->data << std::endl;
    }

    virtual const char* name() { return ""; }
    virtual T peak() { return T(); }
    virtual T pop() { return T(); }
    virtual void push(T val) {}
};

template<class T>
class Stack : public LinkedList<T> {
public:
    const char* name() override {
        return "Stack";
    }

    T peak() override {
        return this->front();
    }

    T pop() override {
        return this->popFront();
    }

    void push(T val) override {
        this->pushFront(val);
    }
};

template<class T>
class Queue : public LinkedList<T> {
public:
    const char* name() override {
        return "Queue";
    }

    T peak() override {
        return this->front();
    }

    T pop() override {
        return this->popFront();
    }

    void push(T val) override {
        this->pushBack(val);
    }
};

int main() {
    return 0;
}