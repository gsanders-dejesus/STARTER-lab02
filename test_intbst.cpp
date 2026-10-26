#include "intbst.h"
 
#include <iostream>
using std::cout;
 
void check(const char* name, bool ok) {
    if (ok) {
        cout << "PASS: " << name << "\n";
    }
    else {
        cout << "FAIL: " << name << "\n";
    }
}
 
int main() {
    IntBST t;
 
    check("insert 50", t.insert(50));
    t.insert(30); t.insert(70); t.insert(20);
    t.insert(40); t.insert(60); t.insert(80);
    check("insert duplicate returns false", !t.insert(40));
 
    cout << "\nPreOrder (expect 50 30 20 40 70 60 80): ";
    t.printPreOrder();
    cout << "\nInOrder (expect 20 30 40 50 60 70 80): ";
    t.printInOrder();
    cout << "\nPostOrder (expect 20 40 30 60 80 70 50): ";
    t.printPostOrder();
    cout << "\n\n";
 
    check("sum == 350", t.sum() == 350);
    check("count == 7", t.count() == 7);
 
    check("contains 60", t.contains(60));
    check("does not contain 65", !t.contains(65));
 
    check("predecessor of 50 is 40", t.getPredecessor(50) == 40);
    check("predecessor of 70 is 60", t.getPredecessor(70) == 60);
    check("predecessor of 20 is none", t.getPredecessor(20) == -1);
 
    check("successor of 50 is 60", t.getSuccessor(50) == 60);
    check("successor of 20 is 30", t.getSuccessor(20) == 30);
    check("80 has no successor", t.getSuccessor(80) == -1);
 
    check("remove leaf 20", t.remove(20) && !t.contains(20));
    check("trying to remove 99 returns false", !t.remove(99));
    t.insert(65);
    check("remove node with one child (60)", t.remove(60) && !t.contains(60) && t.contains(65));
    check("remove node with two children (50)", t.remove(50) && !t.contains(50));
 
    cout << "\nInOrder after removals (expect 30 40 65 70 80): ";
    t.printInOrder();
    cout << "\n";
    check("count == 5 after removals", t.count() == 5);
 
    return 0;
}
