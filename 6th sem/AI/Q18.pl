% Prolog program to implement maxlist(L, M) so that M is the maximum number in the list

maximum([X],X).							% base case when list contains only one element; it is max
maximum([H|T],R) :- maximum(T,R1), R1 > H, R is R1.		% R1 is maximum in tail checking it with head give the max element , R is R1
maximum([H|T],R) :- R is H.					% else R is H

go :-   write('Enter the list : '),
	read(L),nl,						% reading list
	maximum(L,R), write(R),!.
