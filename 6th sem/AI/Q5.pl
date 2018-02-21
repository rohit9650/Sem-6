gcd(0,_,R):- R is 0, !.
gcd(_,0,R):- R is 0, !.
gcd(X,X,R):- R is X, !.
gcd(A,B,R):- A>B, A1 is A-B, gcd(A1,B,R), !.
gcd(A,B,R):- B1 is B-A, gcd(A,B1,R).

go :-   write('Enter first number : '),
	read(A),nl,
	write('Enter Second number : '),
	read(B),nl,
	gcd(A,B,R),
	write('The GCD is : '),write(R).
