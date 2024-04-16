#include <stdio.h>
#include "contatos.h"

int main(){
  int pos = 0;
  Contato contatos[TOTAL];

  int opcao;

  do{
    printf("\nMenu principal\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Deletar contato\n");
    printf("3 - Listar contatos\n");
    printf("4 - Salvar contatos\n");
    printf("5 - Carregar contatos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    printf("%d\n", opcao);
    if(opcao > 5){
      printf("Opcao invalida\n");
    }else if (opcao == 1){
      adicionarC(contatos, &pos);
    }else if (opcao == 2){
      deletarC(contatos, &pos);
    }else if (opcao == 3){
      listarC(contatos, pos);
    }else if (opcao == 4){
      salvarC(contatos, TOTAL, pos);
    }else if (opcao == 5){
      carregarC(contatos, TOTAL, pos);
    }else if (opcao == 0){
      printf("Saindo...");
      break;
    }

  } while(opcao >= 0);
}