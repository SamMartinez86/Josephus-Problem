// JosephusProblem.cpp
// Sam Martinez group project for computational structures
//

#include <iostream>
using namespace std;

//struct for node
struct Node
{
    int data;
    struct Node* next;
};

// create new node for linked list
Node* newNode(int data)
{
    //create new node "temp"
    Node* temp = new Node;

    //make temps pointer
    temp->next = temp;
    temp->data = data;
    return temp;
}

void killPeople(int m, int n)
{
    // Create a circular linked list of
    // size N.
    // data in first node is 1
    Node* head = newNode(1);
    Node* prev = head;
    for (int i = 2; i <= n; i++)
    {
        prev->next = newNode(i);
        prev = prev->next;
    }
    prev->next = head; // Connect last
                       // node to first

    /* while only one node is left in the
    linked list*/
    Node* ptr1 = head, * ptr2 = head;
    while (ptr1->next != ptr1)
    {
        // k-th node
        int count = 1;
        while (count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }

        /* Remove the k-th node */
        ptr2->next = ptr1->next;
        ptr1 = ptr2->next;
    }

    //dereference and print
    int* num = &ptr1->data;
    cout << "Last person left standing: " << *num << endl;
}


int main()
{
    // Create variables
    int n = 0;
    int m = 0;

    // Amount of people in circle user input 
    cout << "Enter number of people in circle: ";
    cin >> n;


    // Amount to be skipped user input
    cout << "Enter number of people skipped in circle: ";
    cin >> m;


    killPeople(m, n);
    return 0;
}


