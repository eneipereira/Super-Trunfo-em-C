# Trabalho: Super Trunfo em C - Cartas

Repositório do trabalho da disciplina **Introdução à Programação de Computadores**, do curso de **Engenharia de Software** da **UNESA (Universidade Estácio de Sá)**.

---

## Descrição

Este projeto tem como objetivo desenvolver, em linguagem **C**, o jogo Super Trunfo de Países, dividido em três níveis de complexidade. A ideia é construir progressivamente funcionalidades que envolvem cadastro, cálculo de atributos e comparação entre cartas que representam cidades.

---

## Níveis do Projeto

### Etapa 1 – Cadastro e Análise das Cartas

- **Nível Novato (Implementado)**  
  Cadastro das cartas do jogo Super Trunfo de Cidades, com entrada e exibição das informações básicas: estado, código, cidade, população, área, PIB e pontos turísticos.

- **Nível Aventureiro (Implementado)**  
  Cálculo e exibição da densidade populacional e do PIB per capita para cada cidade, com formatação adequada dos resultados.

- **Nível Mestre (Implementado)**  
  Comparação entre duas cartas, definindo vencedores por atributo e introduzindo o conceito de "Super Poder", que soma atributos numéricos considerando conversões e critérios especiais.

---

### Etapa 2 – Lógica e Interatividade do Jogo

- **Nível Novato**  
  Comparação entre duas cartas com base em um único atributo definido no código, utilizando estruturas de decisão `if` e `if-else`.

- **Nível Aventureiro**  
  Inclusão de menu interativo com `switch`, permitindo ao jogador escolher o atributo de comparação. Uso de `if-else` aninhado para lógica condicional mais refinada.

- **Nível Mestre**  
  Comparação com múltiplos atributos escolhidos pelo jogador, menus dinâmicos, uso de `switch` e do operador ternário, resultando em lógica avançada e código mais eficiente.

---

## Como compilar

Para compilar o programa, certifique-se de ter o compilador `gcc` instalado e rode o seguinte comando no terminal:

```bash
gcc super_trunfo.c -o super_trunfo
```

---

## Como executar

Após compilar, execute o programa com:

```bash
./supertrunfo
```

O programa solicitará a entrada dos dados para duas cartas e, em seguida, exibirá as informações formatadas.

---

## Estrutura do projeto

- `super_trunfo.c`: Código-fonte do programa em C.

- `.gitignore`: Arquivo para ignorar arquivos compilados e temporários.

- `README.md`: Documento com a descrição do projeto, instruções de uso e informações complementares.

- `LICENSE`: Arquivo contendo a licença de uso do projeto (MIT License).

## Autor

Enei - Curso de Engenharia de Software - UNESA

## Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
