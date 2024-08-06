#ifndef STRINGDINAMICO_H_INCLUDED
#define STRINGDINAMICO_H_INCLUDED
#include "boolean.h"

const int MAX=80;
typedef char * string;

void StrCrear (string &str);

int strlar (string str);

void print (string str);

void scanDinamico (string &str);

boolean strmen(string str, string str2);

boolean streq(string str, string str2);

void strcopDinamico (string &str, string str2);

void strconDinamico(string &str, string str2);

void strswapDinamico(string &str, string &str2);

void StrDestruir (string &str);

boolean CodigoMayor (string s1, string s2);

#endif // STRINGDINAMICO_H_INCLUDED
