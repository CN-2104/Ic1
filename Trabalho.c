/*
Usado para separar partes:
//=================================================================================================================================
Usado para separar entre partes:
//_________________________________________________________________________________________________________________________________
Usado para separar entre "capitulos":
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
   #include <conio.h> // cls ("clear screen")
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
#define ESPACO "================================================\n" // serve para organizacao grafica
#define SEPARA "------------------------------------------------\n" // serve para organizacao grafica

#define TAMANHO_NOME 256 // delimita o tamanho maximo para as variaveis dos produtos
#define SAIR printf("\n\n"SEPARA"Digite 1 para continuar: ");scanf("%d",&sair); // define para sair caso n digitado = 1
//=================================================================================================================================

typedef struct{ // definicao da struct que armazena os usuarios
    char username[TAMANHO_NOME];
    char password[TAMANHO_NOME];
}usuario;

typedef struct{ // definicao da struct que armazena os itens
    int code;
    char name[TAMANHO_NOME];
    float price;
    int available;
}produto;

//!Função criptografar [Usada para senha]
char* crip(char plaintext[]){ // Recebe a senha
    int key[2][2] = {{1, 2}, {3, 4}}; // Matriz de "criptografia"
    int i, j,sum; // i,j = contadores [for] | Sum = variável para armazenar valores
    int len = strlen(plaintext); // Tamanho da senha
    char* encrypted = (char*)malloc((len + 1) * sizeof(char)); // Aloca a memoria para a string

    if (encrypted == NULL){ // Em todas as ocorrencias dessa estrutura, é verificado se a alocacao dinmaica da variavel de interesse foi bem sucedida
        printf("Erro de criptografacao de senha.");
        exit (1); // informa ao programa um codigo que sinaliza erro/falha
    }

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
void armazenarUsers(FILE *file, usuario *user, int posicaoUser); //Armazenar os usuarios cadastrados em arquivo.
void countUsers(FILE *file, int *total_users); //Conta quantos usuarios estao cadastrados no arquivo.
void readUsers(usuario *user, FILE *file, int total_users); //Le os usuarios do arquivo para o programa.
void countItens(FILE *file, int *total_itens); //Conta quantos itens estao cadastrados no arquivo.
void readItens(FILE *file, produto *item, int total_itens); //Le os itens do arquivo para o programa.
void cadastroUsuario(usuario **user,int *total_users, int sair, FILE *file); //Cadastra varios usuarios.
void loginUser(usuario *user, int total_users, int sair);//Interface para logar um usuario cadastrado.
void insercao_erro_inicial(int *numero_itens, int total_itens);/*Trata do total de itens a serem adicionados,
em caso de erro na primeira tentativa de cadastro (numero_itens < 0 ou numero_itens > 20).*/
void informacoes(int total_itens, int numero_itens, produto *item, FILE *file,int sair);/*Trata das informacoes especificas
de cada item a ser cadastrado. */
void armazenarItens(FILE *file, produto *item,int posicaoItem); //Armazenar os itens cadastrados em arquivo.
void editarItem(produto *item, int total_itens, int sair);//Edita itens por posicao.
void buscarItem(produto *item, int total_itens, int sair);//Busca itens por id.
void resumo_cadastro(int soma, int itens_disponiveis, int total_itens, produto *item, float media,int sair); /*Realiza o sumario
dos itens cadastrados / a serem cadastrados. */
//!Funcao Main [Funcao principal]
int main(){

//---------------------------------------------------------------------------------------------------------------------------------
//!Declaracao
    //Loop switch
    int loop = 1;

    //Logica do "SAIR"
    int sair = 0;

    //Login
    FILE *fileUser = NULL;
    usuario *user = NULL;
    int total_users = 0; //! le todos os usuarios/"users" quando estiver em arquivo

    //Cadastro
    FILE *fileItem = NULL; //ponteiro para o arquivo que armazena os itens
    produto *item = NULL;// ponteiro para a struct que armazena os itens
    produto *ptrTemp = NULL; //ponteiro temporario para evitar erros de realocaçao dinamica
    int total_itens = 0; //armazena quantos itens ja foram inseridos
    int numero_itens = 0; // variavel para receber o n itens para cadastro

    //Resumo
    float soma = 0, media = 0; // soma = acumula os valores dos itens bool = true | media = calcula a media dos valores dos itens bool = verdadeiro/"true"
    int itens_disponiveis = 0; // variavel local para contadora para decrementar para resumo [semi-loop]

    //Editar

    //Busca

//---------------------------------------------------------------------------------------------------------------------------------
//!logo
    //ESPERA;
    //logo();
    //ESPERA;
//---------------------------------------------------------------------------------------------------------------------------------
//! Login
     countUsers(fileUser, &total_users); //Conta quantos usuarios ja estao cadastrados para poder alocar memoria no struct
     if(total_users > 0){
        user = (usuario *) malloc(total_users*sizeof(usuario)); //alocacao dinamica de memoria no struct
        if (user == NULL){
            printf("Erro de alocacao de memoria para a struct.");
            exit (1);
        }
     }
     else{
        user = NULL; //Caso ainda nao haja usuarios cadastrados.
     }
     readUsers(user, fileUser, total_users); //atribui os usuarios cadastrados para o struct

     //!Menu pra escolher cadastrar ou logar

//    cadastroUsuario(&user, &total_users, sair, fileUser);
//    loginUser(user, total_users, sair);

//---------------------------------------------------------------------------------------------------------------------------------
//!Cadastro
    //Leitura
    countItens(fileItem, &total_itens); //Conta quantos itens ja estao cadastrados para poder alocar memoria no struct
    if(total_itens > 0){
        item = (produto *) malloc(total_itens*sizeof(produto)); //alocacao dinamica de memoria no struct
        if (item == NULL){
            printf("Erro de alocacao dinamica.");
            exit (1);
        }
    }
    else{
        item = NULL; //Caso ainda nao haja itens cadastrados.
    }
    readItens(fileItem, item, total_itens); //atribui os itens cadastrados para o struct
    insercao_erro_inicial(&numero_itens, total_itens);
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
    informacoes(total_itens,numero_itens, item, fileItem,sair);
//_________________________________________________________________________________________________________________________________
//Loop Menu
    do { // loop para o menu
        LIMPAR;

        //!MENU -> menu para editar, sumario e busca
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
                resumo_cadastro(soma, itens_disponiveis, total_itens, item, media, sair);
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

void armazenarUsers(FILE *file, usuario *user,int posicaoUser){
     file = fopen("users.bin", "ab"); //abertura do arquivo para anexaçao binaria
     if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
         printf("Erro de abertura de arquivo !");
         exit(-3);
     }
     fwrite(user[posicaoUser].username, TAMANHO_NOME*sizeof(char), 1, file); //Escreve as informaçoes dos usuarios cadastrados no arquivo
     fwrite(user[posicaoUser].password, TAMANHO_NOME*sizeof(char), 1, file);

     fclose(file); //fechar arquivo apos uso
}

void countUsers(FILE *file, int *total_users){
     file = fopen("users.bin", "rb"); //abertura do arquivo para leitura binaria
     if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
         printf("Erro de abertura de arquivo !");
         exit(-3);
     }
     fseek(file, 0, SEEK_END); //define a posicao do indicador no arquivo para o final, a fim de medir o tamanho do arquivo
     int fileSize = ftell(file); //armazena o tamanho do arquivo em bytes
     if(fileSize == -1){
         printf("Erro de leitura no arquivo !");
         exit(-2);
     }
     else{
        *total_users = fileSize/sizeof(usuario); //o numero de usuarios equivale ao valor de bytes do arquivo pelo tamanho de 1 item
     }
     fclose(file); //fecha o arquivo apos seu uso
}

void readUsers(usuario *user, FILE *file, int total_users){
     file = fopen("users.bin", "rb"); //abertura do arquivo para leitura binaria
     if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
         printf("Erro de abertura de arquivo !");
         exit(-3);
     }
     for(int i = 0; i < total_users; i++){ //loop para receber os usuarios do arquivo e atribui pro struct
         fread(user[i].username, TAMANHO_NOME*sizeof(char), 1, file);
         fread(user[i].password, TAMANHO_NOME*sizeof(char), 1, file);
     }
     fclose(file); //fecha o arquivo apos seu uso
}

void countItens(FILE *file, int *total_itens){
    file = fopen("itens.bin", "rb"); //abertura do arquivo para leitura binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    fseek(file, 0, SEEK_END); //define a posicao do indicador no arquivo para o final, a fim de medir o tamanho do arquivo
    int fileSize = ftell(file); //armazena o tamanho do arquivo em bytes
    if(fileSize == -1){
        printf("Erro de leitura no arquivo !");
        exit(-2);
    }
    else{
    *total_itens = fileSize/sizeof(produto); //o numero de itens equivale ao valor de bytes do arquivo pelo tamanho de 1 item
    }
    fclose(file); //fecha o arquivo apos seu uso
}

void readItens(FILE *file, produto *item, int total_itens){
    file = fopen("itens.bin", "rb"); //abertura do arquivo para leitura binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    for(int i = 0; i < total_itens; i++){ //loop para receber os itens do arquivo e atribui pro struct
        fread(&item[i].code, sizeof(int), 1, file);
        fread(item[i].name, TAMANHO_NOME*sizeof(char), 1, file);
        fread(&item[i].price, sizeof(float), 1, file);
        fread(&item[i].available, sizeof(int), 1, file);
    }
    fclose(file); //fecha o arquivo apos seu uso
}

void cadastroUsuario(usuario **user, int *total_users, int sair, FILE *file){
    if(*total_users == MAX_USERS){ //Caso o limite de usuarios seja atingido
        do{
            printf("Impossivel cadastrar ! Limite de usuarios atingidos");
            SAIR;
        } while(sair != 1);
    }
    else{
        (*total_users)++; //Incrementa um no total de usuarios cadastrados
        usuario *tempPtr = NULL; //variavel temporaria, aponta para a memoria em que "user" sera realocado, para checar se a realocaçao sera possivel, evitando - se erros
        tempPtr = (usuario *)realloc(*user, (*total_users)*sizeof(usuario));
        if(tempPtr == NULL){
            printf("Erro de alocacao de memoria.");
            exit(-1);
        }
        else{
            *user = tempPtr;
        }
        int posicao = *total_users - 1; //indice do usuario no struct
        printf(ESPACO"CADASTRE-SE\n"SEPARA); //header
        printf("\nDigite o usuario : ");
        scanf(" %255[^\n]", (*user)[posicao].username);
        printf("Digite a senha : ");
        scanf(" %255[^\n]", (*user)[posicao].password);
        printf("\n");

        char *senha_criptografada = crip((*user)[posicao].password); //Criptografa a senha
        strcpy((*user)[posicao].password, senha_criptografada); //Salva a senha criptografada
        armazenarUsers(file, *user, posicao); //apos o usuario ser cadastrado, ele fica armazenado no arquivo
        do{
            printf(ESPACO"-> Cadastrado com Sucesso !\n"ESPACO);
            SAIR;
        }while(sair != 1);
    }
}

void loginUser(usuario *user, int total_users, int sair){
    int aut = 0;// condicao de autenticacao
    char userCheck[TAMANHO_NOME], passCheck[TAMANHO_NOME];// armazena dados inseridos para o login
    while(aut != 1){ // Enquanto não autenticado, executa esta serie de iteracoes a seguir:
        //Recebe a senha
        LIMPAR; // Limpa a tela
        printf(ESPACO"Login\n"SEPARA); //header
        printf("\nDigite o usuario : ");
        scanf(" %255[^\n]", userCheck); //Recebe user

        printf("Digite a senha : ");
        scanf(" %255[^\n]", passCheck); //Recebe senha
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
    }
}

void armazenarItens(FILE *file, produto *item, int posicaoItem){

    file = fopen("itens.bin", "ab"); //abertura do arquivo para anexaçao binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    fwrite(&item[posicaoItem].code, sizeof(int), 1, file); //Escreve as informaçoes dos itens cadastrados no arquivo
    fwrite(item[posicaoItem].name, TAMANHO_NOME*sizeof(char), 1, file);
    fwrite(&item[posicaoItem].price, sizeof(float), 1, file);
    fwrite(&item[posicaoItem].available, sizeof(int), 1, file);

    fclose(file); //fechar arquivo apos uso
}

void insercao_erro_inicial(int *numero_itens, int total_itens){ //Obs: encontrei 2 itens já previamente cadastrados (davi GAMER - 111 e teclado - 222)
    int quantidadeRestante = MAX_ITENS - total_itens; //determina quantos itens ainda podem ser cadastrados
    printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, quantidadeRestante); // header
    printf("\nQuantos itens gostaria de inserir? ");
    scanf("%d", numero_itens); // recebe o numero de itens de interesse declarado pelo user
    while ((*numero_itens <= 0) || (*numero_itens > quantidadeRestante)){ // enquanto o numero de itens a ser cadastrado for invalido pede um novo item [Ser invalido = negativo || maior que limite de itens]
        LIMPAR;
        printf("~VALOR INVALIDO - DEVE ESTAR ENTRE 1 e %d~\n\n", quantidadeRestante);

        printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, quantidadeRestante); // pede novamente o total de produtos a serem adicionados
        printf("\nQuantos itens gostaria de inserir? ");
        scanf("%d", numero_itens);
    }
}

void informacoes(int total_itens, int numero_itens, produto *item, FILE *file, int sair){
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
        scanf(" %255[^\n]", item[i].name);

        printf("Insira o preco do item: ");
        scanf("%f", &item[i].price);

        printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
        scanf("%d", &item[i].available);

        while (item[i].available != 1 && item[i].available != 0){ //repete - se a pergunta anterior, caso o numero informado nao seja nem 0 nem 1
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
            armazenarItens(file, item, i); //apos o item ser cadastrado ele fica armazenado no arquivo
            SAIR;
            LIMPAR;
        } while(sair != 1);
    }
}

void editarItem(produto *item, int total_itens, int sair){
    LIMPAR;
    FILE *tempEditar;
    int editar; //armazena a posicao do item a ser editado
    int value; //variavel temporaria que armazena o valor do "novo ID" antes de ser atribuida ao item para checar se o ID a ser informado ja foi utilizado.
    printf(ESPACO"Editar itens\n"ESPACO);
    printf("Qual dos itens cadastrados, em ordem, gostaria de editar? (1 = primeiro, 2 = segundo, 3 = terceiro e assim por diante...) "); //pede qual o numero associado a ordem do cadastro do item no sistema a ser editado
    scanf("%d", &editar); // item a ser editado

    do { // loop para o menu
        if(editar > total_itens || editar <= 0){ // se o numero do item a ser editado for menor que 0 ou maior que o total, pede - se novamente o numero
            printf(ESPACO" O ITEM (%d) NAO FOI CADASTRADO ", editar);
            SAIR;
            LIMPAR;
        }
        /*
        É pedido a posição do item, logo em seguida é usado a posição "real" [editar-1], visto que o vetor se inicia em 0 e a posição mostrada no termnial, começa em 1
        */
        else{ // se o id estiver entre o intervalo permitido
            printf(SEPARA"Id|Nome|Preco|Disponibilidade\n"); // header
            printf("\n%i | %s | R$%.2f | "  ,item[editar - 1].code , item[editar - 1].name , item[editar - 1].price); // resumo dos itens
            if (item[editar - 1].available == 1) // Print do "booleano"
                printf("Disponivel");
            else
                printf("Nao Disponivel");
            printf("\n\nInsira o novo ID do item: ");
            scanf("%d", &value);
            for(int j = 0; j < total_itens; j++){ //loop para verificar se o id ja foi usado
                while(value == item[j].code && j != editar - 1){ // se id informado for igual ao id de outro item e a variavel do loop for diferente do id do produto atual
                    LIMPAR;
                    printf(" O ID (%d) JA ESTA EM USO \n", value); // avisa o usuario que o id ja foi usado

                    printf(ESPACO"Editar itens\n"ESPACO); // header

                    printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                    printf("\n%i | %s | R$%.2f | ", item[editar - 1].code, item[editar - 1].name, item[editar - 1].price);
                    if (item[editar - 1].available == 1) // Print do "booleano"
                        printf("Disponivel");
                    else
                        printf("Nao Disponivel");
                    printf("\n\nInsira o novo ID do item: "); // Pede novamente o id do item
                    scanf("%d", &value);
                    j = 0; // reinicia a variavel para verificar novamente se o id ja foi usado
                }
            }
            item[editar - 1].code = value; //atribui o "novo ID" ao item ao passar pela verificacao

            // Pede o restante das informacoes dos itens
            printf("Insira o novo nome do item: ");
            scanf(" %255[^\n]", item[editar - 1].name);

            printf("Insira o novo preco do item: ");
            scanf("%f", &item[editar - 1].price);

            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &item[editar - 1].available);

            while (item[editar - 1].available != 1 && item[editar - 1].available != 0){ //repete - se a pergunta anterior, caso o numero informado nao seja nem 0 nem 1
                LIMPAR;
                printf("~VALOR INVALIDO - DEVE SER (1) OU (0)~\n\n");
                printf(ESPACO"Editar itens\n"ESPACO); //header
                printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                    printf("\n%i | %s | R$%.2f | "  , value, item[editar - 1].name, item[editar - 1].price);
                    if (item[editar - 1].available == 1) // Print do "booleano"
                        printf("Disponivel");
                    else
                        printf("Nao Disponivel");
                printf("\n\nInsira o novo ID do item: %d\nInsira o novo nome do item: %s\nInsira o novo preco do item: %.2f\n", item[editar - 1].code, item[editar - 1].name, item[editar - 1].price);
                printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
                scanf("%d", &item[editar - 1].available);
            }
            printf("\n");
            printf(ESPACO"->Item Editado com Sucesso !\n"ESPACO);

            //Editar no arquivo
            tempEditar = fopen("itens.bin", "r+b"); //Abre o arquivo no modo de leitura e escrita binaria
            if(tempEditar == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
                printf("Erro de abertura de arquivo !");
                exit(-3);
            }
            fseek(tempEditar, (editar - 1)*sizeof(produto), SEEK_SET); //Define a posicao do indicador no arquivo pro inicio do item a ser editado

            fwrite(&item[editar - 1].code, sizeof(int), 1, tempEditar); //Sobrescreve com as informaçoes novas no item editado
            fwrite(item[editar - 1].name, TAMANHO_NOME*sizeof(char), 1, tempEditar);
            fwrite(&item[editar - 1].price, sizeof(float), 1, tempEditar);
            fwrite(&item[editar - 1].available, sizeof(int), 1, tempEditar);

            fclose(tempEditar);
            SAIR;
        }
    } while(sair != 1);

}

void buscarItem(produto *item, int total_itens, int sair){
    LIMPAR;
    int input; //armazena o id a ser buscado
    int item_found = 0; //condicao de item encontrado
    printf(ESPACO"Busca de itens\n"ESPACO);
    printf("\nInsira o ID do Item que deseja buscar: ");
    scanf("%i", &input);

    for (int i = 0; i < total_itens; i++) { // busca o item
        if (input == item[i].code) {
            do {
                printf("\n");
                printf(SEPARA"Id|Nome|Preco|Disponibilidade\n\n"); // header
                printf("%d | %s | $%.2f | ", item[i].code, item[i].name, item[i].price);
                if (item[i].available == 1){ // if para o "booleano"
                    printf("Disponivel\n");
                    item_found = 1; // Encontrou item e realizou "Break" (parada forcada da iteracao)
                }
                else{
                    printf("Nao Disponivel\n");
                    item_found = 1; // Encontrou item e realizou "Break" (parada forcada da iteracao)
                }
                SAIR;
                LIMPAR;
            } while(sair != 1);
            sair = 0;
        }
    }
    if (!item_found){ // se o item nao for encontrado, executa os comandos a seguir
        do {
            LIMPAR;
            printf(ESPACO"ID NAO Encontrado\n"ESPACO);
            SAIR;
        } while(sair != 1);
    }
}

void resumo_cadastro(int soma, int itens_disponiveis, int total_itens, produto *item, float media, int sair){
	do {
            LIMPAR;
            soma = 0;
            itens_disponiveis = total_itens; // variavel local contadora para ser decrementada durante o resumo/sumario dos itens
            printf(ESPACO"Sumario de itens\n"ESPACO);
            printf("Posicao|Id|Nome|Preco|Disponibilidade\n");
            for (int i = 0; i < total_itens; i++){ // loop para o resumo dos itens
                printf("\n%i. %i | %s | R$%.2f | "  , i+1 , item[i].code , item[i].name , item[i].price);
                if (item[i].available == 1){ // print do "booleano"
                    soma += item[i].price; // soma dos valores booleanos se o valor-verdade for verdadeiro/"true"
                    printf("Disponivel");
                }
                else{
                    printf("Nao Disponivel");
                    itens_disponiveis--;
                }
            }
            if (itens_disponiveis == 0) // Informa a media dos itens disponíveis
                printf("\n\nPreco medio dos itens disponiveis: R$0.00");
            else{
                media = ((float) soma/itens_disponiveis);
                printf("\n\nPreco medio dos itens disponiveis: R$%.2f\n", media);
            }
        SAIR;
        } while(sair != 1);
}
