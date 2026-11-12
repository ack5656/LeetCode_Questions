
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // 1. Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // 2. Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // 3. Insert at position (0-based)
    void insertAtPosition(int value, int position) {
        if (position < 0) return;

        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        for (int i = 0; temp != nullptr &&
             i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp == tail) {
            insertAtEnd(value);
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // 4. Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) return;

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    // 5. Delete from end
    void deleteFromEnd() {
        if (tail == nullptr) return;

        Node* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    // 6. Delete at position (0-based)
    void deleteAtPosition(int position) {
        if (position < 0 || head == nullptr) return;

        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 0; temp != nullptr &&
             i < position; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp == tail) {
            deleteFromEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    // 7. Search an element
    bool search(int value) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == value)
                return true;

            temp = temp->next;
        }

        return false;
    }

    // 8. Count nodes
    int countNodes() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // 9. Forward traversal
    void displayForward() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // 10. Backward traversal
    void displayBackward() {
        Node* temp = tail;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }

    // 11. Reverse the linked list
    void reverse() {
        Node* curr = head;

        while (curr != nullptr) {
            swap(curr->prev, curr->next);
            curr = curr->prev;
        }

        swap(head, tail);
    }

    // 12. Destructor
    ~DoublyLinkedList() {
        Node* temp = head;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    dll.insertAtBeginning(5);

    dll.insertAtPosition(15, 2);

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    cout << "Total Nodes: "
         << dll.countNodes() << endl;

    cout << "Search 20: "
         << (dll.search(20) ? "Found" : "Not Found")
         << endl;

    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteAtPosition(1);

    cout << "After deletion: ";
    dll.displayForward();

    dll.reverse();

    cout << "After reversal: ";
    dll.displayForward();

    return 0;
}
