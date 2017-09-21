/*!
 \file string_soma.cpp
 \brief Arquivo que contem as implementações das funções de string_soma.hpp 

 \author Ingrid Silva (ingridsilva@gmail.com)
*/

#include "string_soma.hpp"
#include <iostream>
#include <string>
#include <vector>

/*!
 \fn soma_string(char* string_entrada) 
 \brief Função que calcula a soma dos números de uma string.

 A função verifica se na string_entrada houve a definição de delimitadores customizados, se sim 
 a funçao busca_delimitadores é chamada e em sequência a função somatorio, do contrário apenas a 
 função somatorio é chamada.

 \param string_entrada String contendo os números para a soma.
 \return -1 para strings inválidas e o resultado da soma para strings válidas.
*/
int soma_string(char* string_entrada) {
  std::string entrada = string_entrada;
  std::string auxiliar;
  std::vector<std::string> delimitadores = {","};
  std::size_t posicao;
  int valor_retorno = 0;

  if (entrada.find("//[") == 0) {
    posicao = entrada.find("\n");
    auxiliar = entrada.substr(0, posicao + 1);
    entrada.erase(0, auxiliar.size());
    auxiliar.erase(0, 2);
    valor_retorno = busca_delimitadores(&auxiliar, &delimitadores);
    if (valor_retorno == -1) {
      return -1;
    }
  }

  return somatorio(&entrada, &delimitadores);
}

/*!
 \fn busca_delimitadores(std::string* entrada, std::vector<std::string>* vetor) ;
 \brief Realiza a busca por delimitadores em uma string e retorna os delimitadores encontrados.

 Percorre a string entrada buscando os novos delimitadores. Ao encontrar, o mesmo é adicionado ao 
 vector vetor e em seguida o delimitador encontrado é removido da string. O código finaliza ao obter 
 uma string entrada vazia ou se a string entrada for inválida.

 \param entrada String contendo os delimitadores.
 \param vetor Vector de strings onde serão armazenados os delimitadores encontrados.
 \return 0 para strings válidas e -1 para strings inválidas.
*/
int busca_delimitadores(std::string* entrada, std::vector<std::string>* vetor) {
  std::size_t posicao;

  while(entrada->size() > 0){
    if (entrada->find("[") == 0) {
      posicao = entrada->find("]");
      vetor->push_back(entrada->substr(1, posicao - 1));
      entrada->erase(0, posicao + 1);
    } else if (entrada->at(0) == '\n') {
      entrada->erase(0, 1);
    } else {
      return -1;
    }
  }

  return 0;
}

/*!
 \fn somatorio(std::string* entrada, std::vector<std::string>* vetor) ;
 \brief Indentifica e soma os números presentes na string entrada.

 Busca os números e os delimitadores dentro da string entrada. Ao encontrar um número, 
 o mesmo é convertido para inteiro e armazenado e os caracteres do númro são removidos 
 da sting. O número só é somado aos demais após um delimitador ou uma quebra de linha 
 ser encontrada. A cada novo número encontrado, é calculado a diferença entre a quantidade
 de números e a quantidade de delimitadores, que tal diferença sempre deve ser igual a 1.
 Ao encontrar um delimitador ou uma quebra de linha, um processo diferente é executado 
 (acréscimo no contador de delimitadores ou redefinição do valor de números por linha) e logo 
 após o delimitador ou quebra de linha é removido da string. A função termina quando a string 
 entrada se torna vazia ou se a string entrada for invalida.

 \param entrada String contendo os números e delimitadores.
 \param vetor Vector de strings onde estão armazenados os delimitadores.
 \return Resultado da soma dos números para strings válidas e -1 para strings inválidas.
*/
int somatorio(std::string* entrada, std::vector<std::string>* vetor) {
  std::string auxiliar;
  std::size_t posicao;
  int numero = 0;
  int soma = 0;
  int conta_numeros = 0;
  int conta_delimitadores = 0;
  int numeros_por_linha = 0;
  int contador = 0;
  int valor_retorno = 0;

  while (!entrada->empty()) {
    if (entrada->find_first_of("0123456789") == 0) {
      numero = stoi(*entrada);
      auxiliar = std::to_string(numero);
      entrada->erase(0, auxiliar.size());
      conta_numeros++;
      numeros_por_linha++;
      if (numeros_por_linha > 3) {
        return -1;
      }
      if (numero > 1000) {
        numero = 0;
      }
      if ((conta_numeros - conta_delimitadores) != 1) {
        return -1;
      }
    } else if (entrada->at(0) == '\n') {
      entrada->erase(0, 1);
      soma += numero;
      numero = 0;
      numeros_por_linha = 0;
    } else {
      contador = 0;
      posicao = 1;
      while (contador < vetor->size() && posicao != 0) {
        if (entrada->find(vetor->at(contador)) != std::string::npos) {
          if (entrada->find(vetor->at(contador)) == 0) {
            posicao = 0;
            entrada->erase(0, vetor->at(contador).size());
            conta_delimitadores++;
            soma += numero;
            numero = 0;
          }
        }
        contador++;
      } //while
      if (posicao != 0) {
        return -1;  
      }
    } //else
  } //while
  if (numeros_por_linha != 0 || (conta_numeros - conta_delimitadores) != 1) {
    return -1;
  } else {
    return soma;
  }
}