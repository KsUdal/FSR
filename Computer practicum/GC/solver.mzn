include "globals.mzn";
% include "value_precede_set.mzn";
% include "nvalue_fn.mzn";

int: n;
int: e;
int: maxc = 317; % Domain of colors, limits search space. Ideally maxc == 13! if you can solve it
int: frcd; % HACK Number of colors to force to relax problem!

array[1..e,1..2] of int: E;
array[0..n-1] of var 0..maxc: c;   % Color of node n

constraint forall(i in 1..e)(c[E[i,1]] != c[E[i,2]] ); % Two linked nodes have diff color
constraint c[0] == 0;

% Big symmetry breaker. A new color J is only allowed to appear after colors
% 0..J-1 have been seen before (in any order)
constraint forall(i in 0..n-2)( value_precede(i,i+1, c)  );

solve maximize(max(c));

output [ show(max(c)+1), "\n", show(c)]
