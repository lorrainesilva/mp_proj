/*!
 \file string_soma.hpp
 \brief Arquivo de cabeçalhos das funções de string_soma.cpp 
 
 \author Ingrid Silva (ingridsilva@gmail.com)
*/

#ifndef STRING_SOMA_HPP_
#define STRING_SOMA_HPP_

#include "string_soma.hpp"
#include <string>
#include <vector>

/*!
 \fn soma_string(char* string_entrada) 
 \brief Função que calcula a soma dos números de uma string.
 \param string_entrada String contendo os números para a soma.
 \return -1 para strings inválidas e o resultado da soma para strings válidas.
*/
int soma_string(char* string_entrada);

/*!
 \fn busca_delimitadores(std::string* entrada, std::vector<std::string>* vetor) ;
 \brief Realiza a busca por delimitadores em uma string e retorna os delimitadores encontrados.
 \param entrada String contendo os delimitadores.
 \param vetor Vector de strings onde serão armazenados os delimitadores encontrados.
 \return 0 para strings válidas e -1 para strings inválidas.
*/
int busca_delimitadores(std::string* entrada, std::vector<std::string>* vetor);

/*!
 \fn somatorio(std::string* entrada, std::vector<std::string>* vetor) ;
 \brief Indentifica e soma os números presentes na string entrada.
 \param entrada String contendo os números e delimitadores.
 \param vetor Vector de strings onde estão armazenados os delimitadores.
 \return Resultado da soma dos números para strings válidas e -1 para strings inválidas.
*/
int somatorio(std::string* entrada, std::vector<std::string>* vetor);

#endif /* STRING_SOMA_HPP_ */