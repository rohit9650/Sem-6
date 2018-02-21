pow(1,_,R):- R is 1, !.
pow(N,1,R):- R is N, !.
pow(N,0,R):- R is 1, !.
pow(N,E,R):- E1 is E-1, pow(N,E1,R1), R is N*R1, !.

go :-   write('Enter base number : '),
	read(N),nl,
	write('Enter exponent number : '),
	read(E),nl,
	pow(N,E,R),
	write('The result is : '),write(R).
