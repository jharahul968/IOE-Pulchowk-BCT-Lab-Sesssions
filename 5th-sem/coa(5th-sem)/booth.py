from subtractor_using_complement import nBitSubtractor
from unsigned_adder import nBitAdder

def getCmp(m,s,n):
    m=str(m)
    if s==0:
        return m
    elif s==2:
        m=m.zfill(n)
        m=m.replace('1','x')
        m=m.replace('0','1')
        m=m.replace('x','0')
        bitSubtractor=nBitSubtractor(int(n))
        sum1,carry1=bitSubtractor.result(int(m),1)
        m=sum1
        m=str(m).zfill(n)
        return m
    elif s==1:
        m=m.zfill(n)
        m=m.replace('1','x')
        m=m.replace('0','1')
        m=m.replace('x','0')
        return m

def asr(a,b):
    a=str(a)
    b=str(b)
    tempA=a[0]+a[0:len(a)-1]
    tempB=a[-1]+b[0:len(b)-1]
    tempC=b[-1]
    return tempA, tempB, tempC


br=input("Enter the multiplicand: ")
qr=input("Enter the multiplier: ")
n=len(str(qr))
ac=0
ac=str(ac).zfill(n)
sc=n
qn1=0

while(sc!=0):
    qn_qn1=str(qr)[-1]+str(qn1)
    print(qn_qn1)
    if qn_qn1=='10':
        bitAdder=nBitAdder(n)
        ac=bitAdder.result(int(ac),getCmp(br,2,n))[0]
        ac=str(ac).zfill(n)

        ac,qr,qn1=asr(ac,qr)

        print(ac,qr)



        sc-=1
    elif qn_qn1=='01':
        bitAdder=nBitAdder(n)
        ac=bitAdder.result(int(ac),getCmp(br,0,n))[0]
        ac=str(ac).zfill(n)
        ac,qr,qn1=asr(ac,qr)

        print(ac,qr)

        sc-=1
    elif qn_qn1=='00' or qn_qn1=='11':
        ac,qr,qn1=asr(ac,qr)

        print(ac,qr)

        sc-=1

print("Result is: ",ac)