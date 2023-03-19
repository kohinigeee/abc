k = int(input())

cnt = 2 
tmpk = k

while(cnt*cnt <= k):
    while(tmpk%cnt == 0 ):
        tmpk /= cnt 
    cnt += 1

if ( tmpk == k ):
    print(k)