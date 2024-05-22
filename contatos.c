#include "contatos.h"
#include <stdio.h>
#include <string.h>

Erro adicionarC(Contato contatos[], int *pos, ContatoT contatosT[], int *posT){
  if (*pos >= TOTAL && *posT >= TOTAL)
    return MAX_CONTATOS;

  int opcao;

  printf("Qual o tipo de contato?\n");
  printf("1 - Contato pessoal\n");
  printf("2 - Contato de trabalho\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);

  
  if(opcao == 1){
    long long int telefone;
    
    printf("Digite o telefone: ");
    scanf("%lld", &contatos[*pos].telefone );
    clearBuffer();

    for(int i = 0; i<*pos; i++){
      if (contatos[*pos].telefone == contatos[i].telefone){
        return JA_EXISTE;
      }
    }
    printf("Digite o nome: ");
    fgets(contatos[*pos].nome, 100, stdin);
    contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';


    printf("Digite o sobrenome: ");
    fgets(contatos[*pos].sobrenome, 100, stdin);
    contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(contatos[*pos].email, 200, stdin);
    contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

    if (strchr(contatos[*pos].email, '@') != NULL) {
      printf("Contato Adicionado!");
    } else {
      return INVALIDO;
    }
    *pos = *pos +1;
    
  }else if (opcao == 2){
    long long int telefone;

    printf("Digite o telefone: ");
    scanf("%lld", &contatosT[*posT].telefone);
    clearBuffer();

    for(int i = 0; i<*posT; i++){
      if (contatosT[*posT].telefone == contatosT[i].telefone){
        return JA_EXISTE;
      }
    }
    printf("Digite o nome: ");
    fgets(contatosT[*posT].nome, 100, stdin);
    contatosT[*posT].nome[strcspn(contatosT[*posT].nome, "\n")] = '\0';


    printf("Digite o sobrenome: ");
    fgets(contatosT[*posT].sobrenome, 100, stdin);
    contatosT[*posT].sobrenome[strcspn(contatosT[*posT].sobrenome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(contatosT[*posT].email, 200, stdin);
    contatosT[*posT].email[strcspn(contatosT[*posT].email, "\n")] = '\0';

    if (strchr(contatosT[*posT].email, '@') != NULL) {
      printf("Contato Adicionado!");
    } else {
      return INVALIDO;
    }
    *posT = *posT +1;
  }

  return OK;
}

Erro deletarC(Contato contatos[], int *pos, ContatoT contatosT[], int *posT){
  if(*pos == 0)
    return SEM_CONTATOS;

  int pos_d;
  
  long long int numero_d;
  printf("Entre com o número do contato: ");
  scanf("%lld", &numero_d);

  int cont = 0;
  int cont_t = 0;
  
  for(int i = 0; i<*pos; i++){
    if (numero_d == contatos[i].telefone){
      pos_d = i;
      cont++;
      break;
    }
  }
  for(int i = 0; i<*pos; i++){
    if (numero_d == contatosT[i].telefone){
      pos_d = i;
      cont_t++;
      break;
    }
  }
  
  if(pos_d >= *pos && pos_d >= *posT){
    return NAO_EXISTE;
  }else if(cont == 0 && cont_t == 0){
    return NAO_EXISTE;
  }

  if(cont >0){
    for(int i = pos_d; i<*pos; i++){
      contatos[i].telefone = contatos[i + 1].telefone;
      strcpy(contatos[i].nome, contatos[i + 1].nome);
      strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
      strcpy(contatos[i].email, contatos[i + 1].email);
    }

    *pos = *pos - 1;
  }
  if(cont_t >0){
    for(int i = pos_d; i<*pos; i++){
      contatosT[i].telefone = contatosT[i + 1].telefone;
      strcpy(contatosT[i].nome, contatosT[i + 1].nome);
      strcpy(contatosT[i].sobrenome, contatosT[i + 1].sobrenome);
      strcpy(contatosT[i].email, contatosT[i + 1].email);
    }

    *posT = *posT - 1;
  }
  
  return OK;
}

Erro listarC(Contato contatos[], int pos, ContatoT contatosT[], int posT){
  if(pos == 0)
    return SEM_CONTATOS;

  printf("Contatos pessoais:\n");
  for(int i=0; i<pos; i++){
    printf("Nome: %s ", contatos[i].nome);
    printf("%s\n", contatos[i].sobrenome);
    printf("Email: %s\n", contatos[i].email);
    printf("Telefone: %lld\n", contatos[i].telefone);
    printf("------------------------\n");
  }
  
  printf("\nContatos de trabalho:\n");
  for(int i=0; i<posT; i++){
    printf("Nome: %s ", contatosT[i].nome);
    printf("%s\n", contatosT[i].sobrenome);
    printf("Email: %s\n", contatosT[i].email);
    printf("Telefone: %lld\n", contatosT[i].telefone);
    printf("------------------------\n");
  }
  return OK;
}

Erro editarC(Contato contatos[], int *pos, ContatoT contatosT[], int *posT){
  if(*pos == 0)
    return SEM_CONTATOS;

  int pos_e;

  long long int numero_e;
  printf("Entre com o número do contato: ");
  scanf("%lld", &numero_e);

  int cont = 0;
  int cont_t = 0;

  for(int i = 0; i<*pos; i++){
    if (numero_e == contatos[i].telefone){
      pos_e = i;
      cont++;
      break;
    }
  }
  for(int i = 0; i<*pos; i++){
    if (numero_e == contatosT[i].telefone){
      pos_e = i;
      cont_t++;
      break;
    }
  }

  if(pos_e >= *pos){
    return NAO_EXISTE;
  }else if(cont == 0 && cont_t == 0){
    return NAO_EXISTE;
  }

  if(cont > 0){
    printf("Dados atuais:\n");
    printf("Nome: %s ", contatos[pos_e].nome);
    printf("%s\n", contatos[pos_e].sobrenome);
    printf("Email: %s\n", contatos[pos_e].email);
    printf("Telefone: %lld\n", contatos[pos_e].telefone);

    int opcao;
    long long int telefone;

    printf("\nO que deseja editar?\n");
    printf("1 - Nome\n");
    printf("2 - Email\n");
    printf("3 - Telefone\n");
    printf("4 - Voltar\n");
    scanf("%d", &opcao);
    clearBuffer();

    if(opcao == 1){
      printf("Digite o novo nome: ");
      fgets(contatos[pos_e].nome, 100, stdin);
      contatos[pos_e].nome[strcspn(contatos[pos_e].nome, "\n")] = '\0';
      printf("Digite o sobrenome: ");
      fgets(contatos[pos_e].sobrenome, 100, stdin);
      contatos[pos_e].sobrenome[strcspn(contatos[pos_e].sobrenome, "\n")] = '\0';
    }else if(opcao == 2){
      printf("Digite o novo email: ");
      fgets(contatos[pos_e].email, 200, stdin);
      contatos[pos_e].email[strcspn(contatos[pos_e].email, "\n")] = '\0';

      if (strchr(contatos[pos_e].email, '@') != NULL) {
        printf("Contato Adicionado!");
      } else {
        return INVALIDO;
      }
    }else if(opcao == 3){
      printf("Digite o novo telefone: ");
      scanf("%lld", &telefone);

      for(int i = 0; i<*pos; i++){
        if (telefone == contatos[i].telefone){
          return JA_EXISTE;
        }else
          contatos[pos_e].telefone = telefone;
      }
    }
  }
  if(cont_t > 0){
    printf("Dados atuais:\n");
    printf("Nome: %s ", contatosT[pos_e].nome);
    printf("%s\n", contatosT[pos_e].sobrenome);
    printf("Email: %s\n", contatosT[pos_e].email);
    printf("Telefone: %lld\n", contatosT[pos_e].telefone);

    int opcao;
    long long int telefone;

    printf("\nO que deseja editar?\n");
    printf("1 - Nome\n");
    printf("2 - Email\n");
    printf("3 - Telefone\n");
    printf("4 - Voltar\n");
    scanf("%d", &opcao);
    clearBuffer();

    if(opcao == 1){
      printf("Digite o novo nome: ");
      fgets(contatosT[pos_e].nome, 100, stdin);
      contatosT[pos_e].nome[strcspn(contatosT[pos_e].nome, "\n")] = '\0';
      printf("Digite o sobrenome: ");
      fgets(contatosT[pos_e].sobrenome, 100, stdin);
      contatosT[pos_e].sobrenome[strcspn(contatosT[pos_e].sobrenome, "\n")] = '\0';
    }else if(opcao == 2){
      printf("Digite o novo email: ");
      fgets(contatosT[pos_e].email, 200, stdin);
      contatosT[pos_e].email[strcspn(contatosT[pos_e].email, "\n")] = '\0';

      if (strchr(contatosT[pos_e].email, '@') != NULL) {
        printf("Contato Adicionado!");
      } else {
        return INVALIDO;
      }
    }else if(opcao == 3){
      printf("Digite o novo telefone: ");
      scanf("%lld", &telefone);

      for(int i = 0; i<*posT; i++){
        if (telefone == contatosT[i].telefone){
          return JA_EXISTE;
        }else
          contatosT[pos_e].telefone = telefone;
      }
    }
  }
  

  return OK;
}

Erro salvarC(Contato contatos[], int total, int pos, ContatoT contatosT[], int posT){
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

  FILE *ft = fopen("contatosT", "wb");
  if(f == NULL)
    return ABRIR;

  int d = fwrite(contatosT, total, sizeof(ContatoT), ft);
    if(d<=0)
      return ESCREVER;

  d = fwrite(&posT, 1, sizeof(int), ft);
  if(d<=0)
    return ESCREVER;

  d = fclose(ft);
  if(d!=0)
    return FECHAR;
  return OK;
}

Erro carregarC(Contato contatos[], int total, int *pos, ContatoT contatosT[], int *posT){
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

  FILE *ft = fopen("contatosT", "rb");
  if(ft == NULL)
    return ABRIR;

  int et = fread(contatosT, total, sizeof(ContatoT), ft);
  if(et<=0)
    return LER;

  et = fread(posT, 1, sizeof(int), ft);
  if(et<=0)
    return LER;

  et = fclose(ft);
  if(et!=0)
    return FECHAR;

  return OK;
}

void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}