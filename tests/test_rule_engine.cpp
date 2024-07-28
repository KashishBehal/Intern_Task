#include "rule_engine.h"
#include <cassert>
#include <unordered_map>

void test_create_rule() {
    std::string rule = "age > 30 AND department = 'Sales'";
    auto ast = create_rule(rule);
    assert(ast != nullptr);
}

void test_combine_rules() {
    std::string rule1 = "age > 30 AND department = 'Sales'";
    std::string rule2 = "salary > 50000 OR experience > 5";
    auto combined_ast = combine_rules({rule1, rule2});
    assert(combined_ast != nullptr);
}

void test_evaluate_rule() {
    std::string rule = "age > 30 AND department = 'Sales'";
    auto ast = create_rule(rule);
    std::unordered_map<std::string, int> data = {{"age", 35}, {"department", 'Sales'}};
    assert(evaluate_rule(ast, data) == true);
}

int main() {
    test_create_rule();
    test_combine_rules();
    test_evaluate_rule();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
