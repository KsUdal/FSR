int: n;
set of int: OBJ = 1..n;
int: capacity;
array[OBJ] of int: profit;
array[OBJ] of int: size;

array[OBJ] of var int: x;

constraint forall(i in OBJ)(x[i] >= 0);
constraint forall(i in OBJ)(x[i] <= 1);
constraint sum(i in OBJ)(size[i] * x[i]) <= capacity;
solve maximize sum(i in OBJ)(profit[i] * x[i]);

var int: sol;
sol = sum(i in OBJ) (x[i]*profit[i]);

var int: space_left;
space_left = capacity - sum(i in OBJ) (x[i]*size[i]);
