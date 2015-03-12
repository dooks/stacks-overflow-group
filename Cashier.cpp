
#include "Cashier.h" 
#include <iostream>
#include <vector>
#include <string>
#include "inventory.h"
#include "book.h"

Cashier::Cashier(Inventory* minv) {
	inv = minv;
}

vector<Book*> Cashier::findISBN(string isbn) {
	/*
	Create temp string for isbn
	Create temporary book list
	Call inventory find book function with temp string and assign to temp book list
	return temporary book list
	*/
	string userisbn = isbn;
	vector<Book*> isbnsearch = inv->findBook(Book::ISBN, &userisbn);
	return isbnsearch;
}
vector<Book*> Cashier::findAuthor(string author) {
	/*
	Create temp string for author
	Create temporary book list
	Call inventory find book function with temp string and assign to temp book list
	return temporary book list
	*/
	string userauth = author;
	vector<Book*> authsearch = inv->findBook(Book::AUTHOR, &userauth);
	return authsearch;
}
vector<Book*> Cashier::findTitle(string title) {
	/*
	Create temp string for title
	Create temporary book list
	Call inventory find book function with temp string and assign to temp book list
	return temporary book list
	*/
	string usertitle = title;
	vector<Book*> titlesearch = inv->findBook(Book::TITLE, &usertitle);
	return titlesearch;
}

bool Cashier::addCart(Book* book) {
	/*
	Add book to cart list
	*/
	m_cartlist.push_back(book);
	return true;
}

bool Cashier::delCart(Book* book) {
	/*
	If book is in cart list
	erase from cart list
	*/
	for (unsigned i = 0; i < m_cartlist.size(); i++)
	{
		if (book == m_cartlist[i]) {
			// Erases element from m_cartlist
			m_cartlist.erase((m_cartlist.begin() + i));
		}
	}
	return true;
}

bool Cashier::clearCart() {
	/*
	Clear whole cart
	*/
	m_cartlist.clear();
	return true;
}

bool Cashier::purchaseCart() {
	/*
	For each item in cart list
	delete book from inventory
	Clear cart list
	*/
	for (unsigned i = 0; i < m_cartlist.size(); i++)
	{
		inv->delBook(m_cartlist[i]);

	}
	m_cartlist.clear();
	return true;
}
double Cashier::getSalesTax(){
	/*
	Returns sales tax
	*/
	double salestax = 1.0875;
	return salestax;
}
double Cashier::getSubTotal(Book* book){
	/*
	if book is in cart list, add retail price to subtotal
	return subtotal
	*/
	double subtotal = 0;
	for (unsigned i = 0; i < m_cartlist.size(); i++)
	{
		if (book == m_cartlist[i]) {
			// If book matches item in list, this item's subtotal is added
			subtotal += m_cartlist[i]->getRetailPrice();
		}
	}
	return subtotal;
}
double Cashier::getTotal(Book* book){

	/*
	if book is in cart list, add retail price to subtotal
	multiply subtotal by salestax
	return total
	*/
	double subtotal = 0;
	double total = 0;
	for (unsigned i = 0; i < m_cartlist.size(); i++)
	{
		if (book == m_cartlist[i]) {
			// If book matches item in list, this item's subtotal is added
			subtotal += m_cartlist[i]->getRetailPrice();
		}
	}
	total = subtotal*getSalesTax();
	return total;
}
