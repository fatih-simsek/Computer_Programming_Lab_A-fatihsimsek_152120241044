#include <iostream>
#include <string>
using namespace std;


struct Page {
    string url;
    string title;
    int accessTime[3]; 
    Page* next;
    Page* prev;
};

Page* head = NULL;
Page* current = NULL;


Page* createPage(string url, string title, int h, int m, int s) {
    Page* newPage = new Page;
    newPage->url = url;
    newPage->title = title;
    newPage->accessTime[0] = h;
    newPage->accessTime[1] = m;
    newPage->accessTime[2] = s;
    newPage->next = NULL;
    newPage->prev = NULL;
    return newPage;
}


void visit(string url, string title, int h, int m, int s) {
    Page* newPage = createPage(url, title, h, m, s);

    if (head == NULL) {
        head = newPage;
        current = newPage;
    } else {
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }
}


void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
    } else {
        cout << "No previous page!\n";
    }
}


void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
    } else {
        cout << "No next page!\n";
    }
}


void deleteCurrent() {
    if (current == NULL) return;

    Page* temp = current;

    
    if (current == head) {
        head = current->next;
        if (head != NULL) head->prev = NULL;
        current = head;
    }
    else {
        if (current->prev != NULL)
            current->prev->next = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;

     
        if (current->next != NULL)
            current = current->next;
        else
            current = current->prev;
    }

    delete temp;
}


void displayHistory() {
    if (head == NULL) {
        cout << "History is empty!\n";
        return;
    }

    Page* temp = head;

    while (temp != NULL) {
        if (temp == current)
            cout << ">> CURRENT PAGE <<\n";

        cout << "URL: " << temp->url << endl;
        cout << "Title: " << temp->title << endl;

        cout << "Time: ";
        for (int i = 0; i < 3; i++) {
            cout << temp->accessTime[i];
            if (i < 2) cout << ":";
        }
        cout << endl;

        cout << "----------------------\n";
        temp = temp->next;
    }
}


void clearHistory() {
    Page* temp = head;
    while (temp != NULL) {
        Page* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
    current = NULL;
}


int main() {
    int choice;
    string url, title;
    int h, m, s;

    do {
        cout << "\n1. Visit Page\n2. Back\n3. Forward\n4. Delete Current\n5. Display History\n6. EXIT\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Time (h m s): ";
                cin >> h >> m >> s;
                visit(url, title, h, m, s);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                deleteCurrent();
                break;

            case 5:
                displayHistory();
                break;

            case 6:
                clearHistory();
                cout << "Memory cleaned. Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}