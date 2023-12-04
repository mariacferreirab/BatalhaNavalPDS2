#include <iostream>
#include <chrono>
#include <thread>

#include "Tabuleiro.hpp"
#include "Game.hpp"


// void waitForSeconds(int seconds)
// {
// 	//cout << "Waiting for " << seconds << " seconds:" << endl;
// 	for (int i = seconds; i > 0; i--)
// 	{
// 		cout << i << "..." << endl;
// 		this_thread::sleep_for(chrono::seconds(1));
// 	}
// 	//cout << "Done!" << endl;
// }

void displayTurnsMenu()
{
	std::cout << std::endl;
	std::cout << "1. Proxima Jogada" << std::endl;
	std::cout << "2. Salvar Jogo" << std::endl;
	std::cout << "Insira a opcao selecionada: ";
}

void battle(Game game)
{
	Tabuleiro player1 = game.getTabuleiro(1);
	Tabuleiro player2 = game.getTabuleiro(2);
	bool gameOver = false;
	bool player1Turn = true;
	int turnsCounter = 0;
	int minTurns = 15; // numero minimo de rodadas para vencer.No minimo a soma do tam de todos os navios
	int menuOp = 0;
	while (!gameOver)
	{
		// A primeira vez não acontece o display do menu
		if (turnsCounter == 0)
		{
			std::cout << "A BATALHA COMECOU!" << std::endl;
			std::cout << std::endl;
			menuOp = 1;
		} else
		{
			bool validOp = false;
			while (!validOp)
			{
				try
				{
					displayTurnsMenu();
					std::cin >> menuOp;
					if (std::cin.fail())
					{
						throw std::invalid_argument("A entrada deve ser um numero.");
					} else if (menuOp < 1 || menuOp > 2)
					{
						throw std::invalid_argument("Escolha uma opcao entre 1 e 2.");
					} else
					{
						validOp = true;
					}
				} catch (const std::invalid_argument& e)
				{
					system("cls");
					std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');
					continue;
				}
			}
			system("cls");
		}
		// Prox movimento (passa a rodada)
		if (menuOp == 1)
		{
			if (player1Turn)
			{
				bool validInput = false;
				while (!validInput)
				{
					// Display do tabuleiro
					player1.printTabuleiroNavio();
					player2.printShootingTabuleiro();
					// Pergunta sobre as coordenadas para atirar
					std::cout << player1.getNome() << ", eh a sua vez de atirar. Insira as coordenadas (exemplo: B3): ";
					char row;
					char column;
					std::cin >> row >> column;
					int x = row - 'A';
					int y = column - '0';
					try
					{
						if (std::cin.fail() || !std::isupper(row) || row < 'A' || row > 'J')
						{
							throw std::invalid_argument("Coordenada de linha invalida. Favor inserir uma letra maiuscula entre A e J.");
						} else if (!std::isdigit(column) || y < 0 || y > 9)
						{
							throw std::invalid_argument("Coordenada de coluna invalida. Favor inserir um numero entre 0 e 9.");
						} else
						{
							validInput = true;
						}
					} catch (const std::invalid_argument& e)
					{
						system("cls");
						std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');
						continue;
					}
					// Se jogador1 atirar no jogador2. Hit = true: water = false
					player1Turn = player2.atirar(x, y) ? true : false;
				}
			} else
			{
				bool validInput = false;
				while (!validInput)
				{
					// Rodada do Tabuleiro 2 
					// Print tabuleiro
					player2.printTabuleiroNavio();
					player1.printShootingTabuleiro();
					// Solicita as cordenadas do ataque
					std::cout << player2.getNome() << ", eh a sua vez de atirar.Insira as coordenadas (exemplo: B3) ";
					char row;
					char column;
					std::cin >> row >> column;
					int x = row - 'A';
					int y = column - '0';
					try
					{
						if (std::cin.fail() || !std::isupper(row) || row < 'A' || row > 'J')
						{
							throw std::invalid_argument("Coordenada de linha invalida. Favor inserir uma letra maiuscula entre A e J.");
						} else if (!std::isdigit(column) || y < 0 || y > 9)
						{
							throw std::invalid_argument("Coordenada de coluna invalida. Favor inserir um numero entre 0 e 9.");
						} else
						{
							validInput = true;
						}
					} catch (const std::invalid_argument& e)
					{
						system("cls");
						std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<::std::streamsize>::max(), '\n');
						continue;
					}
					// Se jogador1 atirar no jogador2. Hit = true: water = false
					player1Turn = player1.atirar(x, y) ? false : true;
				}

			}
		} else if (menuOp == 2)
		{
			//opcao para salvar no pc, o unico problema é que cada pc tem um path
			std::string path = ""; 
			std::string ext = ".txt";
			std::string fileNome;
			std::cout << "Insira o nome do arquivo: ";
			std::cin >> fileNome;
			std::string finalPath = path + fileNome + ext;
			game.salvarJogo(finalPath);
			std::cout << "Jogo salvo em: " << finalPath << std::endl;
		} else
		{
			system("cls");
			std::cerr << "\033[1;31m" << "ERROR" << "\033[0m" << std::endl;
		}
		// Verifica se o jogo acabou
		if (turnsCounter > minTurns && player2.afundouTudo())
		{
			std::cout << std::endl;
			std::cout << "Acertado, afundado e frota destruida! " << player1.getNome() << " venceu!" << std::endl;
			std::cout << player1.getNome() << " ganhou com um total de " << turnsCounter << " jogadas." << std::endl;
			player1.printTabuleiroNavio();
			player2.printShootingTabuleiro();
			std::cout << "Parabens " << player1.getNome() << " voce eh o campeao." << std::endl;
			gameOver = true;
		} else if (turnsCounter > minTurns && player1.afundouTudo())
		{
			std::cout << std::endl;
			std::cout << "Acertado, afundado e frota destruida! " << player2.getNome() << " venceu!" << std::endl;
			std::cout << player2.getNome() << " ganhou com um total de " << turnsCounter << " jogadas." << std::endl;
			player2.printTabuleiroNavio();
			player1.printShootingTabuleiro();
			std::cout << "Parabens " << player2.getNome() << " voce eh o campeao." << std::endl;
			gameOver = true;
		}

		++turnsCounter;
	}
	std::cout << std::endl;
	std::cout << "FIM DE JOGO." << std::endl;
}
