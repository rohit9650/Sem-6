% Prolog program to implement power (Num,Pow, Ans) : where Num is raised to the power Pow to get Ans.

pow(1,_,R):- R is 1, !.					% base case, when base is 1
pow(N,1,R):- R is N, !.					% base case, when exponent is 1
pow(N,0,R):- R is 1, !.					% base case, when exponent is 0
pow(N,E,R):- E1 is E-1, pow(N,E1,R1), R is N*R1, !.	% recursive defination of power

go :-   write('Enter base number : '),
	read(N),nl,					% read base number
	write('Enter exponent number : '),
	read(E),nl,					% read exponent number
	pow(N,E,R),
	write('The result is : '),write(R).
