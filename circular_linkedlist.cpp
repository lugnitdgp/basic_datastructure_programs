#include <iostream>

using namespace std;

//Declaring a node.
struct Node {
    int data;           //data part of node.
    struct Node* next;  //pointer to next node.
};

struct Node* createNode(int value) {
    struct Node* node;
    node = (struct Node*)malloc(sizeof(struct Node));  //allocating memory to node.

    if (node == NULL) {
        cout << "Overflow" << endl;
        ;  //if there is no space in memory
    } else {
        node->data = value;
        node->next = NULL;
    }

    return node;
}

struct Node* createList() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));  //allocating memory to node.
    if (header == NULL) {
        cout << "Overflow" << endl;  //if there is no space in memory
    } else {
        header->data = 0;
        header->next = NULL;
    }

    return header;
}

void insert(struct Node*& list, int value) {
    struct Node* v = list;

    struct Node* n = createNode(value);
    n->next = list;

    if (list->next != NULL) {  //list is empty

        while (v->next != list) {
            v = v->next;
            cout << v->data << endl;
        }
        v->next = n;
    } else {
        n->next = n;
        list = n;
    }
}

//display of linkedlist
void displaylist(struct Node* header) {
    struct Node* v = header;
    do {
        cout << v->data << " ";
        v = v->next;
    } while (v != header);
}

//Main Body
int main() {
    struct Node* list = createList();

    insert(list, 3);
    insert(list, 1);
    insert(list, 7);
    insert(list, 2);
    insert(list, 9);

    displaylist(list);
    return 0;
}
