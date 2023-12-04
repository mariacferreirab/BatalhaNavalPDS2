#ifndef TABULEIRO_H
#define TABULEIRO_H


#include "Navio.hpp"
#include "Contratorpedeiro.hpp"
#include "Submarino.hpp"
#include "Cruzador.hpp"
#include "Encouracado.hpp"
#include <algorithm>


/**
 * @brief Classe que representa o tabuleiro do jogo de batalha naval.
 */
class Tabuleiro{
private:
    static const int ROWS = 10;
    static const int COLS = 10;
    char tabuleiro[ROWS][COLS];
    std::string nome;
    std::vector<Navio*> navios;

    /**
     * @brief Posiciona um navio no tabuleiro.
     * 
     * @param navio O navio a ser posicionado.
     */
    void posicionarNavio(Navio* navio);
    
public:
    /**
     * @brief Construtor padrão da classe Tabuleiro.
     */
    Tabuleiro();
    //metodos get e set
    std::string getNome();
	  void setNome(std::string nome);
    char (*getTabuleiro())[10];

    std::vector<Navio*> getNavios() const;
	void setNavios(const std::vector<Navio*>& navios);

/**
* @brief Verifica se é possível posicionar um navio no tabuleiro.
* 
* @param navio O navio a ser posicionado.
* @return true se for possível posicionar o navio, false caso contrário.
*/
  bool podePosicionarNavio(Navio* navio);

    /**
     * @brief Posiciona os navios no tabuleiro.
     */
    void posicionarNavios();

    	/**
     	* @brief Posiciona os navios aleatoriamente no tabuleiro.
     	*/
	void posicionarNaviosRandomly();
	
    	/**
     	* @brief Realiza um tiro no tabuleiro.
     	* 
     	* @param x A coordenada x do tiro.
     	* @param y A coordenada y do tiro.
     	* @return true se o tiro acertar algum navio, false caso contrário.
     	*/
	bool atirar(int x, int y);

    /**
     * @brief Verifica se todos os navios do tabuleiro foram afundados.
     * 
     * @return true se todos os navios foram afundados, false caso contrário.
     */
    bool afundouTudo();

    	/**
     	* @brief Imprime o tabuleiro com a posição dos navios.
     	*/
	void printTabuleiroNavio();
    	/**
     	* @brief Imprime o tabuleiro para disparos, mostrando os tiros efetuados.
     	*/
	void printShootingTabuleiro();

    //sobrecarga 
    Tabuleiro& operator=(const Tabuleiro& other);

};
#endif
