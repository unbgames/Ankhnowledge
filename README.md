# Ankhnowledge

[![GitHub release](https://img.shields.io/badge/release-v0--5-red.svg)](https://github.com/sconetto/Ankhnowledge/releases/tag/ankh_ankhnowledge_v0-5)
[![Github All Releases](https://img.shields.io/badge/downloads-218%20total-brightgreen.svg)](https://github.com/sconetto/Ankhnowledge/releases/tag/ankh_ankhnowledge_v0-5)
![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![License](https://img.shields.io/badge/license-GPLv2-yellow.svg)

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

Aguarde o termino do processo de instalação e se estiver tudo ocorrido sem problemas agora basta executar o jogo a partir do seu terminal, executando o segundo comando:

```sh
$ Ankhnowledge
```

E é só jogar agora!

### Desinstalando o Jogo
Para desinstalar o jogo também é simples, basta dentro da pasta _source_ onde os arquivos foram baixados executar o script de desinstalação:

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

# Change Log
* _Realease_ inicial produzida pela equipe de GCS e versão entregue v0-5 pelos desenvolvedores do software.

# Problemas (_Known Issues_)
* Os poderes dos personagens não fazem nada (botão Y no jogo)

* Fique à vontade para abrir novas [_issues_](https://github.com/sconetto/Ankhnowledge/issues/new) no nosso repositório
