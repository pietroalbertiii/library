#include <iostream>
using std::cout;

#include "library.h"
#include "date/Date.h"
#include "patron/Patron.h"
#include "book/Book.h"

int main(){
    
    library mylibrary;

    Book book1{"9780-4390-2348-1",
        "Hunger Games, The",
        "Collins, Suzanne",
        Date{2008, Date::Month::jan, 1},
        Book::Genre::fiction};
		
    Book book2{"9780-4393-5807-1",
        "Harry Potter and the Order of the Phoenix",
        "Rowling, J.K.",
        Date{2003, Date::Month::apr, 6},
        Book::Genre::children};

    /*
        Book book3{"9781-4165-3932-2",
            "Einstein: His Life and Universe",
            "Isaacson, Walter",
            Date{2007, Date::Month::dec, 1},
            Book::Genre::biography};

        Book book4{"9780-3160-6760-7",
            "Lone Survivor",
            "Luttrell, Marcus",
            Date{2008, Date::Month::jan, 6},
            Book::Genre::nonfiction};
    */

    Patron patron1{"andrea",89,0};
    Patron patron2{"jack",1111,0};

    Date date1{2022,3,3};
    Date date2{1999,2,2};

   
    mylibrary.add_book(book1);
    mylibrary.add_book(book2);

    mylibrary.add_patron(patron1);
    

    mylibrary.checkout_book(book1,patron1,date1);

    mylibrary.view_books();
    mylibrary.view_active_transactions();

    return 0;
}