#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Book{
    int bookId;
    string title;
    vector<string> authors;
    vector<string> publishers;
    unordered_map<string, int> copies;

    public:
        void setBookId(int id)
        {
            bookId = id;
        }

        int getBookId()
        {
            return bookId;
        }

        void setBookTitle(string title)
        {
            this->title = title;
        }

        string getBookTitle()
        {
            return title;
        }

        void setAuthors(vector<string> authors)
        {
            for(auto author : authors)
            {
                this->authors.push_back(author);
            }
        }

        void setPublishers(vector<string> publishers)
        {
            for(auto publisher : publishers)
            {
                this->publishers.push_back(publisher);
            }
        }

        void setCopies(vector<string> copies)
        {
            for(auto copy : copies)
            {
                this->copies[copy]++;
            }
        }

        void removeCopies(vector<string> copyIds)
        {
            for(auto id : copyIds)
            {
                copies.erase(id);
            }
        }
};

class BookBuilder{
    Book book;
    public:
        BookBuilder(){
            book = Book();
        }

        void buildBookId(int bookId)
        {
            book.setBookId(bookId);
        }

        void buildBookTitle(string bookTitle)
        {
            book.setBookTitle(bookTitle);
        }

        void buildAuthors(vector<string> authors)
        {
            book.setAuthors(authors);
        }

        void buildPublishers(vector<string> publishers)
        {
            book.setPublishers(publishers);
        }

        void buildCopies(vector<string> copies)
        {
            book.setCopies(copies);
        }

        Book build()
        {
            return book;
        }
};

class Library{
    int no_of_racks;
    vector<unordered_map<string, int>> racks;
    public:
        Library(int no_of_racks)
        {
            this->no_of_racks = no_of_racks;
            unordered_map<string, int> temp;

            for(int i=0;i<no_of_racks;i++)
            {
                racks.push_back(temp);
            }
        }

        int getNoOfRacks()
        {
            return no_of_racks;
        }

        bool checkRackHasCopy(int rackId, int bookId)
        {
            return racks[rackId][to_string(bookId)] > 0;
        }

        void addCopyToRack(int rackId, string copyId, int bookId)
        {
            racks[rackId][copyId]++;
            racks[rackId][to_string(bookId)]++;
        }

        void removeCopy(string copyId, int bookId)
        {
            for(int i=0;i<no_of_racks;i++)
            {
                if(racks[i].find(copyId) != racks[i].end())
                {
                    racks[i].erase(copyId);
                    racks[i].erase(to_string(bookId));
                    break;
                }
            }
        }

        void printAllData()
        {
            for(int i=0;i<no_of_racks;i++)
            {
                cout<<"Rack No: "<<(i+1)<<endl;
                for(auto it = racks[i].begin(); it != racks[i].end(); it++)
                {
                    cout<<it->first<<" "<<it->second<<endl;
                }
            }
        }
};

class BookFactory{
    unordered_map<int, Book*> id_to_book_map;
    unordered_map<string, Book*> title_to_book_map;
    unordered_map<string, Book*> copy_to_book_map;

    public:
        Book createBook(int bookId, string title, vector<string> authors, vector<string> publishers, vector<string> copies, Library* lib)
        {
            BookBuilder bookBuilder;

            bookBuilder.buildBookId(bookId);
            bookBuilder.buildBookTitle(title);
            bookBuilder.buildAuthors(authors);
            bookBuilder.buildPublishers(publishers);
            bookBuilder.buildCopies(copies);
            Book book = bookBuilder.build();

            id_to_book_map[bookId] = &book;
            title_to_book_map[title] = &book;
            for(auto copy : copies)
            {
                copy_to_book_map[copy] = &book;
            }

            addCopiesToRacks(copies, lib);

            return book;
        }

        void removeCopy(string copyId, Library* lib)
        {
            Book* bookPtr = getBookFromCopy(copyId);
            int bookId = bookPtr->getBookId();
            bookPtr->removeCopies({copyId});
            copy_to_book_map.erase(copyId);
            lib->removeCopy(copyId, bookId);
        }

        Book* getBookFromId(int id)
        {
            return id_to_book_map[id];
        }

        Book* getBookFromTitle(string title)
        {
            return title_to_book_map[title];
        }

        Book* getBookFromCopy(string copy)
        {
            return copy_to_book_map[copy];
        }

        void addCopiesToRacks(vector<string> copies, Library* lib)
        {
            int rack_no = 0;
            int total_racks = lib->getNoOfRacks();

            int copy_pointer = 0;
            int total_copies = copies.size();

            int bookId = getBookFromCopy(copies[0])->getBookId();

            while(rack_no < total_racks && copy_pointer < total_copies)
            {
                if(!lib->checkRackHasCopy(rack_no, bookId))
                {
                    lib->addCopyToRack(rack_no, copies[copy_pointer], bookId);
                    copy_pointer++;
                }

                rack_no++;
            }
        }
};

int main()
{
    Library lib1(10);

    BookFactory bookFactory;
    bookFactory.createBook(1, "title 1", {"Jigar"}, {"Nilesh"}, {"copy1", "copy2"}, &lib1);
    bookFactory.createBook(2, "title 2", {"Jigar"}, {"Nilesh"}, {"copy3", "copy5"}, &lib1);
    bookFactory.createBook(3, "title 3", {"Jigar"}, {"Nilesh"}, {"copy4", "copy6"}, &lib1);

    Book* book1 = bookFactory.getBookFromCopy("copy6");

    cout<<book1->getBookId()<<" "<<book1->getBookTitle()<<endl;

    Book* book2 = bookFactory.getBookFromCopy("copy5");

    cout<<book2->getBookId()<<" "<<book2->getBookTitle()<<endl;

    bookFactory.removeCopy("copy2", &lib1);

    cout<<"Completed Erasing"<<endl;

    lib1.printAllData();
}
