import copy
from queue import Queue

primes=set([2,3,5,7,11,13,17])




def board(orig):

    
    states={orig:0}

    q=Queue(maxsize=0)

    q.put(orig)

    while q.qsize()!=0:
        
        curr=q.get()
        val=states[curr]
        for i in range(9):

            if (i+1)%3 and curr[i]+curr[i+1] in primes:

                new_curr=list(curr)
                new_curr[i],new_curr[i+1]=new_curr[i+1],new_curr[i]

                new_curr=tuple(new_curr)

                if new_curr not in states:
                    states[new_curr]=val+1
                    q.put(new_curr)
            if i<6 and curr[i]+curr[i+3] in primes:
                new_curr=list(curr)
                new_curr[i],new_curr[i+3]=new_curr[i+3],new_curr[i]

                new_curr=tuple(new_curr)

                if new_curr not in states:
                    states[new_curr]=val+1
                    q.put(new_curr)


        

        

    return states
states=board((1,2,3,4,5,6,7,8,9))
for _ in range(int(input())):

    x=input()
    state=[]
    for _ in range(3):

        temp=list(map(int,input().split()))
        for e in temp:
            state.append(e)
    state=tuple(state)
    if state in states:
        print(states[state])
    else:
        print(-1)