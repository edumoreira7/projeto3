#define TOTAL 255

typedef struct Contato {
  char nome[400];
  char sobrenome[400];
  char email[400];
  int telefone;
} Contato;

int adicionarC(Contato tarefas[], int *pos);
int deletarC(Contato tarefas[], int *pos);
int listarC(Contato tarefas[], int pos);
int salvarC(Contato tarefas[], int total, int pos);
int carregarC(Contato tarefas[], int total, int pos);