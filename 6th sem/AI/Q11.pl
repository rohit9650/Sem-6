% Prolog program to implement conc (L1, L2, L3) where L2 is the list to be appended with L1 to get the resulted list L3.

conc([],L3,L3).						% base case when list1 is empty
conc([H|T],L2,[H|L]) :- conc(T,L2,L). 			% transferring head of L1 to L3 keeping L2 same than calling conc again with reduced L1 and gained L3

go :-   write('Enter first List : '),
	read(L1),nl,					% reading first list
	write('Enter second List : '),
	read(L2),nl,					% reading second list
	conc(L1,L2,L3), write(L3).
	
