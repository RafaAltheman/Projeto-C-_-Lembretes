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
        } else if(campo == 2){  // Se o usuário escolher a opção 2, ele modificará a categoria
            printf("Nova Categoria:\n");
            scanf("%[^\n]", lt->tarefas[posicao - 1].categoria); //// O scanf substitui a antiga categoria pela nova escolhida pelo usuário
            clearbuffer();
            printf("Tarefa editada!\n");
        } else if(campo == 3){  // Se o usuário escolher a opção 3, ele modificará a descrição
            printf("Nova Descrição:\n");
            scanf("%[^\n]", lt->tarefas[posicao - 1].descricao); // O scanf substitui a antiga descrição pela nova escolhida pelo usuário
            clearbuffer();
            printf("Tarefa editada!\n");
        } else if(campo == 4){  // Se o usuário escolher a opção 4, ele modificará o estado
            printf("Novo Estado:\n");
            scanf("%[^\n]", lt->tarefas[posicao - 1].estado); // O scanf substitui o antigo estado pela nova escolhida pelo usuário
            clearbuffer();
            printf("Tarefa editada!\n");
        } else{  // Se o usuário errar o número, aparece essa mensagem
            printf("Campo não existente!\n");
        }

        salvarlista(lt, "arquivo.txt"); // as modificações são salvas novamente na lista, com seu formato novo, utilizando a função de salvar
    } else{
        printf("Essa tarefa não existe!\n");
    }
}

int filtrarprioridade(listadetarefas *lt){ // Função para filtrar a prioridade que o usuário selecionou 
    int prioridadeescolhida;
    printf("Digite o número da prioridade que voce deseja filtrar:\n"); 
    scanf("%d", &prioridadeescolhida); // guarda nessa variável a prioridade escolhida pelo usuário

    if (prioridadeescolhida >=0 && prioridadeescolhida<=10){ // só é realizada a saída se o usuário escolher um número válido de 0 a 10
        printf("Tarefas com a prioridade %ls selecionada:\n", &prioridadeescolhida); 

        for (int i = 0; i < lt->qtd; i++) {
            if(lt->tarefas[i].prioridade == prioridadeescolhida){ // se a prioridade que esta salva na lista de tarefas for igual a que o usuário escolheu, elas aparecem no terminal.
            printf("Prioridade: %d\n", lt->tarefas[i].prioridade); //Imprime a prioridade, procurando a  informação a partir da posição da tarefa na lista.
            printf("Categoria: %s\n", lt->tarefas[i].categoria); //Imprime a categoria, procurando a  informação a partir da posição da tarefa na lista.
            printf("Descricao: %s\n", lt->tarefas[i].descricao); //Imprime a descrição, procurando a  informação a partir da posição da tarefa na lista.
            printf("Estado da Tarefa: %s\n", lt->tarefas[i].estado); //Imprime o estado da tarefa, procurando a informação a partir da posição da tarefa na lista.
            printf("\n"); //Imprime um espaço para organizar a listagem
            }
    }
}
    else { // se o usuário digitar uma prioridade inválida, essa mensagem aparece na tela.
        printf("Prioridade inválida!\n");
    }
}

int filtrarestado(listadetarefas *lt){ // Função de filtrar estado
    // declaração de variáveis 
    char estadoescolhido[30]; 
    int encontrado = 0;

    printf("Digite o estado que voce quer filtrar(nao iniciado, em andamento ou completo):\n");
    scanf(" %[^\n]", estadoescolhido); // guarda nessa variável o estado escolhido pelo user.

    for(int i = 0; i < lt->qtd; i++){
        if(strcmp(estadoescolhido, lt->tarefas[i].estado) == 0){ // compara o estado que a pessoa escolheu com o que esta na lista guardado.
            printf("Tarefas com o estado selecionado:\n");
            printf("Prioridade: %d\n", lt->tarefas[i].prioridade); //Imprime a prioridade, procurando a  informação a partir da posição da tarefa na lista.
            printf("Categoria: %s\n", lt->tarefas[i].categoria); //Imprime a categoria, procurando a  informação a partir da posição da tarefa na lista.
            printf("Descricao: %s\n", lt->tarefas[i].descricao); //Imprime a descrição, procurando a  informação a partir da posição da tarefa na lista.
            printf("Estado da Tarefa: %s\n", lt->tarefas[i].estado); //Imprime o estado da tarefa, procurando a informação a partir da posição da tarefa na lista.
            printf("\n"); //Imprime um espaço para organizar a listagem
            encontrado = 1; // se o estado for encontrado, ele recebe o valor 1
        }
    }    
    if (!encontrado){ // se o encontrado for diferente de 1, aparece essa mensagem na tela
        printf("Digite um estado válido\n");
    }
}

int filtrarcategoria(listadetarefas *lt){ // Função de filtrar por categoria
    // declaração de variáveis
    char categoriaescolhida[100];
    int encontrado = 0;
    tarefa tarefasprioritarias[100]; // lista utilizada para guardar as tarefas em ordem decrescente

    printf("Digite a categoria que você deseja filtrar:\n");
    scanf(" %[^\n]", categoriaescolhida); //guarda a categoria escolhida pelo usuario 

    int tarefasprioridade = 0;

    for (int i = 0; i < lt->qtd; i++) { // Itera sobre a lista de tarefas para encontrar aquelas que têm a categoria escolhida
        if (strcmp(categoriaescolhida, lt->tarefas[i].categoria) == 0) {
            // se foi encontrada, é armazenado a tarefa em um array secundário e aumenta um no contador
            tarefasprioritarias[tarefasprioridade] = lt->tarefas[i];
            tarefasprioridade++;
            encontrado = 1;
        }
    }

    if (!encontrado){ // mensagem que aparece na tela, caso não exista uma categoria válida
        printf("Digite uma categoria válida\n");
    } else { 
        for(int i = 0; i < tarefasprioridade; i++){ // ordena as tarefas encontradas por prioridade em ordem do maior para o menor
            for(int y = i+1; y < tarefasprioridade; y++){ // verifica se a prioridade da tarefa atual é menor do que a próxima tarefa
                if(tarefasprioritarias[i].prioridade < tarefasprioritarias[y].prioridade){ // se for, troca as posições das tarefas no array para ordenar por prioridade
                    tarefa ordem = tarefasprioritarias[i]; 
                    tarefasprioritarias[i] = tarefasprioritarias[y];
                    tarefasprioritarias[y] = ordem;
                }
            }
        }
    }  
        printf("Tarefas com categoria escolhida e ordenadas por prioridade:\n");
        for (int i = 0; i < tarefasprioridade; i++) { // exibe as tarefas encontradas, ordenadas por prioridade
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefasprioritarias[i].prioridade);
            printf("Categoria: %s\n", tarefasprioritarias[i].categoria);
            printf("Descricao: %s\n", tarefasprioritarias[i].descricao);
            printf("Estado da Tarefa: %s\n", tarefasprioritarias[i].estado);
            printf("\n");
    }
    }

int filtrarprioridadeecategoria(listadetarefas *lt){ // Função de filtrar por prioridade e categoria
    // declaração de variáveis
    int prioridadeescolhida;
    char categoriaescolhida[100];
    int encontrado = 0;

    printf("Digite o número da prioridade que voce deseja filtrar:\n");
    scanf("%d", &prioridadeescolhida); // armazena a prioridade escolhida

    printf("Digite a categoria que você deseja filtrar:\n");
    scanf(" %[^\n]", categoriaescolhida); // armazena a categoria escolhida

    if(prioridadeescolhida >=0 && prioridadeescolhida<=10){ // confere se a prioridade está entre 0 e 10
        for(int i = 0; i < lt->qtd; i++){
            if (lt->tarefas[i].prioridade == prioridadeescolhida && strcmp(categoriaescolhida, lt->tarefas[i].categoria) == 0){ // confere se a prioridade e a categoria digitada estao de acordo com o que esta armazenado na lista
                printf("Tarefas com a categoria e prioridade selecionada:\n"); // Print das tarefas no terminal
                printf("Prioridade: %d\n", lt->tarefas[i].prioridade); 
                printf("Categoria: %s\n", lt->tarefas[i].categoria);
                printf("Descricao: %s\n", lt->tarefas[i].descricao);
                printf("Estado da Tarefa: %s\n", lt->tarefas[i].estado);
                printf("\n");
                encontrado = 1; // adiciona o valor 1 no encontrado
            }
        }
    } else if (!encontrado){ // se encontrado for diferente de 1, esta mensagem aparece na tela
        printf("Nenhuma tarefa encontrada com essa categoria.\n");
    }
    }

int exportarprioridade(listadetarefas lt, char nome[30]){ // Função de exportar por prioridade
    int prioridadeescolhida;
    printf("Digite o número da prioridade que voce deseja exportar:\n");
    scanf("%d", &prioridadeescolhida); // armazena a prioridade digitada
    if (prioridadeescolhida >=0 && prioridadeescolhida<=10){ // confere se a prioridade esta entre 0 e 10
    FILE *f = fopen("tarefasporprioridade.txt", "w"); // abre o arquivo 
   
    if (f == NULL){  //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
   }
   for (int i = 0; i < lt.qtd; i++){
        if(lt.tarefas[i].prioridade == prioridadeescolhida){ // confere se a prioridade digitada pelo usuário é igual a prioridade armazenada
            fprintf(f, "Prioridade: %d, Categoria: %s, Estado: %s, Descrição: %s\n", lt.tarefas[i].prioridade, lt.tarefas[i].categoria, lt.tarefas[i].estado, lt.tarefas[i].descricao); // com o uso do fprintf, todas as informações aparecem no arquivo
        }
   }
    fclose(f); // fecha o arquivo
    printf("Tarefas com a prioridade selecionada foram exportadas\n");
   } else { // se caso for uma prioridade inválida essa mensagem aparece na tela 
        printf("Prioridade não existente\n");
   }
    
}
    
int exportarcategoria(listadetarefas *lt, char nome[30]){
    // declaração de variáveis
    char categoriaselecionada[100];
    int encontrado = 0;
    tarefa tarefasprioritarias[100];

    printf("Digite a categoria que você deseja exportar:\n");
    scanf(" %99[^\n]", categoriaselecionada);

    int tarefasprioridade = 0;

    for (int i = 0; i < lt->qtd; i++) {  // Itera para encontrar as tarefas com a categoria escolhida
        if (strcmp(categoriaselecionada, lt->tarefas[i].categoria) == 0) {
            tarefasprioritarias[tarefasprioridade] = lt->tarefas[i]; // Armazena as tarefas encontradas no array tarefasprioritarias
            tarefasprioridade++;
            encontrado = 1;
        }
    }
    if (!encontrado){ // verifica se alguma tarefa foi encontrada com a categoria escolhi
        printf("Digite uma categoria válida\n");
    } else {
        for(int i = 0; i < tarefasprioridade; i++){ // ordena as tarefas encontradas por prioridade em ordem do maior para o menor
            for(int y = i+1; y < tarefasprioridade; y++){ // verifica se a prioridade da tarefa atual é menor do que a próxima tarefa
                if(tarefasprioritarias[i].prioridade < tarefasprioritarias[y].prioridade){ // se for, troca as posições das tarefas no array para ordenar por prioridade
                    tarefa ordem = tarefasprioritarias[i]; 
                    tarefasprioritarias[i] = tarefasprioritarias[y];
                    tarefasprioritarias[y] = ordem;
                }
            }
        }
    }  

    FILE *f = fopen("tarefasporcategorias.txt", "w"); // abre o arquivo

    if (f == NULL){   // erro ao abrir o arquivo
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
    } 

    for (int i = 0; i < tarefasprioridade; i++){ // itera sobre a o novo array de tarefas prioridade e escreve as informações no arquivo
        fprintf(f, "Prioridade: %d, Categoria: %s, Estado: %s, Descrição: %s\n", tarefasprioritarias[i].prioridade, tarefasprioritarias[i].categoria, tarefasprioritarias[i].estado, tarefasprioritarias[i].descricao);
    }

    fclose(f); // arquivo fechado
    printf("Tarefas com a categoria selecionada foram exportadas\n");
    return 0;
}


int exportarprioridadeecategoria(listadetarefas *lt, char nome[30]){ // Função para exportar por prioridade e categoria
    // declaração de variáveis
    int prioridadeescolhida;
    char categoriaescolhida[100];

    printf("Digite o número da prioridade que voce deseja filtrar:\n");
    scanf("%d", &prioridadeescolhida); // armazena a prioridade escolhida pelo usuário

    printf("Digite a categoria que você deseja filtrar:\n");
    scanf(" %[^\n]", categoriaescolhida); // armazena a categoria escolhida pelo usuário

    FILE *f = fopen("tarefasporprioridadeecategoria.txt", "w"); // abre um arquivo 
    if (f == NULL){  // erro ao abrir o arquivo
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
    } 

    for (int i = 0; i < lt->qtd; i++){ 
        if(lt->tarefas[i].prioridade == prioridadeescolhida && strcmp(categoriaescolhida, lt->tarefas[i].categoria) == 0){ // confere se a prioridade escoolhida e a categoria escolhida são iguais as que estão no array.
            fprintf(f, "Prioridade: %d, Categoria: %s, Estado: %s, Descrição: %s\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].estado, lt->tarefas[i].descricao); // escreve as informções da tarefa no arquivo
        }
    }

    fclose(f); // fecha o arquivo
    printf("Tarefas com a categoria e a prioridade selecionada foram exportadas\n");
    return 0;
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

