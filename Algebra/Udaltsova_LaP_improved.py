import math;
import random;

n = 0;
k = random.randint(5, 20);
p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127];

arr = [0 for i in range(k)];
deg = [0 for i in range(k)];


arr[1] = 2;
deg[1] = 10;
el = 2;

for i in range(2, k):
    arr[i] = p[random.randint(0, 30)]
    if (arr[i] > el):
        el = arr[i]
    deg[i] = random.randint(18, 24);

n = pow(arr[1], deg[1]);
num = pow(arr[1], deg[1]);

for i in range(2, k):
    n = n + pow(arr[i], deg[i])
    num =  num + pow(arr[i], deg[i]);
    
# still need this
# because it puts num and n in the [2^123, 2^128]
    
while (num < pow(2, 123)):
    n = n * el
    num = num * el;

while (num > pow(2, 128)):
    n = round(n / el)
    num = round(num / el);

# due to this moment num is a copy of n

n += 1;

flag = 0;
# we do N smaller because we do not need to check all of them
N = round(math.log(num, 2));
# print(N)

print(n);     

for a in range(2, N): #
    for i in range(1, k): #
        t = pow(a, round((num - 1)/p[i]))
        if ((t % num) != 1):
            if ((pow(a, num-1) % num) == 1):
                flag = 1;
          
          
if (flag == 0):
    print("proved prime")
else:
   print("not prime");
   
# now the second task
# first part can be too slow
# need to comment cicles to see how second works

# had no input in .m version
# used makenum inctead
# here is input

n = int(input());
N = int(input()); 

# used to take N like log
# counted it with makenum in .m version
# now the responsibility of N is on the user

flag = 0;
k = 1;

#print(n);
#print(N);

for i in range(1, n+1):
    if (flag == 0):
        for num in range(1, N+1): # num is k in task
            k = 1
            for j in range(1, num+1):
                k = k*j
            b = (pow(i, k) - 1) % n
            t = math.gcd(b, n)
            if ((t > 1) and (t < n)):
                flag = b
                #print(b)

if (flag == 0):
    print(1)
else:
    print(flag)
    
    