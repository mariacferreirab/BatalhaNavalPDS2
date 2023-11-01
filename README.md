## Jogo Batalha Naval

O projeto consiste na criação de um jogo de Batalha Naval, escrito em C++ e utilizando os conceitos de Programação Orientada a Objeto. O jogo envolve dois jogadores que posicionam suas próprias peças - navios - e tentam atacar as peças adversárias em um tabuleiro de tamanho 10x10. Vence quem afundar todos os navios opositores primeiro.

### Ferramentas

Esse projeto utiliza as seguintes linguagem, ferramentas e bibliotecas:

Linguagem: C++11
Compilação: Make
Documentação: Doxygen
Testes Unitários: Doctest
Cobertura: gcovr

### Requisitos

Certifique-se de ter um compilador C++ instalado em sua máquina antes de executar o jogo.

### Compilação

$ make
Atenção: Criar antes um diretório ./build/

### Execução

$ make run

### Compilação Testes

*Completar

### Documentação
É necessário ter na raiz do projeto um arquivo Doxyfile. Um arquivo padrão pode ser gerado pelo comando:

$ doxygen -g

Abaixo a lista de flags que foram modificadas no arquivo original.

PROJECT_NAME = "BatalhaNavalPDS2"

OUTPUT_DIRECTORY = doc/

RECURSIVE = YES

EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES

HAVE_DOT = NO
Para gerar a documentação, utilizar:

$ doxygen Doxyfile
ou

$ make documentation
Atenção: Criar antes um diretório ./doc/

Remover arquivos auxiliares
$ make clean

### Como Jogar

1. Clone este repositório em sua máquina local.

- git clone https:[(https://github.com/mariacferreirab/BatalhaNavalPDS2.git)]

2. Navegue até o diretório do projeto.

- cd BatalhaNavalPDS2

3. Execute o arquivo principal do jogo.

- g++ \*.cpp -o main
- e depois adicione
- ./main

4. O jogo começará e será solicitado que cada jogador insira as coordenadas de ataque em seu turno.
5. O jogo começará e será solicitado que cada jogador insira as coordenadas de ataque em seu turno.
6. Os jogadores devem alternar seus turnos até que todos os navios de um dos jogadores sejam destruídos.
7. O jogo exibirá o resultado final e o jogador vencedor.

### Regras

O jogo acontece entre dois jogadores, com cada jogador possuindo dois tabuleiros: um para posicionar seus próprios navios e outro para registrar seus tiros no tabuleiro adversário. As colunas são numeradas de 0 a 9, e as linhas são identificadas com letras maiúsculas entre A e J.

As regras são:

1. Cada jogador tem um tabuleiro 10x10, representado por coordenadas de A1 a J10.
2. Cada jogador posiciona seus navios no tabuleiro antes do início do jogo. Os tipos de navios e seu tamanho são:
   - Encouraçado (4 células)
   - Cruzador (3 células)
   - Contratorpedeiro (6 células)
   - Submarino (2 células)
3. Os navios podem ser posicionados horizontalmente ou verticalmente, desde que possuam um espaço vago entre eles.
4. Uma vez posicionados os navios, os jogadores se alternam em atirar no tabuleiro do oponente. Para isso, são informadas as coordenadas da posição escolhida (ex: "A5").
5. Se um tiro não acertar uma peça, o jogo indica acerto em "água".
6. Se um tiro acerta uma peça, o jogo indica "acertou".
7. Se todos os espaços do navio forem acertados, o navio é indicado como "afundado".
8. O jogo continua até que todos os navios de um dos jogadores sejam afundados, quando acaba o jogo.

### Dificuldades

*Completar

### Autores

- [Mariana Villefort] https://github.com/MarianaVRabelo
- [Maria Clara Ferreira] https://github.com/mariacferreirab
- [Valentina Perpetuo] https://github.com/valentinavps
