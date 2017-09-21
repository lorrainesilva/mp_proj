/*!
 \file testa_string_soma_stdin.cpp
 \brief Arquivo que contém a função main

 \author Ingrid Silva (ingridsilva@gmail.com)
*/

#include "string_soma.hpp"

#include <iostream>
#include <cstring>
#include <cstdio>

int main() {
  char string_entrada[100];
  int valor_retorno = 0;

  fscanf(stdin, "%[^EOF]", string_entrada);

  valor_retorno = soma_string(string_entrada);
  std::cout << std::to_string(valor_retorno) << std::endl;
}