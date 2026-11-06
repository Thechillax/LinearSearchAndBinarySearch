# LinearSearchAndBinarySearch

This repository/project is assigned to me and my fellow group members, we are prompted to solve three small computing problems applying the knowledge taught to us by our lecturer. The topics included are Fundamental of logics and Proofs and Algorithm covered in Discrete Mathematics. The computing problems are divided by tasks 
The tasks are as follows.

# Task 1: Access Control Policy Checker [Fundamental of Logic]

Scenario:
A campus web portal grants access if the user is authenticated AND (the user has the admin role OR the request comes from the campus network). Let p = the user is
authenticated, q = the user has the admin role, r = the request comes from the campus network.

From the provided policy. our task ranges from writing a propositional formula, A in p, q and r. We are also required to make a truth table by hand and as a formula in C++. It is to compare the printed table in C++ and our handwritten table. Additionally, we are required to predict by hand whether the formula is equivalent to the provided formulas, The formulas are as follows:

i) ¬(¬p ∨ ¬(q ∨ r))

ii) (p ∧ q) ∨ (p ∧ r)

iii) (p ∨ q) ∧ (p ∨ r)

We are to test the Formulas each row by row in our program and name the law for each equivalent pair. If one of the provided formula is not equivalent to Formula A, it is necessary to provide a counterexample of the pair. lastly, we are to inspect and correct a provided code written by a C++ developer, we should be able to explain how it was grouped, show every row where it disagrees with A and write in one sentence what this means for security. Compile the provided code before correcting it to report whether the line is warned or not. The line in this case:

bool grant = p && q || r;

# Task 2 : incident note-reasoning Checker [Rules Of inference]

An argument is valid if no truth assignment makes all premises true and the conclusion false. We are provided several arguments and conclusions and is tasked to translate each arguments into propositional logic and predict whether it is valid or invalid. The provided argument are as follows:

A1: If the server is down, then the site is unreachable. The server is down. Therefore
the site is unreachable.

A2: If the password is weak, then the account is compromised. The account is
compromised. Therefore the password is wea

A3: If the file is infected, then the antivirus raises an alert. The antivirus raised no alert.
Therefore the file is not infected

A4: The bug is in the frontend or in the backend. The bug is not in the frontend. If the
bug is in the backend, then the API returns an error. Therefore the API returns an error.

We are to use the provided line of code, "bool isValidArgument(const vector<Formula>& premises, const Formula& conclusion, int n, Table& counter)" to write A1 to A4 as C++ formulas and run them which should returns true if the argument is valid and we are tasked to put every counterexample under "counter". Explain in two or three sentences on how it works. Moving on, we are to print out the results in a table and compare it with our predictions. For each invalid arguments, show the counterexample row and describe it in words. Lastly, we are to state the name of the rules of inference used and the fallacy of each invalid arguments

