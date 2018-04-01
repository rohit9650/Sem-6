% Prolog program to implement delete_nth (N, L, R) that removes the element on Nth
% position from a list L to generate a list R.

delete_nth(1,[H|T],T).								% base case if pos is 1, make result same as tail of list
delete_nth(N,[H|T],R) :- N1 is N-1, delete_nth(N1,T,R1), append([H],R1,R).	% reducing pos by 1, deleting this pos from tail, appending the head od this list
										% with previous result 

go :-   write('Enter the list : '),
	read(L),nl,								% reading list L
	write('Enter the position : '),
	read(N),nl,								% reading position N
	delete_nth(N,L,R), write(R),!.
