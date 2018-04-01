% Prolog program to implement reverse (L, R) where List L is original and List R is reversed list.

rev([],[]).						% base case when given list is empty
rev([H|T],R) :- rev(T,R1), append(R1,[H],R). 		% appending head of list after the reverse of tail part to finally put into result

go :-   write('Enter the list : '),
	read(L),nl,					% reading the list
	rev(L,R), write(R).
