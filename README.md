# Ankhnowledge

[![GitHub release](https://img.shields.io/badge/release-v0--5-red.svg)](https://github.com/sconetto/Ankhnowledge/releases/tag/ankh_ankhnowledge_v0-5)
[![Github All Releases](https://img.shields.io/badge/downloads-218%20total-brightgreen.svg)](https://github.com/sconetto/Ankhnowledge/releases)
[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](http://en.cppreference.com/w/cpp)
[![License](https://img.shields.io/badge/license-GPLv2-yellow.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html)

Ankhnowledge é um jogo _multiplayer_ feito em C++ com auxílio da biblioteca de multimídia livre SDL (_Simple DirectMedia Layer_) que foi produzido durante a matéria de Introdução aos Jogos Eletrônicos.

O jogo se ambienta em cenários do antigo egito, onde dois jogadores disputam para ver quem é o melhor explorador.

# Como Instalar
## Instalando pelos Binários (_source_)
O jogo possui em seu _source_ uma série de scripts para a instalação automática, na pasta raíz você vai encontrar:
* __bootstrap.sh__ - script para criar os arquivos necessários para a instalação do jogo
* __cleanup.sh__ - script para limpar arquivos temporários de instalação e compilação
* __install-ankh.sh__ - script para instalação das dependências e instalação automática do jogo
* __uninstall-ankh.sh__ - script para desinstalação automática do jogo

__OBS__: Para instalar o jogo é necessário permissões de super usuário.

__OBS 2__: Use apenas os scripts ``install-ankh.sh`` e ``uninstall-ankh.sh`` para as tarefas de instalação e desinstalação do jogo, não faça uso dos demais scripts a não ser que saiba exatamente o que está fazendo!

### Dependências Necessárias
Algumas depedências necessárias para a instalação do jogo, sendo elas:
* gcc (>= 4:5.3.1-1ubuntu1)
* cpp (>= 4:5.3.1-1ubuntu1)
* gcc-5 (>= 5.3.1-3~)
* g++ (4:5.3.1-1ubuntu1)
* g++-5 (>= 5.3.1-3~)
* libtool (>= 2.4.6-0.1)
* autoconf (>= 2.69-9)
* automake (>= 1:1.15-4ubuntu1)
* libsdl-image1.2 (>= 1.2.12-5build2)
* libsdl-image1.2-dev (>= 1.2.12-5build2)
* libsdl-ttf2.0-0 (>= 2.0.11-3)
* libsdl-ttf2.0-dev (>= 2.0.11-3)
* libsdl-mixer1.2 (>= 1.2.12-11build1)
* libsdl-mixer1.2-dev (>= 1.2.12-11build1)
* libsdl-net1.2 (>= 1.2.8-4)
* libsdl-net1.2-dev (>= 1.2.8-4)

__OBS__: As versões podem variar de acordo com o SO utilizado (a máquina usada para testes e modificações era um Ubuntu 16.04.2 LTS _Kernel_ 4.8.0-52-generic Arquitetura 64 _bits_).

__OBS 2__: É importante validar os pacotes do _gcc_, _cpp_ e _g++_, os demais pacotes são instalados pelo script de instalação do jogo.

### Instalando o Jogo
Após instalado as dependências necessárias, agora basta executar o script de instalação (dentro da pasta _source_ baixada):

```sh
$ cd /home/<user>/<caminho-da-pasta>/
$ ./install-ankh.sh
```

ou

```sh
$ cd /home/<user>/<caminho-da-pasta>/
$ /bin/bash install-ankh.sh
```

Aguarde o termino do processo de instalação e se estiver tudo ocorrido sem problemas agora basta executar o jogo a partir do seu terminal, executando o seguinte comando:

```sh
$ Ankhnowledge
```

Tudo pronto! Agora é só jogar!

### Desinstalando o Jogo
Para desinstalar o jogo também é simples, basta executar o script de desinstalação dentro da pasta _source_, onde os arquivos foram baixados:

```sh
$ cd /home/<user>/<caminho-da-pasta>/
$ ./uninstall-ankh.sh
```

ou

```sh
$ cd /home/<user>/<caminho-da-pasta>/
$ /bin/bash uninstall-ankh.sh
```

Basta aguardar o término da execução e pronto, o jogo estará desinstalado da sua máquina!

## Instalando pelo pacote
O jogo Ankhnowledge ainda irá passar pelo processo de empacotamento para sistemas linux (_Debian Based_) e atualmente deve ser seguido o tutorial acima para ser instaldo e jogado.

# Como Jogar

O jogo faz uso de um _multiplayer_ local, os jodadores devem estar na mesma rede para poder jogar, um dos jogadores deve ser o anfitrião (_host_) e o outro conecta na sala do anfitrião para jogarem.

Após o jogo inciado, o _host_ deve criar uma sala e esperar o segundo jogador se conectar, o segundo jogador deverá conectar na sala do _host_ digitando o IP da máquina do _host_.

Após a entrada na sala os jogadores devem escolher entre dois exploradores, Adam The Explorer e Suti The Medjay, cada um tem sua habilidade especial e sua capacidade de exploração (_stamina_ - número de blocos que consegue caminhar). Depois de selecionados os personagens o _host_ deve escolher um dos cinco mapas disponíveis para então começar o jogo.

## Lista de Comandos

* w - anda um bloco para cima.
* s - anda um bloco para baixo.
* a - anda um bloco para a esquerda.
* d - anda um bloco para direita.
* u + (w, s, a, d) - anda um bloco para a direção desejada e empurra tijolos para essa mesma direção
* y + clicar em um bloco - habilidade especial do personagem.
 * Alan - ele mostra em branco blocos os quais ele pode se teleportar (_blink_).
 * Suti - ele mostra em branco blocos os quais ele pode criar areias movediças que podem atrapalhar os adversários (_quicksand_) e ele pode também retirar blocos marrons e areias movediças para auxiliar ele.
* esc - sair do jogo em andamento.

## Outros Comandos

* End Turn - Um botão dedicado para terminar seu turno de jogar sem ter que usar toda a _stamina_ do personagem.

## Objetivos

Objetivo do jogo é simples, o explorador que chegar primeiro ao baú que está no mapa vence!

### Regras do Jogo

Os jogadores devem ter em mente algumas particularidades do jogo:
1. Apenas os tijolos marrons são movíveis, os tijolos cinza são fixos.
2. Não se pode mover tijolos caso tenha um jogador no lado em que se quer mover os tijolos.
3. A quantidade de tijolos que o jogador move é somado para a subtração da sua _stamina_. Ex: Um jogador quer mover 2 tijolos para a direita, logo sua jogada irá gastar 3 de _stamina_, 1 da movimentação mais 2 da quantidade de tijolos.
4. Potes de água adicionam 2 de _stamina_ para o jogador, esta adição é permanente até o fim do jogo. Ex: Alan The Explorer começa com um total de 10 de _stamina_, enquanto Suti The Medjay começa com um total de 12 de _stamina_, caso Alan pegue 1 pote de água para os próximos turnos Alan inciará com um total de 12 de _stamina_, o mesmo caso segue para Suti, caso ele pegue 1 pote de água ele terá para os próximos turnos um total de 14 de _stamina_.
5. O uso das habilidades especiais também utiliza _stamina_, os valores diferem para Alan e Suti:
 * Alan usa 6 de _stamina_ para fazer seu teleporte (_blink_)
 * Suti usa 5 de _stamina_ para fazer sua areia movediça (_quicksand_)
6. As areias movediças vão aparecendo no mapa a cada fim de turno (além daquelas que o Suti produzir), e as areais atrapalham gastando a _stamina_ dos jogadores, a cada areia movediça que o jogador pisa são retirados 3 de sua _stamina_. Ex: Um jogador tem 12 de _stamina_ e vai se movimentar por um bloco que tenha areia movediça, seu movimento vai usar 4 de _stamina_, 1 para movição e 3 pelo fato de pisar em uma areia movediça.

__OBS__: Caso um jogador tenha _stamina_ menor que 4, que seria o valor normal a ser subtraído de sua _stamina_ para a movimentação sobre a areia, ele ainda conseguirá se movimentar mas sua _stamina_ irá para 0 terminando seu turno.

__OBS 2__: Tijolos marrons não podem ser movidos na direção desejada caso do outro lado tenha uma areia movediça.


## Personagens

* Alan, The Explorer:

![Alan](http://i.imgur.com/6MWMU0d.png)

* Suti, The Medjay:

![Suti](http://i.imgur.com/AjLyTwe.png)

## Tipos de blocos

* Bloco de Movimentação

![Bloco Normal](http://i.imgur.com/s6jC3Ep.png)

* Tijolo Marrom

![Tijolo Marrom](http://i.imgur.com/3vac3X1.png)

* Tijolo Cinza

![Tijolo Cinza](http://i.imgur.com/lpdv0eM.png)

* Pote de Água

![Pote de Água](http://i.imgur.com/Dv4fQ2z.png)

* Areia Movediça

![Areia Movediça](http://i.imgur.com/FxYY8O1.png)

* Baú

![Baú](http://i.imgur.com/m6dzYc3.png)

# Change Log
* _Realease_ inicial produzida pela equipe de GCS e versão entregue v0-5 pelos desenvolvedores do software.

# Problemas (_Known Issues_)

* Fique à vontade para abrir novas [_issues_](https://github.com/sconetto/Ankhnowledge/issues/new) no nosso repositório
