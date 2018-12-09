#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>

//  Declarando os procedimentos como globais

void formt_layout(int *Nft, int *Nct, int *condt, int *Nfpt, int *Ncpt, int *Nfgt, int *bilhetest);
void preencha_layout(int Nf, int Nc, int Nfp, int Ncp, int Nfg, char layout[][Nc]);
void exiba_layout(int cond, int bilhetes, int Nfg, int Nf, int Nc, int Nfp, int Ncp, char layout[][Nc]);
void vendas(int Nc, int *condm, int *Nfpm, int *bilhetesm, int *condic, int *Nfgm, int Nfa, int Nca, int *Nfm, int *Ncm, int *Ncpm, char layout[][Nc]);
void pre_view(int cond, int bilhetes, int  Nfg, int Nf, int Nc, int Nfp , int Ncp, char layout[][Nc]);

int main()
{
    int  Nfp, Ncp, condic = 0, Nc, Nf, Nfa, Nca, cond, Nfg, bilhetes; //Iniciando as vairiaveis


    printf("\t\t============= Layout de teatro ===============\n");

    // Formatando o layout do teatro
    formt_layout(&Nf, &Nc, &cond, &Nfp, &Ncp, &Nfg, &bilhetes);

    char layout[Nfg][Nc]; // Iniciando a matriz layout do teatro

    // Preenchendo a matriz
    preencha_layout(Nf, Nc, Nfp, Ncp, Nfg, layout);

    clrscr();

    // Ciclo para exibir e vender acentos do layout
    while(condic != 1){
        exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
        vendas(Nc, &cond, &Nfp, &bilhetes, &condic, &Nfg, Nfa, Nca, &Nf, &Nc, &Ncp, layout);
    }

    getchar();

    return 0;
}
   // Formatando o layout do teatro
void formt_layout(int *Nft, int *Nct, int *condt, int *Nfpt, int *Ncpt, int *Nfgt, int *bilhetest){

    int Nf = 0, Nc = 0, Nfp = 0, Ncp = 0, Nfg = 0, cond = 3, bilhetes = 0;
    *bilhetest = bilhetes; // passando o valor de bilhetes para o ponteiro com um auxiliar

    printf("\nDigite a quantidade de fileiras comuns presentes no teatro >>. ");
    scanf("%i", &Nf);
    *Nft = Nf;

    printf("\nDigite a quantidade de colunas comuns presentes no teatro >>. ");
    scanf("%i", &Nc);
    *Nct = Nc;

    // Definindo as fileiras preferenciais
    while(cond != 1 && cond != 0){
        printf("\nNo teatro há fileiras preferenciais?");
        printf("\nSe sim (1) se não (0) >>. ");
        scanf("%i", &cond);
        *condt = cond;
    }

    printf("\n");

    // Se o teatro há fileiras preferenciais define os valores das fileiras..
    if(cond == 1){
            printf("Digite o numero de fileiras preferênciais >>. ");
            scanf("%i", &Nfp);
            *Nfpt = Nfp;
            printf("Digite o numero de colunas preferênciais >>. ");
            scanf("%i", &Ncp);
            *Ncpt = Ncp;
    }
    Nf += 1;    // Acressentando para exibir o indice no layout
    *Nft = Nf;
    Nfg = Nf + Nfp;     // Passando os valores dos auxiliares para os ponteiros
    *Nfgt = Nfg;
}
    // Preechendo o layout com os valores equivalentes
void preencha_layout(int Nf, int Nc, int Nfp, int Ncp, int Nfg, char layout[][Nc]){

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
}
    // Procedimento para exibir o layout no console
void exiba_layout(int cond, int bilhetes, int Nfg, int Nf, int Nc, int Nfp, int Ncp, char layout[][Nc]){
    int i, j;

    // Condições para tornar o cabeçalho alinhado com o layout
    if(Nc < 8){
        printf("\t==============================================================\n");
        printf("\t\t\t\t  Layout atual\n");
        printf("\t==============================================================\n");
        printf("\n");
    }else{
        printf("\t\t\t========================================================\n");
        printf("\t\t\t\t\t\tLayout atual\n");
        printf("\t\t\t========================================================\n");
        printf("\n");
    }

    for(i = 0; i < Nfg; ++i){
        if(i < 10){
        printf("\t\t\t%i  ", i); // define o indice de fileiras no layout
        }else{
            printf("\t\t       %i  ", i);
        }
        for(j = 0; j < Nc; ++j){
            if(i == 0){
                if(j < 9){
                    printf(" %i ", j+1); // define o indice de colunas no layout
                }else{
                    printf("%i ", j+1);
                }
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

    if(i < 6 && j < 10){
        printf("\n\n\tL : Lugar vago \tP : Lugar preferencial vago \t# : Lugar vendido\n");
    }else{
        printf("\n\tL : Lugar vago \tP : Lugar preferencial vago \t# : Lugar vendido\n");
    }
    printf("\n\tQuantidade de bilhetes vendidos >>  %i\n", bilhetes);
    printf("\n\tSenha de Adiministrador para a condição Deseja vender >>. 1234\n");

}
    // Procedimento para a venda de acentos e inicialização de modificações
void vendas(int Nc, int *condm, int *Nfpm, int *bilhetesm, int *condic, int *Nfgm, int Nfa, int Nca, int *Nfm, int *Ncm, int *Ncpm, char layout[][Nc]){
    int cond, condics, Nfp, bilhetes, Nfg, Nf, Ncp; // Declarando as variáveis que serão utilizadas
    cond = *condm;
    Nfp = *Nfpm;
    bilhetes = *bilhetesm; // variáveis auxiliares recebe os valores dos ponteios
    Nfg = *Nfgm;
    Nf = *Nfm;
    Nc = *Ncm;

    int cert;
    int condi;

    // Declarando o procedimento de modificação pelo adiministrador
    void modifc_layout(int Nc, int *Nfv, int *Ncv, int *condv, int *bilhetesv, int *Nfpv, int *Ncpv, int *Nfgv, char layout[][Nc]);

    do{
        condi = 2;
        printf("\nDeseja vender algum acento?");    // fazer a condição enquanto o programa não encerra
        printf("\nSe sim (1) se não (0) >>. ");
        scanf("%i", &condi);
    }while(condi != 1 && condi != 0 && condi != 1234);

    if(condi == 1234){      // Condição para a modificação no teatro por senha
        clrscr();
        // Procedimento de modificação
        modifc_layout(Nc, &Nf, &Nc, &cond, &bilhetes, &Nfp, &Ncp, &Nfg, layout);
        clrscr();
        // Procedimento de exibição
        exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
        cert = 2;
    }

    if(condi == 1){     // Condição para vender o acento
        do{
            cert = 2;   // Iniciando a variável com 2
            Nfa = 0;    // Zerando as variáveis
            Nca = 0;
            printf("\nDigite a fileira e a coluna desejada ex.: (2 x 3) >>. ");
            scanf("%i x %i", &Nfa, &Nca);
            fflush(stdin);
            printf("\nTem certeza que o acento desejado é esse. [%i x %i]", Nfa, Nca);
            printf("\nSe sim (1) se não (0) >>. ");
            scanf("%i", &cert);
            fflush(stdin);
            // Condição para caso o lugar já tenha sido vendio
            if(layout[Nfa][Nca - 1] == '#'){
                clrscr();
                getchar();
                printf("\n\n\n\n\n\n\t\t!!! É impossível, o acento já foi vendido !!!\n");
                printf("\t\t  Prescione qualquer tecla para retornar.. ");
                getchar();
                cert = 4;
            }
            if(cert == 1){
                bilhetes+=1;    //  o acento foi vendido
                }
        }while(cert != 1 && cert !=4);
    }

    clrscr();

    if(cert == 1){
        layout[Nfa][Nca - 1] = '#';
    }else{
        if(cert == 0 || condi == 0){
            printf("\nDeseja encerrar o programa?");
            printf("\nSe sim (1) se não (0) >>. ");
            scanf("%i", &condics);
            *condic = condics;
            if(condics == 0 || condics == 1){
                clrscr();
            }
        }
    }
    *condm = cond;
    *Nfpm = Nfp;
    *bilhetesm = bilhetes;  // Passando os valores das auxiliares para os ponteiros
    *Nfgm = Nfg;
    *Nfm = Nf;
    *Ncm = Nc;

}
    // Procedimento de modificação no layout do teatro
void modifc_layout(int Nc, int *Nfv, int *Ncv, int *condv, int *bilhetesv, int *Nfpv, int *Ncpv, int *Nfgv, char layout[][Nc]){
    // Declarando as auxiliares e as variáveis para a modificação
    int condad = 0, sairadm = 1, Nfga, Nfgm, Ncga, Ncgm, condigh, Nf, condi, cond, bilhetes, Nfp, Ncp, Nfg;
    Nf = *Nfv;
    Nc = *Ncv;
    cond = *condv;  // Auxiliares receberão os valores dos ponteiros
    Nfp = *Nfpv;
    Ncp = *Ncpv;
    Nfg = *Nfgv;
    bilhetes = *bilhetesv;

    do{
        clrscr();
        printf("\n\t\t================== Adiministrador ==================\n");

        printf("\n\n\nDeseja efetuar alguma alteração no layout?\nSe sim digite (1) caso contrário digite qualquer número >>. ");
        scanf("%i", &condad);
        clrscr();

        if(condad == 1){        // Condição para a modificação do design do teatro
            bilhetes = 0;

            pre_view(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

            Nf = 0, Nc = 0, cond = 3, Nfp = 0, Ncp = 0, Nfg = 0;

            // chamando o procedimento de formatação do layout
            formt_layout(&Nf, &Nc, &cond, &Nfp, &Ncp, &Nfg, &bilhetes);
            // chamando o procedimento de preenchimento do layout
            preencha_layout(Nf, Nc, Nfp, Ncp, Nfg, layout);

            *Nfv = Nf;
            *Ncv = Nc;
            *condv = cond;      // Passando os auxiliares para os ponteiros
            *Nfpv = Nfp;
            *Ncpv = Ncp;
            *Nfgv = Nfg;
            *bilhetesv = bilhetes;

            // chamando a exibição da nova formatação
            pre_view(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

            getchar();

            }else{
                printf("\n\t\t================== Adiministrador ==================\n");
                printf("\nDeseja modificar alguma venda já estabelecida?");
                printf("\nSe sim Digite (2) caso contrário digite qualquer número >>. ");
                scanf("%i", &condi);
                clrscr();

                if(condi == 2){ // Condição para a modificação de acento ou remoção

                    clrscr();
                    printf("\n\t\t ================== Adiministrador ==================\n");

                    // chamando o procedimento de exibição
                    pre_view(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

                    printf("\nQual a fileira e coluna desejada para a mudança ex.: (2 x 3) >>. ");
                    scanf("%i x %i", &Nfgm, &Ncgm);

                    printf("\nSe desejar mudar um acento digite (1) se deseja remover digite (2) >>. ");
                    scanf("%i", &condigh);

                    if(condigh == 1){
                        printf("\nPara qual fileira e coluna vc deseja move-lo ex.: (2 x 3) >>. ");
                        scanf("%i x %i", &Nfga, &Ncga);
                        if(Nfgm < Nf){
                            layout[Nfgm][Ncgm -1] = 'L';
                        } else{
                            layout[Nfgm][Ncgm - 1] = 'P';
                            }
                        layout[Nfga][Ncga - 1] = '#';

                    clrscr();

                    // chamando o procedimento de exibição
                    pre_view(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

                    printf("\nDeseja efetuar outras alterações no sistema ?");
                    printf("\nSe sim (1) se não (0) >>. ");
                    scanf("%i", &sairadm);
                    }else{
                        if(layout[Nfgm][Ncgm-1] == 'L' || layout[Nfgm][Ncgm-1] == 'P'){
                            bilhetes = 0;
                        }else{
                            clrscr();
                            if(Nfgm < Nf){
                                layout[Nfgm][Ncgm-1] = 'L';
                            }else{
                                layout[Nfgm][Ncgm-1] = 'P';
                            }
                            bilhetes -= 1;
                            *bilhetesv = bilhetes;
                            }
                    }
                }
                if(condi != 1 && condi !=2){
                    clrscr();

                    //chamando o procedimento de exibição
                    pre_view(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);

                    printf("\nDeseja efetuar outras alterações no sistema ?");
                    printf("\nSe sim (1) se não (0) >>. ");
                    scanf("%i", &sairadm);
                }
            }
        clrscr();
    }while(sairadm != 0);
}
    // Procedimento de pre exibição para o modific_layout
void pre_view(int cond, int bilhetes, int  Nfg, int Nf, int Nc, int Nfp , int Ncp, char layout[][Nc]){

    printf("\nPRÉ-VISUALIZAÇÃO .... \n");
    exiba_layout(cond, bilhetes, Nfg, Nf, Nc, Nfp , Ncp, layout);
    printf("\n\t===========================================================\n");

}

