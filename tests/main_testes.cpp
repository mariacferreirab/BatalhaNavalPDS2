#include <iostream>
#include <cassert>
#include <sstream>
#include "Game.hpp"  

// Função de teste para a inicialização do jogo
void testGameInitialization() {
    Game game;

    // Teste se a criação do jogo não lança exceções
    try {
        game.setTabuleiro(/* configurar o seu tabuleiro */);
        std::cout << "Teste: Inicialização do jogo - Passou\n";
    } catch (...) {
        std::cerr << "Teste: Inicialização do jogo - Falhou\n";
    }
}

// Função de teste para a inicialização de jogadores
void testPlayerInitialization() {
    // Simula a entrada de nomes de jogador
    std::istringstream playerNameInput("Jogador1\nJogador2\n");
    std::cin.rdbuf(playerNameInput.rdbuf());

    // Teste se a inicialização dos jogadores não lança exceções
    try {
        startNewGame();
        std::cout << "Teste: Inicialização de jogadores - Passou\n";
    } catch (...) {
        std::cerr << "Teste: Inicialização de jogadores - Falhou\n";
    }
}

// Função de teste para a entrada de opções de menu
void testMenuOptionInput() {
    // Simula a entrada de opções de menu
    std::istringstream menuOptionInput("1\n");
    std::cin.rdbuf(menuOptionInput.rdbuf());

    // Teste se a entrada de opções de menu não lança exceções
    try {
        main();
        std::cout << "Teste: Entrada de opções de menu - Passou\n";
    } catch (...) {
        std::cerr << "Teste: Entrada de opções de menu - Falhou\n";
    }
}

int main() {
    // Execute os testes
    testGameInitialization();
    testPlayerInitialization();
    testMenuOptionInput();

    return 0;
}
