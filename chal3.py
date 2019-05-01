def fact (n):
    if n == 1:
        return 1

    else:
        return n*fact(n-1)

def comb (n, r):
    return fact(n)/(fact(n-r)*fact(r))

if __name__ == '__main__':

    T = raw_input()
    N = []

    for i in xrange(0, T):

        N[i] = raw_input()
        j = 0
        while (  )
