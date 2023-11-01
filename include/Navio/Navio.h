#ifndef NAVIO_H
#define NAVIO_H

#include <string>
#include <vector>
#include <iostream>

class Navio {
protected:
char simbolo;
std::string nome;
int tamanho;
int danos;
char orientacao;
int x,y;
bool afundou;

public:
/**
* @brief Construtor padrão. Cria um novo objeto Navio.
*/
Navio();

/**
 * @brief Obtém o nome do navio.
 * @return O nome do navio.
 */
std::string getNome();

/**
 * @brief Define o nome do navio.
 * @param nome O nome a ser definido.
 */
void setNome(std::string nome);

/**
 * @brief Obtém o tamanho do navio.
 * @return O tamanho do navio.
 */
int getTamanho();

/**
 * @brief Define o tamanho do navio.
 * @param tamanho O tamanho a ser definido.
 */
void setTamanho(int tamanho);

/**
 * @brief Obtém o símbolo do navio.
 * @return O símbolo do navio.
 */
char getSimbolo();

/**
 * @brief Define o símbolo do navio.
 * @param simbolo O símbolo a ser definido.
 */
void setSimbolo(char simbolo);

/**
 * @brief Obtém a orientação do navio.
 * @return A orientação do navio.
 */
char getOrientacao();

/**
 * @brief Define a orientação do navio.
 * @param orientacao A orientação a ser definida.
 */
void setOrientacao(char orientacao);

/**
 * @brief Obtém a coordenada horizontal do navio.
 * @return A coordenada horizontal do navio.
 */
int getX();

/**
 * @brief Define a coordenada horizontal do navio.
 * @param x A coordenada horizontal a ser definida.
 */
void setX(int x);

/**
 * @brief Obtém a coordenada vertical do navio.
 * @return A coordenada vertical do navio.
 */
int getY();

/**
 * @brief Define a coordenada vertical do navio.
 * @param y A coordenada vertical a ser definida.
 */
void setY(int y);

/**
 * @brief Obtém o número de danos do navio.
 * @return O número de danos do navio.
 */
int getDanos();

/**
 * @brief Define o número de danos do navio.
 * @param danos O número de danos a ser definido.
 */
void setDanos(int danos);

/**
 * @brief Registra um dano no navio.
 */
void dano();

/**
 * @brief Verifica se o navio afundou.
 * @return true se o navio afundou, false caso contrário.
 */
bool getAfundou();

/**
 * @brief Define se o navio afundou.
 * @param afundou O valor indicando se o navio afundou ou não.
 */
void setAfundou(bool afundou);

/**
 * @brief Sobrecarga do operador de extração para ler dados de um objeto Navio.
 * @param input O fluxo de entrada.
 * @param navio O objeto Navio para ler os dados.
 * @return O fluxo de entrada atualizado.
 */
friend std::istream& operator>>(std::istream& input, Navio& navio);
};

#endif // NAVIO_H
