#include "library.h"
#include <iostream>
#include <algorithm>
using std::find;
using std::cout;

library::library()
    {
        library_active_transactions_={};
        library_books_={};
        library_patrons_={};
    }
    

library::library(vector <transaction>& library_active_transactions,vector <Book>& library_books,vector <Patron>& library_patrons)
    : library_active_transactions_{library_active_transactions},
      library_books_{library_books},
      library_patrons_{library_patrons}
{

}

void library::checkout_book(Book& checkout_book,Patron& checkout_patron, Date& checkout_date)
{
    auto book_pos=find(library_books_.begin(),library_books_.end(),checkout_book);
    auto patron_pos=find(library_patrons_.begin(),library_patrons_.end(),checkout_patron);

    if (((book_pos!=library_books_.end()) && patron_pos!=library_patrons_.end()))
    {
        (*book_pos).check_out();
        (*patron_pos).set_fees(100);

        transaction new_transaction{checkout_book,checkout_patron,checkout_date};
        library_active_transactions_.push_back(new_transaction);
    }

    else
    {
        cout<<"either the book or the patron does not exist in the library\n\n\n";
        exit(1);
    }

}

void library::view_books() const
{
    for (auto it=library_books_.begin(); it!=library_books_.end(); it++)
    {
        cout<<*it <<"\n\n";
    }
}

void library::view_active_transactions() const
{
    for (auto it=library_active_transactions_.begin(); it!=library_active_transactions_.end(); it++)
    {
        cout<<"BOOK:\n";
        cout<<(*it).transaction_book <<"\n\n";
        cout<<"patron:\n";
        cout<<(*it).transaction_patron <<"\n\n";
        cout<<"date:\n";
        cout<<(*it).transaction_date <<"\n\n\n\n";
    }
}