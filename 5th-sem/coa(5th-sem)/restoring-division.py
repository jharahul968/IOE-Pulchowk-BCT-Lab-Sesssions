from subtractor_using_complement import nBitSubtractor

def leftShift(a,b):
    tempA=a[1:]+b[0]
    tempB=b[1:]+'0'
    return tempA, tempB


q=input("Enter the dividend: ")
m=input("Enter the divisor: ")
a=""

n=len(q)+1

a=a.zfill(n)
m=m.zfill(n)

m=m.replace('1','x')
m=m.replace('0','1')
m=m.replace('x','0')
bitSubtractor=nBitSubtractor(int(n))
sum1,carry1=bitSubtractor.result(int(m),1)
m=sum1

for i in range(n-1):
    a,q=leftShift(a,q)

    sub=nBitSubtractor(n)
    tempA=a





    a=str(sub.result(int(a),int(m))[0])
    print("result=",a)
    a=a.zfill(n)
    
    if a[0]=='1':
        q=list(q)
        q[-1]='0'
        q="".join(q)
        a=tempA
    elif a[0]=='0':
        q=list(q)
        q[-1]='1'
        q="".join(q)


print("Quotient is ", int(q))
print("Remainder is ", int(a))