#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* solve(Node* head) {
    Node* dummy = new Node(0); // Dummy node to handle head safely
    dummy->next = head;
    Node* act = dummy; // Active pointer for the last zero node
    Node* temp = head->next;
    int sum = 0;

    while (temp) {
        if (temp->val != 0) {
            sum += temp->val;
        } else {
            act->next = temp;  // Link last zero to current zero
            act = temp;        // Move active pointer
            act->val = sum;    // Set sum at zero position
            sum = 0;           // Reset sum
        }
        temp = temp->next;
    }
    
    return dummy->next; // Fix: Return `dummy->next` instead of `dummy->next->next`
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Test the function
int main() {
    // Example 1: 0 -> 3 -> 1 -> 0 -> 4 -> 2 -> 1 -> 0
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);
   
    Node* result = solve(head);
    printList(result); // Expected output: 4 -> 7

    return 0;
}
