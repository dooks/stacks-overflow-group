#ifndef CASHIER_H
#define CASHIER_H
#include <iostream>
#include <string>

using namespace std;

class Cashier
{
protected:
	double salestax=1.0875;
	double subtotal;
	double total;
	double amountpaid;
	double amountowed;
	double change;
	string searchISBN;
	string searchTitle;
	double Addbook;
	double Removebook;

	

public:
	string searchISBN() const
	{
		return searchISBN;
		//call to inventory database to search for ISBN, pull info for said book
	}
	string searchTitle() const
	{
		return searchTitle;
		//call to inventory database to search for ISBN, pull info for said book
	}
	double Addbook() const
	{
		return Addbook;
		//return book to inventory database
	}
	double Removebook() const
	{
		return Removebook;
		//remove book from inventory database
	}
	void Displaybook(double ISBN, string title, double retailprice)
	{
		return ISBN, title, retailprice;
		//call to inventory database, display ISBN, title, and price of most recently searched book
	}
	double gettotal() const
	{
		return subtotal*salestax;
		//calculates total by multiplying the subtotal by the tax rate
	}
	double getsubtotal() const
	{
		return retailprice;
		//call to inventory database to retrieve the retail price for the particular book that's been searched
	}
	double amountowed() const
	{
		return total;
		//displays the total charge for purchase
	}
	double change() const
	{
		return amountpaid - amountowed;
		//displays the amount of change owed the customer after initial monetary transaction
	}
	double amountpaid() const
	{
		return amountpaid;
		//user enters amount customer has paid so far
	}
	


};
#endif

