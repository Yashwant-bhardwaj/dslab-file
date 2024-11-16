// Singly Linked List Implementation in C++:
#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct Node {
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key) {
            Node* prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }
        Node* prev = temp;
        prev->next = temp->next;
        delete temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Test case for Singly Linked List
int main() {
    SinglyLinkedList sll;
    sll.insert(10);
    sll.insert(20);
    sll.insert(30);
    cout << "Original List: ";
    sll.traverse();
    sll.deleteNode(20);
    cout << "After deleting 20: ";
    sll.traverse();
    return 0;
}
// Output for Singly Linked List:
// Original List: 30 -> 20 -> 10 -> NULL
// After deleting 20: 30 -> 10 -> NULL

// Doubly Linked List Implementation in C++:
#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }
        temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        delete temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Test case for Doubly Linked List
int main() {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    cout << "Original List: ";
    dll.traverse();
    dll.deleteNode(20);
    cout << "After deleting 20: ";
    dll.traverse();
    return 0;
}
// Output for Doubly Linked List:
// Original List: 30 <-> 20 <-> 10 <-> NULL
// After deleting 20: 30 <-> 10 <-> NULL

 // Circular Linked List Implementation in C++:
 #include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void deleteNode(int key) {
        Node* temp = head;
        if (temp != nullptr && temp->data == key) {
            if (temp->next == head) {
                delete temp;
                head = nullptr;
                return;
            }
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }
        while (temp->next != head && temp->data != key) {
            temp = temp->next;
        }
        if (temp->data == key) {
            Node* prev = head;
            while (prev->next != temp) {
                prev = prev->next;
            }
            prev->next = temp->next;
            delete temp;
        } else {
            cout << "Node with value " << key << " not found." << endl;
        }
    }

    void traverse() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "Back to head" << endl;
    }
};

// Test case for Circular Linked List
int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cout << "Original List: ";
    cll.traverse();
    cll.deleteNode(20);
    cout << "After deleting 20: ";
    cll.traverse();
    return 0;
}
// output of this code is 

// Original List: 30 -> 20 -> 10 -> Back to head
// After deleting 20: 30 -> 10 -> Back to head

// postfix calculator 

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> s;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));  // Push operand (numbers) to stack
        } else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            switch (token[0]) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                default: cout << "Invalid operator!" << endl; return -1;
            }
        }
    }
    return s.top();  // The result will be the only element left in the stack
}

int main() {
    string expression = "3 4 + 2 * 7 /";  // Example postfix expression
    cout << "Postfix Expression: " << expression << endl;
    cout << "Result: " << evaluatePostfix(expression) << endl;
    return 0;
}

// output of the code is 
// Postfix Expression: 3 4 + 2 * 7 /
// Result: 2

 // 2. Queue-Based System Simulation:
 #include <iostream>
#include <queue>
#include <string>
using namespace std;

class TicketingSystem {
private:
    queue<string> q;
    
public:
    // Add customer to the queue
    void addCustomer(const string& customerName) {
        q.push(customerName);
        cout << "Customer " << customerName << " added to the queue." << endl;
    }

    // Serve the next customer in the queue
    void serveCustomer() {
        if (q.empty()) {
            cout << "No customers in the queue!" << endl;
        } else {
            cout << "Serving customer: " << q.front() << endl;
            q.pop();
        }
    }

    // Show all customers waiting in the queue
    void showQueue() {
        if (q.empty()) {
            cout << "No customers in the queue!" << endl;
            return;
        }
        cout << "Customers in queue: ";
        queue<string> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    TicketingSystem ts;

    ts.addCustomer("Alice");
    ts.addCustomer("Bob");
    ts.addCustomer("Charlie");

    ts.showQueue();
    
    ts.serveCustomer();
    ts.serveCustomer();

    ts.showQueue();
    
    ts.serveCustomer();
    ts.serveCustomer();  // Empty queue test

    return 0;
}
// output of this code is 
// Customer Alice added to the queue.
// Customer Bob added to the queue.
// Customer Charlie added to the queue.
// Customers in queue: Alice Bob Charlie 
// Serving customer: Alice
// Serving customer: Bob
// Customers in queue: Charlie 
// Serving customer: Charlie
// No customers in the queue!

// C++ Code for PriorityQueue Using Heaps:

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    priority_queue<int> pq;  // Max-heap by default
    
public:
    // Insert element into the priority queue
    void insert(int data) {
        pq.push(data);
        cout << "Inserted " << data << " into the priority queue." << endl;
    }

    // Remove and return the highest priority element
    void pop() {
        if (pq.empty()) {
            cout << "Priority queue is empty!" << endl;
        } else {
            cout << "Removed " << pq.top() << " from the priority queue." << endl;
            pq.pop();
        }
    }

    // Return the highest priority element without removing it
    void peek() {
        if (pq.empty()) {
            cout << "Priority queue is empty!" << endl;
        } else {
            cout << "Highest priority element: " << pq.top() << endl;
        }
    }

    // Show all elements in the priority queue
    void showQueue() {
        if (pq.empty()) {
            cout << "Priority queue is empty!" << endl;
            return;
        }
        cout << "Priority queue elements: ";
        priority_queue<int> temp = pq;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(20);

    pq.showQueue();

    pq.peek();
    
    pq.pop();
    pq.showQueue();
    
    pq.pop();
    pq.pop();
    pq.pop();  // Empty queue test

    return 0;
}
 // Output for PriorityQueue Using Heaps:
 Inserted 30 into the priority queue.
Inserted 10 into the priority queue.
Inserted 20 into the priority queue.
Priority queue elements: 30 20 10 
Highest priority element: 30
Removed 30 from the priority queue.
Priority queue elements: 20 10 
Removed 20 from the priority queue.
Removed 10 from the priority queue.
Priority queue is empty!

