#include <iostream>
#include <string>
using namespace std;
struct Person {
	int id;
	string name;
	friend ostream& operator <<(ostream& os, const Person& p) {
		os << "\t+ Id: " << p.id << endl;
		os << "\t+ Name: " << p.name << endl;
	}
	friend istream& operator >> (istream& in, Person& p) {
		cout << "input person information:" << endl;
	}
};
struct Node {
	Person data;
	Node* next;
};
struct LinkedList {
	Node* head;
	void show() {
		Node* item = head;
		while (item != NULL) {
			cout << "ID: " << item->data.id << endl;
			cout << "Name: " << item->data.name << endl;
			item = item->next;
		}
	}
};

int main()
{
	LinkedList List = {NULL};
	do {
		system("cls");
		cout << "--- HUMAN RESOURCE --------" << endl;
		cout << "1.View person list" << endl;
		cout << "2.Add a person" << endl;
		cout << "3.Remove a person " << endl;
		cout << "4.Find a person by name" << endl;
		cout << "5.Export to file " << endl;
		cout << "6.Import from file" << endl;
		cout << "0.Exit" << endl;
		cout << "------------------------------" << endl;
		cout << "Your command";
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 1: {
			
			break;
		}
		case 2: {
			
			break;
		}
		case 3: {
			int id;
			cout << "Input ID to remove: ";
			cin >> id;
			
			break;
		}
		case 4: {
			string name;
			cout << "Input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = false;
			if (res) {
				cout << "found person with name " << name << endl;
			}
			else {
				cout << "person isn't existed" << endl;
			}
			break;
		}
		case 5: {
			cout << "export successfully" << endl;
			break;
		}
		case 6: {
			cout << "export successfully" << endl;
			break;
		}
		case 0: {
			return 0;
		}
		default:
			cout << "Your command is not found.Try again ..." << endl;
			break;
		}
		cout << "Press Enter to continue...";
		cin.ignore();
		cin.get();
	} while (true);
	return 0;

}