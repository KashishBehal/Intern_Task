#ifndef AST_H
#define AST_H

#include <string>
#include <memory>

struct Node {
    std::string node_type; // "operator" or "operand"
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::string value;

    Node(const std::string& type, std::shared_ptr<Node> l = nullptr, std::shared_ptr<Node> r = nullptr, const std::string& val = "")
        : node_type(type), left(l), right(r), value(val) {}
};

#endif // AST_H
