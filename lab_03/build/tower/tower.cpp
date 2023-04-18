#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int Data;
    char from, to;
    Node* prev;
    Node* next;
};

void Move(Node** headPointer, int disk, char from, char to) {
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


void MoveTower(int disk, char point1, char point2, char temporaryPoint, Node** headPointer) {
    if (disk == 0)
        return;
    
    MoveTower(disk - 1, point1, temporaryPoint, point2, headPointer);

    Move(headPointer, disk, point1, point2); 

    MoveTower(disk - 1, temporaryPoint, point2, point1, headPointer);
}

void print(Node** head) {
    Node* temp = *head;   
    while (temp) {
        cout << "Move disk " << temp->Data << " from peg " << temp->from << " to peg " << temp->to << "\n";
        temp = temp->prev;
    }
}

int main() {
    int N=8;

    Node* head= nullptr; 

    MoveTower(N, 'A', 'C', 'B', &head);

    print(&head);

    while (head) {
        Node* temp = head;
        head = head->prev;
        delete temp;
    }

    return 0;
}