remove(X,[H|T],R) :- X\=H, remove(X,T,R).
remove(X,[H|T],T).

sub_list([H|T],L) :- member(H,L), remove(H,L,R), sub_list(T,R), !.
sub_list([],L) :- !.

go :-   write('Enter the list : '),
	read(L),nl,
	write('Enter the sub-list : '),
	read(S),nl,
	sub_list(S,L).
