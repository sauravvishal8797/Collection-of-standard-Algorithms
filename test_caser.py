from random import randint as rand

T = rand(1,10)
print T

for i in xrange(T):
    N = rand(1, 100000)
    print N

    for i in xrange(N):
        print rand(1, 1000000)
