maximum([X],X).
maximum([H|T],R) :- maximum(T,R1), R1 > H, R is R1.
maximum([H|T],R) :- R is H.

go :-   write('Enter the list : '),
	read(L),nl,
	maximum(L,R), write(R),!.
