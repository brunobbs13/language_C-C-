//GAME SNAKE
//Desenvolvido por BRUNO BARRETO, como projeto do primeiro periodo de analise e desenvolvimento de sistema, People
//Unidade Taboão da Serra-SP

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define i 20  //quantia de linhas.
#define j 60  //quantia de colunas.

char nome[30];
int veloc,op=2;
void irparaxy(int x,int y)
//------------------------------------------------------COMEÇA A DESENHAR AS COLUNAS DO PROGRAMA----------------------------------------------------------------
{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});   //X=J(SÃO COLUNAS) E Y=I(SÃO LINHAS)
}
void desenha_campo() //DESENHA AS PAREDES
{
    system("color 9f");
int z; //VARIAVEL AUXILIAR PARA DESENHAR
for (z=0;z<j;z++) //DESENHAR PAREDE DE CIMA HORIZONTAL
{
    irparaxy(z,0);
    printf("%c",43);
    Sleep(10);
}
for (z=0;z<i;z++) //DESENHA A PAREDE DA DIREITA VERTICAL
{
    irparaxy(j,z);
    printf("%c",43);
    Sleep(10);
}
for (z=j;z>=0;z--) //DESENHAR PAREDE DE BAIXO HORIZONTAL
{
    irparaxy(z,i);
    printf("%c",43);
    Sleep(10);
}
for (z=i;z>0;z--) //DESENHA A PAREDE DA ESQUERDA VERTICAL
{
    irparaxy(0,z);
    printf("%c",43);
    Sleep(10);
}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

int bem_vindo()
{
    int tecla,aux_dif=0;
    irparaxy(15,5);
    printf("Bem vindo !!!\t\t Jogo Snake");
    irparaxy(15,8);
    printf("Digite seu nome:");
    fflush(stdin);
        gets(nome);
        irparaxy(15,10);
    printf("MENU");
    irparaxy(15,12);
    printf("Selecione uma das op%c%ces",135,228);
    irparaxy(15,14);
    printf("<ENTER> Iniciar\t<ESC>Instru%c%ces\t<ESPACO> Dificuldade",135,228);

    do
    {
        tecla=getch();

        if(tecla == 27)
        {
         intrucoes();
         system ("cls");
         irparaxy(15,5);
         printf("<ENTER> Iniciar \t\t <ESPAÇO> Dificuldade");
         tecla=getch();
        }
        if (tecla==32)
        {
            veloc=dificuldade();
            aux_dif=1;
            irparaxy(15,5);
            printf ("Precione enter para come%car",135);
            tecla=getch();
        }
        if (aux_dif == 0) veloc=200;
        system("cls");
        }while (tecla !=13 && tecla !=27 && tecla !=32);
}
    int intrucoes()

    {
        system("cls");
        irparaxy(15,3);
        printf("Use as setas para controlar a cobrinha:");
        irparaxy(15,5);
        printf ("Move para cima %c",24);
        irparaxy(15,6);
        printf("Move para baixo %c",25);
        irparaxy(15,7);
        printf ("Move para a direita %c",26);
        irparaxy(15,8);
        printf ("Move para a esquerda %c",27);
        irparaxy(15,11);
        printf ("Coma os alimentos %c para evoluir",1);
        irparaxy(15,14);
        printf (" E evite os obstaculos %c",88);
        irparaxy(15,17);
        printf ("Use a tecla Espa%co para pausar a qualquer movimento",135);
        irparaxy(15,19);
        printf ("Use a tecla ESC para finalizar a qualquer momento");
        printf ("\n\n\t");
        system("pause");
    }
    int dificuldade()
    {
        int nivel_dif;
        do
        {
            system("cls");
            irparaxy(15,5);
            printf("Escolha o Nivel de Dificuldade");
            irparaxy(15,8);
            printf("<1> FACIL \t <2> MEDIA \t <3> DIFICIL");
            scanf("%d",&op);
            nivel_dif=300/op;
            }while (op<1 || op > 3);
            system("cls");
            return(nivel_dif);
    }
    int desenvolvimento()
    {
int d=2,x,t=1,pontos=0,level=1,k=10,resp;

//D= direção/ X- auxiliar/ T= auxiliar/level=nivel k = controle do nivel/pontos=pontuação/veloc=controlesleep/resp=resposta para continuar
int cx[300]={1,2},cy[300]={7,7},ax,ay,ox,oy;
//cx=tamanho da cobra na horizontal//cy=tamanho da cobra vertical//ax e ay = local do alimento//ox e oy = local do obstaculo
int tecla=32;
//tecla para receber o botão precionado

irparaxy(3,i+2);//MOSTRA O NOME DA PESSOA ABAIXO DO QUADRO DO JOGO
printf("%s",nome);
srand(time(NULL)); //CRIA O ALIMENTO E O OBSTACULO EM POSIÇÃO AlEATORIA ,INICIALIZA
ax=(rand()%(j-1))+1;
ay=(rand()%(i-1))+1;
ox=(rand()%(j-1))+1;
oy=(rand()%(i-1))+1;

while(tecla!=27)//DESENVOLVIMENTO DO JOGO
{while(tecla!=27 &&!(tecla=kbhit()))
{for (x=t;x>0;x--)
    {cx[x]=cx[x-1];
    cy[x]=cy[x-1];
    }
    if(d==0)cx[0]--; //ESQUERDA
    if(d==1)cy[0]--; //CIMA
    if(d==2)cx[0]++; //DIREITA
    if(d==3)cy[0]++; //BAIXO
    irparaxy(cx[t],cy[t]);
    printf(" ");
    if(ax==cx[0]&&ay==cy[0])
    {

        t++;
        ax=(rand()%(j-1))+1;
        ay=(rand()%(i-1))+1;
pontos++;
    }

irparaxy(cx[0],cy[0]);
printf("%c",254);
irparaxy(ax,ay);
    printf("%c",1);
    irparaxy(ox,oy);
    printf("%c",88);
    if (pontos==k)

    {
     level++;
     k=k+10;
     veloc=veloc-veloc/10;
     ox=(rand()%(j-1))+1;
     oy=(rand()%(i-1))+1;
    }
irparaxy(20,i+2);
printf("Pontua%c%co= %d" ,135,198,pontos);
irparaxy(45,i+2);
    printf("Level= %d",level);
Sleep(veloc);
irparaxy(10,i+4);
printf("Dificuldade: %d",op);
irparaxy(30,i+4);
    printf("Sleep  real: %d",veloc);
    for(x=1;x<t;x++)
    {if(cx[0]==cx[x]&&cy[0]==cy[x])tecla=27;
    }

    if(ox==cx[0]&& oy==cy[0])tecla=27;
    if(cy[0]==0||cy[0]==i||cx[0]==0||cx[0]==j)tecla=27;
}
if (tecla!=27)tecla=getch();
if (tecla==75)d=0;
if (tecla==72)d=1;
if (tecla==77)d=2;
if (tecla==80)d=3;
if (tecla==32)system("pause");
if(cy[0]==0||cy[0]==i||cx[0]==0||cx[0]==j)tecla=27;
}
system("cls");

printf("\a\a\a\n\n\t\t GAME OVER \n\n\t\t Pontua%c%co = %d \n\n\n",135,198,pontos);
system("pause");
{
printf("\n\n\t\t Deseja come%cadenovo? \n\t\t <1>SIM <2>N%cO \n",135,199); //SELEÇÃO PARA RECOMEÇAR O JOGO
scanf("%d",&resp);
     }while (resp!=1 && resp!=2);
system ("cls");
if (resp==1) //se 1 precionando , eçe retorna ao main e começa tudo de novo
{
      main();
}
else
    {
    printf("\n\n\t\t FIM DO JOGO \n\n"); //se o 2 precionando,ele finaliza o jogo
    }
     }
void main ()

{
    bem_vindo(); //tela inicial
    desenha_campo(); //desenha o quadro do campo
    desenvolvimento(); //desenvolvimento do jogo
}

