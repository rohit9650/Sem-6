delete_nth(1,[H|T],T).
delete_nth(N,[H|T],R) :- N1 is N-1, delete_nth(N1,T,R1), append([H],R1,R).

go :-   write('Enter the list : '),
	read(L),nl,
	write('Enter the position : '),
	read(N),nl,
	delete_nth(N,L,R), write(R),!.
