#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Message(const std::string &str = ""): contents(str){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void addFolder(Folder*);
    void remFolder(Folder*);
};
#endif