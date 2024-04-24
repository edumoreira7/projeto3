#include "contatos.h"
#include <stdio.h>
#include <string.h>

Erro adicionarC(Contato contatos[], int *pos){
  if (*pos >= TOTAL)
    return MAX_CONTATOS;

  printf("Digite o telefone: ");
  scanf("%lld", &contatos[*pos].telefone);
  clearBuffer();
  
  printf("Digite o nome: ");
  fgets(contatos[*pos].nome, 400, stdin);
  contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';
  
  printf("Digite o sobrenome: ");
  fgets(contatos[*pos].sobrenome, 400, stdin);
  contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';

  printf("Digite o email: ");
  fgets(contatos[*pos].email, 400, stdin);
  contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

  *pos = *pos +1;

  return OK;
}

Erro deletarC(Contato contatos[], int *pos){
  if(*pos == 0)
    return SEM_CONTATOS;

  int pos_d;
  
  long long int numero_d;
  printf("Entre com o número do contato: ");
  scanf("%lld", &numero_d);

  int cont = 0;
  
  for(int i = 0; i<*pos; i++){
    if (numero_d == contatos[i].telefone){
      pos_d = i;
      cont++;
      break;
    }
  }
  
  if(pos_d >= *pos){
    return NAO_EXISTE;
  }else if(cont == 0){
    return NAO_EXISTE;
  }
  
  for(int i = pos_d; i<*pos; i++){
    contatos[i].telefone = contatos[i + 1].telefone;
    strcpy(contatos[i].nome, contatos[i + 1].nome);
    strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
    strcpy(contatos[i].email, contatos[i + 1].email);
  }
  
  *pos = *pos - 1;
  
  return OK;
}

Erro listarC(Contato contatos[], int pos){
  if(pos == 0)
    return SEM_CONTATOS;

  for(int i=0; i<pos; i++){
    printf("Nome: %s ", contatos[i].nome);
    printf("%s\n", contatos[i].sobrenome);
    printf("Email: %s\n", contatos[i].email);
    printf("Telefone: %lld\n", contatos[i].telefone);
    printf("------------------------\n");
  }

  return OK;
}

Erro salvarC(Contato contatos[], int total, int pos){
  FILE *f = fopen("contatos", "wb");
  if(f == NULL)
    return ABRIR;

  int e = fwrite(contatos, total, sizeof(Contato), f);
    if(e<=0)
      return ESCREVER;

  e = fwrite(&pos, 1, sizeof(int), f);
  if(e<=0)
    return ESCREVER;

  e = fclose(f);
  if(e!=0)
    return FECHAR;

  return OK;
}

Erro carregarC(Contato contatos[], int total, int *pos){
  FILE *f = fopen("contatos", "rb");
  if(f == NULL)
    return ABRIR;

  int e = fread(contatos, total, sizeof(Contato), f);
  if(e<=0)
    return LER;

  e = fread(pos, 1, sizeof(int), f);
  if(e<=0)
    return LER;

  e = fclose(f);
  if(e!=0)
    return FECHAR;

  return OK;
}

void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}