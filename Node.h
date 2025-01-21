#include <iostream>

// Node -> elementos armazenados e ligações
class Node {
private:
    int x, y;  // coordenada
    char info; // char relacionado

public:
    Node();
    Node(int x, int y, char info);
    int getX() const;
    int getY() const;
    char getInfo() const;
    bool operator==(const Node& n) const;
    bool operator<(const Node& n) const;
};