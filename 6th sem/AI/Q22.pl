delete_all(X,[H|T],R) :- delete_all(X,T,R1), X\=H, append([H],R1,R). 
delete_all(X,[H|T],R) :- delete_all(X,T,R).
delete_all(X,[],[]).

go :-   write('Enter the list : '),
	read(L),nl,
	write('Enter the element to be deleted : '),
	read(X),nl,
	delete_all(X,L,R), write(R), !.
