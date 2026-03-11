#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* next;
};
void addSong(Node*& head, string songTitle) {
    Node* newNode = new Node;
    newNode->title = songTitle;
    newNode->next = head;
    head = newNode;
    cout << "Song added to playlist.\n";
   }
void listSongs(Node* head) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;
    int count = 1;

    cout << "\nPlaylist:\n";
    while (temp != NULL) {
        cout << count << ". " << temp->title << endl;
        temp = temp->next;
        count++;
    }
}
void searchSong(Node* head, string songTitle) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->title == songTitle) {
            cout << "Song found in playlist.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Song not found.\n";
}
int main() {
    Node* head = NULL;
    int choice;
    string songTitle;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. Search Song\n";
        cout << "3. List Songs\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
switch (choice) {
        case 1:
            cout << "Enter song title: ";
            getline(cin, songTitle);
            addSong(head, songTitle);
            break;

        case 2:
            cout << "Enter song title to search: ";
            getline(cin, songTitle);
            searchSong(head, songTitle);
            break;

        case 3:
            listSongs(head);
            break;

        case 4:
            cout << "Exiting program\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
