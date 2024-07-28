#include "rule_engine.h"
#include <sstream>
#include <stack>
#include <iostream>

std::shared_ptr<Node> create_rule(const std::string& rule_string) {
    std::istringstream iss(rule_string);
    std::stack<std::shared_ptr<Node>> stack;
    std::string token;

    while (iss >> token) {
        if (token == "AND" || token == "OR") {
            auto right = stack.top(); stack.pop();
            auto left = stack.top(); stack.pop();
            auto node = std::make_shared<Node>("operator", left, right, token);
            stack.push(node);
        } else {
            auto node = std::make_shared<Node>("operand", nullptr, nullptr, token);
            stack.push(node);
        }
    }

    return stack.empty() ? nullptr : stack.top();
}

std::shared_ptr<Node> combine_rules(const std::vector<std::string>& rules) {
    std::vector<std::shared_ptr<Node>> asts;
    for (const auto& rule : rules) {
        asts.push_back(create_rule(rule));
    }

    while (asts.size() > 1) {
        auto left = asts.back(); asts.pop_back();
        auto right = asts.back(); asts.pop_back();
        auto combined = std::make_shared<Node>("operator", left, right, "AND");
        asts.push_back(combined);
    }

    return asts.empty() ? nullptr : asts.front();
}

bool evaluate_rule(const std::shared_ptr<Node>& ast, const std::unordered_map<std::string, int>& data) {
    if (ast->node_type == "operator") {
        bool left_value = evaluate_rule(ast->left, data);
        bool right_value = evaluate_rule(ast->right, data);

        if (ast->value == "AND") {
            return left_value && right_value;
        } else if (ast->value == "OR") {
            return left_value || right_value;
        }
    } else if (ast->node_type == "operand") {
        std::istringstream iss(ast->value);
        std::string attribute, op;
        int threshold;
        iss >> attribute >> op >> threshold;

        if (op == ">") {
            return data.at(attribute) > threshold;
        } else if (op == "<") {
            return data.at(attribute) < threshold;
        } else if (op == "=") {
            return data.at(attribute) == threshold;
        }
    }

    return false;
}
