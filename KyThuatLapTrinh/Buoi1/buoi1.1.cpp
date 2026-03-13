#include <iostream>
#include <vector>
using namespace std;
struct Person {
	int id;
	string name;
	int age;
	string address;
};
int main() {
	vector <Person> list;
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
		//dfasdfsadfsdfsd
		int a;
		cin >> cmd;
		switch (cmd) {
		case 1: {
			break;
		}
		case 2: {
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