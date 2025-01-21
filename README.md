# **Análise de Componentes Conexos e Frequência de Personagens em um Grafo**

Este projeto implementa um algoritmo para analisar **componentes conexos** em um grafo bidimensional representado por uma matriz. Além disso, determina qual personagem ('A', 'B', 'C', 'D', 'E') aparece com maior frequência na matriz.

---

## **Funcionalidades**

- **Identificação de Componentes Conexos:**  
  O programa identifica e conta o número de componentes conexos presentes na matriz, onde cada componente representa um grupo de células conectadas.

- **Personagem Mais Frequente:**  
  Durante a análise, o programa determina qual personagem aparece com maior frequência global na matriz.

---

## **Estrutura do Código**

1. **Entrada de Dados:**  
   A matriz é lida do terminal, com cada célula representando um personagem.

2. **Construção do Grafo:**  
   Cada célula da matriz é modelada como um nó (`Node`) do grafo, enquanto as conexões adjacentes são tratadas como arestas.

3. **Busca em Largura (BFS):**  
   A função `bfs` realiza o caminhamento nos componentes do grafo para marcá-los e contabilizar as frequências dos personagens.

4. **Resultados:**  
   O programa calcula o número total de componentes conexos e identifica o personagem mais frequente com sua contagem.

---

## **Estrutura do Projeto**

```
├── main.cpp          # Código principal
├── Graph.h           # Declaração da classe Graph
├── Graph.cpp         # Implementação da classe Graph
├── Node.h            # Declaração da classe Node
└── Node.cpp          # Implementação da classe Node
```

---

## **Possíveis Melhorias**

- Adicionar suporte à adjacência em 8 direções.
- Permitir a leitura da matriz diretamente de arquivos.
- Implementar uma interface gráfica para a visualização dos componentes.

---
