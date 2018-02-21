value([H|_], 1, R) :- R is H.
value([H|T], N, R) :- N1 is N-1, value(T,N1,R).

go :-   write('Enter the list : '),
	read(L),nl,
	write('Enter the position : '),
	read(N),nl,
	value(L,N,R), write(R).
