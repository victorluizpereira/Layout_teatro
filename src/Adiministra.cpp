#include "Adiministra.h"

Adiministra::Adiministra()
{
}
{
    void Adiministra::adiministra_scri( int Nf, int Nc, int cond, int  bilhetes, int Nfp, int Ncp, int Nfg, char layout[][Nc]){

    cond = 2;
    int condad = 0, sairadm = 1;
    int Nfga, Nfgm;
    int Ncga, Ncgm;
    int condigh;
    bilhetes = 0;

    do{
        clrscr();
        printf("\n\t\t================== Adiministrador ==================\n");

        printf("\n\n\nDeseja efetuar alguma alteração no layout?\n Se sim digite (1) caso contrário digite qualquer número >>. ");
        scanf("%i", &condad);

        if(condad == 1){
            Nfp = 0;
            Ncp = 0;
            printf("\n\tPRÉ-VISUALIZAÇÃO .... \n");
            exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
            printf("\n\t================================================================\n");
            printf("\nDigite a quantidade de fileiras comuns presentes no teatro >>. ");
            scanf("%i", &Nf);

            printf("\nDigite a quantidade de colunas comuns presentes no teatro >>. ");
            scanf("%i", &Nc);

            while(cond != 1 && cond != 0){
                printf("\nNo teatro há fileiras preferenciais?");
                printf("\nSe sim (1) se não (0) >>. ");
                scanf("%i", &cond);
            }

            printf("\n");

            if(cond == 1){
                printf("\nDigite o numero de fileiras preferênciais >>. ");
                scanf("%i", &Nfp);
                printf("Digite o numero de colunas preferênciais >>. ");
                scanf("%i", &Ncp);
            }
            Nf += 1;
            Nfg = Nf+Nfp;
            layout[Nfg][Nc];

            exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

            getchar();

            }else{
                printf("\nDeseja modificar alguma venda já estabelecida?");
                printf("\nSe sim Digite (2) caso contrário digite qualquer número >>. ");
                scanf("%i", &cond);

                if(cond == 2){

                clrscr();
                printf("\n\t\t ================== Adiministrador ==================\n");

                printf("\n\tPRÉ-VISUALIZAÇÃO ....");
                exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

                printf("\n\t============================================================\n");

                printf("\nQual a fileira e coluna desejada para a mudança ex.: (2 x 3) >>. ");
                scanf("%i x %i", &Nfgm, &Ncgm);

                printf("\nSe desejar mudar um acento digite (1) se deseja remover digite (2) >>. ");
                scanf("%i", &condigh);

                if(condigh == 1){
                    printf("\nPara qual fileira e coluna vc deseja move-lo ex.: (2 x 3) >>. ");
                    scanf("%i x %i", &Nfga, &Ncga);
                    if(Nfgm <= Nf){
                        layout[Nfgm][Ncgm -1] = 'L';
                    }else{
                        layout[Nfgm][Ncgm - 1] = 'P';
                        }
                layout[Nfga][Ncga - 1] = '#';
                }

                clrscr();
                printf("\nPRÉ-VISUALIZAÇÃO DA MODIFICAÇÃO .... ");
                exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
                printf("\n\t============================================================\n");
                printf("\nDeseja efetuar outras alterações no sistema ?");
                printf("\nSe sim (1) se não (0) >>. ");
                scanf("%i", &sairadm);
            }else{
                    clrscr();
                    if(Nfgm <= Nf){
                        layout[Nfgm][Ncgm -1] = 'L';
                    }else{
                        layout[Nfgm][Ncgm -1] = 'P';
                    }
                    printf("\nPRÉ-VISUALIZAÇÃO .... ");
                    exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
                    printf("\n\t===========================================================\n");
                    printf("\nDeseja efetuar outras alterações no sistema ?");
                    printf("\nSe sim (1) se não (0) >>. ");
                    scanf("%i", &sairadm);
                }
            }
    }while(sairadm != 0);
        }

Adiministra::~Adiministra()
{
    //dtor
}
