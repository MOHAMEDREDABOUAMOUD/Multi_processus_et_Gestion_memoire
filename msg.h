#ifndef MSG_H
#define MSG_H
#include <iostream>
using namespace std;

class msg
{
public:
    msg();
    void gettab(string,string &tab);
private:
    string tab[100];
};
#endif // MSG_H
