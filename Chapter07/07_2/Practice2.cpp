#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *title;
    char *isbn;
    int price;

public:
    Book(char *bTitle, char *bIsbn, int bPrice) : price(bPrice)
    {
        title = new char[strlen(bTitle) + 1];
        isbn = new char[strlen(bIsbn) + 1];
        strcpy(title, bTitle);
        strcpy(isbn, bIsbn);
    }
    void ShowBookInfo() const
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;

public:
    EBook(char *ebTitle, char *ebIsbn, int ebPrice, char *ebDRMKey) : Book(ebTitle, ebIsbn, ebPrice)
    {
        DRMKey = new char[strlen(ebDRMKey) + 1];
        strcpy(DRMKey, ebDRMKey);
    }
    void ShowEBookInfo() const
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
};

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}