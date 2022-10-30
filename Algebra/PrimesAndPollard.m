function Udaltsova1
  clc; clear;
  syms n;
  syms b;
  n = 0;
  k = randi([5 20]);
  p = [2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127];

  arr(1) = 2;
  deg(1) = 50;
  el = 2;
  for i=2:1:k
    arr(i)=p(randi([1 31]));
    if (arr(i) > el)
      el = arr(i);
    end
    deg(i)=randi([18 128]);
  end

  n = 0;

  for i = 1:1:k
    n = n + arr(i)^deg(i);
  end

  while (n < 2^123)
    n = ceil(n * el);
  end
  while (n > 2^128)
    n = floor(n / el);
  end

  n = n + 1;

  %n = 127.56
  n = floor(n)

  flag = 0;
  N = round(log2(n));
  for a = 2:N
    for i = 1:k
      t = a^((n-1)/p(i));
      if (mod(t, n) != 1)
        if (mod(a^(n-1), n) == 1)
          flag = 1;
        end
      end
    end
  end

  disp(sym(n));
  n = round(n);
  if(flag == 0)
    disp("proved prime");
  else
   disp("not prime");
  end

  flag = 0;
  a = floor(n/2);
  k = 1;
  for i = 1:1:N
    k = k*i;
    b = mod(a^k - 1, n);
    if ((gcd(b, n) > 1) && ( gcd(b, n) < n))
      flag = 1;
      %disp(sym(b));
    end
  end

  if(flag = 0)
    disp(1);
  else
    disp(sym(b));
    b
  end

end
