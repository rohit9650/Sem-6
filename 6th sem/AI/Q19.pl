insert_nth(I,1,L,R) :- append([I],L,R).
insert_nth(I,N,[H|T],R) :- N1 is N-1, insert_nth(I,N1,T,R1), append([H],R1,R).

go :-   write('Enter the list : '),
	read(L),nl,
	write('Enter the position : '),
	read(N),nl,
	write('Enter the value to insert : '),
	read(I),nl,
	insert_nth(I,N,L,R), write(R),!.
