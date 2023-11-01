#include "Navio.h"
#include <iostream>

Navio::Navio()
{
    nome = "Navio";
    tamanho = 0;
    simbolo = 'S';
    orientacao = 'V';
    x = 0;
    y = 0;
    danos = 0;
    afundou = false;
}

std::string Navio::getNome()
{
    return nome;
}

void Navio::setNome(std::string nome)
{
    this->nome = nome;
}

int Navio::getTamanho()
{
    return tamanho;
}

void Navio::setTamanho(int tamanho)
{
    this->tamanho = tamanho;
}

char Navio::getSimbolo()
{
    return simbolo;
}

void Navio::setSimbolo(char simbolo)
{
    this->simbolo = simbolo;
}

char Navio::getOrientacao()
{
    return orientacao;
}

void Navio::setOrientacao(char orientacao)
{
    this->orientacao = orientacao;
}

int Navio::getX()
{
    return x;
}

void Navio::setX(int x)
{
    this->x = x;
}

int Navio::getY()
{
    return y;
}

void Navio::setY(int y)
{
    this->y = y;
}

int Navio::getDanos()
{
    return danos;
}

void Navio::setDanos(int danos)
{
    this->danos = danos;
}

void Navio::dano()
{
    ++danos;
}

bool Navio::getAfundou()
{
    if (danos == tamanho)
    {
        afundou = true;
    } else
    {
        afundou = false;
    }
    return afundou;
}

void Navio::setAfundou(bool afundou)
{
    this->afundou = afundou;
}

std::istream& operator>>(std::istream& cin, Navio& navio)
{
    std::cout << "Digite as coordenadas (x,y) e a orientação (H/V) do " << navio.nome << ": ";
    std::cin >> navio.x >> navio.y >> navio.orientacao;
    return std::cin;
}
