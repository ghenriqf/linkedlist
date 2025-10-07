#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node (int data){
        data = data;
    }
};

struct linkedList {

    Node* head;
    
    void linkedlist() {
        head -> next = nullptr;
    }

    void insert(Node*& head,int data) {

        if (head -> next == nullptr) {
            head -> next = new Node(data);
            return; 
        }
        insert(head -> next,data);
    }

};

int main () {
}