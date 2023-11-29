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

void Tabuleiro::posicionarNavios()
{
	for (size_t i = 0; i < navios.size(); i++)
	{
		Navio* currentNavio = navios[i];
		std::cout << nome << ", sua vez de posicionar seus navios. Seja esperto!" << std::endl;
		printTabuleiroNavio();
		std::cout << std::endl;
		std::cout << "Posicionando " << navios[i]->getNome() << " de tamanho " << navios[i]->getTamanho() << std::endl;

		while (true)
		{
			std::cout << "Insira a coordenada da linha (A-J), a coordenada da coluna (0-9) e a orientacao (H/V)." << std::endl;
			std::cout << "Exemplo A0V: ";

			std::string input;
			std::cin >> input;


			// Verificar se a entrada tem o tamanho correto
			if (input.size() != 3 )
			{
				std::cerr << "\033[1;31m" << "Entrada invalida. Insira uma coordenada valida no formato A0H." << "\033[0m" << std::endl;

				// Limpar o buffer de entrada
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			char row = input[0];
			char column = input[1];
			char orientation = input[2];

			int x = row - 'A';
			int y = column - '0';

			if (!validarCoordenadaLinha(row))
			{
				std::cerr << "\033[1;31m" << "Coordenada de linha invalida. Insira uma letra valida entre A e J em maiusculas." << "\033[0m" << std::endl;

				// Limpar o buffer de entrada
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				continue;
			}

			if (!validarCoordenadaColuna(column))
			{
				std::cerr << "\033[1;31m" << "Coordenada de coluna invalida. Por favor, insira um numero valido entre 0 e 9." << "\033[0m" << std::endl;

				// Limpar o buffer de entrada
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				continue;
			}

			if (!validarOrientacao(orientation))
			{
				std::cerr << "\033[1;31m" << "Orientação invalida. Insira uma letra H/V valida em maiusculas." << "\033[0m" << std::endl;

				// Limpar o buffer de entrada
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				continue;
			}

			//Define as coordenadas e orientacao do navio
			currentNavio->setOrientacao(orientation);
			currentNavio->setX(x);
			currentNavio->setY(y);

			if (podePosicionarNavio(currentNavio))
			{
				posicionarNavio(currentNavio);
				// Limpar a tela
				system("cls");
				break;
			}
			else
			{
				std::cerr << "\033[1;31m" << "Necessario deixar um espaco de agua entre os barcos." << "\033[0m" << std::endl;
				std::cerr << "\033[1;31m" << "Coordenadas invalidas. Por favor, tente novamente." << "\033[0m" << std::endl;
			}
		}
	}

	printTabuleiroNavio();
}

/*void Tabuleiro::posicionarNaviosRandomly()
{
	//generate a random number 0-9
	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist1(0, 9);
	uniform_int_distribution<mt19937::result_type> dist2(0, 9);
	uniform_int_distribution<int> dist3(numeric_limits<int>::min(), numeric_limits<int>::max());
	// randomNumber = dist(rng)

	for (auto navio : navios)
	{
		bool posicionard = false;
		while (!posicionard)
		{
			navio->setX(dist1(rng));
			navio->setY(dist2(rng));
			char randomOrientacao = (dist3(rng)) ? 'H' : 'V'; //generate a randomly 'V'(even) / 'H'(odd)
			navio->setOrientacao(randomOrientacao);
			if (podePosicionarNavio(navio))
			{
				posicionarNavio(navio);
				posicionard = true;
			}
		}
	}
	cout << nome << "'s game tabuleiro randomly generated." << endl;
	printTabuleiroNavio();
}*/


bool Tabuleiro::atirar(int x, int y)
{
	if (tabuleiro[x][y] == 'S' || tabuleiro[x][y] == 'C' || tabuleiro[x][y] == 'P' || tabuleiro[x][y] == 'E')
	{
		// se é um navio atirar
		char symbolHit = tabuleiro[x][y];
		// achar o navio no vector de navios que bate com o simbolo
			auto it = find_if(navios.begin(), navios.end(), [symbolHit](Navio* navio) {
			return navio->getSimbolo() == symbolHit;
			});

		if (it != navios.end())
		{
			Navio* foundNavio = *it;
			foundNavio->dano();
			if (foundNavio->getAfundou())
			{

				std::cout << "\033[1;32m" << foundNavio->getNome() << " Afundado! " << "\033[0m" << std::endl;
				std::cout << "\033[1;32m" << "Voce destruiu o navio " << foundNavio->getNome() << " de " << nome << "! "<< "\033[0m" << std::endl;
			} else
			{
				std::cout << "\033[1;32m" << "Acertou!" << "\033[0m" << std::endl;
			}
		} else
		{
			// Navio não foi achado
		}
		tabuleiro[x][y] = 'X';
		return true;
	} else if (tabuleiro[x][y] == 'X' || tabuleiro[x][y] == '*')
	{
		// Se voce ja atirou aqui
		std::cout << "\033[1;31m" << "Voce ja atirou aqui antes!" << "\033[0m" << std::endl;
		std::cout << "\033[1;31m" << "Acabou de perder sua tentativa!" << "\033[0m" << std::endl;
		return false;
	} else
	{
		// Virar agua
		tabuleiro[x][y] = '*';
		std::cout << "\033[1;34m" << "Agua!" << "\033[0m" << std::endl;
		return false;
	}
}


