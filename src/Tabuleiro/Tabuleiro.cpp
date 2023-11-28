#include "Tabuleiro.hpp"
#include <iostream>
#include <algorithm>

Tabuleiro::Tabuleiro()
{
	nome = "DefaultPlayerNome";
	navios.push_back(new Contratorpedeiro());
	navios.push_back(new Cruzador());
	navios.push_back(new Submarino());
	navios.push_back(new Encouracado());
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tabuleiro[i][j] = '.';
		}
	}

}

std::string Tabuleiro::getNome()
{
	return nome;
}

void Tabuleiro::setNome(std::string nome)
{
	this->nome = nome;
}

std::vector<Navio*> Tabuleiro::getNavios() const
{
	return navios;
}

void Tabuleiro::setNavios(const std::vector<Navio*>& navios)
{
	this->navios = navios;
}

bool Tabuleiro::podePosicionarNavio(Navio* navio)
{
	if (navio->getOrientacao() == 'H')
	{
		if (navio->getY() + navio->getTamanho() > COLS)
		{
			return false;
		}
		for (int i = navio->getY() - 1; i <= navio->getY() + navio->getTamanho(); i++)
		{
			for (int j = navio->getX() - 1; j <= navio->getX() + 1; j++)
			{
				if (i >= 0 && i < COLS && j >= 0 && j < ROWS && tabuleiro[j][i] != '.')
				{
					return false;
				}
			}
		}
	} else
	{
		if (navio->getX() + navio->getTamanho() > ROWS)
		{
			return false;
		}
		for (int i = navio->getX() - 1; i <= navio->getX() + navio->getTamanho(); i++)
		{
			for (int j = navio->getY() - 1; j <= navio->getY() + 1; j++)
			{
				if (i >= 0 && i < ROWS && j >= 0 && j < COLS && tabuleiro[i][j] != '.')
				{
					return false;
				}
			}
		}
	}
	return true;
}

char(*Tabuleiro::getTabuleiro())[10]
{
	return tabuleiro;
}

void Tabuleiro:: printTabuleiroNavio()
{
	//cout << endl;
	std::cout << "Tabuleiro de: " << nome << std::endl;
	//Espaço para os frames do tabuleiro
	std::cout << "  ";
	for (int i = 0; i < COLS; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << (char)('A' + i) << " ";
		for (int j = 0; j < COLS; j++)
		{
			// Se for dado, não printar nos navios
			if (tabuleiro[i][j] == '*')
			{
				std::cout << ". ";
			} else
			{
				std::cout << tabuleiro[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Tabuleiro::printShootingTabuleiro()
{
	std::cout << "\t\t\t" << "Tabuleiro de Historico de Tiros:" << std::endl;
	
	std::cout << "\t\t\t  ";
	for (int i = 0; i < COLS; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << "\t\t\t" << (char)('A' + i) << " ";
		for (int j = 0; j < COLS; j++)
		{
			if (tabuleiro[i][j] == 'S' || tabuleiro[i][j] == 'C' || tabuleiro[i][j] == 'P' || tabuleiro[i][j] == 'E' )
			{
				std::cout << "." << " ";
			} else
			{
				std::cout << tabuleiro[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Tabuleiro::afundouTudo()
{
	for (size_t i = 0; i < navios.size(); i++)
	{
		if (!navios[i]->getAfundou())
		{
			return false;
		}
	}
	return true;
}

Tabuleiro& Tabuleiro::operator=(const Tabuleiro& other)
{
	if (this != &other)
	{
		nome = other.nome;
		for (size_t i = 0; i < navios.size(); i++)
		{
			navios[i] = new Navio(*(other.navios[i]));
		}
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				tabuleiro[i][j] = other.tabuleiro[i][j];
			}
		}
	}
	return *this;
}

void Tabuleiro::posicionarNavio(Navio* navio)
{
	if (navio->getOrientacao() == 'H')
	{
		for (int i = navio->getY(); i < navio->getY() + navio->getTamanho(); i++)
		{
			tabuleiro[navio->getX()][i] = navio->getSimbolo();
		}
	} else
	{
		for (int i = navio->getX(); i < navio->getX() + navio->getTamanho(); i++)
		{
			tabuleiro[i][navio->getY()] = navio->getSimbolo();
		}
	}
}

bool validarCoordenadaLinha(char row)
{
	return (isalpha(row) && isupper(row) && row >= 'A' && row <= 'J');
}

bool validarCoordenadaColuna(char column)
{
	return (isdigit(column) && column >= '0' && column <= '9');
}

bool validarOrientacao(char orientation)
{
	return (isalpha(orientation) && isupper(orientation) && (orientation == 'V' || orientation == 'H'));
}



