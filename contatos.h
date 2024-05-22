#define TOTAL 255

typedef struct Contato {
  char nome[100];
  char sobrenome[100];
  char email[200];
  long long int telefone;
} Contato;

typedef struct ContatoT {
  char nome[100];
  char sobrenome[100];
  char email[200];
  long long int telefone;
} ContatoT;

typedef enum Erros {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_EXISTE, ABRIR, FECHAR, ESCREVER, LER, JA_EXISTE, INVALIDO} Erro;

Erro adicionarC(Contato contatos[], int *pos, ContatoT contatosT[], int *posT);
Erro deletarC(Contato contatos[], int *pos, ContatoT contatosT[], int *posT);
Erro listarC(Contato contatos[], int pos, ContatoT contatosT[], int posT);
Erro editarC(Contato contatos[], int *pos, ContatoT contatosT[], int *posT);
Erro salvarC(Contato contatos[], int total, int pos, ContatoT contatosT[], int posT);
Erro carregarC(Contato contatos[], int total, int *pos, ContatoT contatosT[], int *posT);
void clearBuffer();