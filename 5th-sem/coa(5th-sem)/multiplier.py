from unsigned_adder import nBitAdder


size=int(input("enter the size of bit multiplication: "))


input1=input("enter first number: ")
input2=input("enter second number: ")
input1=input1.zfill(size)
input2=input2.zfill(size)

temp_input2=input2[::-1]
result=0

for i in range(size):
    if temp_input2[i]=='1':
        bitAdder=nBitAdder(int(size)*2)
        result=bitAdder.result(int(input1+(i*'0')),result)
        # print(result)
        result=result[0]
        # print(result)
print(result)