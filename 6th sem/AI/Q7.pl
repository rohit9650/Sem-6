% Prolog program to implement mul (N1, N2, R) : where N1 and N2 denotes the numbers to be multiplied and R represents the result.

mul(X,Y,R):- X>Y, succ_addition(X,Y,Res), R is Res, !.			% X is max so that it is added minimum number of times
mul(X,Y,R):- succ_addition(Y,X,Res), R is Res, !.

succ_addition(X,1,R):- R is X.
succ_addition(X,0,R):- R is 0.						% base case 
succ_addition(X,Y,R):- Y1 is Y-1, succ_addition(X,Y1,R1), R is X+R1.	% adding succissively

go :-   write('Enter first number : '),
	read(A),nl,							% reading number 1
	write('Enter Second number : '),
	read(B),nl,							% reading number 1
	mul(A,B,R),
	write('The result is : '),write(R).
