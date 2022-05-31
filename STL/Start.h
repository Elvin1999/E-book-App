#include<iostream>
#include "Functions.h"
using namespace std;

namespace Start {
	Client* CurrentClient;
	class Controller {
	public:
		static void StartProject(){
			DatabaseSection::Init();
			while (true)
			{
				FirstHomeMenu();
				int select = 0;
				cin >> select;
				system("cls");
				if (select == 1) {
					//admin
				}
				else if (select == 2) {
					
					cin.ignore();
					cin.clear();
					cout << "Enter username : " << endl;
					string username;
					cin >> username;
					cout << "Enter password : " << endl;
					string password;
					cin >> password;
					CurrentClient = GetClient(username, password);
					if (CurrentClient->GetId() != -1) {
						ClientHomeMenu();
						cin >> select;
						system("cls");
						if (select == 1) {
							ShowAllBooks();
						}
						else if (select == 2) {
							ShowAllBooks();
							cout << "Enter book id : " << endl;
							int id = 0;
							cin >> id;
							auto book = GetBookById(id);
							cout << "From which date you will take" << endl;
							cout << "Day : "<<endl;
							int day = 0;
							cin >> day;
							cout << "Enter month : " << endl;
							int month = 0;
							cin >> month;
							cout << "Enter year : " << endl;
							int year = 0;
							cin >> year;

							cout << "How many days you take book" << endl;
							int days = 0;
							cin >> days;

							CurrentClient->TakeBook(*book, days, Date{day,month,year});
						}
						else if (select == 3) {
							CurrentClient->ShowAllRents();
						}

					}
					else {
						cout << "ACCESS DENIED" << endl;
					}

					system("pause");
				}
				else {
					cout << "Wrong Selection" << endl;
				}
			}
		}

		static void AdminHomeMenu() {
			cout << "Show All Books" << endl;
			cout << "Show All Rents" << endl;
			cout << "Add Book" << endl;
		}
		static void FirstHomeMenu() {
			cout << "Admin  [1]" << endl;
			cout << "Client [2]" << endl;
		}
		static void ClientHomeMenu() {

			cout << "Show   Books [1]" << endl;
			cout << "Take   Book  [2]" << endl;
			cout << "Show All your rents  [3]" << endl;

		}
	};
}
