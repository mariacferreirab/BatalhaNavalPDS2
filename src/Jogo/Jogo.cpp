#include "Game.hpp"

Jogo::Jogo()
{
}

void Jogo::setTabuleiro(const Tabuleiro& jogador, int numero)
{
    if (numero == 1)
    {
        jogador1 = jogador;
    }
    else
    {
        jogador2 = jogador;
    }
}

Tabuleiro& Jogo::getTabuleiro(int numero)
{
    if (numero == 1)
    {
        return jogador1;
    }
    else
    {
        return jogador2;
    }
}
void Jogo::salvarJogo(std::string filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        // Salvar jogador1
        file << jogador1.getNome() << std::endl;
        std::vector<Navio*> navios = jogador1.getNavios();
        for (auto& navio : navios)
        {
            file << navio->getNome() << " " << navio->getTamanho() << " " << navio->getAfundou() << std::endl;
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                file << jogador1.getTabuleiro()[i][j] << " ";
            }
            file << std::endl;
        }
        // Salvar jogador2
        file << jogador2.getNome() << std::endl;
        navios = jogador2.getNavios();
        for (auto& navio : navios)
        {
            file << navio->getNome() << " " << navio->getTamanho() << " " << navio->getAfundou() << std::endl;
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                file << jogador2.getTabuleiro()[i][j] << " ";
            }
            file << std::endl;
        }

        file.close();
    }
}

void Jogo::carregarJogo(std::string filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string nome1, nome2;
        file >> nome1 >> nome2;
        jogador1.setNome(nome1);
        jogador2.setNome(nome2);
        // carregar outras variaveis do jogo
        file.close();
    }
}
