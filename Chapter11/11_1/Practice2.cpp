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
    // 복사 생성자 for 깊은 복사
    Book(const Book &cpy) : price(cpy.price)
    {
        title = new char[strlen(cpy.title) + 1];
        isbn = new char[strlen(cpy.isbn) + 1];
        strcpy(title, cpy.title);
        strcpy(isbn, cpy.isbn);
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
    // 대입 연산자 for 깊은 복사
    Book &operator=(const Book &ref)
    {
        delete[] title;
        delete[] isbn;

        price = ref.price;
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        return *this;
    }
    void ShowBookInfo() const
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
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
    // 복사 생성자 for 깊은 복사
    EBook(const EBook &cpy) : Book(cpy)
    {
        DRMKey = new char[strlen(cpy.DRMKey) + 1];
        strcpy(DRMKey, cpy.DRMKey);
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
    // 대입 연산자 for 깊은 복사
    EBook &operator=(const EBook &ref)
    {
        Book::operator=(ref);
        delete[] DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }
    void ShowEBookInfo() const
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
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