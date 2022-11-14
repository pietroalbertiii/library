// Book.h

#ifndef Book_h
#define Book_h

#include <string>
#include "../date/Date.h"

class Book {
public:
	enum class Genre {
		fiction, nonfiction, periodical, biography, children, unknown
	};

	Book();
		Book(std::string ISBN, std::string title, std::string author, Date copyright_date, Genre genre = Genre::unknown);

		std::string isbn() const { return isbn_; }
		std::string title() const { return title_; }
		std::string author() const { return author_; }
		Date copyright() const { return copyright_date_; }
		Genre genre() const { return genre_; }
		bool checked_out() const { return checked_out_; }

		void check_out();
		void check_in();

		std::string genre_as_string() const;

private:
		std::string isbn_;
		std::string title_;
		std::string author_;
		Date copyright_date_;
		Genre genre_;
		bool checked_out_;

		bool isbn_valid() const;
		bool is_number(const std::string &s) const;
	};


std::ostream& operator<<(std::ostream& os, const Book& b);
bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);

#endif