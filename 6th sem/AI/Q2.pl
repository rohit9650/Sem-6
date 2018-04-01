% Prolog program to implement max(X, Y, M) so that M is the maximum of two numbers X and Y.

max(X,Y,M):- X>Y,M is X,!.	% cut to stop backtracking
max(_,Y,M):- M is Y.

go :-   write('Enter first number : '),
	read(A),nl,				% reading 1st number
	write('Enter Second number : '),
	read(B),nl,				% reading 1st number
	max(A,B,R),
	write('The Maximum is : '),write(R).	% printing max
