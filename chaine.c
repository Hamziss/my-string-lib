#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "chaine.h"

#define MAX 256



//1er
void strinsert(char* M, char* T, int i){
    char* temp = (char*)malloc(MAX);
    strcpy(temp, M + i);
    M[i] = '\0';
    strcat(M, T);
    strcat(M, temp);
}

//2eme
void strninsert(char* M, char* T, int i, int n){
    char temp[MAX]; 
    strncpy(temp,T,n);
    strinsert(M,temp,i);        
}
//3eme
void triertab(char* s){
char temp;	
	int lg = strlen(s);
	for (int i = 0; i < lg-1; i++) {
		for (int j = i+1; j < lg; j++) {
			if (s[i] > s[j]) {
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
			}
		}
	}
}
void normaliser(char* s){
    int i,lg=strlen(s);
    for(int i=0;i<lg;i++){
        s[i]= tolower(s[i]);
    }
}
char* alphabet(char* s){
    char* alp = (char*)malloc(MAX);alp[0]='\0';
    char* p=s;
    int i=0; 
    normaliser(s);
    for (p=s;*p!='\0';p++){ 
        if(!strchr(alp,*p)){
            alp[i]=*p;
            alp[i+1]='\0';
            i++;
        }      
    }
    triertab(alp);
    return alp;
}
//4eme
int freqchar(char* M,char c){
    int cpt=0;
    for (int i = 0 ;M[i] != '\0'; i++){
        if (M[i]==c){
        ++cpt;
        }
    }
    return cpt;
}
char* alphabet_2(char* s);


//5eme
freq* frequence(char* s){
    char* chaine = alphabet_2(s);
    int i=0;
    freq tab[256];
while (*chaine!='\0')
{
    int cpt = freqchar(s,*chaine);
    tab[i].car=*chaine;
    tab[i].nb=cpt;
    printf("le caractere %c apparait %d\n",tab[i].car,tab[i].nb);
    i++;
    chaine++;
}
    
}

//6eme
char* strnchr(char* s,char c, int n){
    char* p = strchr(s,c);
    int i=0;     
    if(p){
        while( i<n && *s!='\0'){
            if (*(p) == c){            
                ++i;
            }
        ++s;
        ++p;        
        }    
        if(*s != '\0'){return p-1;}
        else {return NULL;}  // cas ou loccurence donner 'n' est plus grand au nombre total doccurence du caractere
    }
    else {return NULL;}   //cas ou le caractere donner nexite pas dans la chaine
}

//7eme
int distance(char* s1,char* s2){    
    int cpt=0;
    //supprimer les caracteres repetitives pour ne pas considerer 2 même caractere comme etant 2 difference
    s1=alphabet(s1);
    s2=alphabet(s2);
    //sauvegarde des debut de poiteurs    
    char* start=s1;
    char* start2=s2;    
    //traitement des caracteres qui sont dans s1 et qui existe pas dans s2
    while (*s1!='\0'){   
        s2=start2;        
        while (*s2!='\0' && *s2!=*s1){       
            s2++;
        }
        if(*s2=='\0'){cpt++;}
      s1++; 
    }
    //traitement des caracteres qui sont dans s2 et qui existe pas dans s1
    s2=start2;  
    while (*s2!='\0'){
        s1=start;        
        while (*s1!='\0' && *s2!=*s1){       
            s1++;
        }
        if(*s1=='\0'){cpt++;}
      s2++;  
    }    
    return cpt;
}

//8eme
 char* strnstr(const char* s, char* c, int n)
{
    int cpt=1;
    char* nth_ptr=strstr(s,c);
    for (cpt=1;nth_ptr != NULL && cpt < n && *c!='\0';cpt++) 
    {
         nth_ptr = strstr(nth_ptr+1, c);
    }
    return nth_ptr;
}

//9eme
char * strrstr(char * s,char * p){
    char*temp=s,*dernier=0;
    while(temp=strstr(temp,p)){         
        dernier=temp++;
        }
    return dernier;
}

//10eme
void strndel(char* M,int i, int n){
    char* temp = (char*)malloc(MAX);
    char* temp2 = (char*)malloc(MAX);
    strncpy(temp,M,i);temp[i]='\0';
    strcpy(temp2,(M+i+n));
    strcat(temp,temp2);
    M=temp;    
}



//EN +
//fonction meme que alphabet mais en considerant les lettres en maj(pour lutiliser dans la qst 5)
char* alphabet_2(char* s){
    char* alp = (char*)malloc(MAX);alp[0]='\0';
    char* p=s;
    int i=0;     
    for (p=s;*p!='\0';p++){ 
        if(!strchr(alp,*p)){
            alp[i]=*p;
            alp[i+1]='\0';
            i++;
        }      
    }
    triertab(alp);
    return alp;
}
