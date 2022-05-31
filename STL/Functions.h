#pragma once

#include "Database.h"
using namespace DatabaseSection;


bool ClientExists(const string& username, const string& password) {
	for (auto user : database.Clients) {
		if (user.GetUser().GetUsername() == username &&
			user.GetUser().GetPassword() == password) {
			return true;
		}
	}
	return false;
}
Client GetClient(const string& username, const string& password) {
	bool hasUser = ClientExists(username, password);
	if (hasUser) {
		for (auto user : database.Clients) {
			if (user.GetUser().GetUsername() == username &&
				user.GetUser().GetPassword() == password) {
				return user;
			}
		}
	}
	return Client();
}


Book GetBookById(int id) {
	for (auto book : database.Books) {
		if (book.GetId() == id) {
			return book;
		}
	}
	return Book();
}

void ShowAllBooks() {
	for (auto book : database.Books) {
		cout << "Book ID : " << book.GetId() << endl;
		cout << "Title : " << book.GetTitle() << endl;
		cout << "Author : " << book.GetAuthor() << endl;
		cout << "Price : " << book.GetPrice() <<"$" << endl;
		cout << "Rating : " << book.GetRating() <<"*"<< endl;
		cout << endl << endl;
	}
}
