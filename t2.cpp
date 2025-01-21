#include "Graph.h"
#include <queue>
#include <iomanip>
#include <ctime>  
#include <vector>

using namespace std;

//funcao que realiza caminhamento
void bfs(Graph& g, Node& v, char& c, int& maior) {
    
    vector<int> cont(5,0);//array com cont de personagem conforme pos-> cont[0] = 'A', cont[1] = 'B', cont[2] = 'C', cont[3] = 'D', cont[4] = 'E'

    queue<Node> fila;//cria fila para armzenar adjacentes garantido FIFO
    fila.push(v);//adiciona nodo primario na fila
    g.setMarked(v);//altera primario como marcado

    while (!fila.empty()) {
        Node n = fila.front();//pega primeiro elemento da fila
        fila.pop();//retira primeiro elemento da fila

        switch (n.getInfo()) {//conforma info da celula, conta na posicao conforme o personagem
            case 'A': cont[0]++;break;
            case 'B': cont[1]++;break;
            case 'C': cont[2]++;break;
            case 'D': cont[3]++;break;
            case 'E': cont[4]++;break;
        }

        for (auto& w : g.getAdj(n)) {
            if (g.getMarked().find(w) == g.getMarked().end()) {//para cada adjacente w de v nao marcado
                g.setMarked(w);//altera como marcado
                fila.push(w);//adiciona na lista para garantir o caminhamento dos adjacentes de w
            }
        }
    }

    for (int i = 0; i < 5; i++) {//verifica qual maior elemento 
        if (cont[i] > maior) {
            maior = cont[i];
            c = 'A' + i;//com auxilio do indice, verifica qual letra do maior. EX: se maior no cont[1] -> i = 1, entao 'A'- 1 = 'B'
        }
    }
}

void criaMatriz(int& linha, int& coluna, vector<vector<Node>>& lab){
    char c;

    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            cin >> c;
            lab[i][j] = Node(i, j, c);//cria nodo na determinada pos de lab
        }
    }
}

int main() {
    int linha, coluna, maior = 0, componente = 0;//variavies
    char c;

    cin >> linha >> coluna;//leitura da linha e da coluna do terminal
    cin.ignore();//ignora endl do arq

    vector<vector<Node>> lab(linha, vector<Node>(coluna));//matriz de Node

    criaMatriz(linha, coluna, lab);//para cada dado de entrada, cria um Node e adiciona em Lab

    Graph g(linha, coluna, lab);//cria graph com base em lab

    for (auto& v : g.getVerts()) {//para cada vertice de g
        if (g.getMarked().find(v) == g.getMarked().end()) {//verifica se ja foi marcado
            bfs(g, v, c, maior);//faz o caminhamento BFS a partir dele
            componente++;//conta um componente
        }
    }

    cout << "Componentes: " << componente << ". Personagem com mais frequencia: " << c << maior;

    return 0;
}