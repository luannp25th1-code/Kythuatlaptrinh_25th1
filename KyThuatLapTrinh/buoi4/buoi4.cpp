#include <iostream>
#include <string>
#include <Account.h>
#include <LinkedList.h>
using namespace std;

int main()
{
    LinkedList<Account> account = { NULL };
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
            //books.Show();
            break;
        }
        case 2: {
            /*Book b;
            cin >> b;
            Node* newNode = new Node;
            newNode->Create(b);
            books.AddFirst(newNode);*/
            break;
        }
        case 3: {
            int removeId;
            cout << "Enter book's id to remove: ";
            cin >> removeId;
            bool res = books.Remove(removeId);
            if (res)
                cout << "Remove book successfully" << endl;
            else
                cout << "Invalid vook id" << endl;
            break;
        }
        case 4: {
            int updateId;
            cout << "Enter book's id to update: ";
            cin >> updateId;
            bool res = books.Update(updateId);
            if (res)
                cout << "Update book successfully" << endl;
            else
                cout << "Invalid book id" << endl;
            break;
        }
        case 5: {
            string bookName;
            cout << "Enter book ' s name to find : ";
            cin.ignore();
            getline(cin, bookName);
            Book* res = books.Find(bookName);
            if (res != NULL) {
                cout << *res;
            }
            else {
                cout << "No book with name : " << bookName << endl;
            }
            break;
        }
        case 6: {
           // books.Export("25TH1.dla");
            //cout << "Exported successfully" << endl;
            break;
        }
        case 7: {
            //books.Export("25TH1.dla");
            //cout << "Exported successfully" << endl;
            break;
        }
        case 0: {
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