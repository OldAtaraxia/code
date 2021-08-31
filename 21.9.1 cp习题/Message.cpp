#include "Message.h"
#include "Folder.h"
#include <set>

void Message::save(Folder& f){
    f.addMsg(this);
    folders.insert(&f);
}

void Message::remove(Folder& f){
    f.remMsg(this);
    folders.erase(&f);;
}

void Message::add_to_Folders(const Message& m){
    for(auto f: m.folders){
        f->addMsg(this);
    }
}

Message::Message(const Message& m): contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders(){
    for(auto f: folders){
        f->remMsg(this);
    }
}

Message& Message::operator=(const Message &rhs){
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message(){
    remove_from_Folders();
}

void swap(Message& lhs, Message& rhs){
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void Message::addFolder(Folder *f){
    folders.insert(f);
}

void Message::remFolder(Folder *f){
    folders.erase(f);
}

