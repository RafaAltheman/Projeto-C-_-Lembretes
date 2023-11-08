// Rafaela Altheman de Campos (24.123.010-1)
#include <stdio.h>
#include "proj3func.h"

int main() {
    //carregarlista(listartarefa, "arquivo.txt"); //Esta função carrega a lista de tarefas, abrindo o arquivo
    //Declarando variáveis
    int cod;
    char arquivo[] = "tarefas.bin";
    listadetarefas lt;

    cod = carregarlista(&lt, arquivo);
    if(cod == 1) //Se o "return" for 1, a lista de tarefas é igualada a zero para iniciar as funções
        lt.qtd = 0;

    int opcao;

    // Declaramos um while para o usuário decidir qual função ele quer no momento.
    while (1){
        printf("Opcoes de escolha:\n");
        printf("1. Cadastrar \n");
        printf("2. Deletar \n");
        printf("3. Listar \n");
        printf("4. Editar \n");
        printf("5. Filtrar por prioridade \n");
        printf("6. Filtrar por estado \n");
        printf("7. Filtrar por Categoria \n");
        printf("8. Filtrar por prioridade e Categoria \n");
        printf("9. Exportar tarefas por prioridade \n");
        printf("10. Exportar tarefa por categoria \n");
        printf("11. Exportar tarefas por prioridade e categoria \n");
        printf("12. Sair \n");

        printf("Escolha uma opcao (1 a 12): ");
        scanf("%d", &opcao); //Usuário digita a opção dele e ela é salva na mamória.

        // Dependendo da escolha do usuário, a função roda para realizar a função que o cliente deseja realizar com seus lembretes.
        if (opcao==0){
        } else if (opcao==1){
            criartarefa(&lt); //Na opção 1, a função criar tarefa é chamada
        } else if (opcao==2){
            deletartarefa(&lt); //Na opção 2, a função deletar tarefa é chamada
        } else if (opcao==3){
            listartarefa(lt); //Na opção 3, a função listar tarefa é chamada
        } else if (opcao==4){
            editartarefa(&lt); //Na opção 4, a função editar tarefa é chamada
        } else if (opcao == 5){
            filtrarprioridade(&lt); //Na opção 5, a função filtrar tarefa por prioridade é chamada
        } else if (opcao == 6){
            filtrarestado(&lt); //Na opção 6, a função filtrar tarefa por estado é chamada
        } else if (opcao == 7){
            filtrarcategoria(&lt); //Na opção 7, a função filtrar tarefa por categoria é chamada
        } else if (opcao == 8){
            filtrarprioridadeecategoria(&lt); //Na opção 8, a função filtrar por prioridade e categoria é chamada
        } else if (opcao == 9){
            exportarprioridade(lt, "tarefasporprioridade.txt"); //Na opção 9, a função exportar por prioridade é chamada
        } else if (opcao == 10){
            exportarcategoria(&lt, "tarefasporcategorias.txt"); //Na opção 10, a função exportar categoria é chamada 
        } else if (opcao == 11){
            exportarprioridadeecategoria(&lt, "tarefasporprioridadeecategoria.txt"); //Na opção 11, a função exportar por prioridade e categoria é chamada
        } else if (opcao == 12){ //Para o usuário salvar o arquivo, ele deve apertar a opção ("Sair"), sendo que quando acessar o programa novamente, todas as informações fornecidas antes de sair serão listadas
            salvarlista(&lt, "tarefas.bin");
            break;
        } else{
            printf("Erro! Escolha um numero valido! \n"); //Caso o usuário escolha um número fora do intervalo de 1 a 4, essa mensagem aparece na tela
        }
    }

    cod = salvarlista(&lt,arquivo); //Salva as informações na lista
    if (cod !=0) //Se o "return" for diferente de zero, a tarefa não é cadastrada
        printf("Erro ao cadastrar as tarefas!");
}