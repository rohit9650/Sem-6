max(X,Y,M):- X>Y,M is X,!.
max(_,Y,M):- M is Y.

go :-   write('Enter first number : '),
	read(A),nl,
	write('Enter Second number : '),
	read(B),nl,
	max(A,B,R),
	write('The Maximum is : '),write(R).
