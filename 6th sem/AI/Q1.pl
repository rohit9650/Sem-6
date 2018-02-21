sum(A,B,R) :- R is A+B.

go :-   write('Enter first number : '),
	read(A),nl,
	write('Enter Second number : '),
	read(B),nl,
	sum(A,B,R),
	write('The result is : '), write(R).
