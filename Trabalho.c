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
#define MAX_ITENS 20 // Total dos vetores | loop cadastro dos itens
#define MAX_USERS 20 // Total de usuarios que podem ser cadastrados
#define ESPACO "================================================\n" // para organizacao grafica
#define SEPARA "------------------------------------------------\n" // para organizacao grafica

#define TAMANHO_NOME 256 // delimita o tamanho maximo para as variaveis dos produtos
#define SAIR printf("\n\n"SEPARA"Digite 1 para continuar: ");scanf("%d",&sair); // define para sair caso n digitado = 1
//=================================================================================================================================

typedef struct{ // definicao do struct que armazena os usuarios
    char username[TAMANHO_NOME];
    char password[TAMANHO_NOME];
}usuario;

typedef struct{ // definicao do struct que armazena os itens
    int code;
    char name[TAMANHO_NOME];
    float price;
    int available;
}produto;

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
//!Prototipagem das funcoes utilizadas
void countItens(FILE **file, int *total_itens); //Conta quantos itens estao cadastrados no arquivo
void readItens(FILE **file, produto *item, int *total_itens); //Passa os itens do arquivo para o programa
void cadastroUsuario(usuario **user,int *total_users, int sair); //Cadastrar varios usuarios
void loginUser(usuario *user, int total_users, int sair);//Interface para logar um usuario cadastrado
void func_insercao_erro_inicial(int *numero_itens, int total_itens);/*Trata do total de itens a serem adicionados,
em caso de erro na primeira tentativa de cadastro (numero_itens < 0 ou numero_itens > 20).*/
void func_informacoes(int total_itens, int numero_itens, produto *item, FILE **file,int sair);//Trata das informacoes especificas de cada item a ser cadastrado.
void armazenarItens(FILE **file, produto *item,int posicaoItem); //Armazenar os itens cadastrados em arquivo
void editarItem(produto *item, int total_itens, int sair);//Edita itens por posicao
void buscarItem(produto *item, int total_itens, int sair);//Busca itens por id
//!Funcao Main [Funcao principal]
int main(){

//---------------------------------------------------------------------------------------------------------------------------------
//!Declaracao
    //Geral [loops]
    int i; // loop

    //Loop switch
    int loop = 1;

    //Logica do "SAIR"
    int sair = 0;

    //Login
    usuario *user = NULL;
    int total_users = 0; //! ler todos os users quando tiver em arquivo

    //Cadastro
    FILE *fileItem = NULL; //ponteiro para o arquivo que armazena os itens
    produto *item = NULL;// ponteiro para struct que armazena os itens
    produto *ptrTemp = NULL; //ponteiro temporario para evitar erros de realocaçao dinamica
    int total_itens = 0; //armazena quantos itens ja foram inseridos
    int numero_itens = 0; // variavel para receber o n itens para cadastro

    //Resumo
    float soma, media; // soma = acumula os valores dos itens bool = true | media = calcula a media dos valores dos itens bool = true
    int itens_disponiveis; // variavel local para contadora para decrementar para resumo [semi-loop]

    //Editar

    //Busca

//---------------------------------------------------------------------------------------------------------------------------------
//!logo
    //ESPERA;
    //logo();
    //ESPERA;
//---------------------------------------------------------------------------------------------------------------------------------
//! Login
    //cadastroUsuario(&user, &total_users, sair);
    //loginUser(user, total_users, sair);

//---------------------------------------------------------------------------------------------------------------------------------
//!Cadastro
    //Leitura
    countItens(&fileItem, &total_itens); //Conta quantos itens ja estao cadastrados para poder alocar memoria no struct
    if(total_itens > 0){
        item = (produto *) malloc(total_itens*sizeof(produto)); //alocacao dinamica de memoria no struct
    }
    else{
        item = NULL; //Caso ainda nao haja itens cadastrados
    }
    readItens(&fileItem, item, &total_itens); //atribui os itens cadastrados para o struct
    func_insercao_erro_inicial(&numero_itens, total_itens);
    total_itens += numero_itens; //Incrementa "total_itens" com o numero de itens a serem cadastrados
    ptrTemp = (produto *) realloc(item, total_itens*sizeof(produto));
    if(ptrTemp == NULL){
        printf("Erro de alocacao de memoria.");
        exit(-1);
    }
    else{
        item = ptrTemp; //Caso nao haja erro de realocaçao, "item" aponta para a memoria
    }
//_________________________________________________________________________________________________________________________________
    //Cadastro
    func_informacoes(total_itens,numero_itens, item, &fileItem,sair);
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
                editarItem(item, total_itens, sair);
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 2:
                //!RESUMO
                do {
                    LIMPAR;
                    soma = 0;
                    itens_disponiveis = total_itens; // variavel local contadora para decrementar para resumo
                    printf(ESPACO"Sumario de itens\n"ESPACO);
                    printf("Posicao|Id|Nome|Preco|Disponibilidade\n");
                    for (i=0; i<total_itens ; i++){ // loop para o resumo dos itens
                        printf("\n%i. %i | %s | R$%.2f | "  , i+1 , item[i].code , item[i].name , item[i].price);
                        if (item[i].available==1){ // print do booleano
                            soma+=item[i].price; // soma dos booleano se true
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
                buscarItem(item, total_itens, sair);
                break;
        }
    } while(loop != 0);
    free(item); //desalocacao de memoria ao fim do programa
    free(user);

    return 0;
}

void countItens(FILE **file, int *total_itens){
    *file = fopen("itens.txt", "rb"); //abertura do arquivo para leitura binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    fseek(*file, 0, SEEK_END); //define a posicao do indicador no arquivo pro final a fim de medir o tamanho do arquivo
    int fileSize = ftell(*file); //armazena o tamanho do arquivo em bytes
    if(fileSize == -1){
        printf("Erro de leitura no arquivo !");
        exit(-2);
    }
    else{
    *total_itens = fileSize/sizeof(produto); //o numero de itens equivale ao valor de bytes do arquivo pelo tamanho de 1 item
    }
    fclose(*file); //fechar arquivo apos uso
}

void readItens(FILE **file, produto *item, int *total_itens){
    *file = fopen("itens.txt", "rb"); //abertura do arquivo para leitura binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    for(int i = 0; i < *total_itens; i++){ //loop para receber os itens do arquivo e atribui pro struct
        fread(&item[i].code, sizeof(int), 1, *file);
        fread(item[i].name, TAMANHO_NOME*sizeof(char), 1, *file);
        fread(&item[i].price, sizeof(float), 1, *file);
        fread(&item[i].available, sizeof(int), 1, *file);
    }
    fclose(*file);//fechar arquivo apos uso
}

void cadastroUsuario(usuario **user, int *total_users, int sair){
    if(*total_users == MAX_USERS){
        do{
            printf("Impossivel cadastrar ! Limite de usuarios atingidos");
            SAIR;
        } while(sair != 1);
        sair = 0;
    }
    else{
        (*total_users)++;
        usuario *tempPtr = NULL; //variavel temporaria, aponta para a memoria que "user" sera realocado para checar se a realocaçao sera possivel e evitar erros
        tempPtr = (usuario *)realloc(*user, (*total_users)*sizeof(usuario));
        if(tempPtr == NULL){
            printf("Erro de alocacao de memoria.");
            exit(-1);
        }
        else{
            *user = tempPtr;
        }
        printf(ESPACO"CADASTRE-SE \t\t!TEMPORARIO! \n"SEPARA); //header
        printf("\nDigite o usuario : ");
        scanf("%s", (*user[*total_users-1]).username);
        printf("Digite a senha : ");
        scanf("%s", (*user[*total_users-1]).password);
        printf("\n");
        crip((*user[*total_users - 1]).password); //! Salvar a senha criptografada no file
        do{
            printf(ESPACO"-> Cadastrado com Sucesso !\n"ESPACO);
            SAIR;
        }while(sair != 1);
        sair = 0;
    }
}

void loginUser(usuario *user, int total_users, int sair){
    int aut = 0;// condicao de autenticado
    char userCheck[TAMANHO_NOME],passCheck[TAMANHO_NOME];// armazena dados inseridos para login
    while(aut != 1){ // Enquanto não autenticado
        //Recebe a senha
        LIMPAR; // Limpa a tela
        printf(ESPACO"Login\n"SEPARA); //header
        printf("\nDigite o usuario : ");
        scanf("%s", userCheck); //Recebe user

        printf("Digite a senha : ");
        scanf("%s", passCheck); //Recebe senha
        printf("\n");
        //checagem
        char *senha_criptografada = crip(passCheck); // criptografa a senha digitada
        do {
            if ((!strcmp(userCheck,user[total_users-1].username))&&(!strcmp(senha_criptografada, user[total_users-1].password))){ // checa as credenciais
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
}

void armazenarItens(FILE **file, produto *item,int posicaoItem){

    *file = fopen("itens.txt", "ab"); //abertura do arquivo para anexaçao binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    fwrite(&item[posicaoItem].code, sizeof(int), 1, *file); //Escreve as informaçoes dos itens cadastrados no arquivo
    fwrite(item[posicaoItem].name, TAMANHO_NOME*sizeof(char), 1, *file);
    fwrite(&item[posicaoItem].price, sizeof(float), 1, *file);
    fwrite(&item[posicaoItem].available, sizeof(int), 1, *file);

    fclose(*file); //fechar arquivo apos uso
}

void func_insercao_erro_inicial(int *numero_itens, int total_itens){
    int quantidadeRestante = MAX_ITENS - total_itens; //quantos itens ainda podem ser cadastrados
    printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, quantidadeRestante); // header
    printf("\nQuantos itens gostaria de inserir? ");
    scanf("%d", numero_itens); // recebe o numero de itens
    while ((*numero_itens <= 0) || (*numero_itens > quantidadeRestante)){ // enquanto numero de itens a ser cadastrado for invalido pede um novo item [Ser invalido = negativo || maior que limite de itens]
        LIMPAR;
        printf("~VALOR INVALIDO - DEVE ESTAR ENTRE 1 e %d~\n\n", quantidadeRestante);

        printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, quantidadeRestante); // pede novamente o n
        printf("\nQuantos itens gostaria de inserir? ");
        scanf("%d", numero_itens);
    }
}

void func_informacoes(int total_itens, int numero_itens, produto *item, FILE **file,int sair){
    int quantidadeInicial = total_itens - numero_itens; //posicao inicial a se cadastrar os itens
    for(int i = quantidadeInicial; i < total_itens ; i++){ // loop para pedir a informacao de cada item
        LIMPAR;
        printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, total_itens);
        printf("\nInsira o ID do item: ");
        scanf("%d", &item[i].code);

        for(int j = 0; j < i; j++){ // checa se o id ja foi digitado
            while(item[i].code == item[j].code){ // enquanto o id ja foi utilizado, continua a pedir o id
                LIMPAR;
                printf(" O ID (%d) JA ESTA EM USO\n", item[i].code);
                printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, total_itens); // header

                printf("\nInsira o ID do item: ");
                scanf("%d", &item[i].code);
                j = 0; // reseta o loop para verificar novamente se o id já foi usado
            }
        }
        printf("Insira o nome do item: ");
        scanf("%s", item[i].name);

        printf("Insira o preco do item: ");
        scanf("%f", &item[i].price);

        printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
        scanf("%d", &item[i].available);

        while (item[i].available != 1 && item[i].available != 0){ //repete - se a pergunta anterior, caso o numero informado nao ser 0 ou 1
            LIMPAR;
            printf("~VALOR INVALIDO - DEVE SER (1) OU (0)~\n\n");
            printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, total_itens);
            printf("\nInsira o ID do item: %d\nInsira o nome do item: %s\nInsira o preco do item: %.2f\n", item[i].code, item[i].name, item[i].price);
            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &item[i].available);
        }

        do {
            printf("\n"ESPACO"Item cadastrado:\n"SEPARA"-> ID do item: %d\n-> Nome do item: %s\n-> Preco do item: R$%.2f\n-> Disponibilidade do item: ", item[i].code,item[i].name,item[i].price); // Printa o resumo
            if (item[i].available == 1){
                printf("Disponivel\n");
            }
            else{
                printf("Nao Disponivel\n");
            }
            armazenarItens(file, item,i); //apos o item ser cadastrado ele fica armazenado no arquivo
            SAIR;
            LIMPAR;
        } while(sair != 1);
        sair = 0; // reseta a variavel apos mostrar
    }
}

void editarItem(produto *item, int total_itens, int sair){
    LIMPAR;
    int editar; //armazena a posicao do item a ser editado
    int value; //variavel temporaria que armazena o valor do "novo ID" antes de atribuir ao item para checar se ja foi utilizado.
    printf(ESPACO"Editar itens\n"ESPACO);
    printf("Qual item gostaria de editar ? ");
    scanf("%d", &editar); // item a ser editado

    do { // loop para o menu
        if(editar > total_itens || editar <= 0){ // se n°itens < que o n° do item a ser editado, pede novamente
            printf(ESPACO" O ITEM (%d) NAO FOI CADASTRADO ", editar);
            SAIR;
            LIMPAR;
        }
        /*
        É pedido a posição do item, logo em seguida é usado a posição "real" [editar-1], visto que o vetor inicia em 0 e a posição mostrada, começa em 1
        */
        else{ // se o id estive entre o range permitido
            printf(SEPARA"Id|Nome|Preco|Disponibilidade\n"); // header
            printf("\n%i | %s | R$%.2f | "  ,item[editar - 1].code , item[editar - 1].name , item[editar - 1].price); // resumo dos itens
            if (item[editar - 1].available==1){ // Print do "booleano"
                    printf("Disponivel");
            }
            else{
                printf("Nao Disponivel");
            }
            printf("\n\nInsira o novo ID do item: ");
            scanf("%d", &value);
            for(int j = 0; j < total_itens; j++){ //loop para verificar se o id ja foi usado
                while(value == item[j].code && j != editar - 1){ // se id == id de outro item && loop != do id do produto atual
                    LIMPAR;
                    printf(" O ID (%d) JA ESTA EM USO \n", value); // avisa o usuario que o id ja foi usado

                    printf(ESPACO"Editar itens\n"ESPACO); // header

                    printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                    printf("\n%i | %s | R$%.2f | ", item[editar - 1].code, item[editar - 1].name, item[editar - 1].price);
                    if (item[editar - 1].available == 1){ // Print do booleano
                        printf("Disponivel");
                    }
                    else{
                        printf("Nao Disponivel");
                    }
                    printf("\n\nInsira o novo ID do item: "); // Pede novamente o id do item
                    scanf("%d", &value);
                    j = 0; // reinicia a variavel para verificar novamente se o id ja foi usado
                }
            }
            item[editar - 1].code = value; //atribui o "novo ID" ao item ao passar pela verificacao

            // Pede o restante das informacoes dos itens
            printf("Insira o novo nome do item: ");
            scanf("%s", item[editar - 1].name);

            printf("Insira o novo preco do item: ");
            scanf("%f", &item[editar - 1].price);

            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &item[editar - 1].available);

            while (item[editar - 1].available != 1 && item[editar - 1].available != 0){ //repete - se a pergunta anterior, caso o numero informado nao ser 0 ou 1
                LIMPAR;
                printf("~VALOR INVALIDO - DEVE SER (1) OU (0)~\n\n");
                printf(ESPACO"Editar itens\n"ESPACO); //header
                printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                    printf("\n%i | %s | R$%.2f | "  , value, item[editar - 1].name, item[editar - 1].price);
                    if (item[editar - 1].available == 1){ // Print do booleano
                        printf("Disponivel");
                    }
                    else{
                        printf("Nao Disponivel");
                    }
                printf("\n\nInsira o novo ID do item: %d\nInsira o novo nome do item: %s\nInsira o novo preco do item: %.2f\n", item[editar - 1].code, item[editar - 1].name, item[editar - 1].price);
                printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
                scanf("%d", &item[editar - 1].available);
            }
            printf("\n");
            printf(ESPACO"->Item Editado com Sucesso !\n"ESPACO);
            SAIR;
        }
    } while(sair != 1);
    sair = 0; // continua o loop
}

void buscarItem(produto *item, int total_itens, int sair){
    LIMPAR;
    int input; //armazena o id a ser buscado
    int item_found = 0;//condicao de item encontrado
    printf(ESPACO"Busca de itens\n"ESPACO);
    printf("\nInsira o ID do Item que deseja buscar: ");
    scanf("%i", &input);

    for (int i = 0; i < total_itens; i++) { // busca o item
        if (input == item[i].code) {
            do {
                printf("\n");
                printf(SEPARA"Id|Nome|Preco|Disponibilidade\n\n"); // header
                printf("%d | %s | $%.2f | ", item[i].code, item[i].name, item[i].price);
                if (item[i].available == 1){ // if para o booleano
                    printf("Disponivel\n");
                }
                else{
                    printf("NAO Disponivel\n");
                }
                item_found = 1; // Encontrou item e realizou "Break"
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
}
