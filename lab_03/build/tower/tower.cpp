#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int Data;
    int from, to;
    Node* prev;
    Node* next;
};

void Move(int disk, int from, int to, Node** headPointer) {
    Node* newMove = new Node;
    newMove->Data = disk;
    newMove->from = from;
    newMove->to = to;
    newMove->prev = *headPointer;
    newMove->next = nullptr;

    if (*headPointer) 
        (*headPointer)->next = newMove;

    *headPointer = newMove;
}

void MoveTower(int disk, int from, int to, int tmp, Node** headPointer) {
    if (disk == 0)
        return;
    
    MoveTower(disk - 1, from, tmp, to, headPointer);

    Move(disk, from, to, headPointer); 

    MoveTower(disk - 1, tmp, to, from, headPointer);
}

void print(Node** head) {
    Node* temp = *head;   
    while (temp) {
        cout << "Move disk " << temp->Data << " from " << temp->from << " to " << temp->to << "\n";
        temp = temp->prev;
    }
}

int main() {
    int N=3;

    Node* head= nullptr; 

    MoveTower(N, 1, 2, 3, &head);

    print(&head);

    while (head) {
        Node* temp = head;
        head = head->prev;
        delete temp;
    }

    return 0;
}