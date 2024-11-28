/* Bagian 1 */
/* Deklarasi Fakta */
% pria
pria(qika).
pria(panji).
pria(shelby).
pria(barok).
pria(aqua).
pria(eriq).
pria(francesco).

% wanita
wanita(hinatsuru).
wanita(makio).
wanita(suma).
wanita(yennefer).
wanita(roxy).
wanita(suzy).
wanita(frieren).
wanita(ruby).
wanita(aihoshino).
wanita(eve).

% usia
usia(qika, 109).
usia(panji, 124).
usia(shelby, 42).
usia(barok, 59).
usia(aqua, 66).
usia(eriq, 69).
usia(francesco, 25).
usia(hinatsuru, 105).
usia(makio, 96).
usia(suma, 86).
usia(yennefer, 61).
usia(roxy, 70).
usia(suzy, 23).
usia(frieren, 90).
usia(ruby, 63).
usia(aihoshino, 48).
usia(eve, 5).

% menikah
menikah(qika, hinatsuru).
menikah(hinatsuru, qika).

menikah(qika, makio).
menikah(makio, qika).

menikah(barok, roxy).
menikah(roxy, barok).

menikah(panji, frieren).
menikah(frieren, panji).

menikah(eriq, ruby).
menikah(ruby, eriq).

menikah(francesco, suzy).
menikah(suzy, francesco).


% anak
anak(shelby, qika).
anak(shelby, hinatsuru).
anak(yennefer, qika).
anak(yennefer, hinatsuru).
anak(barok, qika).
anak(barok, makio).
anak(suzy, barok).
anak(suzy, roxy).
anak(aqua, panji).
anak(aqua, frieren).
anak(ruby, panji).
anak(ruby, frieren).
anak(aihoshino, ruby).
anak(aihoshino, eriq).
anak(eve, suzy).
anak(eve, francesco).


/* Deklarasi Rules */
% pria(X) 	: X adalah pria
% wanita(X) 	: X adalah wanita
% usia(X,Y) 	: X berusia Y
% menikah(X,Y)	: X menikah dengan Y
% anak(X,Y) 	: X adalah anak Y	   

% X adalah saudara kandung maupun tiri dari Y
saudara(X,Y) :- 
    anak(X, Parent), 
    anak(Y, Parent), 
    X \= Y.

% X adalah saudara tiri dari Y 
saudaratiri(X, Y) :-
    anak(X, Parent), 
    anak(Y, Parent),
    X \= Y,               
    anak(X, Parent2),
    anak(Y, Parent3),
    Parent \= Parent2,  
    Parent \= Parent3,  
    Parent2 \= Parent3.                               

% X adalah kakak dari Y (kakak kandung maupun tiri)
kakak(X,Y) :-
    saudara(X,Y),
    usia(X, AgeX),
    usia(Y, AgeY),
    AgeX > AgeY.

% X adalah keponakan dari Y
keponakan(X,Y) :-
    saudara(Y, Sibling),
    anak(X, Sibling).

% X adalah mertua dari Y
mertua(X,Y) :-
    anak(Child, X),
    menikah(Child, Y).

% X adalah nenek dari Y
nenek(X,Y) :-
    wanita(X),
    anak(Parent, X),
    anak(Y, Parent).

% X adalah keturunan dari Y (anak, cucu, dan seterusnya)
keturunan(X,Y) :-
    anak(X,Y).

keturunan(X,Y) :-
    anak(X,Z),
    keturunan(Z,Y).

% X adalah orang yang tidak menikah
lajang(X) :-
    \+ menikah(X, _),
    \+ menikah(_, X).

% X adalah anak paling muda
anakbungsu(X) :-
    saudara(X, _),                 
    (usia(X, AgeX),                    
     \+ (saudara(X, Y), usia(Y, AgeY), AgeY < AgeX)), !.

% X adalah anak paling tua
anaksulung(X) :-
    saudara(X, _),                
    (usia(X, AgeX),                    
     \+ (saudara(X, Y), usia(Y, AgeY), AgeY > AgeX)), !.

% X adalah orang yang orang tuanya tidak terdefinisi
yatimpiatu(X) :-
    (pria(X); wanita(X)),
    \+ (anak(X,_)).



/* Bagian <2> */
/* Deklarasi Rules */
% Exponent A^B = X
exponent(_, 0, X) :- X is 1.    % Basis
exponent(A, B, X) :- 
    B > 0,
    B1 is B - 1,
    exponent(A, B1, X1),
    X is A * X1.

% Growth
growth(I, _, _, 0, X) :- X is I.
growth(I, G, H, T, X) :- 
    T > 0,
    T1 is T - 1,
    growth(I, G, H, T1, X1),
    ( isprime(T) ->
        X is X1 + G;
        X is X1 - H 
    ).


% Si Imut Anak Nakal
% Base case : Semua pohon sudah didatangi
harvestFruits(N, Fruits, TreeNumber, Fruits) :-
    TreeNumber > N, !.

% Base case : Fruits habis sebelum pohon didatangi semua
harvestFruits(_, Fruits, _, 0) :-
    Fruits =< 0,
    write('Si Imut pulang sambil menangis :('), !.

% Recursive case
harvestFruits(N, Fruits, TreeNumber, FinalFruits) :-
    Fruits > 0,                          
    treeRules(TreeNumber, Fruits, UpdatedFruits), 
    NextTree is TreeNumber + 1,          
    harvestFruits(N, UpdatedFruits, NextTree, FinalFruits). 

treeRules(TreeNumber, Fruits, UpdatedFruits) :-
    (divides(3, TreeNumber) -> Fruits1 is Fruits + 2 ; Fruits1 = Fruits),
    (divides(4, TreeNumber) -> Fruits2 is Fruits1 - 5 ; Fruits2 = Fruits1),
    (divides(5, TreeNumber) -> Fruits3 is Fruits2 + 3 ; Fruits3 = Fruits2),
    (isprime(TreeNumber) -> UpdatedFruits is Fruits3 - 10 ; UpdatedFruits = Fruits3).

% KPK
% mencari KPK
kpk(X,Y, FinalKPK):-
    gcd(X,Y,GCD),
    KPK is X * Y // GCD,
    (KPK < 0 -> 
        FinalKPK is KPK * -1;
        FinalKPK is KPK).

% Factorial
factorial(N,X):-
    N >= 0,
    N < 2, !,
    X = 1.
factorial(N,X):-
    N > 1,
    N1 is N - 1,
    factorial(N1,X1),
    X is N * X1.

% Make Pattern
% Main predicate to generate and print the pattern
makePattern(N) :-
    makePatternRows(N, 1), !.

% Menulis N baris dimulai dari 1
makePatternRows(N, Row) :-
    Row =< N,                        
    makePatternRow(N, Row, 1),    
    nl,                             
    Row1 is Row + 1,              
    makePatternRows(N, Row1).  
makePatternRows(_, _).             

% Menulis satu baris
makePatternRow(N, Row, Col) :-
    Col =< N,
    DepthBottom is N - Row + 1,
    DepthRight is N - Col + 1,                  
    min4(Row, Col, DepthBottom, DepthRight, Depth), 
    write(Depth), write(' '),        
    Col1 is Col + 1,             
    makePatternRow(N, Row, Col1).
makePatternRow(_, _, _).              



% HELPER BAGIAN 2

% Fungsi Antara Growth
isprime(2).
isprime(N) :-
    N > 2,
    \+ divisible(N,2).

% mengecek apakah N memiliki divisor D
divisible(N, D) :-
    D * D =< N,
    (divides(D,N);
    D1 is D + 1,
    divisible(N, D1)).

% X habis membagi Y
divides(X,Y) :-
    X \= 0,
    Y mod X =:= 0.


% mencari FPB
gcd(X, 0, X) :-
    X > 0, !.
gcd(X,Y, GCD) :-
    Y > 0,
    Y1 is X mod Y,
    gcd(Y, Y1, GCD).


% Mencari minimum dari dua nilai
min2(A, B, A) :- A =< B, !.
min2(A, B, B).

% Mencari minimum dari empat nilai
min4(A, B, C, D, Min) :-
    min2(A, B, TempMin1),
    min2(C, D, TempMin2),
    min2(TempMin1, TempMin2, Min).




/* Bagian 3 */
/* Deklarasi Rules */
% STATISTIK
min([Min], Min).
min([Head|Tail], Min) :-
    min(Tail, TailMin),
    (Head =< TailMin -> Min = Head ; Min = TailMin).

max([Max], Max).
max([Head|Tail], Max) :-
    max(Tail, TailMax),
    (Head >= TailMax -> Max = Head ; Max = TailMax).

range(List, Range) :-
    max(List, Max),
    min(List, Min),
    Range is Max - Min.

count([_], Count) :- Count = 1. 
count([_|Tail], Count) :-
    count(Tail, TailCount),
    Count is TailCount + 1.

sum([Sum], Sum). 
sum([Head|Tail], Sum) :-
    sum(Tail, TailSum),
    Sum is Head + TailSum.

% MERGE SORT
mergeSort([], ListB, ListB).
mergeSort(ListA, [], ListA).

mergeSort([HeadA|TailA], [HeadB|TailB], [HeadA|Result]) :-
    HeadA =< HeadB, 
    mergeSort(TailA, [HeadB|TailB], Result). 

mergeSort([HeadA|TailA], [HeadB|TailB], [HeadB|Result]) :-
    HeadA > HeadB, 
    mergeSort([HeadA|TailA], TailB, Result). 

% FILTER ARRAY
filterArray([], _, _, []).
filterArray([Head|Tail], El1, El2, [Head|Result]) :-
    Head > El1,
    divides(El2, Head), 
    filterArray(Tail, El1, El2, Result). 

filterArray([Head|Tail], El1, El2, Result) :-
    (Head =< El1 ; \+ divides(El2, Head)),
    filterArray(Tail, El1, El2, Result).

% REVERSE
reverselist([], []).
reverselist([Head|Tail], Reversed) :-
    reverselist(Tail, ReversedTail),
    appendManual(ReversedTail, Head, Reversed). 

% CEK PALINDROM
cekPalindrom(List) :-
    reverse(List, List).

% ROTATE
rotate([], _, []).

% N < 0
rotate(List, N, Result) :-
    N < 0,
    count(List, Length),
    Pos is (Length + (N mod Length)) mod Length,
    rotate(List, Pos, Result).

% N > Length
rotate(List, N, Result) :-
    count(List, Length),
    Pos is N mod Length,
    rotateLeft(List, Pos, Result).

% Rotate to Left
rotateLeft(List, 0, List). 
rotateLeft([Head|Tail], N, Result) :-
    N > 0,
    N1 is N - 1,
    appendManual(Tail, Head, Rotated),
    rotateLeft(Rotated, N1, Result). 



% MAPPING
prosesMahasiswa(Name, Grades, Result) :-
    mapGrades(Grades, GradeLetters), 
    sum(Grades, Total),
    count(Grades, Count),
    average(Total, Count, Avg),
    status(Avg, Status),
    Result = [Name, GradeLetters, Avg, Status].




% HELPER BAGIAN 3
% Append
appendManual([], Elem, [Elem]).
appendManual([Head|Tail], Elem, [Head|Result]) :-
    appendManual(Tail, Elem, Result).

% Average
average(Total, Count, Avg) :- Avg is Total/Count.

% Grade to Letter
gradeToLetter(Grade, 'A') :- Grade >= 80.
gradeToLetter(Grade, 'B') :- Grade >= 70, Grade < 80.
gradeToLetter(Grade, 'C') :- Grade >= 60, Grade < 70.
gradeToLetter(Grade, 'D') :- Grade >= 50, Grade < 60.
gradeToLetter(Grade, 'E') :- Grade < 50.

% Mapping
mapGrades([], []).
mapGrades([Grade|Tail], [Letter|MappedTail]) :-
    gradeToLetter(Grade, Letter),   
    mapGrades(Tail, MappedTail). 

% Status
status(Avg, 'Pass') :- Avg >= 80.
status(Avg, 'Fail') :- Avg < 80.