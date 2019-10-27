#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void printNyawa(int i)
{
    int j;
    for(j = 1; j<=i; j++)
    {
        printf("\x03");
    }
    printf("\n\n");
}

int main()
{
    int jawaban,panjang,nyawa = 3,tebakan;
    bool bonus = true;
    srand(time(NULL));

    do
    {
        printf("Masukan maksimal nilai (10 - 100) : ");
        scanf("%d",&panjang);
        if(panjang < 10)
            printf("Nilai yang anda masukan terlalu kecil\n\n");
        else if(panjang > 100)
        {
            printf("Nilai yang anda masukan terlalu besar\n\n");
        }
    }
    while(panjang < 10 || panjang > 100);

    printf("Silahkan tebak nilai antara 0 sampai %d\n",panjang);
    jawaban = (rand() % panjang)+1;
    printf("(cheat : ini adalah angka yang ditebak : %d)\n\n",jawaban);

    while(nyawa != 0)
    {
        printf("Masukan Tebakan Anda : ");
        scanf("%d",&tebakan);
        if(tebakan == jawaban)
        {
            printf("Jawaban Anda Benar\n\n");
            break;
        }
        else
        {
            if(tebakan > jawaban)
                printf("Jawaban anda terlalu besar\n");
            else
                printf("Jawaban anda terlalu kecil\n");
            nyawa--;
            printf("Nyawa anda sisa : ");
            printNyawa(nyawa);
        }

        //BONUS stage
        if(nyawa == 0 && bonus)
        {
            srand(time(NULL)); //reset nilai random
            nyawa = rand() % 2;
            if(nyawa == 1)
            {
                printf("Anda mendapatkan BONUS !!!\nboleh coba 1 kali lagi\n");
                bonus = false;
            }
        }
    }

    printf("Game Over !!!");
    return 0;
}
