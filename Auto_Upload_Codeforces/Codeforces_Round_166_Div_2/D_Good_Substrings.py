
class RollingHash:
	def __init__(self) -> None:
	
	    self.value=0 	
	    self.a=719
	    self.b=265252859812191058636308479999999
	def hash(self,s):
		a=self.a 
		b=self.b
		nums=[ord(i) for i in s]
		
		for i in range(len(nums)):

			

			self.value=((self.value*a)%b+nums[i])%b 
		
		
		return self.value
	
	def remove(self,l,n):
		a=self.a 
		b=self.b
		l=ord(l) 
		self.value-=(l*pow(a,n,b))%b
		self.value=(self.value*pow(a,-1,b))%b 
		return self.value 
	def add(self,l):

		a=self.a 
		b=self.b 

		self.value*=a 
		self.value%=b 
		self.value+=ord(l) 
		self.value%=b
		return self.value

def main(s,arr,k):
    
    ans=set()
    
    
    for i in range(len(s)):
        h=RollingHash()
        curr=0
        for j in range(i,len(s)):
            l=ord(s[j])-97
            curr+=1 if not int(arr[l]) else 0 
            if curr<=k:
                value=h.add(s[j]) 
               
                ans.add(value) 
            else:
                break
                
    return len(ans)

s=input() 
arr=input() 
k=int(input())
print(main(s,arr,k))
            
           