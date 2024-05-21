#include <stdio.h>
#include "contatos.h"

int main(){
  int pos = 0;
  Contato contatos[TOTAL];

  Erro e = carregarC(contatos, TOTAL, &pos);
  if(e == ABRIR){
    printf("Erro ao abrir o arquivo.\n");
  }
  else if(e == LER){
    printf("Erro ao ler o arquivo.\n");
  }  
  else if(e == FECHAR){
    printf("Erro ao fechar o arquivo.\n");
  }
 
  int opcao;

  do{
    printf("\nMenu principal\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Deletar contato\n");
    printf("3 - Listar contatos\n");
    printf("4 - Editar contato\n");
    printf("5 - Salvar contatos\n");
    printf("6 - Carregar contatos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
  
    scanf("%d", &opcao);
    printf("\n");
    if(opcao > 6){
      printf("Opção invalida\n");
    }else if (opcao == 1){
      e = adicionarC(contatos, &pos);
      if(e == MAX_CONTATOS)
        printf("Não é possivel adicionar mais contatos.\n");
      else if(e == JA_EXISTE)
        printf("Já existe um contato com esse número.\n");
      else if(e == INVALIDO)
        printf("Email inválido.\n");
    }else if (opcao == 2){
      e = deletarC(contatos, &pos);
      if(e == SEM_CONTATOS)
        printf("Não há contatos para deletar.\n");
      else if(e == NAO_EXISTE)
        printf("Contato não encontrado.\n");
    }else if (opcao == 3){
      e = listarC(contatos, pos);
      if(e == SEM_CONTATOS)
        printf("Não há contatos para listar.\n");
    }else if (opcao == 4){
      e = editarC(contatos, &pos);
      if(e == SEM_CONTATOS)
        printf("Não há contatos para editar.\n");
    }else if (opcao == 5){
      e = salvarC(contatos, TOTAL, pos);
      if(e == ABRIR)
        printf("Erro ao abrir o arquivo.\n");
      if(e == ESCREVER)
        printf("Erro ao escrever no arquivo.\n");
      if(e == FECHAR)
        printf("Erro ao fechar o arquivo.\n");
    }else if (opcao == 6){
      e = carregarC(contatos, TOTAL, &pos);
      if(e == ABRIR)
        printf("Erro ao abrir o arquivo.\n");
      else if(e == LER)
        printf("Erro ao ler o arquivo.\n");
      else if(e == FECHAR)
        printf("Erro ao fechar o arquivo.\n");
    }else if (opcao == 0){
      printf("Saindo...");
      e = salvarC(contatos, TOTAL, pos);
      if(e == ABRIR)
        printf("Erro ao abrir o arquivo.\n");
      if(e == ESCREVER)
        printf("Erro ao escrever no arquivo.\n");
      if(e == FECHAR)
        printf("Erro ao fechar o arquivo.\n");
      break;
    }

  } while(opcao >= 0);
}