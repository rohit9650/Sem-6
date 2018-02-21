sum([],0).
sum([H|T],R) :- sum(T,R1), R is H+R1.

go :-   write('Enter the list : '),
	read(L),nl,
	sum(L,R), write(R).
