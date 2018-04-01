% Program in PROLOG to implement sublist(S, L) that checks whether the list S is the
% sublist of list L or not. (Check for sequence or the part in the same order).

remove(X,[H|T],R) :- X\=H, remove(X,T,R).				% utility predicate to remove the given element from the result and returning the reduced list
remove(X,[H|T],T).

sub_list([H|T],L) :- member(H,L), remove(H,L,R), sub_list(T,R), !.	% checking the head of list if member of L, if yes removing it and calling sublist on reduced 										% lists
sub_list([],L) :- !.							% base case empty list is sublist of every list

go :-   write('Enter the list : '),
	read(L),nl,							% reading list L
	write('Enter the sub-list : '),
	read(S),nl,							% reading sublist S
	sub_list(S,L).
