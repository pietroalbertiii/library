#ifndef Library_H
#define Library_H

#include<vector>
using std::vector;

#include "date/Date.h"
#include "patron/Patron.h"
#include "book/Book.h"

struct transaction
{
    Book transaction_book;
    Patron transaction_patron;
    Date transaction_date;
};

class library
{
private:
    vector <transaction> library_active_transactions_;
    vector <Book> library_books_;
    vector <Patron> library_patrons_;

public:
    library(vector <transaction>& library_active_transactions,vector <Book>& library_books,vector <Patron>& library_patrons);
    library();
    
    void add_book(Book& added_book){library_books_.push_back(added_book);}
    void add_patron(Patron& added_patron){library_patrons_.push_back(added_patron);}
    
    void checkout_book(Book& checkout_book,Patron& checkout_patron,Date& checkout_date);
    void view_books() const;
    void view_active_transactions() const;
};


#endif