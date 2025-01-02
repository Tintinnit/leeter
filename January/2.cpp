#include <iostream>
using namespace std;

// 2. Add Two Numbers

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        // Save the next node
        next = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    return prev; // New head of the reversed list
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* output = nullptr;
    bool carry = false;

    // Process both lists
    while (l1 != nullptr || l2 != nullptr || carry) {
        int value = (carry ? 1 : 0); // Start with the carry value

        if (l1 != nullptr) {
            value += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            value += l2->val;
            l2 = l2->next;
        }

        carry = (value >= 10);
        value %= 10;

        output = new ListNode(value, output);
    }

    if (carry) {
        output = new ListNode(1, output);
    }
    return reverseLinkedList(output);
}


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* other = new ListNode(1);
    other->next = new ListNode(2);

    printList(head);
    printList(other);

    ListNode * sum = addTwoNumbers(head, other);

    printList(sum);
}
