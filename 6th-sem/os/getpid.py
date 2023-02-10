import os
import time

pid=os.fork()
if pid==0:
    print("child process")
    print("child process id: ", os.getpid())
    print("parent process id: ", os.getppid())
    time.sleep(5)
    print("child after sleep 5")
    print("child id: ", os.getpid())
    print("parent id: ", os.getppid())
else:
    print("parent process")
    time.sleep(10)
    print("child id: ", os.getpid())
    print("parent id: ",os.getppid())
    print("parent terminates")