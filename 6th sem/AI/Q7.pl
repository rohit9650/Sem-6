mul(X,Y,R):- X>Y, succ_addition(X,Y,Res), R is Res, !.
mul(X,Y,R):- succ_addition(Y,X,Res), R is Res, !.

succ_addition(X,1,R):- R is X.
succ_addition(X,0,R):- R is 0.
succ_addition(X,Y,R):- Y1 is Y-1, succ_addition(X,Y1,R1), R is X+R1.

go :-   write('Enter first number : '),
	read(A),nl,
	write('Enter Second number : '),
	read(B),nl,
	mul(A,B,R),
	write('The result is : '),write(R).
