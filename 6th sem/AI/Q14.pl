% Prolog program to implement sumlist(L, S) so that S is the sum of a given list L.

sum([],0).					% base case when list is empty
sum([H|T],R) :- sum(T,R1), R is H+R1.		% Result = head of list + recursive sum of tailof list

go :-   write('Enter the list : '),
	read(L),nl,				% reading list
	sum(L,R), write(R).
