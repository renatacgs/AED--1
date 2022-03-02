#include <stdio.h>
#include "lista.h"
#define tam 9
int main(int argc, char const *argv[])
{
  //INICIALIZA A LISTA
  Lista lst = cria_lista();
  char x;
  //IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }

  //IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }

  // IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }

  //ESVAZIE A LISTA
  limpa_lista(&lst);
  // IMPRIME A LISTA
  if (!obtem_tamanho(&lst))
  {
    printf("Lista vazia\n");
  }
  else
  {
    for (size_t i = 0; i < obtem_tamanho(&lst); i++)
    {
      obtem_posicao(lst, i, &x);
      printf("%c ", x);
    }
    printf("\n");
  }
  return 0;
}
