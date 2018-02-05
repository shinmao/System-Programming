#include <stdio.h>
#include <string.h>

struct Aclass{
        int id;
        char name[10];
        char interest[50];
};

int main(){

        struct Aclass std1;
        struct Aclass std2;
        struct Aclass *st2 = &std2;

        std1.id = 10;
        strcpy(std1.name,"john");
        strcpy(std1.interest,"basketball");

        st2->id = 20;
        strcpy(st2->name,"rafael");
        strcpy(st2->interest,"piano");

        printf("%d\n",std1.id);
        printf("%s\n",st2->name);

        return 0;
}

