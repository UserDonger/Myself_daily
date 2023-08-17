#ifndef __LOGINSIGNUO_H_
#define __LOGISIGNUP_H_

#include"DoubleLinkList.h"

// struct User
// {
//     char * name;
//     char * password;

// };
struct User;

struct User *CreaterUser(char *name, char *pwd);
int IsEqualID(const char *FilePath, char *userName);
int SignUp(char *name, char *pwd);
void StrTok(ElementType element,DLlist * list);
int Login(char * name,char *pwd,DLlist *list);
#endif