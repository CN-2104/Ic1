/*
Usado para separar partes:
//=================================================================================================================================
Usado para separar entre partes
//_________________________________________________________________________________________________________________________________
Usado para separar entre "capitulos
//---------------------------------------------------------------------------------------------------------------------------------
*/

//=================================================================================================================================
//! Bibliotecas

#include <stdio.h> // padrao
#include <string.h> // lenght + string compare
#include <stdlib.h> // system (limpar)

//=================================================================================================================================
//! Defines
//Limpar
#ifdef _WIN32 //definindo funcoes para win e linux
   #define LIMPAR system("cls");
   #include <conio.h> // cls
   #include <windows.h> // Sleep
   #define ESPERA Sleep(3000); // Usado para as esperas grande
   #define DESENHO Sleep(80); // Usado para a "animacao" da logo
#else
   #include <unistd.h> //usleep
   #define LIMPAR system("clear");
   #define ESPERA usleep(3000*1000);
   #define DESENHO usleep(80*1000);
#endif
//_________________________________________________________________________________________________________________________________
//Outros
#define TOTAL_ITENS 20 // Total dos vetores | loop cadastro dos itens
#define ESPACO "================================================\n" // para organizacao grafica
#define SEPARA "------------------------------------------------\n" // para organizacao grafica

#define TAMANHO_NOME 256 // delimita o tamanho maximo para as variaveis dos produtos
#define SAIR printf("\n\n"SEPARA"Digite 1 para continuar: ");scanf("%d",&sair); // define para sair caso n digitado = 1
//=================================================================================================================================
//!Função criptografar [Usada para senha]
char* crip(char plaintext[]){ // Recebe a senha
    int key[2][2] = {{1, 2}, {3, 4}}; // Matriz de "criptografia
    int i, j,sum; // i,j = contadores [for] | Sum = variável para armazenar valores
    int len = strlen(plaintext); // Tamanho da senha
    char* encrypted = (char*)malloc((len + 1) * sizeof(char)); // Aloca a memoria para a string

    // Multiplicação da matriz pela senha
    for (i = 0; i < len; i++) {
        sum = 0; // reseta a senha para 0
        for (j = 0; j < 2; j++) {
            sum += (plaintext[i] - 'a') * key[j][0]; // pega o "valor" da letra e multiplica pela matriz
        }
        encrypted[i] = (sum %26) + 'a'; // Apenas para manter os valores dentro do alfabeto de 26 letras e volta para "letras"
    }
    encrypted[len] = '\0'; // Salva o final da string
    return encrypted; // Retorna a string criptografada
}
//=================================================================================================================================
//!Função Logo [Usada para desenhar a logo]
void logo(){
    /*
    Usada um programa para desenhar em caracteres ASCII e depois ajustado manualmente;
    No código pode parecer desalinhado, mas no terminal está normal;
    A cada linha se espera um delay para dar uma impressão de "animacao"
    */
    printf("\n                   ###       ####   ###              .#######.    #####\n");DESENHO;
    printf("                  .###       ###   ##                ###   ###   ##   ##      ###\n");DESENHO;
    printf("     ###+ #####    ###       ###  ##                 ###.  ###  ###   ###     ###      ####-\n");DESENHO;
    printf("  ###  #   ###     ###       ### -#                  ###.  ###  ###   ###    +###      ### ##+\n");DESENHO;
    printf(" ###   #   ###     ###       ##- #=                  ###   ##   ###   ###.   #####     ###  ###\n");DESENHO;
    printf(" ###   #   ###     ###       ######                  ######+    ###   ####   # ###     ###   ##\n");DESENHO;
    printf(" ###.      ###     ###       ######       ####       ###  ##    ###   ####  +# ###     ###   ###\n");DESENHO;
    printf(" ####-     ###     ###       ##- ###      #.+#+      ###  ##-   ###   ####  ## .##     ###   ###\n");DESENHO;
    printf("  ####+    ###     ###       ###  ##.     +#  ##     ###  +##   ###   ###.  ######.    ###   ###\n");DESENHO;
    printf("   #####   ###     ###       ###  ###      ##  .#    ###   ##   ###   ###  ##   ###    ###   ###\n");DESENHO;
    printf("    ####   ###     ###       ##-   ##     ###   #    ###    ##   ##   ###  ##   ###    ###   ###\n");DESENHO;
    printf("     ###+  ###     ###       ##   ####    ###-.-.#   ###    ###   #####+  ###   ###+   ###   ###\n");DESENHO;
    printf(" #    ##   ###    #########            ###-+######                       ####   ####   ###   ##+\n");DESENHO;
    printf(" #+  -##  #####                       -++##-...+.#-                                    ####  ##\n");DESENHO;
    printf(" ######+               - #####+#       ###-+  +#-+##+                                  #######-\n");DESENHO;
    printf("  ###+              ####..  # ##       #++##-.-.+   .#-\n");DESENHO;
    printf("                   ###. #######      ### +#      +####\n");DESENHO;
    printf("                      +##.## .#   .####-.-##   ########\n");DESENHO;
    printf("                         #   -#    ###  ## -#####.    ##\n");DESENHO;
    printf("                       --#.  -## .##..     #  #-  ####.-#\n");DESENHO;
    printf("                      -   #   .#####  ###### #        +..#\n");DESENHO;
    printf("                      -   #.+   -  .  -    ##+  #  -.  ####\n");DESENHO;
    printf("                       -   ##  ##+    + .    ####.     +.##\n");DESENHO;
    printf("                       --  ##. ..#  #-+#+     ###   -# #++#\n");DESENHO;
    printf("                         -- .#####  ### ####-###    .  #+##\n");DESENHO;
    printf("                                 #  .###.  #+-##-  .#--#.##\n");DESENHO;
    printf("                                 .#-#   ##########  #####+#\n");DESENHO;
    printf("                                  #.#   ###      #..#   #-#\n");DESENHO;
    printf("                                   ##.  ##-      #..#   ###\n");DESENHO;
    printf("                                   #+#  ##+       #+#   #-#\n");DESENHO;
    printf("                                   ###  ##       +###    #-#\n");DESENHO;
    printf("                                   #-#  ##       .##+     ##\n");DESENHO;
    printf("                                   +##  ##.       +##     #-#\n");DESENHO;
    printf("                                    ##   #.        ##      ##\n");DESENHO;
    printf("                                    ##   #         ##.     ##\n");DESENHO;
    printf("                                    ##   ##        ##       #.\n");DESENHO;
    printf("                                    ##    #.      ##        #.\n");DESENHO;
    printf("                                    ##   ###     ##         .#+\n");DESENHO;
    printf("                                   ###   ##     #+#          ###\n");DESENHO;
    printf("                                                ###\n");DESENHO;
}
//=================================================================================================================================
//!Funcao Main [Funcao principal]
int main(){

//---------------------------------------------------------------------------------------------------------------------------------
//!Declaracao
    //Geral [loops]
    int i,j; // loop

    //Loop switch
    int loop = 1;

    //Logica do "SAIR"
    int sair;

    //Login
    char login[] = "admin"; // login armazenado
    char senha[] = "amwgaW"; // senha armazenada
    char user[TOTAL_ITENS],pass[TOTAL_ITENS]; // recebe o login e senha
    int aut = 0; // condicao de autenticado

    //Cadastro
    int item_code[TOTAL_ITENS];  // id do item
    char item_name[TOTAL_ITENS][TAMANHO_NOME]; // nome do item
    float item_price[TOTAL_ITENS]; // preco do produto
    int item_available[TOTAL_ITENS]; // disponibilidade "booleano"
    int numero_Itens; // variavel para receber o n itens para cadastro

    //Resumo
    float soma, media; // soma = acumula os valores dos itens bool = true | media = calcula a media dos valores dos itens bool = true
    int itens_disponiveis; // variavel local para contadora para decrementar para resumo [semi-loop]
    int value; //variavel temporaria que armazena o valor do ID antes de qualquer alteracao para exibir no resumo caso o "novo ID" inserido ja esteja sendo utilizado.

    //Editar
    int editar;

    //Busca
    int input;
    int item_found = 0;
//---------------------------------------------------------------------------------------------------------------------------------
//!logo
    //ESPERA;
    //logo();
    //ESPERA;
//---------------------------------------------------------------------------------------------------------------------------------
//! Login
    while(aut != 1){ // Enquanto não autenticado
        //Recebe a senha
        LIMPAR; // Limpa a tela
        printf(ESPACO"Login\n"SEPARA); //header
        printf("\nDigite o usuario : ");
        scanf("%s",user); //Recebe user

        printf("Digite a senha : ");
        scanf("%s",pass); //Recebe senha
        printf("\n");
        //checagem
        char* senha_criptografada = crip(pass); // criptografa a senha difitada
        do {
            if ((!strcmp(user,login))&&(!strcmp(senha_criptografada, senha))){ // checa as credenciais
                aut = 1; // User autenticado;
                printf(ESPACO"-> Login Efetuado\n"ESPACO);
                SAIR;
                LIMPAR;
            }
            else{
                printf(ESPACO"-> Login Falhou (Usuario|Senha incorreto)\n");
                SAIR;
                LIMPAR;
            }
        } while(sair != 1);
        sair = 0; // sai do loop
    }
//---------------------------------------------------------------------------------------------------------------------------------
//!Cadastro
    //Leitura
    printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, TOTAL_ITENS); // header
    printf("\nQuantos itens gostaria de inserir? ");
    scanf("%d", &numero_Itens); // recebe o numero de itens

    while ((numero_Itens <= 0) || (numero_Itens > TOTAL_ITENS)){ // enquanto numero de itens a ser cadastrado for invalido pede um novo item [Ser invalido = negativo || maior que limite de itens]
        LIMPAR;
        printf("~Valor Invalido~\n\n");

        printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, TOTAL_ITENS); // pede novamente o n
        printf("\nQuantos itens gostaria de inserir? ");
        scanf("%d", &numero_Itens);
    }
//_________________________________________________________________________________________________________________________________
    //Cadastro
    for(i=0; i < numero_Itens ; i++){ // loop para pedir a informacao de cada item
        LIMPAR;
        printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, numero_Itens);
        printf("\nInsira o ID do item: ");
        scanf("%d", &item_code[i]);

        for(j = 0; j < i; j++){ // checa se o id ja foi digitado
            while(item_code[i] == item_code[j]){ // enquanto o id ja foi utilizado, continua a pedir o id
                LIMPAR;
                printf(" O ID (%d) JA ESTA EM USO\n", item_code[i]);
                printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, numero_Itens); // header

                printf("\nInsira o ID do item: ");
                scanf("%d", &item_code[i]);
                j = 0; // reseta o loop para verificar novamente se o id já foi usado
            }
        }
        printf("Insira o nome do item: ");
        scanf("%s", item_name[i]);

        printf("Insira o preco do item: ");
        scanf("%f", &item_price[i]);

        printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
        scanf("%d", &item_available[i]);

        while (item_available[i] != 1 && item_available[i] != 0){ //repete - se a pergunta anterior, caso o numero informado nao ser 0 ou 1
            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &item_available[i]);
        }

        do {
            printf("\n"ESPACO"Item cadastrado:\n"SEPARA"-> ID do item: %d\n-> Nome do item: %s\n-> Preco do item: R$%.2f\n-> Disponibilidade do item: ", item_code[i],item_name[i],item_price[i]); // Printa o resumo
            if (item_available[i] == 1){
                printf("Disponivel\n");
            }else{
                printf("Nao Disponivel\n");
             }
            SAIR;
            LIMPAR;
        } while(sair != 1);
        sair = 0; // reseta a variavel apos mostrar
    }
//_________________________________________________________________________________________________________________________________
//Loop Menu
    do { // loop para o menu
        LIMPAR;

        //!MENU -> menu para editar,sumario e busca
        printf(ESPACO"Menu\n"ESPACO); // header
        printf("\n(1) Editar itens\n(2) Sumario de itens\n(3) Busca de itens\n(0) Sair\n\n"SEPARA"Digite uma opcao : "); // Opcoes
        scanf("%d",&loop); // variavel do loop
//---------------------------------------------------------------------------------------------------------------------------------
        switch(loop){
            case 1:
            //!EDITAR
                LIMPAR;
                printf(ESPACO"Editar itens\n"ESPACO);
                printf("Qual item gostaria de editar ? ");
                scanf("%d", &editar); // item a ser editado

                do { // loop para o menu
                    if(numero_Itens < editar){ // se n°itens < que o n° do item a ser editado, pede novamente
                        printf(ESPACO" O ITEM (%d) NAO FOI CADASTRADO ", editar);
                        SAIR;
                        LIMPAR;
                    }
                    /*
                    É pedido a posição do item, logo em seguida é usado a posição "real" [editar-1], visto que o vetor inicia em 0 e a posição mostrada, começa em 1
                    */
                    else{ // se o id estive entre o range permitido
                        printf(SEPARA"Id|Nome|Preco|Disponibilidade\n"); // header
                        printf("\n%i | %s | R$%.2f | "  ,item_code[editar - 1] , item_name[editar - 1] , item_price[editar - 1]); // resumo dos itens
                        if (item_available[editar - 1]==1){ // Print do "booleano"
                                printf("Disponivel");
                        }
                        else{
                            printf("Nao Disponivel");
                        }
                        value = item_code[editar - 1]; //variavel temporaria que armazena o valor do ID antes de qualquer alteracao, para exibir no resumo caso o "novo ID" inserido ja esteja sendo utilizado.
                        printf("\n\nInsira o novo ID do item: ");
                        scanf("%d", &item_code[editar - 1]);
                        for(j = 0; j < i; j++){ //loop para verificar se o id ja foi usado
                            while(item_code[editar - 1] == item_code[j] && j != editar - 1){ // se id == id de outro item && loop != do id do produto atual
                                LIMPAR;
                                printf(" O ID (%d) JA ESTA EM USO \n", item_code[editar - 1]); // avisa o usuario que o id ja foi usado

                                printf(ESPACO"Editar itens\n"ESPACO); // header

                                printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                                printf("\n%i | %s | R$%.2f | "  , value, item_name[editar - 1], item_price[editar - 1]);
                                if (item_available[editar - 1]==1){ // Print do booleano
                                    printf("Disponivel");
                                }
                                else{
                                    printf("Nao Disponivel");
                                }
                                printf("\n\nInsira o novo ID do item: "); // Pede novamente o id do item
                                scanf("%d", &item_code[editar - 1]);
                                j = 0; // reinicia a variavel para verificar novamente se o id ja foi usado
                            }
                        }
                        // Pede o restante das informacoes dos itens
                        printf("Insira o novo nome do item: ");
                        scanf("%s", item_name[editar - 1]);

                        printf("Insira o novo preco do item: ");
                        scanf("%f", &item_price[editar - 1]);

                        printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
                        scanf("%d", &item_available[editar - 1]);

                        while (item_available[editar - 1] != 1 && item_available[editar - 1] != 0){ //repete - se a pergunta anterior, caso o numero informado nao ser 0 ou 1
                            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
                            scanf("%d", &item_available[editar - 1]);
                        }
                        SAIR;
                    }
                } while(sair != 1);
                sair = 0; // continua o loop
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 2:
                //!RESUMO
                do {
                    LIMPAR;
                    soma = 0;
                    itens_disponiveis = numero_Itens; // variavel local contadora para decrementar para resumo
                    printf(ESPACO"Sumario de itens\n"ESPACO);
                    printf("Posicao|Id|Nome|Preco|Disponibilidade\n");
                    for (i=0; i<numero_Itens ; i++){ // loop para o resumo dos itens
                        printf("\n%i. %i | %s | R$%.2f | "  , i+1 , item_code[i] , item_name[i] , item_price[i]);
                        if (item_available[i]==1){ // print do booleano
                            soma+=item_price[i]; // soma dos booleano se true
                            printf("Disponivel");
                        }
                        else{
                            printf("Nao Disponivel");
                            itens_disponiveis--;
                        }
                    }
                    if (itens_disponiveis == 0){ // Print a media dos itens disponíveis
                        printf("\n\nPreco medio dos itens disponiveis: R$0.00");
                    }
                    else{
                        media = ((float) soma/itens_disponiveis);
                        printf("\n\nPreco medio dos itens disponiveis: R$%.2f\n", media);
                    }
                    SAIR;
                } while(sair != 1);
                sair = 0;
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 3:
                //!BUSCA
                LIMPAR;
                printf(ESPACO"Busca de itens\n"ESPACO);
                printf("\nInsira o ID do Item que deseja buscar: ");
                scanf("%i", &input);

                for (i = 0; i < numero_Itens; i++) { // busca o item
                    if (input == item_code[i]) {
                        do {
                            printf("\n");
                            printf(SEPARA"Id|Nome|Preco|Disponibilidade\n\n"); // header
                            printf("%d | %s | $%.2f | ", item_code[i], item_name[i], item_price[i]);
                            if (item_available[i] == 1){ // if para o booleano
                                printf("Disponivel\n");
                            }
                            else{
                                printf("NAO Disponivel\n");
                            }
                            item_found = 1;
                            SAIR;
                            LIMPAR;
                        } while(sair != 1);
                        sair = 0;
                    }
                }
                if (!item_found){ // se n encontrado
                    do {
                        LIMPAR;
                        printf(ESPACO"ID NAO Encontrado\n"ESPACO);
                        SAIR;
                    } while(sair != 1);
                    sair = 0;
                }
                item_found = 0; // reseta a variavel para buscas seguintes
                break;
        }
    } while(loop != 0);
    return 0;
}
