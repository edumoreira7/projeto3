#include "contatos.h"
#include <stdio.h>
#include <string.h>

int adicionarC(Contato contatos[], int *pos){
  if (*pos >= TOTAL)
    return 1;
  if (*pos == 0)
    return 1;

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

  printf("%d", *pos);
  return 0;
}

int deletarC(Contato contatos[], int *pos){
  if(*pos == 0)
    return 1;

  int pos_d;
  
  long long int numero_d;
  printf("Entre com o número do contato: ");
  scanf("%lld", &numero_d);

  int cont;
  
  for(int i = 0; i<*pos; i++){
    if (numero_d == contatos[i].telefone){
      pos_d = i;
    }else{
      cont = 0;
    }
  }
  if(pos_d >= *pos)
    return 2;
  
  for(int i = pos_d; i<*pos; i++){
    contatos[i].telefone = contatos[i + 1].telefone;
    strcpy(contatos[i].nome, contatos[i + 1].nome);
    strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
    strcpy(contatos[i].email, contatos[i + 1].email);
  }
  
  *pos = *pos - 1;

  if(pos_d >= *pos)
    return 2;
  
  return 0;
}

int listarC(Contato contatos[], int pos){
  if(pos == 0)
    return 1;

  for(int i=0; i<pos; i++){
    printf("Nome: %s ", contatos[i].nome);
    printf("%s\n", contatos[i].sobrenome);
    printf("Email: %s\n", contatos[i].email);
    printf("Telefone: %lld\n", contatos[i].telefone);
    printf("------------------------\n");
  }

  return 0;
}
int salvarC(Contato contatos[], int total, int pos){
  printf("funcao de salvar contato\n");
  return 0;
}
int carregarC(Contato contatos[], int total, int pos){
  printf("funcao de carregar contato\n");
  return 0;
}
void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}