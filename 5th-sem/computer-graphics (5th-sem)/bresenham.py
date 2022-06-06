from PIL import Image 
      
# creating a image object
img = Image.open(r'black.png') 
k = 0
x1 = int(input("Enter the value of x1 "))
y1 = int(input("Enter the value of y1 "))
x2 = int(input("Enter the value of x2 "))
y2 = int(input("Enter the value of y2 "))
dx = abs(x2-x1)
dy = abs(y2-y1)
if x2>x1:
    lx = 1
else:
    lx = -1
if y2>y1:
    ly = 1
else:
    ly = -1

xk, yk = x1, y1
img.putpixel((x1,y1), (255, 255, 255, 255))

if dx>= dy: #slope is less than or equal to 1
    pk = 2*dy - dx
    while k<=dx:
        if pk<0:
            xk += 1
            pk += 2*dy
        else:
            xk += 1
            yk += 1
            pk += 2*(dy - dx)
        
        img.putpixel((xk,yk), (255, 255, 255, 255))
        k += 1

else:
    pk = 2*dx - dy
    while k<=dy:
        if pk<0:
            yk += 1
            pk += 2*dx
        else:
            xk += 1
            yk += 1
            pk += 2*(dx - dy)
        
        img.putpixel((xk,yk), (255, 255, 255, 255))
        k += 1



# width, height = img.size
  
# for x in range(height):
#     img.putpixel( (x, x), (255, 0, 0, 255) )
  
img.show()