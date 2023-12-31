#ifndef JOGO_HPP
#define JOGO_HPP

#include "Tabuleiro.hpp"
#include "Navio.hpp"
#include <fstream>

/**
@brief Classe Jogo usada para gerenciar o jogo e seus componentes.
*/
class Jogo {
private:
Tabuleiro jogador1; // Tabuleiro do jogador 1
Tabuleiro jogador2; // Tabuleiro do jogador 2
public:
/**
* @brief Construtor padrão. Cria um novo objeto Jogo.
*/
Jogo();
/**
 * @brief Define o tabuleiro do jogo para um jogador específico.
 * @param jogador O tabuleiro a ser definido.
 * @param numero O número do jogador (1 ou 2).
 */
void setTabuleiro(const Tabuleiro& jogador, int numero);

/**
 * @brief Obtém o tabuleiro do jogo de um jogador específico.
 * @param numero O número do jogador (1 ou 2).
 * @return O tabuleiro do jogador especificado.
 */
Tabuleiro& getTabuleiro(int numero);

/**
 * @brief Salva o estado atual do jogo em um arquivo.
 * @param filename O nome do arquivo para salvar o jogo.
 */
void salvarJogo(std::string filename);

/**
 * @brief Carrega um jogo previamente salvo de um arquivo.
 * @param filename O nome do arquivo para carregar o jogo.
 */
void carregarJogo(std::string filename);
};

#endif
