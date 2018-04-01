% program in PROLOG to implement delete_all (X, L, R) where X denotes the element
% whose all occurrences has to be deleted from list L to obtain list R.

delete_all(X,[H|T],R) :- delete_all(X,T,R1), X\=H, append([H],R1,R). 	% if head isn't same as X, calling delete_all with tail of list than appending head of list 
									% with this result
delete_all(X,[H|T],R) :- delete_all(X,T,R).				% else remove the head and call delete all on tail of list
delete_all(X,[],[]).							% base case when list is empty; result will be empty list itself

go :-   write('Enter the list : '),
	read(L),nl,							% reading the list L
	write('Enter the element to be deleted : '),
	read(X),nl,							% reading the element to be deleted X
	delete_all(X,L,R), write(R), !.
