rev([],[]).
rev([H|T],R) :- rev(T,R1), append(R1,[H],R). 

go :-   write('Enter the list : '),
	read(L),nl,
	rev(L,R), write(R).
