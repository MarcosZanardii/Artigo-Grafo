
#include "Node.h"
#include <map>
#include <vector>
#include <set>

using namespace std;

// Graph -> Estrutura que armazena os dados
class Graph {
private:
    map<Node, vector<Node>> graph; // relação de um Node com uma lista de Nodes (seus adjacentes)
    set<Node> markedNodes; // conjunto de nós marcados

public:
    Graph(int linha, int coluna, vector<vector<Node>> lab);

    // Retorna lista de adjacentes de determinado Node
    vector<Node> getAdj(const Node& v) const;

    // Retorna os vértices do grafo
    vector<Node> getVerts() const;

    // Retorna lista de marked
    const set<Node>& getMarked()const;

    // Marca um nó como visitado
    void setMarked(const Node& n);

    // Adiciona ligação (aresta) ao grafo
    void addEdge(const Node& v, const Node& w);
};