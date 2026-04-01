#include <iostream>
#include <string>
using namespace std;

struct MoneyBundle {
    string serialNumber;
    string currencyType;
    int billCounts[3]; 
};

struct MoneyNode {
    MoneyBundle data;
    MoneyNode* next;
};


void push(MoneyNode*& top, MoneyBundle bundle) {
    MoneyNode* newNode = new MoneyNode;
    newNode->data = bundle;
    newNode->next = top;
    top = newNode;
}

bool pop(MoneyNode*& top, MoneyBundle& removed) {
    if (top == NULL) {
        cout << "No money!\n";
        return false;
    }
    MoneyNode* temp = top;
    removed = top->data;
    top = top->next;
    delete temp;
    return true;
}

void displayStack(MoneyNode* top) {
    cout << "\n Money in bank \n";
    while (top != NULL) {
        cout << "Seri: " << top->data.serialNumber
             << ", Tur: " << top->data.currencyType
             << ", [100:" << top->data.billCounts[0]
             << ", 50:" << top->data.billCounts[1]
             << ", 20:" << top->data.billCounts[2] << "]\n";
        top = top->next;
    }
}



#define SIZE 5

struct Customer {
    string customerName;
    string transactionType;
};

struct CircularQueue {
    Customer arr[SIZE];
    int front;
    int rear;
};

void initQueue(CircularQueue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isFull(CircularQueue& q) {
    return (q.rear + 1) % SIZE == q.front;
}

bool isEmpty(CircularQueue& q) {
    return q.front == -1;
}

void enqueue(CircularQueue& q, Customer c) {
    if (isFull(q)) {
        cout << "Kuyruk dolu!\n";
        return;
    }

    if (isEmpty(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % SIZE;
    }

    q.arr[q.rear] = c;
}

bool dequeue(CircularQueue& q, Customer& c) {
    if (isEmpty(q)) {
        cout << "Tail is empty!\n";
        return false;
    }

    c = q.arr[q.front];

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front = (q.front + 1) % SIZE;
    }

    return true;
}

void displayQueue(CircularQueue& q) {
    cout << "\n--- Waiting Customers ---\n";

    if (isEmpty(q)) {
        cout << "Tail is empty.\n";
        return;
    }

    int i = q.front;
    while (true) {
        cout << "Ad: " << q.arr[i].customerName
             << ", Islem: " << q.arr[i].transactionType << endl;

        if (i == q.rear)
            break;

        i = (i + 1) % SIZE;
    }
}



int main() {
    MoneyNode* stackTop = NULL;
    CircularQueue queue;
    initQueue(queue);

    

    MoneyBundle m1 = {"A123", "TL", {10, 5, 2}};
    MoneyBundle m2 = {"B456", "USD", {7, 3, 1}};

    push(stackTop, m1);
    push(stackTop, m2);

    Customer c1 = {"Fatih", "Withdraw"};
    Customer c2 = {"ELif", "Deposit"};

    enqueue(queue, c1);
    enqueue(queue, c2);

    
    displayStack(stackTop);
    displayQueue(queue);

    
    cout << "\n--- Process  started ---\n";

    Customer servedCustomer;
    MoneyBundle usedMoney;

    if (dequeue(queue, servedCustomer) && pop(stackTop, usedMoney)) {
        cout << "Customer: " << servedCustomer.customerName << " received service.\n";
        cout << "The series of currency used: " << usedMoney.serialNumber << endl;
    }
    
    displayStack(stackTop);
    displayQueue(queue);

    return 0;
}