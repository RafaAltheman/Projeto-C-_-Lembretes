#include "proj3func.h"
#include <stdio.h>

void clearbuffer(){ //função que limpa o buffer de entrada para receber novas informações do usuário
   int c; 
   while((c = getchar()) != '\n' && c != EOF); 
}

//Função para criar a tarefa onde o usuário pode declarar a prioridade, categoria e descrição do lembrete;
int criartarefa(listadetarefas *lt){
    if (lt->qtd < 100) { //se a quantidade de tarefas for menor que cem (o máximo) o programa irá pedir a prioridade da tarefa, sua categoria e descrição.
        printf("Prioridade (0 a 10): ");
        scanf("%d", &lt->tarefas[lt->qtd].prioridade); //Pedimos a prioridade da tarefa e guardamos a informação na memória.
        printf("Categoria: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].categoria); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como prioridade na memória..
        printf("Descricao: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].descricao); // Usamos " %[^\n]" para ler o "scanf" com espaços, guardando o que o usuário informar como prioridade na memória.
        printf("Estado da tarefa: (nao iniciado, em andamento ou completo) ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].estado);
        lt->qtd++; //A quantidade de tarefas aumenta quando o usuário terminar de descrever sua tarefa.
        printf("Tarefa cadastrada!\n"); //Quando o usuário terminar de descrever a tarefa essa mensagem aparece.
    } else {
        printf("A lista de tarefas esta cheia! Nao e possivel adicionar mais tarefas.(MAXIMO 100)\n"); //Caso haja mais de 100 tarefas é informado que foi atingida a capacidade máxima.
    }
    return 0;
}


int deletartarefa(listadetarefas *lt){ //Função para deletar tarefas
    int posicao;
    printf("Digite o numero da tarefa que deseja deletar (de 1 a %d): ", lt->qtd); //Pedindo pro usuário informar a tarefa que deve ser deletada.
    scanf("%d", &posicao);//Usuário informa qual é sua tarefa e ela é deletada a partir da posição que está na lista de tarefas (encontramos ela na lista por sua posição).
    if (posicao >= 1 && posicao <= lt->qtd) { //Se a posição da tarefa foi maior que 1 e menor ou igual que a quantidade, poderá ser encontrada (pois ela existe)
        posicao--; //Apaga a tarefa
        for (int i = posicao; i < lt->qtd - 1; i++) { //Um "for" para iterar entre as posições , e enquanto for menor que a quantidade da lista de tarefas, ele apaga e corrige a posição da tarefa na lista.
            lt->tarefas[i] = lt->tarefas[i + 1];
        }
        lt->qtd--; //Diminui a quantidade de tarefas.
        printf("Tarefa deletada!\n"); //Informa que ela foi deletada com sucesso
    } else {
        printf("Essa tarefa nao existe!\n"); //Caso a tarefa não for encontrada (for menor que 1 ou maior que a quantidade atual), será informado que ela não existe.
    }
    return 0;
}


int listartarefa(listadetarefas lt){ //Função para listar as tarefas previamente adicionadas
    if (lt.qtd == 0) {
        printf("A lista de tarefas esta vazia.\n"); //Se a quantidade de tarefas for 0 aparecerá essa mensagem
    } else {
        printf("Lista de tarefas:\n"); //Caso a quantidade de tarefas for maior que 0, pegamos a tarefa por sua posição (i) e listamos.
        for (int i = 0; i < lt.qtd; i++) {
            printf("Tarefa %d:\n", i + 1);//Imprime a tarefa em ordem cronológica (começando por "Tarefa 1"), assim, conforme o número de tarefas cresce é somado o número da tarefa anterior à 1.
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade); //Imprime a prioridade, procurando a  informação a partir da posição da tarefa na lista.
            printf("Categoria: %s\n", lt.tarefas[i].categoria); //Imprime a categoria, procurando a  informação a partir da posição da tarefa na lista.
            printf("Descricao: %s\n", lt.tarefas[i].descricao); //Imprime a descrição, procurando a  informação a partir da posição da tarefa na lista.
            printf("Estado da Tarefa: %s\n", lt.tarefas[i].estado); //Imprime o estado da tarefa, procurando a informação a partir da posição da tarefa na lista.
            printf("\n"); //Imprime um espaço para organizar a listagem
        }
    }
    return 0;
}

int editartarefa(listadetarefas *lt){ // Função para editar as tarefas ja existentes
    // Declaração de variáveis
    int posicao;
    int campo;
    // Pede para o usuário qual tarefa ele deseja editar e guarda na variável "posição"
    printf("Digite o número da Tarefa que deseja editar (de 1 a %d): ", lt->qtd);
    scanf("%d", &posicao);
    // Confere se é uma tarefa existente
    if (posicao >=1 && posicao <= lt->qtd){
        int campo;
    // Se a tarefa existir, o programa fornece um menu para o usuário escolher qual tópico da tarefa ele deseja modificar
        printf("1. Prioridade\n");
        printf("2. Categoria\n");
        printf("3. Descrição\n");
        printf("4. Estado\n");

    // Pede para o usuário qual campo ele deseja modificar e guarda na variável "campo"
        printf("Digite o campo da tarefa que voce deseja modificar:");
        scanf("%d", &campo);
        clearbuffer();

    // Se o usuário escolher a opção 1, ele modificará a prioridade
        if(campo == 1){
            printf("Nova Prioridade (0 a 10):\n");
            scanf("%d", &lt->tarefas[posicao - 1].prioridade); // O scanf substitui a antiga prioridade pela nova escolhida pelo usuário
            clearbuffer();
            printf("Tarefa editada!\n");
        } else if(campo == 2){
            printf("Nova Categoria:\n");
            scanf("%[^\n]", lt->tarefas[posicao - 1].categoria);
            clearbuffer();
            printf("Tarefa editada!\n");
        } else if(campo == 3){
            printf("Nova Descrição:\n");
            scanf("%[^\n]", lt->tarefas[posicao - 1].descricao);
            clearbuffer();
            printf("Tarefa editada!\n");
        } else if(campo == 4){
            printf("Novo Estado:\n");
            scanf("%[^\n]", lt->tarefas[posicao - 1].estado);
            clearbuffer();
            printf("Tarefa editada!\n");
        } else{
            printf("Campo não existente!\n");
        }

        salvarlista(lt, "arquivo.txt");
    } else{
        printf("Essa tarefa não existe!\n");
    }
}

int filtrarprioridade(listadetarefas *lt){
    int prioridadeescolhida;
    printf("Digite o número da prioridade que voce deseja filtrar:\n");
    scanf("%d", &prioridadeescolhida);

    if (prioridadeescolhida >=0 && prioridadeescolhida<=10){
        printf("Tarefas com a prioridade %ls selecionada:\n", &prioridadeescolhida);

        for (int i = 0; i < lt->qtd; i++) {
            if(lt->tarefas[i].prioridade == prioridadeescolhida){
            printf("Prioridade: %d\n", lt->tarefas[i].prioridade); //Imprime a prioridade, procurando a  informação a partir da posição da tarefa na lista.
            printf("Categoria: %s\n", lt->tarefas[i].categoria); //Imprime a categoria, procurando a  informação a partir da posição da tarefa na lista.
            printf("Descricao: %s\n", lt->tarefas[i].descricao); //Imprime a descrição, procurando a  informação a partir da posição da tarefa na lista.
            printf("Estado da Tarefa: %s\n", lt->tarefas[i].estado); //Imprime o estado da tarefa, procurando a informação a partir da posição da tarefa na lista.
            printf("\n"); //Imprime um espaço para organizar a listagem
            }
    }
}
    else {
        printf("Prioridade inválida!\n");
    }
}

int filtrarestado(listadetarefas *lt){
    char estadoescolhido[30];
    int encontrado = 0;

    printf("Digite o estado que voce quer filtrar(nao iniciado, em andamento ou completo):\n");
    scanf(" %[^\n]", estadoescolhido);

    for(int i = 0; i < lt->qtd; i++){
        if(strcmp(estadoescolhido, lt->tarefas[i].estado) == 0){
            printf("Tarefas com o estado selecionado:\n");
            printf("Prioridade: %d\n", lt->tarefas[i].prioridade); //Imprime a prioridade, procurando a  informação a partir da posição da tarefa na lista.
            printf("Categoria: %s\n", lt->tarefas[i].categoria); //Imprime a categoria, procurando a  informação a partir da posição da tarefa na lista.
            printf("Descricao: %s\n", lt->tarefas[i].descricao); //Imprime a descrição, procurando a  informação a partir da posição da tarefa na lista.
            printf("Estado da Tarefa: %s\n", lt->tarefas[i].estado); //Imprime o estado da tarefa, procurando a informação a partir da posição da tarefa na lista.
            printf("\n"); //Imprime um espaço para organizar a listagem
            encontrado = 1;
        }
    }    
    if (!encontrado){
        printf("Digite um estado válido\n");
    }
}

int filtrarcategoria(listadetarefas *lt){
    char categoriaescolhida[100];
    int encontrado = 0;
    tarefa tarefasprioritarias[100];

    printf("Digite a categoria que você deseja filtrar:\n");
    scanf(" %[^\n]", categoriaescolhida);

    int tarefasprioridade = 0;

    for (int i = 0; i < lt->qtd; i++) {
        if (strcmp(categoriaescolhida, lt->tarefas[i].categoria) == 0) {
            tarefasprioritarias[tarefasprioridade] = lt->tarefas[i];
            tarefasprioridade++;
            encontrado = 1;
        }
    }

    if (!encontrado){
        printf("Digite uma categoria válida\n");
    } else {
        for(int i = 0; i < tarefasprioridade; i++){
            for(int y = i+1; y < tarefasprioridade; y++){
                if(tarefasprioritarias[i].prioridade < tarefasprioritarias[y].prioridade){
                    tarefa ordem = tarefasprioritarias[i]; 
                    tarefasprioritarias[i] = tarefasprioritarias[y];
                    tarefasprioritarias[y] = ordem;
                }
            }
        }
    }  
        printf("Tarefas com categoria escolhida e ordenadas por prioridade:\n");
        for (int i = 0; i < tarefasprioridade; i++) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefasprioritarias[i].prioridade);
            printf("Categoria: %s\n", tarefasprioritarias[i].categoria);
            printf("Descricao: %s\n", tarefasprioritarias[i].descricao);
            printf("Estado da Tarefa: %s\n", tarefasprioritarias[i].estado);
            printf("\n");
    }
    }

int filtrarprioridadeecategoria(listadetarefas *lt){
    int prioridadeescolhida;
    char categoriaescolhida[100];
    int encontrado = 0;

    printf("Digite o número da prioridade que voce deseja filtrar:\n");
    scanf("%d", &prioridadeescolhida);

    printf("Digite a categoria que você deseja filtrar:\n");
    scanf(" %[^\n]", categoriaescolhida);

    if(prioridadeescolhida >=0 && prioridadeescolhida<=10){
        for(int i = 0; i < lt->qtd; i++){
            if (lt->tarefas[i].prioridade == prioridadeescolhida && strcmp(categoriaescolhida, lt->tarefas[i].categoria) == 0){
                printf("Tarefas com a categoria e prioridade selecionada:\n");
                printf("Prioridade: %d\n", lt->tarefas[i].prioridade);
                printf("Categoria: %s\n", lt->tarefas[i].categoria);
                printf("Descricao: %s\n", lt->tarefas[i].descricao);
                printf("Estado da Tarefa: %s\n", lt->tarefas[i].estado);
                printf("\n");
                encontrado = 1;
            }
        }
    } else if (!encontrado){
        printf("Nenhuma tarefa encontrada com essa categoria.\n");
    }
    }

int exportarprioridade(listadetarefas lt, char nome[30]){
    int prioridadeescolhida;
    printf("Digite o número da prioridade que voce deseja exportar:\n");
    scanf("%d", &prioridadeescolhida);
    if (prioridadeescolhida >=0 && prioridadeescolhida<=10){
    FILE *f = fopen("tarefasporprioridade.txt", "w");
   
    if (f == NULL){  //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
   }
   for (int i = 0; i < lt.qtd; i++){
        if(lt.tarefas[i].prioridade == prioridadeescolhida){
            fprintf(f, "Prioridade: %d, Categoria: %s, Estado: %s, Descrição: %s\n", lt.tarefas[i].prioridade, lt.tarefas[i].categoria, lt.tarefas[i].estado, lt.tarefas[i].descricao);
        }
   }
    fclose(f);
    printf("Tarefas com a prioridade selecionada foram exportadas\n");
   } else {
        printf("Prioridade não existente\n");
   }
    
}
    
int exportarcategoria(listadetarefas *lt, char nome[30]){
    char categoriaselecionada[100];

    printf("Digite a categoria que você deseja exportar:\n");
    scanf(" %99[^\n]", categoriaselecionada);

    FILE *f = fopen("tarefasporcategorias.txt", "w");
    printf("%p ", f);
    if (f == NULL){  //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
   } for (int i = 0; i < lt -> qtd; i++){
        if(strcmp(lt->tarefas[i].categoria ,categoriaselecionada)==0){
            fprintf(f, "Prioridade: %d, Categoria: %s, Estado: %s, Descrição: %s\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].estado, lt->tarefas[i].descricao);
        }
   }

    fclose(f);
    printf("Tarefas com a categoria selecionada foram exportadas\n");

}

int exportarprioridadeecategoria(listadetarefas *lt, char nome[30]){
    int prioridadeescolhida;
    char categoriaescolhida[100];

    printf("Digite o número da prioridade que voce deseja filtrar:\n");
    scanf("%d", &prioridadeescolhida);

    printf("Digite a categoria que você deseja filtrar:\n");
    scanf(" %[^\n]", categoriaescolhida);

    FILE *f = fopen("tarefasporprioridadeecategoria.txt", "w");
    if (f == NULL){  //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
   } for (int i = 0; i < lt -> qtd; i++){
        if(lt->tarefas[i].prioridade == prioridadeescolhida && strcmp(categoriaescolhida, lt->tarefas[i].categoria) == 0){
            fprintf(f, "Prioridade: %d, Categoria: %s, Estado: %s, Descrição: %s\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].estado, lt->tarefas[i].descricao);
        }
   }
    fclose(f);
    printf("Tarefas com a categoria e a prioridade selecionada foram exportadas\n");
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int salvarlista(listadetarefas *lt, char nome[]){ //Função para salvar a lista no arquivo
    FILE *f = fopen(nome, "wb"); //Abre um arquivo no formato binário
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n"); //Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    if(fwrite(lt, sizeof(listadetarefas), 1, f) != 1 ) //Este comando escreve no arquivo em formato binário as informações dadas pelo usuário
    {
        printf("Erro ao salvar\n");
        fclose(f);
        return 1;
    }
    fclose(f); //Fecha o arquivo
    return 0;
}


int carregarlista(listadetarefas *lt, char nome[]){ //Função para carregar a lista de tarefas
    FILE *f = fopen(nome, "rb"); //Abre o arquivo em formato de leitura binária
    if (f == NULL) {
        printf("Arquivo nao encontrado.\n"); //Caso o arquivo não exista, esta mensagem aparece no terminal alertando o usuário
        return 1;
    }
    fread(lt, sizeof(listadetarefas), 1, f); //Este comando le o arquivo binário
    fclose(f); //Fecha o arquivo
    return 0;
}

/*
int ler_exportarprioridade(listadetarefas *lt, char nome[30]){
    FILE *f = fopen(nome, "r"); //abre o arquivo e lê ele em formato binário
    if (f == NULL) { //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
        printf("Arquivo nao encontrado.\n"); 
        return 1;
    }
    fread(lt, sizeof(listadetarefas), 1, f); //escreve as informações do cliente no arquivo
    fclose(f); //fecha o arquivo
    return 0;

    printf("Tarefas com a prioridade escolhida foram exportadas com sucesso!");
}
*/

//int ler_exportarcategoria(listadetarefas *lt, char nome[30]){
  //  FILE *f = fopen(nome, "rb"); //abre o arquivo e lê ele em formato binário
  //  if (f == NULL) { //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
  //      printf("Arquivo nao encontrado.\n"); 
  //      return 1;
  //  }
   // fread(lt, sizeof(listadetarefas), 1, f); //escreve as informações do cliente no arquivo
   // fclose(f); //fecha o arquivo
   // return 0;

   // printf("Tarefas com a categoria escolhida foram exportadas com sucesso!");
//}

