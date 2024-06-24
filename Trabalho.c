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
#ifdef _WIN32 //definindo funcoes para windows e linux
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
#define MAX_ITENS 20 // Total dos vetores para o loop de cadastro dos itens
#define MAX_USERS 20 // Total de usuarios que podem ser cadastrados
#define ESPACO "================================================\n" // serve para organizacao grafica
#define SEPARA "------------------------------------------------\n" // serve para organizacao grafica

#define TAMANHO_NOME 256 // delimita o tamanho maximo para as variaveis dos produtos
#define SAIR printf("\n\n"SEPARA"Digite 1 para continuar: ");scanf("%d",&sair); //define para sair caso o numero digitado seja a 1
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

    if (encrypted == NULL){ // Em todas as ocorrencias dessa estrutura, é verificado se a alocacao dinamica da variavel de interesse foi bem sucedida
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
    Usado um programa para desenhar em caracteres ASCII e depois ajustado manualmente;
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
void removerItem(produto *item, int *total_itens, FILE *file, int sair);
void lerArquivos(FILE *file, int *total_itens, produto **item, usuario **user, int *total_users); /*Le todas as informacoes dos
arquivos e as passa para o programa.*/
void menu_inicio(usuario **user, int *total_users, int sair, FILE *fileUser); //Menu (Login ou Cadastro).
void menu_sec(produto *item, int total_itens, int sair, int numero_itens, FILE *file); //Menu para manipulaçao dos itens.
void armazenarUsers(FILE *file, usuario *user, int posicaoUser); //Armazena os usuarios cadastrados em arquivo.
void countUsers(FILE *file, int *total_users); //Conta quantos usuarios estao cadastrados no arquivo.
void readUsers(usuario *user, FILE *file, int total_users); //Le os usuarios do arquivo para o programa.
void countItens(FILE *file, int *total_itens); //Conta quantos itens estao cadastrados no arquivo.
void readItens(FILE *file, produto *item, int total_itens); //Le os itens do arquivo para o programa.
void cadastroUsuario(usuario **user, int *total_users, int sair, FILE *file); //Realiza o cadastro dos usuarios.
void loginUser(usuario *user, int total_users, int sair, int *aut); //Ilustra a interface de login para um usuario cadastrado.
void insercao_erro_inicial(int *numero_itens, int *total_itens); /*Trata do total de itens a serem adicionados,
em caso de erro na primeira tentativa de cadastro (numero_itens < 0 ou numero_itens > 20).*/
void informacoes(int *total_itens, int *numero_itens, produto **item, FILE *file,int sair); /*Trata das informacoes especificas
de cada item a ser cadastrado. */
void armazenarItens(FILE *file, produto *item,int posicaoItem); //Armazena os itens cadastrados em arquivo.
void editarItem(produto *item, int total_itens, int sair); /*Edita os itens por posicao, a qual é gravada na declaracao de suas
caracteristicas (nome, ID etc.).*/
void buscarItem(produto *item, int total_itens, int sair); //Busca os itens a partir de seus ID's próprios.
void resumo_cadastro(int total_itens, produto *item, int sair); //Realiza o sumariodos itens cadastrados / a serem cadastrados.
//!Funcao Main [Funcao principal]
int main(){

//---------------------------------------------------------------------------------------------------------------------------------
//!Declaracao
    //Logica do "SAIR"
    int sair = 0;

    //Login
    FILE *fileUser = NULL;
    usuario *user = NULL;
    int total_users = 0; // le todos os usuarios/"users" quando estiverem gravados em arquivo

    //Cadastro
    FILE *fileItem = NULL; //ponteiro para o arquivo que armazena os itens
    produto *item = NULL;// ponteiro para a struct que armazena os itens
    int total_itens = 0; //armazena quantos itens ja foram inseridos/declarados
    int numero_itens = 0; // variavel para receber o numero de itens para serem cadastrados
//---------------------------------------------------------------------------------------------------------------------------------
//!logo
    //ESPERA;
    //logo();
    //ESPERA;
//---------------------------------------------------------------------------------------------------------------------------------
//! Login

     lerArquivos(fileItem, &total_itens, &item, &user, &total_users);

    //!Menu pra escolher cadastrar ou logar
    menu_inicio(&user, &total_users, sair, fileUser);

//---------------------------------------------------------------------------------------------------------------------------------
//!Cadastro
    //Cadastro
    informacoes(&total_itens,&numero_itens, &item, fileItem,sair);
//_________________________________________________________________________________________________________________________________
//Loop Menu
    menu_sec(item,total_itens,sair, numero_itens, fileItem);
//_________________________________________________________________________________________________________________________________
//Fim
    free(item); //desalocacao da memoria do buffer utilizada, ao fim do programa
    free(user);

    return 0;
}

void lerArquivos(FILE *file, int *total_itens, produto **item, usuario **user, int *total_users){

    //Leitura do arquivo de itens
    countItens(file, total_itens); //Conta quantos itens ja estao cadastrados para poder realizar a alocacao de memoria na struct/"estrutura"
    if(*total_itens > 0){
        *item = (produto *) malloc((*total_itens)*sizeof(produto)); //alocacao dinamica de memoria na struct
        if (*item == NULL){
            printf("Erro na alocacao de memoria para a struct de itens.");
            exit (1);
        }
    }else
        *item = NULL; //Caso ainda nao haja itens cadastrados.

    readItens(file, (*item), (*total_itens)); //atribui os itens cadastrados para a struct

    //Leitura do arquivo de usuarios
    countUsers(file, total_users); //Conta quantos usuarios ja estao cadastrados para poder alocar memoria na struct
    if(*total_users > 0){
       *user = (usuario *) malloc((*total_users)*sizeof(usuario)); //alocacao dinamica de memoria na struct
       if (*user == NULL){
           printf("Erro na alocacao de memoria para a struct de usuarios.");
           exit (1);
       }
    }else
        *user = NULL; //Caso ainda nao haja usuarios cadastrados.

     readUsers((*user), file, (*total_users)); //atribui os usuarios cadastrados para a struct
}

void menu_inicio(usuario **user, int *total_users, int sair, FILE *fileUser){
    int loop; //armazena o numero escolhido no menu de interacao
    int aut = 0; // condicao de autenticacao do login
    int existeUsuario = 1; //Confere se ha usuarios cadastrados para permitir o login
    int limiteUsuario = 0;
    do{ // loop para o menu
        LIMPAR;
        if(!existeUsuario){ //Caso nao haja usuarios cadastrados, imprime um aviso
            printf("~NAO HA NENHUM USUARIO CADASTRADO PARA LOGAR~\n\n");
            existeUsuario = 1; //reseta a variavel para uma nova verificacao
        }
        else if(limiteUsuario){
            printf("~LIMITE DE CADASTRO DE USUARIOS ATINGIDO~\n\n");
            limiteUsuario = 0; //reseta a variavel para uma nova verificacao
        }
        //!MENU -> Login ou Cadastro
        printf(ESPACO"Menu\n"ESPACO); // header
        printf("\n(1) Login\n(2) Cadastro\n(0) Sair\n"SEPARA"Digite uma opcao : "); // Opcoes
        scanf("%d",&loop); // variavel do loop

       switch(loop){
            case 1:
                if(*total_users>0)
                    loginUser(*user, *total_users, sair, &aut);
                else
                    existeUsuario = 0; //Condicao para imprimir o aviso
                break;

            case 2:
                if(*total_users == MAX_USERS) //Caso o limite de usuarios seja atingido
                    limiteUsuario = 1;
                else
                    cadastroUsuario(user, total_users, sair, fileUser);
                break;

            case 0:
                exit(0);
                break;
       }
   }while(aut != 1); //execucao da iteracao "do - while", enquanto o login nao ter sido concluido
}

void menu_sec(produto *item, int total_itens, int sair, int numero_itens, FILE *file){
    int loop = 1;
    do{ // loop para o menu
        LIMPAR;

        //!MENU -> menu para as funcionalidades: editar, sumario, busca, cadastro e remocao
        printf(ESPACO"Menu\n"ESPACO); // header/"cabeçalho"
        printf("\n(1) Editar itens\n(2) Sumario de itens\n(3) Busca de itens\n(4) Cadastro Itens\n(5) Remocao de itens\n(0) Sair\n\n"SEPARA"Digite uma opcao : "); // Opcoes
        scanf("%d",&loop); // variavel do loop

        switch(loop){
//---------------------------------------------------------------------------------------------------------------------------------
            case 1:
                editarItem(item, total_itens, sair);
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 2:
                resumo_cadastro(total_itens, item, sair);
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 3:
                buscarItem(item, total_itens, sair);
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 4:
                informacoes(&total_itens, &numero_itens, &item, file, sair);
                break;
//---------------------------------------------------------------------------------------------------------------------------------
            case 5:
                removerItem(item, &total_itens, file, sair);
                break;
        }

    }while(loop != 0);
}

void armazenarUsers(FILE *file, usuario *user,int posicaoUser){
     file = fopen("users.bin", "ab"); //abertura do arquivo para anexaçao binaria ("append binary")
     if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
         printf("Erro de abertura de arquivo !");
         exit(-3);
     }
     fwrite(user[posicaoUser].username, TAMANHO_NOME*sizeof(char), 1, file); //Escreve as informaçoes dos usuarios cadastrados no arquivo
     fwrite(user[posicaoUser].password, TAMANHO_NOME*sizeof(char), 1, file);

     fclose(file); //arquivo é fechado devidamente apos seu uso
}

void countUsers(FILE *file, int *total_users){
     file = fopen("users.bin", "rb"); //abertura do arquivo para leitura binaria ("read binary")
     if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
         printf("Erro de abertura de arquivo !");
         exit(-3);
     }
     fseek(file, 0, SEEK_END); //funcao que define a posicao do indicador no arquivo para o final (argumento SEEK_END), a fim de medir o tamanho do arquivo
     int fileSize = ftell(file); //armazena o tamanho do arquivo em bytes
     if(fileSize == -1){
         printf("Erro de leitura no arquivo !");
         exit(-2);
     }
     else
        *total_users = fileSize/sizeof(usuario); //o numero de usuarios equivale a razao do valor de bytes do arquivo pelo tamanho de 1 item
     fclose(file); //arquivo é fechado devidamente apos seu uso
}

void readUsers(usuario *user, FILE *file, int total_users){
     file = fopen("users.bin", "rb"); //abertura do arquivo para leitura binaria
     if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
         printf("Erro de abertura de arquivo !");
         exit(-3);
     }
     for(int i = 0; i < total_users; i++){ //loop para receber os usuarios do arquivo e para atribui-los para a struct
         fread(user[i].username, TAMANHO_NOME*sizeof(char), 1, file);
         fread(user[i].password, TAMANHO_NOME*sizeof(char), 1, file);
     }
     fclose(file); //arquivo é fechado devidamente apos seu uso
}

void countItens(FILE *file, int *total_itens){
    file = fopen("itens.bin", "rb"); //abertura do arquivo para leitura binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    fseek(file, 0, SEEK_END); //funcao que define a posicao do indicador no arquivo para o final (argumento SEEK_END), a fim de medir o tamanho do arquivo
    int fileSize = ftell(file); //armazena o tamanho do arquivo em bytes
    if(fileSize == -1){
        printf("Erro de leitura no arquivo !");
        exit(-2);
    }
    else
        *total_itens = fileSize/sizeof(produto); //o numero de usuarios equivale a razao do valor de bytes do arquivo pelo tamanho de 1 item
    fclose(file); //arquivo é fechado devidamente apos seu uso
}

void readItens(FILE *file, produto *item, int total_itens){
    file = fopen("itens.bin", "rb"); //abertura do arquivo para leitura binaria
    if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
        printf("Erro de abertura de arquivo !");
        exit(-3);
    }
    for(int i = 0; i < total_itens; i++){ //loop para receber os usuarios do arquivo e para atribui-los para a struct
        fread(&item[i].code, sizeof(int), 1, file);
        fread(item[i].name, TAMANHO_NOME*sizeof(char), 1, file);
        fread(&item[i].price, sizeof(float), 1, file);
        fread(&item[i].available, sizeof(int), 1, file);
    }
    fclose(file); //arquivo é fechado devidamente apos seu uso
}

void cadastroUsuario(usuario **user, int *total_users, int sair, FILE *file){
    LIMPAR;
    (*total_users)++; //Incrementa um no total de usuarios cadastrados
    usuario *tempPtr = NULL; //variavel temporaria, aponta para a memoria em que "user" sera realocado, para checar se a realocaçao sera possivel, evitando - se, assim, erros
    tempPtr = (usuario *)realloc(*user, (*total_users)*sizeof(usuario));
    if(tempPtr == NULL){
        printf("Erro de alocacao de memoria.");
        exit(-1);
    }
    else
        *user = tempPtr;
    int posicao = *total_users - 1; //indice do usuario na struct
    printf(ESPACO"CADASTRE-SE\n"SEPARA); //header/"cabecalho"
    printf("\nDigite o usuario : ");
    scanf(" %255[^\n]", (*user)[posicao].username);
    for(int j = 0; j < posicao; j++){ // checa se o username ja foi utilizado
        while(!(strcmp((*user)[posicao].username, (*user)[j].username))){ // enquanto detectar que o username foi utilizado, o programa continua a pedir o username
            LIMPAR;
            printf(" O USERNAME '%s' JA ESTA EM USO\n", (*user)[posicao].username);
            printf(ESPACO"CADASTRE-SE\n"SEPARA); //header
            printf("\nDigite o usuario : ");
            scanf(" %255[^\n]", (*user)[posicao].username);
            j = 0; // reseta o loop para verificar novamente se o username já foi usado
        }
    }
    printf("Digite a senha : ");
    scanf(" %255[^\n]", (*user)[posicao].password);
    printf("\n");
    char *senha_criptografada = crip((*user)[posicao].password); //Criptografa a senha
    strcpy((*user)[posicao].password, senha_criptografada); //Salva a senha criptografada
    armazenarUsers(file, *user, posicao); //apos o usuario ser cadastrado, ocorre o seu armazenamento no arquivo
    do{
        printf(ESPACO"-> Cadastrado com Sucesso !\n"ESPACO);
        SAIR;
    }while(sair != 1);
}


void loginUser(usuario *user, int total_users, int sair, int *aut){
    LIMPAR;
    char userCheck[TAMANHO_NOME], passCheck[TAMANHO_NOME];// armazena os dados inseridos no o login
        //Recebe a senha
        LIMPAR; // Limpa a tela ("clear screen")
        printf(ESPACO"Login\n"SEPARA); //header/"cabecalho"
        printf("\nDigite o usuario : ");
        scanf(" %255[^\n]", userCheck); //Recebe o user

        printf("Digite a senha : ");
        scanf(" %255[^\n]", passCheck); //Recebe a senha
        printf("\n");
        //checagem
        char *senha_criptografada = crip(passCheck); // criptografa a senha digitada
        do{
            for(int i = 0;i<total_users;i++){
                if ((!strcmp(userCheck,user[i].username))&&(!strcmp(senha_criptografada, user[i].password))){ // checa as credenciais
                    *aut = 1; // User autenticado;
                    i = total_users; // break controlado
                    printf(ESPACO"-> Login Efetuado\n"ESPACO);
                }
            }
            if(!(*aut))
                printf(ESPACO"-> Login Falhou (Usuario|Senha incorreto)\n");
            SAIR;
            LIMPAR;
        }while(sair != 1);
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

    fclose(file); //o arquivo é devidamente fechado apos o seu uso
}

void insercao_erro_inicial(int *numero_itens, int *total_itens){
    int quantidadeRestante = MAX_ITENS - *total_itens; //determina quantos itens ainda podem ser cadastrados
    printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, quantidadeRestante); // header/"cabecalho"
    printf("\nQuantos itens gostaria de inserir? ");
    scanf("%d", numero_itens); // recebe o numero de itens de interesse declarado pelo user
    while ((*numero_itens <= 0) || (*numero_itens > quantidadeRestante)){ // enquanto o numero de itens a ser cadastrado for invalido pede um novo item [Ser invalido = negativo ou maior que o limite de itens]
        LIMPAR;
        printf("~VALOR INVALIDO - DEVE ESTAR ENTRE 1 e %d~\n\n", quantidadeRestante);

        printf(ESPACO"Adicionar itens (De 1 a %d)\n"ESPACO, quantidadeRestante); // pede novamente o total de produtos a serem adicionados
        printf("\nQuantos itens gostaria de inserir? ");
        scanf("%d", numero_itens);
    }
    *total_itens += *numero_itens; //Realiza a soma do valor de "total_itens" com o numero de itens a serem cadastrados
}

void informacoes(int *total_itens, int *numero_itens, produto **item, FILE *file, int sair){
    produto *ptrTemp = NULL; //ponteiro temporario para evitar erros de realocaçao dinamica
    insercao_erro_inicial(numero_itens, total_itens);
    ptrTemp = (produto *) realloc((*item), (*total_itens)*sizeof(produto));
    if(ptrTemp == NULL){
        printf("Erro de alocacao de memoria.");
        exit(-1);
    }
    else
        *item = ptrTemp; //Caso nao haja erro de realocaçao, "item" aponta para a memoria

    int quantidadeInicial = *total_itens - *numero_itens; //posicao inicial a se cadastrar os itens
    for(int i = quantidadeInicial; i < *total_itens ; i++){ // loop para pedir a informacao de cada item
        LIMPAR;
        printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, *total_itens);
        printf("\nInsira o ID do item: ");
        scanf("%d", &(*item)[i].code);

        for(int j = 0; j < i; j++){ // checa se o id ja foi utilizado anteriormente
            while((*item)[i].code == (*item)[j].code){ // enquanto detectar que o ID foi utilizado, continua a pedir o ID
                LIMPAR;
                printf(" O ID (%d) JA ESTA EM USO\n", (*item)[i].code);
                printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, *total_itens); // header/"cabecalho"

                printf("\nInsira o ID do item: ");
                scanf("%d", &(*item)[i].code);
                j = 0; // reseta o loop para verificar novamente se o ID já foi usado
            }
        }
        printf("Insira o nome do item: ");
        scanf(" %255[^\n]", (*item)[i].name);

        printf("Insira o preco do item: ");
        scanf("%f", &(*item)[i].price);

        printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
        scanf("%d", &(*item)[i].available);

        while ((*item)[i].available != 1 && (*item)[i].available != 0){ //repete - se a pergunta anterior, caso o numero informado nao seja nem 0 nem 1
            LIMPAR;
            printf("~VALOR INVALIDO - DEVE SER (1) OU (0)~\n\n");
            printf(ESPACO"Adicionar item %d/%d\n"ESPACO, i+1, *total_itens);
            printf("\nInsira o ID do item: %d\nInsira o nome do item: %s\nInsira o preco do item: %.2f\n", (*item)[i].code, (*item)[i].name, (*item)[i].price);
            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &(*item)[i].available);
        }

        do {
            printf("\n"ESPACO"Item cadastrado:\n"SEPARA"-> ID do item: %d\n-> Nome do item: %s\n-> Preco do item: R$%.2f\n-> Disponibilidade do item: ",(*item)[i].code, (*item)[i].name, (*item)[i].price); // "Printa", no terminal, o resumo
            if ((*item)[i].available == 1)
                printf("Disponivel\n");
            else
                printf("Nao Disponivel\n");
            armazenarItens(file, *item, i); //apos o item ser cadastrado, o mesmo fica armazenado no arquivo
            SAIR;
            LIMPAR;
        } while(sair != 1);
    }
}

void editarItem(produto *item, int total_itens, int sair){
    LIMPAR;
    FILE *tempEditar;
    int ID_editar; //armazena o ID do item a ser editado
    int value; //variavel temporaria que armazena o valor do "novo ID" antes de ser atribuida ao item, com o intuito de checar se o ID a ser informado ja foi utilizado.

    printf(ESPACO"Editar itens\n"ESPACO);
    printf("Informe o ID do item o qual tem interesse em editar suas informacoes: "); //pede o ID do item a ser editado na funcao.
    scanf("%d", &ID_editar); // ID do item a ser editado

    do { // loop para o menu
        for (int i = 0; i < total_itens; i++){
            if (ID_editar == item[i].code){
                printf(ESPACO"O ITEM DE ID %d FOI ENCONTRADO ", ID_editar);
                ID_editar = i; // atribuicao realizada para facilitar a manipulacao das variaveis do tipo struct associadas
                SAIR;
                LIMPAR;
                break;
            }
            else if(i == total_itens - 1 && ID_editar != item[i].code){ // Se o id informado nao foi cadastrado, encerra - se a edicao
                printf(ESPACO" O ITEM DE ID %d NAO FOI CADASTRADO ", ID_editar);
                SAIR;
                LIMPAR;
            }
        }
            printf(SEPARA"Id|Nome|Preco|Disponibilidade\n"); // header/"cabecalho"
            printf("\n%i | %s | R$%.2f | "  ,item[ID_editar].code , item[ID_editar].name , item[ID_editar].price); // resumo dos itens
            if (item[ID_editar].available == 1) // "Print" do valor-verdade da variavel booleana associada ("booleano")
                printf("Disponivel");
            else
                printf("Nao Disponivel");
            printf("\n\nInsira o novo ID do item: ");
            scanf("%d", &value);
            for(int j = 0; j < total_itens; j++){ //loop para verificar se o id ja foi usado
                while(value == item[j].code && j != ID_editar){ // executa - se essa iteracao, caso o ID informado for igual ao ID de outro item, que nao pode ser o item sendo editado

                    printf(" O ID (%d) JA ESTA EM USO \n", value); // avisa o usuario que o id ja foi usado

                    printf(ESPACO"Editar itens\n"ESPACO); // header/"cabecalho"

                    printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                    printf("\n%i | %s | R$%.2f | ", item[ID_editar].code, item[ID_editar].name, item[ID_editar].price);
                    if (item[ID_editar].available == 1) // "Print" do valor-verdade da variavel booleana associada ("booleano")
                        printf("Disponivel");
                    else
                        printf("Nao Disponivel");
                    printf("\n\nInsira o novo ID do item: "); // Pede novamente o ID do item
                    scanf("%d", &value);
                    j = 0; // reinicia a variavel para reverificar se o ID ja foi usado
                }
            }
            item[ID_editar].code = value; //atribui o "novo ID" ao item ao passar pela verificacao

            // Pede o restante das informacoes dos itens
            printf("Insira o novo nome do item: ");
            scanf(" %255[^\n]", item[ID_editar].name);

            printf("Insira o novo preco do item: ");
            scanf("%f", &item[ID_editar].price);

            printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &item[ID_editar].available);

            while (item[ID_editar].available != 1 && item[ID_editar].available != 0){ //repete - se a pergunta anterior, caso o numero informado nao seja nem 0 nem 1
                LIMPAR;
                printf("~VALOR INVALIDO - DEVE SER (1) OU (0)~\n\n");
                printf(ESPACO"Editar itens\n"ESPACO); //header
                printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                    printf("\n%i | %s | R$%.2f | "  , value, item[ID_editar].name, item[ID_editar].price);
                    if (item[ID_editar].available == 1) // "Print" do valor - verdade da variavel booleana associada ("booleano")
                        printf("Disponivel");
                    else
                        printf("Nao Disponivel");
                printf("\n\nInsira o novo ID do item: %d\nInsira o novo nome do item: %s\nInsira o novo preco do item: %.2f\n", item[ID_editar].code, item[ID_editar].name, item[ID_editar].price);
                printf("O item esta disponivel ? (1 = Sim | 0 = Nao): ");
                scanf("%d", &item[ID_editar].available);
            }
            printf("\n");
            printf(ESPACO"->Item Editado com Sucesso !\n"ESPACO);

            //Editar no arquivo
            tempEditar = fopen("itens.bin", "r+b"); //Abre o arquivo no modo de leitura e escrita binaria ("read and binary write")
            if(tempEditar == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
                printf("Erro de abertura de arquivo !");
                exit(-3);
            }
            fseek(tempEditar, (ID_editar)*sizeof(produto), SEEK_SET); // a funcao define a posicao do indicador no arquivo pro inicio do item a ser editado

            fwrite(&item[ID_editar].code, sizeof(int), 1, tempEditar); //Sobrescreve - se as informacoes originais com as informaçoes novas do item editado
            fwrite(item[ID_editar].name, TAMANHO_NOME*sizeof(char), 1, tempEditar);
            fwrite(&item[ID_editar].price, sizeof(float), 1, tempEditar);
            fwrite(&item[ID_editar].available, sizeof(int), 1, tempEditar);

            fclose(tempEditar);

            SAIR;

    } while(sair != 1);

}

void buscarItem(produto *item, int total_itens, int sair){
    LIMPAR;
    int input; //armazena o id a ser buscado
    int item_found = 0; //condicao de item encontrado
    printf(ESPACO"Busca de itens\n"ESPACO);
    printf("\nInsira o ID do Item que deseja buscar: ");
    scanf("%i", &input);

    for (int i = 0; i < total_itens; i++) { // busca do item de interesse
        if (input == item[i].code) {
            do {
                printf("\n");
                printf(SEPARA"Id|Nome|Preco|Disponibilidade\n\n"); // header
                printf("%d | %s | $%.2f | ", item[i].code, item[i].name, item[i].price);
                if (item[i].available == 1){ // if para o  valor-verdade associada a variavel booleana ("booleano")
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
    if (!item_found){ // executa esta iteracao, se o item nao for encontrado
        do {
            LIMPAR;
            printf(ESPACO"ID NAO Encontrado\n"ESPACO);
            SAIR;
        } while(sair != 1);
    }
}

void resumo_cadastro(int total_itens, produto *item, int sair){
	do {
            LIMPAR;
            float soma = 0, media = 0; // soma = acumulo dos valores dos itens bool = "verdadeiro"/true | media = calculo da media dos valores dos itens bool = verdadeiro/"true"
            int itens_disponiveis = total_itens; // variavel local para contar o decremento no resumo [semi-loop]
            printf(ESPACO"Sumario de itens\n"ESPACO);
            printf("Posicao|Id|Nome|Preco|Disponibilidade\n");
            for (int i = 0; i < total_itens; i++){ // loop para o resumo dos itens
                printf("\n%i. %i | %s | R$%.2f | "  , i+1 , item[i].code , item[i].name , item[i].price);
                if (item[i].available == 1){ // "Print" do valor - verdade da variavel booleana associada ("booleano")
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

void removerItem(produto *item, int *total_itens, FILE *file, int sair){
    LIMPAR;
    int remover;
    int confirmar;
    do{
        LIMPAR; //arrumar o sair
        printf(ESPACO"Remover Item\n"ESPACO);
        if(*total_itens == 0){
            printf("\nNenhum item cadastrado");
            SAIR;
        }
        else{
            printf("\nInsira qual item remover: ");
            scanf("%d", &remover);
            printf("\n");
            while(remover <=0 || remover > *total_itens){
                LIMPAR;
                printf("~VALOR INVALIDO - ESCOLHA UM ITEM CADASTRADO DE (1) A (%d)~\n\n", *total_itens);
                printf(ESPACO"Remover Item\n"ESPACO);
                printf("\nInsira qual item remover: ");
                scanf("%d", &remover);
                printf("\n");
            }
            printf(SEPARA"Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
            printf("\n%i | %s | R$%.2f | "  , item[remover - 1].code, item[remover - 1].name, item[remover - 1].price);
            if (item[remover - 1].available == 1) // Print do "booleano"
                printf("Disponivel");
            else
                printf("Nao Disponivel");

            printf("\n\nTem certeza que deseja remover esse item ? (1 = Sim | 0 = Nao): ");
            scanf("%d", &confirmar);
            while(confirmar != 1 && confirmar != 0){
                LIMPAR;
                printf("~VALOR INVALIDO - DEVE SER (1) OU (0)~\n\n");
                printf(ESPACO"Remover Item\n"ESPACO);
                printf("Id|Nome|Preco|Disponibilidade\n"); // Resumo do item
                printf("\n%i | %s | R$%.2f | "  , item[remover - 1].code, item[remover - 1].name, item[remover - 1].price);
                if (item[remover - 1].available == 1) // Print do "booleano"
                    printf("Disponivel");
                else
                    printf("Nao Disponivel");

                printf("\n\nTem certeza que deseja remover esse item ? (1 = Sim | 0 = Nao): ");
                scanf("%d", &confirmar);
            }
            if(confirmar == 0){
                SAIR;
            }
            else{
                //remove do struct
                for(int i = remover - 1; i < *total_itens - 1; i++){
                    item[i].code = item[i + 1].code;
                    strcpy(item[i].name, item[i + 1].name);
                    item[i].price = item[i + 1].price;
                    item[i].available = item[i + 1].available;
                }
                (*total_itens)--;

                //remove do arquivo
                file = fopen("itens.bin", "wb");
                if(file == NULL){ //caso haja erro na abertura do arquivo, o programa se encerra
                    printf("Erro de abertura de arquivo !");
                    exit(-3);
                }
                for(int i = 0; i < *total_itens; i++){
                    fwrite(&item[i].code, sizeof(int), 1, file); //Sobrescreve o arquivo sem o item removido
                    fwrite(item[i].name, TAMANHO_NOME*sizeof(char), 1, file);
                    fwrite(&item[i].price, sizeof(float), 1, file);
                    fwrite(&item[i].available, sizeof(int), 1, file);
                }
                fclose(file);
                printf("\n");
                printf(ESPACO"->Item Removido com Sucesso !\n"ESPACO);
                SAIR;
            }
        }
    } while(sair != 1);
}

