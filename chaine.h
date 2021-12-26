


typedef struct freq {
    char car;
    int nb;
} freq;




void strinsert(char* M, char* T, int i);
void strninsert(char* M, char* T, int i, int n);
void triertab(char* s);
void normaliser(char* s);
char* alphabet(char* s);
int freqchar(char* M,char c);
freq* frequence(char* s);
char* strnchr(char* s,char c, int n);
int distance(char* s1,char* s2);
char* strnstr(const char* s, char* c, int n);
char * strrstr(char * s,char * p);
void strndel(char* M,int i, int n);