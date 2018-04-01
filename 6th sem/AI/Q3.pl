% program in PROLOG to implement factorial (N, F) where F represents the factorial of a number N.

factorial(0,0).							% base case
factorial(1,1).							% base case
factorial(N,R):- N1 is N-1, factorial(N1,R1), R is R1*N,!.	% recursive defination of factorial

go :-   write('Enter number : '),
	read(N),nl,				% reading the number , it should be greater than 0
	factorial(N,R),
	write('The Factorial is : '),write(R).
