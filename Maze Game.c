#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player1;
int player2;
int hartakarun1;
int hartakarun2;

int menuUtama()
{
    system("clear");
    
    printf("Silakan pilih menu berikut:\n");
    printf("1. Untuk memulai permainan\n");
    printf("2. Untuk keluar dari permainan\n\n");
    printf("Anda memilih: ");
 
    int pilih;
    scanf("%d", &pilih);
 
    if (pilih != 1 && pilih !=2)
    {
        return menuUtama();
    }
    else
    {
        return pilih;
    }
}

char confirmKeluar()
{
    system("clear");
    printf("Apakah anda yakin untuk keluar?(y/n)");
  
    char pilih;
    scanf("\n%c", &pilih);
 
    if (pilih != 'y' && pilih != 'n')
    {
        return confirmKeluar();
    }
    else
    {
        return pilih;
    }
}

int menuGame()
{
    printf("Silakan pilih menu berikut:\n");
    printf("1. Untuk begerak ke atas\n");
    printf("2. Untuk begerak ke kanan\n");
    printf("3. Untuk begerak ke bawah\n");
    printf("4. Untuk begerak ke kiri\n");
    printf("0  Untuk pemainan selesai\n\n");
    printf("Anda memilih: ");
 
    int pilih;
    scanf("%d", &pilih);
    return pilih;
}

int gameRun(int baris, int kolom, char** peta2d)
{
    int pilih = 0;
    
    do
    {
        system("clear");
 
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                if (i == player2 && j == player1)
                {
                    printf("X ");
                }
                else if (i == hartakarun2 && j == hartakarun1)
                {
                    printf("* ");
                }
                else
                {
                    printf("%c ", peta2d[i][j]);
                }
            }
            printf("\n");
        }
    
        printf("Posisi X pemain = %d\n", player1 + 1);
        printf("Posisi Y pemain = %d\n", player2 + 1);

        printf("Posisi X harta karun = %d\n", hartakarun1 + 1);
        printf("Posisi Y harta karun = %d\n\n", hartakarun2 + 1);
        pilih = menuGame();
        //  return menuGame();
    
        switch (pilih)
        {
            case 1:
            player2--;
            break;
      
            case 2:
            player1++;
            break;
        
            case 3:
            player2++;
            break;
        
            case 4:
            player1--;
            break;
        
            default:
            break;
        }
    
        if(player2 == -1)
        {
            player2 = 0;
        }
        else if(player2 == -1) 
        //else if
        {
            player2 = baris -1;
        }
        if(player1 == -1)
        {
            player1 = 0;
        }
        else if (player1 == kolom)
        {
            player1 = kolom -1;
        }
        if (player1 == hartakarun1 && player2 == hartakarun2)
        {
            printf("Anda menang (silakan tekan enter)\n");
            getchar();
            getchar();
   
            pilih = 0;
        }
    }
    while (pilih != 0);
    return pilih;
}

int gameStart()
{
    int baris;
    int kolom;
    char **peta2d;
 
    printf("Silahkan masukkan jumlah baris yang diinginkan: ");
    scanf("%d", &baris);
    
    printf("Silahkan masukkan jumlah kolom yang diinginkan: ");
    scanf("%d", &kolom);
 
    peta2d = calloc(baris, sizeof(char*));
    if(peta2d == NULL)
    {
        printf("Pembuatan peta gagal\n");
        return -1;
    }
    for (int i = 0; i < baris; i++)
    {
        peta2d[i] = calloc(kolom, sizeof(int));
    
        if (peta2d[i] == NULL)
        {
            printf("Pembuatan peta gagal\n");
            return -1;
        }
    }
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            peta2d[i][j] = 'O';
        }
    }
 
    player1 = rand() % kolom;
    player2 = rand() % baris;
    
    do
    {
        hartakarun1 = rand() % kolom;
        hartakarun2 = rand() % baris;
    }
    while(player1 == hartakarun1 && player2 == hartakarun2);
    
    gameRun(baris, kolom, peta2d);
 
    for (int i = 0; i < baris; i++)
    {
        free(peta2d[i]);
        peta2d[i] = NULL;
    }
    free(peta2d);
    peta2d = NULL;
    return 0;
}

int main()
{
    srand(time(NULL));
    while(1)
    {
        int i = menuUtama();
        
        if (i == 1)
        {
            gameStart();
        }
        else if (i == 2)
        {
            if (confirmKeluar() == 'y')
            {
                break;
            }
        }
    }
    return 0;
}