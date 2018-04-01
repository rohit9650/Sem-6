% prolog program to implement insert_nth(I, N, L, R) that inserts an item I into Nth
% position of list L to generate a list R.

insert_nth(I,1,L,R) :- append([I],L,R).						% base case when pos is 1;  append value I in the beginning of L
insert_nth(I,N,[H|T],R) :- N1 is N-1, insert_nth(I,N1,T,R1), append([H],R1,R).	% reducing pos by 1; calling insert_nth with reduced pos and tail of list  											% than appending its result to head of list 

go :-   write('Enter the list : '),
	read(L),nl,								% reading list L
	write('Enter the position : '),
	read(N),nl,								% reading position N
	write('Enter the value to insert : '),
	read(I),nl,								% reading the value to insert I
	insert_nth(I,N,L,R), write(R),!.
