def XOR(input1, input2):
    if input1==input2:
        return 0
    else:
        return 1
def AND(input1, input2):
    if input1==0 or input2==0:
        return 0
    else:
        return 1
def OR(input1, input2):
    if input1 ==1 or input2==1:
        return 1
    else:
        return 0



class adder:
    def Sum(self, a, b, c):
        return XOR(XOR(a,b),c)
    def Carry(self, a, b, c):
        return OR(OR(AND(a,b), AND(b,c)),AND(c,a))

class nBitSubtractor(adder):
    def __init__(self, n):
        super().__init__()
        self.n=n
        self.sum=None
        self.carry=None
    
    def S(self, input1, input2):
        input1=str(input1).zfill(self.n)
        input2=str(input2).zfill(self.n)
        carry=0
        result=""
        for i in range(self.n-1,-1,-1):
            sum=super().Sum(int(input1[i]),int(input2[i]), carry)
            carry=super().Carry(int(input1[i]),int(input2[i]), carry)
            result=str(sum)+result
        self.sum=int(result)
        return int(result)
    def C(self, input1, input2):
        input1=str(input1).zfill(self.n)
        input2=str(input2).zfill(self.n)
        carry=0
        result=""
        for i in range(self.n-1,-1,-1):
            sum=super().Sum(int(input1[i]),int(input2[i]), carry)
            carry=super().Carry(int(input1[i]),int(input2[i]), carry)
            result=str(sum)+result
        self.carry=carry
        return int(carry)
    def result(self, input1, input2):
        self.S(input1, input2)
        self.C(input1, input2)
        return self.sum, self.carry

if __name__=="__main__":
    size=input("Enter the size of bit adder: ")
    input1=input("Enter the first number: ")

    input2=input("Enter the second number: ")
    input2=input2.zfill(int(size))
    input2=input2.replace('1','x')
    input2=input2.replace('0','1')
    input2=input2.replace('x','0')
    bitSubtractor=nBitSubtractor(int(size))
    sum1,carry1=bitSubtractor.result(int(input2),1)
    input2=sum1


    bitAdder=nBitSubtractor(int(size))
    print("The result is in the form (sum,carry): ", bitSubtractor.result(int(input1),int(input2)))