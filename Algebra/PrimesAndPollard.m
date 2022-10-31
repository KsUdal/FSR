function PrimesAndPollard
  clc; clear;

  %pkg install symbolic-3.0.1.tar.gz
  %pkg load symbolic

  syms n;
  syms b;
  n = 0;
  k = randi([5 20]);
  p = [2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127];

  arr(1) = 2;
  deg(1) = 10;
  el = 2;

  num = 0;

  for i=2:k
    arr(i)=p(randi([1 31]));
    if (arr(i) > el)
      el = arr(i);
    end
    deg(i)=randi([18 24]);
  end

  n = sym (arr(1))^(deg(1));
  num = (arr(1))^(deg(1));

  for i = 2:k
    n = n + sym(arr(i))^(deg(i));
    num =  num + (arr(i))^(deg(i));
  end

  while (num < 2^123)
    n = sym (ceil(n * el));
    num = ceil(num * el);
  end
  while (num > 2^128)
    n = sym (floor(n / sym(el)));
    num = floor(num / el);
  end

  n = n + 1;

  num

  flag = 0;
  N = ceil(log2(num));
  for a = 2:N
    for i = 1:k
      t = a^((num-1)/p(i));
      if (mod(t, num) != 1)
        if (mod(a^(num-1), num) == 1)
          flag = 1;
        end
      end
    end
  end

  disp(sym(n));

  if(flag == 0)
    disp("proved prime");
  else
   disp("not prime");
  end

  [k1, k1um] = makenum(p, k) %как множитель p
  [k2, k2um] = makenum(p, k) %как множитель q
  n = k1*k2 % n = pq
  num = k1um*k2um

  flag = 0;
  aum = floor(num/2);
  a = (n-1)/2;
  k = 1;
  N = ceil(log2(num));
  for i = 1:N
    k = k*i;
    b = mod(sym(a)^(k) - 1, n);
    bum = mod(aum^k - 1, num);

    t = evklid(bum, num);
    if ((t > 1) && (t < num))
      flag = 1;
    end
  end

  if (flag == 0)
    disp(1);
  else
    disp(sym(b));
    bum
  end

end

function [n, num] = makenum(p,k)
  arr(1) = 2;
  deg(1) = 10;
  el = 2;

  for i = 2:k
    arr(i)=p(randi([1 31]));
    if (arr(i) > el)
      el = arr(i);
    end
    deg(i)=randi([5 10]);
  end

  n = sym (arr(1))^(deg(1));
  num = (arr(1))^(deg(1));

  for i = 2:k
    n = n + sym(arr(i))^(deg(i));
    num =  num + (arr(i))^(deg(i));
  end
end


function z = evklid(a,b)
	c = a - b;

	if (b > c)
	  evklid(b, c);
  end;

	if (c > b)
	  evklid(c, b);
	end;

	if (c == b)
	  nod = c;
	  z = nod;
	end;
end

