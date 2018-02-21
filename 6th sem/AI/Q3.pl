factorial(1,R):- R is 1.
factorial(N,R):- N1 is N-1, factorial(N1,R1), R is R1*N,!.

go :-   write('Enter number : '),
	read(N),nl,
	factorial(N,R),
	write('The Factorial is : '),write(R).
