#include "StringDinamico.h"

void StrCrear (string &str){
 str= new char[1];
 str[0]='\0';
}

int strlar (string str){
int i=0, largo=0;
while(str[i]!='\0' && i<MAX-1){
   largo++;
   i++;
}
return(largo);
}

void print (string str){
int i=0;
while(str[i]!='\0' && i<MAX){
    printf("%c", str[i]);
    i++;
}
}


void scanDinamico (string &str){
    StrCrear(str);
 string aux=new char [MAX];
 StrCrear(aux);
 char c;
 int i = 0;
 fflush (stdin);
 scanf ("%c", &c);
while (c != '\n' && i < MAX-1)
{
 aux[i] = c;
 i++;
 scanf ("%c", &c);
 }
 aux[i]= '\0';
 strcopDinamico(str,aux);
 StrDestruir(aux);
}

boolean strmen(string str, string str2){
boolean menor;
int i=0, valor1=0,valor2=0;
while(str[i]!='\0'){
    valor1+= str[i];
    i++;
}
i=0;
while(str2[i]!='\0'){
    valor2+=str2[i];
    i++;
}

if(valor1<valor2)
    menor=TRUE;
else
    menor=FALSE;

return(menor);
}

boolean streq(string str, string str2){
    int i=0;
    boolean iguales=TRUE;
    if(strlar(str)!= strlar(str2))
        iguales=FALSE;
    while(iguales && str[i]!='\0'){
            if(str[i]!=str2[i])
                iguales=FALSE;
            else
                i++;
    }

    return(iguales);
}

void strcopDinamico (string &str, string str2){
int cant=strlar(str2);
int i=0;

StrDestruir(str);
str= new char[cant];
while(str2[i]!='\0'){
    str[i]=str2[i];
    i++;
}
str[i]='\0';
}


void strconDinamico(string &str, string str2){
string aux;
StrCrear(aux);
int largo= strlar(str) + strlar(str2) + 1;
strcopDinamico(aux, str);
StrDestruir(str);
str= new char [largo];
int i=0;
int j=0;
while(aux[j]!='\0' && i<MAX-1){
    str[i]=aux[j];
    i++;
    j++;
}
j=0;
while(str2[j]!='\0' && i<MAX-1){
    str[i]=str2[j];
    i++;
    j++;
}
str[i]='\0';
StrDestruir(aux);
}

void strswapDinamico(string &str, string &str2){
string aux;
aux= str;
str=str2;
str2=aux;
}


void StrDestruir (string &str){
    delete[]str;
    str=NULL;
}

boolean CodigoMayor (string s1, string s2){
    boolean iguales=TRUE;
    int i=0;
    while(iguales && i<MAX){
        if(s1[i] != s2[i] )
            iguales=FALSE;
        else
            i++;
    }
    if(s1[i]> s2[i])
        return TRUE;
    else
        return FALSE;
}
