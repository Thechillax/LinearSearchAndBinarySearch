# LinearSearchAndBinarySearch

This repository/project is assigned to me and my fellow group members, we are prompted to solve three small computing problems applying the knowledge taught to us by our lecturer. The topics included are Fundamental of logics and Proofs and Algorithm covered in Discrete Mathematics. The computing problems are divided by tasks 
The tasks are as follows.

# Task1: Access Control Policy Checker
Scenario:
A campus web portal grants access if the user is authenticated AND (the user has the admin role OR the request comes from the campus network). Let p = the user is
authenticated, q = the user has the admin role, r = the request comes from the campus network.

From the provided policy. our task ranges from writing a propositional formula, A in p, q and r. We are also required to make a truth table by hand and as a formula in C++. It is to compare the printed table in C++ and our handwritten table. Additionally, we are required to predict by hand whether the formula is equivalent to the provided formulas, The formulas are as follows:

i) ¬(¬p ∨ ¬(q ∨ r))

ii) (p ∧ q) ∨ (p ∧ r)

iii) (p ∨ q) ∧ (p ∨ r)

We are to test the Formulas each row by row in our program and name the law for each equivalent pair. If one of the provided formula is not equivalent to Formula A, it is necessary to provide a counterexample of the pair. lastly, we are to inspect and correct a provided code written by a C++ developer, we should be able to explain how it was grouped, show every row where it disagrees with A and write in one sentence what this means for security. Compile the provided code before correcting it to report whether the line is warned or not. The line in this case:

bool grant = p && q || r;
