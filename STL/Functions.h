#pragma once

#include "Database.h"
using namespace DatabaseSection;


bool ClientExists(const string& username, const string& password) {
	for (int i = 0; i < database.client_count;i++) {
		auto user = database.clients[i]->GetUser();
		if (user.GetUsername() == username &&
			user.GetPassword() == password) {
			return true;
		}
	}
	return false;
}
Client* GetClient(const string& username, const string& password) {
	bool hasUser = ClientExists(username, password);
	if (hasUser) {
		for (int i = 0; i < database.client_count; i++) {
			auto user = database.clients[i]->GetUser();
			if (user.GetUsername() == username &&
				user.GetPassword() == password) {
				return database.clients[i];
			}
		}
	}
	return nullptr;
}


Book* GetBookById(int id) {
	for (int i = 0; i < database.book_count;i++) {
		if (database.books[i]->GetId() == id) {
			return database.books[i];
		}
	}
	return nullptr;
}

void ShowAllBooks() {
	for (int i = 0; i < database.book_count;i++) {
		auto book = database.books[i];
		cout << "Book ID : " << book->GetId() << endl;
		cout << "Title : " <<   book->GetTitle() << endl;
		cout << "Author : " <<  book->GetAuthor() << endl;
		cout << "Price : " <<   book->GetPrice() <<"$" << endl;
		cout << "Rating : " <<  book->GetRating() <<"*"<< endl;
		cout << endl << endl;
	}
}
