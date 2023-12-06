## Jogo Batalha Naval

O projeto consiste na criação de um jogo de Batalha Naval, escrito em C++ e utilizando os conceitos de Programação Orientada a Objeto. O jogo envolve dois jogadores que posicionam suas próprias peças - navios - e tentam atacar as peças adversárias em um tabuleiro de tamanho 10x10. Vence quem afundar todos os navios opositores primeiro.

## Relevancia
Construir o jogo Batalha Naval é muito relevante para nosso grupo por diversos motivos, entre eles:
**Domínio da Linguagem C++:** 
Criar um projeto de Batalha Naval em C++ oferece uma oportunidade para aprender e aplicar os princípios essenciais da linguagem de programação C++, incluindo a sintaxe, estruturas de controle, funções, classes e objetos.

**Aplicação de Algoritmos e Estruturas de Dados:**
Implementar a lógica da Batalha Naval requer a aplicação eficiente de algoritmos e estruturas de dados. Isso pode envolver a manipulação de matrizes para representar o tabuleiro e o uso de algoritmos de busca para determinar os resultados dos ataques, entre outros.

**Desenvolvimento de Habilidades de Resolução de Problemas:**
Criar um jogo como a Batalha Naval exige habilidades analíticas e de resolução de problemas. Os desafios incluem posicionar os navios estrategicamente, gerenciar a lógica do jogo e determinar quando um navio foi afundado.

**Compreensão de Jogos e Lógica de Jogo:**
Ao criar um jogo, é possível adquirir uma compreensão mais profunda da lógica dos jogos, como as regras e a interação do jogador. Isso é valioso para quem tem interesse em programação de jogos.

**Aplicação Prática de Conceitos Teóricos:**
O projeto permite a aplicação prática de conceitos teóricos aprendidos em cursos de algoritmos, estruturas de dados e programação.

## Objetivo
O principal objetivo do nosso projeto é aplicar os conhecimentos adquiridos nas aulas de Programação e Desenvolvimento de Software II (PDS II) para criar um programa interativo e divertido, por isso optamos por desenvolver o jogo Batalha Naval, que, inclusive, pode ser expandido futuramente para incluir funcionalidades avançadas, como inteligência artificial para oponentes controlados pelo computador, proporcionando uma oportunidade para aprimoramento contínuo e inovação.

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

$ make tests Execução Testes $ make run_tests Relatório de Cobertura Para imprimir o relatório simplificado no próprio Terminal, utilizar:

$ make coverage Para gerar o relatório em HTML, utilizar:

$ make html_coverage Atenção: Criar antes um diretório ./coverage/

Documentação É necessário ter na raiz do projeto um arquivo Doxyfile. Um arquivo padrão pode ser gerado pelo comando:

$ doxygen -g Abaixo a lista de flags que foram modificadas no arquivo original.

PROJECT_NAME = "BatalhaNavalPDS2"

OUTPUT_DIRECTORY = doc/

RECURSIVE = YES

EXTRACT_ALL = YES EXTRACT_PRIVATE = YES EXTRACT_STATIC = YES

HAVE_DOT = NO 

Para gerar a documentação, utilizar:

$ doxygen Doxyfile ou

$ make documentation 

Atenção: Criar antes um diretório ./doc/

Remover arquivos auxiliares $ make clean

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

3. Execute o arquivo principal do jogo atraves do seguinyte comando:

- make
4. E depois adicione o seguinte comando para rodar o programa:
  
- make run

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
- Estruturar o projeto e definir as funções para que o jogo de batalha naval funcionasse da maneira correta;
- Tivemos dificuldades em estrturar testes para o projeto.

### Autores

- [Mariana Villefort] https://github.com/MarianaVRabelo
- [Maria Clara Ferreira] https://github.com/mariacferreirab
- [Valentina Perpetuo] https://github.com/valentinavps
