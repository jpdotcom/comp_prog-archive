def main(arr):
    
    idx={} 
    arr_sorted=sorted(arr)
    if arr_sorted==arr:
        print('yes')
        print(1,1)
        return
    for i in range(0,len(arr)-1):
        if arr[i]>arr[i+1]:
            start=i 
            end=len(arr)-1
            for j in range(start+1,len(arr)):
                if arr[j]<=arr[j-1]:
                    continue
                else:
                    end=j-1
                    break 
            
                    
            
            sub=list(reversed(arr[i:end+1]))
            
            arr=arr[0:i]+sub+arr[end+1:]
            
            if arr==arr_sorted:
                print('yes')
                print(start+1,end+1)
                return
            else:
                print('no')
                return
n=int(input())
arr=list(map(int,input().split()))
main(arr