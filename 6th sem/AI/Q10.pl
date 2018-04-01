% Prolog program to implement memb(X, L): to check whether X is a member of L or not.

memberOf(X,[X|_]) :- !.				% base case when head is the same to be searched
memberOf(X,[_|T]) :- memberOf(X, T). 		% ignoring head and matching the X in rest of list

go :-   write('Enter the list : '),
	read(L),nl,				% reading list
	write('Enter any element : '),
	read(X),nl,				% reading the element to search
	memberOf(X,L), write('It is an element of list.'); write('It is not element of list.').
