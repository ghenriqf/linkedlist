#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


struct linkedList {

    Node* head;
    
    Node* iniciarList(int data) {
        head -> data = data;
        head -> next = nullptr;

        return head;
    }

    void inserir(Node *node, int data) {

        if (head -> next == nullptr) {
            head -> next = node;
            return;
        }
        return inserir(head -> next, int data);
    }

};



int main () {
    int x = 10;
    linkedList list;
    list.head = list.iniciarList(x);

    cout << list.head -> next;
}