/*!
 \file string_soma.cpp
 \brief Arquivo que contem as implementações das funções de string_soma.hpp 

 \author Ingrid Silva (ingridsilva@gmail.com)
*/

#include "string_soma.hpp"
#include <iostream>
#include <string>

/*!
 \fn soma_string(char* string_entrada) 
 \brief Função que calcula a soma dos números de uma string
 \param string_entrada String contendo os números para a soma
*/
int soma_string(char* string_entrada) {
  std::string entrada = string_entrada;
  std::string auxiliar;
  int numero = 0;
  int soma = 0;
  int conta_numeros = 0;
  int conta_delimitadores = 0;
  int numeros_por_linha = 0;

  while (!entrada.empty()) {
    if (entrada.find_first_of("0123456789") == 0) {
      numero = stoi(entrada);
      auxiliar = std::to_string(numero);
      entrada.erase(0, auxiliar.size());
      conta_numeros++;
      numeros_por_linha++;
      if (numeros_por_linha > 3) {
        return -1;
      }
      if (numero > 1000) {
        numero = 0;
      }
    } else if (entrada[0] == ',') {
      entrada.erase(0, 1);
      conta_delimitadores++;
      soma += numero;
      numero = 0;
    } else if (entrada[0] == '\n') {
      entrada.erase(0, 1);
      soma += numero;
      numero = 0;
      numeros_por_linha = 0;
    } else {
      return -1;
    }
  }

  if (numeros_por_linha != 0 || (conta_numeros - conta_delimitadores) != 1) {
    return -1;
  } else {
    return soma;
  }
}