import os

# if not os.fork():
#     print("child process id=",os.getpid())
#     print("i am from child")
# else:
#     print("i am from parent")
#     print("parent process id=",os.getppid())


id=os.fork()
if id<0:
    print("cant create file")
elif id==0:
    print("child process")
else:
    print("parent process")