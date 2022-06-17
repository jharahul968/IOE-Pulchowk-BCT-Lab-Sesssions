from subtractor_using_complement import nBitSubtractor

def getCmp(m,s):
    if s==0:
        return m
    else:
        m=m.zfill(n)
        m=m.replace('1','x')
        m=m.replace('0','1')
        m=m.replace('x','0')
        bitSubtractor=nBitSubtractor(int(n))
        sum1,carry1=bitSubtractor.result(int(m),1)
        m=sum1
        return m

def leftShift(a,b):
    tempA=a[1:]+b[0]
    tempB=b[1:]+'0'
    return tempA, tempB


q=input("Enter the dividend: ")
m=input("Enter the divisor: ")
a=""

n=len(q)+1

a=a.zfill(n)
m0=m.zfill(n)


for i in range(n-1):
    if str(a[0])=='1':
        a,q=leftShift(a,q)
        sub=nBitSubtractor(n)
        m=getCmp(m0,0)
        a=str(sub.result(int(a),int(m))[0])
 
        a=a.zfill(n)
        if a[0]=='1':
            q=list(q)
            q[-1]='0'
            q="".join(q)
        elif a[0]=='0':
            q=list(q)
            q[-1]='1'
            q="".join(q)

    elif str(a[0])=='0':
        a,q=leftShift(a,q)
        sub=nBitSubtractor(n)
        m=getCmp(m0,1)
        a=str(sub.result(int(a),int(m))[0])
        a=a.zfill(n)
        if a[0]=='1':
            q=list(q)
            q[-1]='0'
            q="".join(q)
        elif a[0]=='0':
            q=list(q)
            q[-1]='1'
            q="".join(q)

if str(a[0])=='1':
    sub=nBitSubtractor(n)
    a=str(sub.result(int(a),int(m))[0])


print("Quotient is ", int(q))
print("Remainder is ", int(a))