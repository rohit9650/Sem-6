% Prolog program to implement GCD of two numbers.

gcd(0,_,R):- R is 0, !.					% base case when one number is 0
gcd(_,0,R):- R is 0, !.					% base case when one number is 0
gcd(X,X,R):- R is X, !.					% base case when both number are same
gcd(A,B,R):- A>B, A1 is A-B, gcd(A1,B,R), !.		% cut to stop backtracking
gcd(A,B,R):- B1 is B-A, gcd(A,B1,R).

go :-   write('Enter first number : '),
	read(A),nl,					% reading first number
	write('Enter Second number : '),
	read(B),nl,					% reading second number
	gcd(A,B,R),
	write('The GCD is : '),write(R).
