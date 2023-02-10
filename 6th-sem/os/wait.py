import os
import time

i=10
pid=os.fork()
if pid==0:
    print("initial: ",i)
    i+=10
    print("value of i: ",i)
    print("child terminated")
else:
    os.wait()
    print("value of i in parent: ",i)