#include <bits/stdc++.h>
using namespace std;


// Your code goes here


class Book{
public:
    string title, author;

    Book(string title, string author) : title(title), author(author){
        // this->title = title;
        // this->author = author;
    }

    void display(){
        cout << "Book : " << this->title;
        cout << ", Author : " << this->author << endl;
    }

};

class Library{
public:
    string name;
    vector<Book*> books;

    Library(string name) : name(name){
        // this->name = name;
        // books = new ArrayList<>();
    }

    void addBook(Book* book){
        books.push_back(book);
    }

    void display(){
        cout << "Library : " << this->name << endl;
        for(Book *b: books){
            b->display();
        }
    }

    Library* shallowClone(){
        Library *newLibrary = new Library(this->name);
        newLibrary->books = this->books;
        return newLibrary;
    }

    Library* deepClone(){
        Library *newLibrary = new Library(this->name);
        for(Book *b : this->books){
            Book* newbook = new Book(b->title, b->author);
            newLibrary->addBook(newbook);
        }
        return newLibrary;
    }
};

// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `Library` and the class `Book`.

int main() {

    string name;
    vector<string> titles, authors;

    // Creating the Library class object
    Library* library = new Library(name);

    // Adding the title and author names to the list of books present in the class Library
    for (int j = 0; j < x; j++) {
        library->addBook(new Book(titles[j], authors[j]));
    }

    cout << "Original Library : " << endl;

    // Calling the display function to display the original details that we set in above part of code
    library->display();

    // Cloning objects using shallowClone and deepClone methods
    Library* shallowLibrary = library->shallowClone();
    Library* deepLibrary = library->deepClone();

    int changeIndex;
    string changeTitle, changeAuthor;

    // Changing the title and author of the book present at index changeIndex using the original library object
    library->books[changeIndex]->title = changeTitle;
    library->books[changeIndex]->author = changeAuthor;

    cout << "\nAfter Modification : " << endl;
    cout << "\nOriginal Library : " << endl;

    // Calling the display method through original library object to print the output
    library->display();

    cout << "\nShallow Clone : " << endl;

    // Calling the display method through shallow clone object to print the output
    shallowLibrary->display();

    cout << "\nDeep Clone : " << endl;

    // Calling the display method through deep clone object to print the output
    deepLibrary->display();

    delete library;
    delete shallowLibrary;
    delete deepLibrary;

    return 0;
}

*/

/*
// Below are the output statements

cout << "Library : " << name << endl;
cout << "Book : " << book.title << ", Author : " << book.author << endl;

*/
