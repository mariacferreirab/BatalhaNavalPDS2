#ifndef GAME_H
#define GAME_H

#include "Tabuleiro.h"
#include "Navio.h"
#include <fstream>

/**
@brief Classe Game usada para gerenciar o jogo e seus componentes.
*/
class Game {
private:
Tabuleiro jogador1; // Tabuleiro do jogador 1
Tabuleiro jogador2; // Tabuleiro do jogador 2
public:
/**
* @brief Construtor padrão. Cria um novo objeto Game.
*/
Game();
/**
 * @brief Define o tabuleiro do jogo para um jogador específico.
 * @param jogador O tabuleiro a ser definido.
 * @param numero O número do jogador (1 ou 2).
 */
void setTabuleiro(const Tabuleiro& jogador, int numero);