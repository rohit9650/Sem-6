memberOf(X,[X|_]) :- !.
memberOf(X,[_|T]) :- memberOf(X, T). 

go :-   write('Enter the list : '),
	read(L),nl,
	write('Enter any element : '),
	read(X),nl,
	memberOf(X,L), write('It is an element of list.'); write('It is not element of list.').
