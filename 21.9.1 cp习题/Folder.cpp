#include "Folder.h"

void swap(Folder& lhs, Folder& rhs){
    using std::swap;
    for(auto m: lhs.msgs){
        m->remFolder(&lhs);
    }
    for(auto m: rhs.msgs){
        m->remFolder(&rhs);
    }
    swap(lhs.msgs, rhs.msgs);
    for(auto m: lhs.msgs){
        m->addFolder(&lhs);
    }
    for(auto m: rhs.msgs){
        m->addFolder(&rhs);
    }
}

void Folder::addMsg(Message *m){
    msgs.insert(m);
}

void Folder::remMsg(Message *m){
    msgs.erase(m);
}

void Folder::add_to_Message(const Folder &f){
    for(auto m : f.msgs){
        m->addFolder(this);
    }
}

Folder::Folder(const Folder& f):msgs(f.msgs)
{
    for(auto m: f.msgs){
        m->addFolder(this);
    }
}

Folder& Folder::operator=(const Folder &f){
    for(auto m : msgs){
        m->remFolder(this);
    }
    msgs = f.msgs;
    for(auto m: msgs){
        m->addFolder(this);
    }
    return *this;
}

Folder::~Folder(){
    for(auto m : msgs){
        m->remFolder(this);
    }
}