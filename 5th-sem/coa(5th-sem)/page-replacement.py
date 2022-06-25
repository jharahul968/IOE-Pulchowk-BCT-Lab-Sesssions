# cap=input("Enter the number of page frames: ")

# # creating an empty list
# lst = []

# # number of elements as input
# n = int(input("Enter number of elements : "))

# print("Enter elements below: ")

# # iterating till the range
# for i in range(0, n):
# 	ele = int(input())

# 	lst.append(ele) # adding the element


cap = 4
lst = [ 7, 0, 1, 2, 0, 3, 0,
                4, 2, 3, 0, 3, 2]

s=[]
pageFaults=0
for i in lst:
    if i not in s:
        if (len(s)==cap):
            s.remove(s[0])
            s.append(i)

            print(s)

        else:
            s.append(i)

            print(s)

        pageFaults+=1
    else:
        s.remove(i)
        s.append(i)

        print(s)

print("Total page faults are ", pageFaults)