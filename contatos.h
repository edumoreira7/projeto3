#define TOTAL 255

typedef struct Contato {
  char nome[400];
  char sobrenome[400];
  char email[400];
  long long int telefone;
} Contato;

typedef enum Erros {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_EXISTE, ABRIR, FECHAR, ESCREVER, LER} Erro;

Erro adicionarC(Contato contatos[], int *pos);
Erro deletarC(Contato contatos[], int *pos);
Erro listarC(Contato contatos[], int pos);
Erro salvarC(Contato contatos[], int total, int pos);
Erro carregarC(Contato contatos[], int total, int *pos);
void clearBuffer();