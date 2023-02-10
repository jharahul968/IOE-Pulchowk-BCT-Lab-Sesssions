import os
import time
id=os.fork()
if id==-1:
    print("cant create file")
elif id==0:
    time.sleep(2)
    print("child process")
else:
    print("parent process")