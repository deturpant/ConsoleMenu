#include <iostream>
#include <list>
#include "src/MyMenu.h"
#include "src/MenuItem.h"
using namespace KVA;

void func1(any &param) {
    auto lst = any_cast<list<string>>(param);
    // кастим наш param под лист из стрингов
    cout << "It`s func num 1\n";
    for (string s : lst) {
        cout << s << endl;
    }
}
void func2(any &param) {
    auto lst = any_cast<list<string>>(param);
    cout << "It`s func num 2\n";
    lst.push_back("test");
    for (string s : lst) {
        cout << s << endl;
    }
}
void func3(any &param) {
    auto lst = any_cast<list<string>>(param);
    cout << "It`s func num 3\n";

}
void func4(any &param) {
    auto lst = any_cast<list<string>>(param);
    cout << "It`s func num 4\n";

}
const int ITEMS = 4;

int main() {
    list<string> lst = {"kek", "lol", "volodya"};

    MenuItem items[ITEMS] {
        MenuItem{"Func1", func1},
        MenuItem{"Func2", func2},
        MenuItem{"Func3", func3},
        MenuItem{"Func4", func4}
    };
    MyMenu menu("Menu", items, ITEMS);
    any param = lst;
    while (true) {
        menu.runCommand(param);
    }

    return 0;
}
