#ifndef RULE_ENGINE_H
#define RULE_ENGINE_H

#include "ast.h"
#include <string>
#include <vector>
#include <unordered_map>

std::shared_ptr<Node> create_rule(const std::string& rule_string);
std::shared_ptr<Node> combine_rules(const std::vector<std::string>& rules);
bool evaluate_rule(const std::shared_ptr<Node>& ast, const std::unordered_map<std::string, int>& data);

#endif // RULE_ENGINE_H
