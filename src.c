#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{

    char cpf[20];
    char phone_number[20];
    char name[100];
    char email[100];

}user;

//inicialização da função:
void user_registration(user *pessoa);
void save_user_to_file(user *pessoa);

int main()
{
    int loop_continuation = 1, c;
    
    printf("Bem-vindo ao sistema de cadastro da biblioteca\n");
    
    //incio do loop de tarefas:
    while (loop_continuation == 1){
    int decision;

    printf("\ndigite o numero da ação que deseja realizar:\n");
    printf("1-cadastro de novo usuario || 2-retirada/devolução || 3-verificação de prazos || 4-atualização de cadastro\n");

    scanf("%d",&decision);
    while ((c = getchar()) != '\n' && c != EOF); //limpa o buffer

    switch (decision)
    {
    case 1:
        user *a = malloc(sizeof(user));
        user_registration(a);
        save_user_to_file(a);
        break;
    case 2:
    
    default:
        break;
    }

    printf("você deseja realizar mais alguma tarefa?\n");
    printf("sim-1\n");
    printf("não-2\n");
    
    scanf("%d",&loop_continuation);
    while ((c = getchar()) != '\n' && c != EOF); //limpa o buffer
    }
    
    return 0;
}

// código das funções:

//entrada de dados do cadastro
void user_registration(user *pessoa){

    printf("\nnovo cadastro:\n");

    printf("\nnome: ");
    fflush(stdout);//garante que a mensagem será exibida antes do programa esperar a entrada do usuário, em qualquer ambiente.
    fgets(pessoa->name, 99, stdin);
    pessoa->name[strcspn(pessoa->name, "\n")] = '\0'; //remover o \n adicionado pelo fgets

    printf("\nCPF: ");
    fflush(stdout);//garante que a mensagem será exibida antes do programa esperar a entrada do usuário, em qualquer ambiente.
    fgets(pessoa->cpf, 20, stdin);
    pessoa->cpf[strcspn(pessoa->cpf, "\n")] = '\0'; //remover o \n adicionado pelo fgets


    printf("\ntelefone (sem espaço, sem caracteres de seperação, ex: 54000000000): ");
    fflush(stdout);//garante que a mensagem será exibida antes do programa esperar a entrada do usuário, em qualquer ambiente.
    fgets(pessoa->phone_number, 20, stdin);
    pessoa->phone_number[strcspn(pessoa->phone_number, "\n")] = '\0'; //remover o \n adicionado pelo fgets

    printf("\nemail: ");
    fflush(stdout);//garante que a mensagem será exibida antes do programa esperar a entrada do usuário, em qualquer ambiente.
    fgets(pessoa->email, 99, stdin);
    pessoa->email[strcspn(pessoa->email, "\n")] = '\0'; //remover o \n adicionado pelo fgets

    printf("usuário cadastrado com sucesso!\n");

}

//armazenamento do cadastro (aquivo txt)
void save_user_to_file(user *pessoa) {

    // Abre \ cria o arquivo em modo de adição
    FILE *f = fopen("usuarios.txt", "a");
    if (!f) { // Se fopen falhar
        perror("Erro ao abrir o arquivo usuarios.txt");
        return; // Sai da função
    }

    // Escreve os dados formatados no arquivo
    fprintf(f, "%s;%s;%s;%s\n",
            pessoa->name,
            pessoa->cpf,
            pessoa->phone_number,
            pessoa->email);

    // Fecha o arquivo para garantir gravação segura
    fclose(f);

    // Mensagem opcional para o usuário
    printf("Dados salvos com sucesso em usuarios.txt\n");
}

