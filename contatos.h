#define TOTAL 255

typedef struct Contato {
  char nome[400];
  char sobrenome[400];
  char email[400];
  long long int telefone;
} Contato;

int adicionarC(Contato contatos[], int *pos);
int deletarC(Contato contatos[], int *pos);
int listarC(Contato contatos[], int pos);
int salvarC(Contato contatos[], int total, int pos);
int carregarC(Contato contatos[], int total, int *pos);
void clearBuffer();