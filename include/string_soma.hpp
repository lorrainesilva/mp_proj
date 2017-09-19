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
 \brief Função que calcula a soma dos números de uma string
 \param string_entrada String contendo os números para a soma
*/
int soma_string(char* string_entrada);
int busca_delimitadores(std::string* entrada, std::vector<std::string>* vetor);
int somatorio(std::string* entrada, std::vector<std::string>* vetor);

#endif /* STRING_SOMA_HPP_ */