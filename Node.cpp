#include "Node.h"

Node::Node(){}
Node::Node(int x, int y, char info) : x(x), y(y), info(info){}

int Node::getX() const { return x; }
int Node::getY() const { return y; }
char Node::getInfo() const { return info; }

// Sobrecarga para <map>
bool Node::operator==(const Node& n) const {
    return x == n.getX() && y == n.getY();
}
bool Node::operator<(const Node& n) const {
    if (x == n.getX()) {
        return y < n.getY();
    }
    return x < n.getX();
}