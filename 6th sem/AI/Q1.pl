% prolog program to calculate the sum of two numbers 
sum(A,B,R) :- R is A+B.

go :-   write('Enter first number : '),
	read(A),nl,				% reading 1st number 
	write('Enter Second number : '),
	read(B),nl,				% reading 1st number
	sum(A,B,R),				% R = A+B
	write('The result is : '), write(R).	% writing result R
