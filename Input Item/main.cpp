#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int stat;
    char nama[20];
}Senjata;

int main()
{
    Senjata s[10];
    int terhebat = 0,terlemah = 0;
    char lagi = 'y';
    int i = 0;

    while(lagi == 'y' || lagi == 'Y'){
        printf("Masukkan Nama Item : ");scanf("%s",&s[i].nama);
        printf("Masukkan Stat Item : ");scanf("%d",&s[i].stat);
        printf("Nama : %s\n",s[i].nama);
        printf("Stat : %d\n",s[i].stat);

        if(s[i].stat >= s[terhebat].stat)
            terhebat = i;

        if(s[i].stat <= s[terlemah].stat)
            terlemah = i;

        if(i == 0)
            printf("Item sebelumnya : Nothing\n");
        else
            printf("Item sebelumnya : %s\n",s[i-1].nama);

        printf("Item terhebat %s\n",s[terhebat].nama);
        printf("Item terlemah %s\n",s[terlemah].nama);
        fflush(stdin);
        printf("Lagi ?");scanf("%c",&lagi);
        printf("\n");
        i++;
    }
    return 0;
}
