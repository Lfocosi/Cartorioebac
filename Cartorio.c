#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// função responsavel pela pagina de registro
void registro()
{
    // iniciando variaveis
    // arquivo recebe o cpf que sera usado como nome do arquivo
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // salvando o cpf digitado
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    // copiando o cpf para a variavel arquivo
    strcpy(arquivo, cpf);

    // criando o arquivo e escrevendo o cpf nele
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    // adicionando virgula
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // salvando o nome digitado
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    // escrevendo no arquivo o nome
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    // adicionando virgula
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // salvando o sobrenome digitado
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    // escrevendo no arquivo o sobrenome
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    // adicionando virgula
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // salvando o cargo digitado
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    // escrevendo no arquivo o cargo
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

// função responsavel pela pagina de consulta
void consulta()
{
    // iniciando variaveis
    char cpf[40];
    char conteudo[160];

    // configurando a linguagem para portugues
    setlocale(LC_ALL, "Portuguese");

    // salvando o cpf digitado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // lendo o arquivo do cpf passado
    FILE *file;
    file = fopen(cpf, "r");

    // verificando se ouve retorno (se encontrou o arquivo)
    // se for null retorna uma mesngem
    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }
    // salvando na variavel conteudo ate 200 caracter do arquivo, enquanto for diferente de null
    while(fgets(conteudo, 200, file) != NULL)
    {
        // mostrando no console as informações
        printf("\nEssas são as informações do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
}

// função responsavel pela pagina de deletar
void deletar()
{
    // iniciando variaveis
    char cpf[40];

    // configurando a linguagem para portugues
    setlocale(LC_ALL, "Portuguese");

    // salvando o cpf digitado
    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s", cpf);

    // lendo o arquivo do cpf passado
    FILE *file;
    file = fopen(cpf, "r");

    // verificando se ouve retorno (se encontrou o arquivo)
    // se for null retorna uma mesngem
    if(file == NULL)
    {
        printf("O usuario não se encontra no sistema!\n");
    }

    // se ouve retorno então remova o arquivo o usuario
    if(file != NULL)
    {
        remove(cpf);
        printf("Usuario deletado!\n");
    }

    system("pause");
}

int main()
{
    // configurando a linguagem para portugues
    setlocale(LC_ALL, "Portuguese");

    // iniciando variaveis {opção: responsavel pelo contrlode da pagina, laço: responsavel pelo controle da volta ao menu}
    int opcao = 0;
    int laco = 1;
    char senhaUsuario[10] = "a";

    // garantindo aceeso para adim
    printf("### Cartório da EBAC ###");
    printf("Login de administrador!\n\n");
    printf("Digite dua senha:");
    // guardando a senha digitada na variavel
    scanf("%s", &senhaUsuario);

    // casso a senha esteja errada, notifique o usuario e encerre o programa
    // comparando as strings pelo resultado na memoria (0 se for igual)
    if(strcmp(senhaUsuario, "admin") != 0)
    {
        system("cls");
        printf("Senha incorreta!\n\n");
        return 0;
    }

    // inicio da repetição que garante a volta para o menu
    for(laco = 1; laco == 1;)
    {
        // limpar o console para nova execução
        system("cls");

        // criando/mostrando o menu
        printf("### Cartório da EBAC ###");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Opção: ");
        
        // salvando a opção digitada pelo usuario
        scanf("%d", &opcao);

        // limpando o console para mostrar nova pagina
        system("cls");

        // selecionando a pagina atravez da escolha do usuario
        // caso a opção não exista mostra mensagem e repetir o menu 
        switch(opcao)
        {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            default:
                printf("Essa opção não esta disponivel!\n\n");
                system("pause");
                break;
        }
    }
    // saindo do sistema
    return 0;
}
