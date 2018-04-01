% program in PROLOG to implement remove_dup (L, R) where L denotes the list with some
% duplicates and the list R denotes the list with duplicates removed.

remove_duplicate([H|T],R1) :- member(H,T), remove_duplicate(T,R1). 	% checking if head is member of tail if yes recursively call remove_duplicate on tail
remove_duplicate([H|T],[H|R]) :- remove_duplicate(T,R). 		% checking if head already present in sub-result if yes than call remove_duplicate on tail
remove_duplicate([],[]).						% base case when list is empty

go :-   write('Enter the list : '),
	read(L),nl,							% reading list
	remove_duplicate(L,R), write(R),!.
