#include "rule_engine.h"
#include <iostream>
#include <unordered_map>

int main() {
    std::string rule1 = "age > 30 AND department = 'Sales' OR age < 25 AND department = 'Marketing' AND salary > 50000 OR experience > 5";
    std::string rule2 = "age > 30 AND department = 'Marketing' AND salary > 20000 OR experience > 5";

    auto ast1 = create_rule(rule1);
    auto ast2 = create_rule(rule2);

    std::vector<std::string> rules = {rule1, rule2};
    auto combined_ast = combine_rules(rules);

    std::unordered_map<std::string, int> data1 = {{"age", 35}, {"department", 'Sales'}, {"salary", 60000}, {"experience", 3}};
    std::unordered_map<std::string, int> data2 = {{"age", 22}, {"department", 'Marketing'}, {"salary", 45000}, {"experience", 2}};
    std::unordered_map<std::string, int> data3 = {{"age", 28}, {"department", 'HR'}, {"salary", 30000}, {"experience", 1}};

    std::cout << "Evaluation result for data1: " << evaluate_rule(combined_ast, data1) << std::endl;
    std::cout << "Evaluation result for data2: " << evaluate_rule(combined_ast, data2) << std::endl;
    std::cout << "Evaluation result for data3: " << evaluate_rule(combined_ast, data3) << std::endl;

    return 0;
}
