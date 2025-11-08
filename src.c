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


int main()
{
    int loop_continuation = 1;
    
    printf("Bem-vindo ao sistema de cadastro da biblioteca\n");
    
    //incio do loop de tarefas:
    while (loop_continuation == 1){
    int decision;

    printf("\ndigite o numero da ação que deseja realizar:\n");
    printf("1-cadastro de novo usuario || 2-retirada/devolução || 3-verificação de prazos || 4-atualização de cadastro\n");

    scanf("%d",&decision);

    switch (decision)
    {
    case 1:
        user *a = malloc(sizeof(user));
        user_registration(a);
        break;
    case 2:
    
    default:
        break;
    }

    printf("você deseja realizar mais alguma tarefa?\n");
    printf("sim-1\n");
    printf("não-2\n");
    
    scanf("%d",&loop_continuation);
    }
    

    //teste e exemplo de como fazer a atribuição
    user *teste = malloc(sizeof(user));
    
    user_registration(teste);

    printf("cpf: %s\n",teste->phone_number);

    return 0;
}

// código das funções:
void user_registration(user *pessoa)
{

    printf("\nnovo cadastro:\n");

    printf("\nnome: ");
    fgets(pessoa->name, 99, stdin);
    pessoa->name[strcspn(pessoa->name, "\n")] = '\0'; //remover o \n adicionado pelo fgets

    printf("\nCPF: ");
    fgets(pessoa->cpf, 20, stdin);
    pessoa->cpf[strcspn(pessoa->cpf, "\n")] = '\0'; //remover o \n adicionado pelo fgets


    printf("\ntelefone (sem espaço, sem caracteres de seperação, ex: 54000000000): ");
    fgets(pessoa->phone_number, 20, stdin);
    pessoa->phone_number[strcspn(pessoa->phone_number, "\n")] = '\0'; //remover o \n adicionado pelo fgets

    printf("\nemail: ");
    fgets(pessoa->email, 99, stdin);
    pessoa->email[strcspn(pessoa->email, "\n")] = '\0'; //remover o \n adicionado pelo fgets

    printf("usuário cadastrado com sucesso!\n");

}