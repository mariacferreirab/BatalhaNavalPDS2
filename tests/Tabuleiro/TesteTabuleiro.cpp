
#include "doctest.h"
#include "Navio.hpp"
#include "Cruzador.hpp"
#include "Tabuleiro.hpp"
#include <iostream>

#include <sstream>
#include <iostream>

TEST_CASE("Tabuleiro: Posicionar Navios - Orientação inválida") {
    Tabuleiro tabuleiro;
    
    // Redirecionar a saída de erro para uma string
    std::stringstream errorOutput;
    std::streambuf* oldCerrBuffer = std::cerr.rdbuf();
    std::cerr.rdbuf(errorOutput.rdbuf());

    // Simular a entrada inválida
    std::string input = "A0X\n";
    std::stringstream inputBuffer(input);
    std::streambuf* oldCinBuffer = std::cin.rdbuf();
    std::cin.rdbuf(inputBuffer.rdbuf());

    // Chamar o método de posicionarNavios
    tabuleiro.posicionarNavios();

    // Restaurar os buffers de entrada e saída
    std::cin.rdbuf(oldCinBuffer);
    std::cerr.rdbuf(oldCerrBuffer);

    // Verificar a saída de erro
    std::string expectedErrorMessage = "\033[1;31m" + std::string("Entrada invalida. Insira uma coordenada valida no formato A0H.") + "\033[0m" + "\n";
    std::string actualErrorMessage = errorOutput.str();
    CHECK(actualErrorMessage == expectedErrorMessage);
}


 TEST_CASE("Teste do construtor Tabuleiro") 
 {
      //Criação de um objeto Tabuleiro
     Tabuleiro tabuleiro;

      //Verifica se o nome padrão está correto
     CHECK(tabuleiro.getNome() == "DefaultPlayerNome");
     tabuleiro.setNome("NotDefaultPlayerNome");
     CHECK(tabuleiro.getNome() == "NotDefaultPlayerNome");
      //Verifica se a quantidade de navios é correta
     CHECK(tabuleiro.getNavios().size() == 4);

      //Verifica se o tabuleiro foi inicializado corretamente
     for (int i = 0; i < 10; i++) 
     {
         for (int j = 0; j < 10; j++) 
         {
             CHECK(tabuleiro.getTabuleiro()[i][j] == '.');
         }
     }
 }

 TEST_CASE("Teste da função podePosicionarNavio") {
    //Criação de um objeto Tabuleiro
     Tabuleiro tabuleiro;

    //Criação de um objeto Navio para teste
     Cruzador navio;

     SUBCASE("Teste de posicionar navio na horizontal válido") {
         navio.setOrientacao('H');
         navio.setY(2);
         navio.setY(3);

          //Verifica se é possível posicionar o navio
         CHECK(tabuleiro.podePosicionarNavio(&navio) == true);
     }

     SUBCASE("Teste de posicionar navio na horizontal inválido") {
         navio.setOrientacao('H');
         navio.setY(9);
         navio.setY(9);

          //Verifica se não é possível posicionar o navio
         CHECK(tabuleiro.podePosicionarNavio(&navio) == false);
     }

     SUBCASE("Teste de posicionar navio na vertical válido") {
         navio.setOrientacao('V');
         navio.setX(4);
         navio.setY(2);

          //Verifica se é possível posicionar o navio
         CHECK(tabuleiro.podePosicionarNavio(&navio) == true);
     }

     SUBCASE("Teste de posicionar navio na vertical inválido") {
         navio.setOrientacao('V');
         navio.setX(7);
         navio.setY(3);

          //Verifica se não é possível posicionar o navio
         CHECK(tabuleiro.podePosicionarNavio(&navio) == false);
     }
 }


 TEST_CASE("Teste da função afundouTudo") 
 {
      //Criação de um objeto Tabuleiro
     Tabuleiro tabuleiro;

     SUBCASE("Teste com todos os navios afundados") 
     {
          //Configuração dos navios para estarem afundados
        for (std::vector<Navio*>::size_type i = 0; i < tabuleiro.getNavios().size(); i++)
         {
             tabuleiro.getNavios()[i]->setAfundou(true);
         }

          //Verifica se todos os navios estão afundados
         CHECK(tabuleiro.afundouTudo() == true);
     }

     SUBCASE("Teste com pelo menos um navio não afundado") 
     {
          //Configuração de um navio não afundado
         tabuleiro.getNavios()[0]->setAfundou(false);

          //Verifica se a função retorna falso quando pelo menos um navio não está afundado
         CHECK(tabuleiro.afundouTudo() == false);
     }
 }

 
  
 