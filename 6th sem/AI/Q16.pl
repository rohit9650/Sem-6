% Prolog program to implement nth_element (N, L, X) where N is the desired position, L is
% a list and X represents the Nth element of L.

value([H|_], 1, R) :- R is H.				% base case when pos=1; element is head so R is H
value([H|T], N, R) :- N1 is N-1, value(T,N1,R).		% reducing pos by 1 and checking it in tail; recursively reducing pos so that eventually it become 1
							% thus Head will be returned
go :-   write('Enter the list : '),
	read(L),nl,					% reading list
	write('Enter the position : '),
	read(N),nl,					% reading the position
	value(L,N,R), write(R).
