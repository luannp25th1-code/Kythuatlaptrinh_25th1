#include <iostream>
#include <string>
using namespace std;

struct Author {
    int id;
    string name;
    friend istream& operator>>(istream& in, Author& a) {
        cout << "Author information:" << endl;
        cout << "\t+ Id:";
        in >> a.id;
        cout << "\t+ Name: ";
        in.ignore();
        getline(in, a.name);
        return in;
    }
};
struct Book {
    int id;
    string name;
    Author author;
    friend ostream& operator<<(ostream& os, const Book& b) {
        os << "Book information:" << endl;
        os << "\t+Id: " << b.id << endl;
        os << "\t+ Name: " << b.name << endl;
        os << "\t+ Author name: " << b.author.name << endl;
        return os;
    }
    friend istream& operator>>(istream& in, Book& b) {
        cout << "Book information:" << endl;
        cout << "\t+ Id:";
        in >> b.id;
        cout << "\t+ Name: ";
        in.ignore();
        getline(in, b.name);
        in >> b.author;
        return in;
    }
};
struct Node {
    Book data;
    Node* next;
    void Create(Book b) {
        data = b;
        next = nullptr;
    }
};
struct LinkedList {
    Node* head;
    void Show() {
        if (head == NULL) {
            cout << "No book available" << endl;
            return;
        }
        Node* item = head;
        while (item != NULL) {
            cout << item->data;
            item = item->next;
        }
    }
    void AddFirst(Node* p) {
        p->next = head;
        head = p;
    }
};
int main()
{
    LinkedList books = { NULL };
    do {
        system("cls");
        cout << "________BOOK MANAGEMENT_______" << endl;
        cout << "1.Show all books" << endl;
        cout << "2.Add a book" << endl;
        cout << "3.Delete a book" << endl;
        cout << "4.Update a book" << endl;
        cout << "5.Find book" << endl;
        cout << "6.Export to file" << endl;
        cout << "7.Import from file" << endl;
        cout << "0.Exit" << endl;
        cout << "________________________________" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            books.Show();
            break;
        }
        case 2: {
            Book b;
            cin >> b;
            Node* newNode = new Node;
            newNode->Create(b);
            books.AddFirst(newNode);
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        case 7: {
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "Invalid choice, try again" << endl;
            break;
        }
        }
        system("pause");
        cout << "Press any key to continue...";
    } while (true);
}