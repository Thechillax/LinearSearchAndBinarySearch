// DFDU 1503 Discrete Mathematics - Group Assignment
// Group no: ______
// Members (name and matric no): 1. ____________________  2. ____________________
//                               3. ____________________  4. ____________________
//
// HOW TO USE THIS FILE
//  * Keep everything in this ONE file. Do not rename any function or change its parameters:
//    they are tested against hidden inputs.
//  * truthTable and isValidArgument are PROVIDED. Read them, understand them, use them, but do not
//    change them. You write linearSearch and binarySearch, and the code in the task functions.
//    Each member does the Design Sheet on paper BEFORE the group codes.
//  * Fill in every TODO. You may add helper functions of your own.
//  * Compile with C++11 or later, e.g.  g++ -std=c++11 -Wall -Wextra dm_assignment.cpp
//    (works in OnlineGDB, JDoodle, Code::Blocks, Visual Studio, etc.)
//  * Read the compiler warnings. They often point to a real bug.
//  * main() runs selfTest() first. All PASS does NOT mean your solution is correct;
//    it only checks the function signatures and a few simple cases.
//  * Submit this file as  GroupNo_DM_Code.cpp  together with your group PDF report.

#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <chrono>
#include <string>
using namespace std;

typedef vector<bool> Assignment;                       // one truth assignment = one row
typedef vector<Assignment> Table;                      // all rows
typedef function<bool(const Assignment&)> Formula;     // a formula evaluated on one row; v[0]=first variable

bool imp(bool a, bool b) { return !a || b; }           // conditional a -> b

// ---------------------------------------------------------------- helpers (given)
string bits(const Assignment& a) {                     // prints a row as 1 0 1 ...
    string s;
    for (size_t i = 0; i < a.size(); i++) s += a[i] ? "1 " : "0 ";
    return s;
}

// ---------------------------------------------------------------- PROVIDED FUNCTIONS (do not change)
// All 2^n rows, n columns. Row 0 is all TRUE, the last row is all FALSE (textbook order).
// Column k is variable k; the first column changes slowest. (Trace truthTable(2) by hand in Part C.)
Table truthTable(int n) {
    int rows = 1 << n;
    Table T(rows, Assignment(n));
    for (int r = 0; r < rows; r++)
        for (int k = 0; k < n; k++)
            T[r][k] = !((r >> (n - 1 - k)) & 1);
    return T;
}

// valid = true if NO row makes every premise true and the conclusion false.
// counter receives every such row (every counterexample).
bool isValidArgument(const vector<Formula>& premises, const Formula& conclusion,
                     int n, Table& counter) {
    Table T = truthTable(n);
    counter.clear();
    for (size_t r = 0; r < T.size(); r++) {
        bool allPremises = true;
        for (size_t k = 0; k < premises.size(); k++)
            if (!premises[k](T[r])) { allPremises = false; break; }
        if (allPremises && !conclusion(T[r])) counter.push_back(T[r]);
    }
    return counter.empty();
}

// ---------------------------------------------------------------- YOUR FUNCTIONS
// Task 3.1. (YOU WRITE THIS, from your flowchart) Positions are 1-based; return 0 if x is absent.
// count = number of list elements examined (one per loop iteration).
int linearSearch(const vector<int>& A, int x, int& count) {
    count = 0;
    // TODO
    (void)A; (void)x;
    return 0;
}

// Binary search on a sorted list. You MUST use  mid = (lo + hi) / 2  with lo = 1 and hi = n,
// and the element at position mid is A[mid - 1].
int binarySearch(const vector<int>& A, int x, int& count) {
    count = 0;
    // TODO
    (void)A; (void)x;
    return 0;
}

// ---------------------------------------------------------------- TASKS (write your code here)
void task1() {
    cout << "=== TASK 1 ===\n";
    // p = user is authenticated, q = user has admin role, r = request from campus network
    // Design Sheet first: symbols, formula A, your hand-made truth table, your predictions for (i)-(iii).
    // TODO 1.1 define the policy formula A as a Formula (v[0]=p, v[1]=q, v[2]=r)
    // TODO 1.2 use truthTable(3) to print the complete truth table of A, then compare it with your hand table
    // TODO 1.3 test equivalence (i), (ii), (iii) row by row; print the counterexample rows
    // TODO 1.4 the junior developer wrote:   bool grant = p && q || r;
    //          print every row where it disagrees with A, then write the corrected statement
}

void task2() {
    cout << "=== TASK 2 ===\n";
    // Design Sheet first: your symbols, formulas and predicted validity (with rule or fallacy) for A1-A4.
    // TODO 2.1 define A1..A4 as Formulas, then call isValidArgument on each
    // TODO 2.3 print a results table; for each invalid argument print its counterexample row
}

void task3() {
    cout << "=== TASK 3 ===\n";
    // Design Sheet first: a flowchart (or pseudocode) of both searches, and a hand trace of
    //                     binary search for target 11 on {2,4,...,20}.
    // TODO 3.2 test both searches on A = {2,4,...,20} (targets 2, 20, 10, 11, 1, 30) and on a
    //          list of one element (target present and absent). Print idx and count for each test.
}

void taskC() {
    cout << "=== PART C2 ===\n";
    // TODO time the PROVIDED truthTable(n) (and a pass over its rows) for n = 10, 12, 14, 16, 18 using
    //      <chrono>. Print n, 2^n and the time, then estimate the rows needed for n = 40.
}

// ---------------------------------------------------------------- self test (signatures only)
void check(const string& name, bool ok) { cout << (ok ? "  PASS  " : "  FAIL  ") << name << "\n"; }

void selfTest() {
    cout << "Self test (checks signatures and a few simple cases only):\n";
    Table c;
    int cnt = 0;
    check("truthTable(3) has 8 rows", truthTable(3).size() == 8);
    check("isValidArgument: p |- p is valid",
          isValidArgument({ [](const Assignment& v) { return (bool)v[0]; } },
                          [](const Assignment& v) { return (bool)v[0]; }, 1, c));
    check("linearSearch finds 15 at position 3 after 3 steps", linearSearch({ 4, 8, 15 }, 15, cnt) == 3 && cnt == 3);
    check("binarySearch finds 8 at position 2 after 1 step", binarySearch({ 4, 8, 15 }, 8, cnt) == 2 && cnt == 1);
    cout << "\n";
}

int main() {
    selfTest();
    task1();
    task2();
    task3();
    taskC();
    return 0;
}