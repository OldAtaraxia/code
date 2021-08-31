#include "Message.h"

class Message;

class Folder{
    friend void swap(Folder&, Folder&);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder& operator=(const Folder&);
    ~Folder();

private:
    std::set<Message*> msgs;
    void add_to_Message(const Folder&);
    void remove_from_Message();
    void addMsg(Message *m);
    void remMsg(Message *m);
};