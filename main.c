#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>

int main()
{
    int Nf, Nfp = 0, Nc, Ncp = 0 , Nfa, Nca, cond, condic = 0;
    int bilhetes = 0;

    void exiba_layout(int cond, int bilhetes, int Nfg, int Nf, int Nc, int Nfp, int Ncp, char layout[][Nc]);
    void atualiz_layout(int cond, int Nfp, int *bilhetes, int *condic, int Nfg, int Nfa, int Nca, int Nf, int Nc, int Ncp, char layout[][Nc]);


    printf("\t\t============= Layout de teatro ===============\n");

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
    int Nfg = Nf+Nfp;
    char layout[Nfg][Nc];

    for(int i = 0; i < Nfg; ++i){
        for(int j = 0; j < Nc; ++j){
            layout[i][j] = 'L';
            if(i >= Nf && j < Ncp){
                layout[i][j] = 'P';
            }else{
                if( i >= Nf && j >= Ncp){
                    layout[i][j] = ' ';
                }
            }
        }
    }

    clrscr();

    while(condic == 0){
        exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
        atualiz_layout(cond, Nfp, &bilhetes, &condic, Nfg, Nfa, Nca, Nf, Nc, Ncp, layout);
    }

    getchar();

    return 0;
}
void exiba_layout(int cond, int bilhetes, int Nfg, int Nf, int Nc, int Nfp, int Ncp, char layout[][Nc]){
    int i, j;

    printf("\n");
    printf("\t==============================================================\n");
    printf("\t\t\t\t  Layout atual\n");
    printf("\t==============================================================\n");
    printf("\n");

    for(i = 0; i < Nfg; ++i){
        if(i < 10){
        printf("\t\t\t%i  ", i);
        }else{
            printf("\t\t       %i  ", i);
        }
        for(j = 0; j < Nc; ++j){
            if(i == 0){
                printf(" %i ", j+1);
                if(j == (Nc/2)-1 && Nc > 5){
                    printf("\t");
                }
            }else{
                if(j == (Nc/2) && Nc > 5){
                    printf("\t");
                }
                printf(" %c ", layout[i][j]);
            }
        }

        if((i == 0 || i == Nf - 1) || (i == (Nf/2) && Nf > 10)){
            printf("\n");
        }

        printf("\n");

        }

    printf("\n\n\tL : Lugar vago \tP : Lugar preferencial vago \t# : Lugar vendido\n");

    printf("\n\tQuantidade de bilhetes vendidos >>  %i\n", bilhetes);

}
void atualiz_layout(int cond, int Nfp, int *bilhetes, int *condic, int Nfg, int Nfa, int Nca, int Nf, int Nc, int Ncp, char layout[][Nc]){

    int cert;
    void modifc_layout(int Nf, int Nc, int cond, int bilhetes, int Nfp, int Ncp, int Nfg, char layout[][Nc]);

    do{
        cond = 2;
        printf("\nDeseja vender algum acento?");
        printf("\nSe sim (1) se não (0) >>. ");
        scanf("%i", &cond);
    }while(cond != 1 && cond != 0 && cond != 1234);

    if(cond == 1234){
        clrscr();
        modifc_layout( Nf, Nc, cond, bilhetes, Nfp, Ncp, Nfg, layout);
        clrscr();
        exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
    }

    if(cond == 1){
        do{
            cert = 2;
            Nfa = 0;
            Nca = 0;
            printf("\nDigite a fileira e a coluna desejada ex.: (2 x 3) >>. ");
            scanf("%i x %i", &Nfa, &Nca);
            fflush(stdin);
            printf("\nTem certeza que o acento desejado é esse. [%i x %i]", Nfa, Nca);
            printf("\nSe sim (1) se não (0) >>. ");
            scanf("%i", &cert);
            fflush(stdin);
            if(layout[Nfa][Nca - 1] == '#'){
                clrscr();
                getchar();
                printf("\n\n\n\n\n\n\t\t!!! É impossível, o acento já foi vendido !!!\n");
                printf("\t\t  Prescione qualquer tecla para retornar.. ");
                getchar();
                cert = 4;
            }
            if(cert == 1){
                *bilhetes+=1;
                }
        }while(cert != 1 && cert !=4);
    }

    clrscr();

    if(cert == 1){
        layout[Nfa][Nca - 1] = '#';
    }else{
        if(cert == 0){
            printf("\nDeseja encerrar o programa?");
            printf("\nSe sim (1) se não (0) >>. ");
            scanf("%i", &condic);
            if(condic == 0){
                clrscr();
            }
        }
    }

}
void modifc_layout(int Nf, int Nc, int cond, int bilhetes, int Nfp, int Ncp, int Nfg, char layout[][Nc]){
    cond = 2;
    int condad = 0, sairadm = 1;
    bilhetes = 0;

    do{
        clrscr();
        printf("\n\t\t================== Adiministrador ==================\n");

        printf("\n\n\nDeseja efetuar alguma alteração no layout?\n Se sim digite (1) caso contrário digite qualquer número >>. ");
        scanf("%i", &condad);

        if(condad == 1){
            printf("\n\tPRÉ-VISUALIZAÇÃO .... \n");
            exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
            printf("\n================================================================\n");
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
                    int Nfga, Nfgm;
                    int Ncga, Ncgm;
                    int condigh;

                clrscr();
                printf("\n\t\t ================== Adiministrador ==================\n");

                printf("\n\tPRÉ-VISUALIZAÇÃO ....");
                exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

                printf("\n============================================================\n");

                printf("\nQual a fileira desejada para a mudança >>. ");
                scanf("%i", &Nfgm);

                printf("\nQual a coluna desejada para a mudança >>. ");
                scanf("%i", &Ncgm);

                printf("\nSe desejar afetuar uma mudança digite (1) se deseja remover digite (2) >>. ");
                scanf("%i", &condigh);

                if(condigh == 1){
                    printf("\nPara qual fileira e coluna vc deseja move-lo ex.: (2 x 3) >>. ");
                    scanf("%i x %i", &Nfga, &Ncga);
                    if(Nfgm < Nf){
                        layout[Nfgm][Ncgm -1] = 'L';
                    }else{
                        if(Nfgm > Nf){
                            layout[Nfgm][Ncgm - 1] = 'P';
                        }
                    }
                layout[Nfga][Ncga - 1] = '#';

                clrscr();
                printf("\nPRÉ-VISUALIZAÇÃO DA MODIFICAÇÃO .... ");
                exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
                printf("\n============================================================\n");
                printf("\nDeseja efetuar outras alterações no sistema ?");
                printf("\nSe sim (1) se não (0) >>. ");
                scanf("%i", &sairadm);
            }else{
                if(condigh == 2){
                    clrscr();
                    if(Nfgm < Nf){
                        layout[Nfgm][Ncgm -1] = 'L';
                    }else{
                        if(Nfgm > Nf){
                            layout[Nfgm][Ncgm -1] = 'P';
                        }
                    }
                    printf("\nPRÉ-VISUALIZAÇÃO .... ");
                    exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
                    printf("\n===========================================================\n");
                    printf("\nDeseja efetuar outras alterações no sistema ?");
                    printf("\nSe sim (1) se não (0) >>. ");
                    scanf("%i", &sairadm);
                }
            }
        }

        }
    }while(sairadm != 0);
}

