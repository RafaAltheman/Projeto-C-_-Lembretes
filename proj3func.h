//Criação do struct dos elementos da tarefa, incluindo prioridade, categoria e descrição (com a quantidade máxima de caracteres em cada um)
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
    char estado[30];
} tarefa;
// Criação do struct que une os elementos da tarefa, criando uma lista de tarefas
typedef struct {
    tarefa tarefas[100];
    int qtd;
} listadetarefas;

//Chamando as funções já explicadas em "biblioteca.c"
int criartarefa(listadetarefas *lt);
int deletartarefa(listadetarefas *lt);
int listartarefa(listadetarefas lt);
int editartarefa(listadetarefas *lt);

int salvarlista(listadetarefas *lt, char nome[]);
int carregarlista(listadetarefas *lt, char nome[]);