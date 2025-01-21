#include "Graph.h"

Graph::Graph(int linha, int coluna, vector<vector<Node>> lab) {

    // cria as ligações dos vértices conforme seu valor hexa
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            
            char info = lab[i][j].getInfo();//acessa o conteudo do nodo na posicao ij
            
            int val = (info >= 'A') ? (info - 'A' + 10) : (info - '0');//se info for "ABCDEF", converte para que seja um valor inteiro [0,5] e soma 10

            if (!(val & 0x8) && i - 1 >= 0) {   //compara bit a bit com "1000"
                addEdge(lab[i][j], lab[i - 1][j]);//cria ligacoes usando lab como base
            }
            if (!(val & 0x4) && j + 1 < coluna)     {//compara bit a bit com "0100"
                addEdge(lab[i][j], lab[i][j + 1]);//cria ligacoes usando lab como base
            }
            if (!(val & 0x2) && i + 1 < linha) {    //compara bit a bit com "0010"
                addEdge(lab[i][j], lab[i + 1][j]);//cria ligacoes usando lab como base
            }
            if (!(val & 0x1) && j - 1 >= 0) {     //compara bit a bit com "0001"
                addEdge(lab[i][j], lab[i][j - 1]);//cria ligacoes usando lab como base
            }
        }
    }
}

// Insere Nodo->w à lista do Node->v
void Graph::addEdge(const Node& v, const Node& w) {
    vector<Node>& list = graph[v];
    list.push_back(w);
}

// Marca um nó como visitado
void Graph::setMarked(const Node& n) {
    markedNodes.insert(n);
}

const set<Node>& Graph::getMarked() const { return markedNodes; }

// Retorna lista de adjacentes de determinado Node
vector<Node> Graph::getAdj(const Node& v) const {
    return graph.at(v);
}

// Retorna os vértices do grafo
vector<Node> Graph::getVerts() const {
    vector<Node> aux;
    for (const auto& element : graph)
        aux.push_back(element.first);
    return aux;
}