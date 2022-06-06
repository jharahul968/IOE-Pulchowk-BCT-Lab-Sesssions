from PIL import Image as Img
img = Img.open(r'black.png')  #image size is 1914x901

print("Enter the center and the radius of the circle")
# xc = 950
# yc = 450
# r = 400
xc = int(input("Enter the x coordinate of the center "))
yc = int(input("Enter the y coordinate of the center "))
r = int(input("Enter the radius of the circle "))

pk = 5/4 - r
xk, yk, k = 0, r, 0

# img.putpixel((xc, yc-r), (255, 255, 255, 255))
# img.putpixel((xc, yc+r), (255, 255, 255, 255))
# img.putpixel((xc + r, yc), (255, 255, 255, 255))
# img.putpixel((xc - r, yc), (255, 255, 255, 255))
# img.putpixel((xc, yc), (255, 255, 255, 255)) 
#this plots the center

while yk >= xk:
    if pk < 0:
        xk += 1
        pk += 2*xk + 1
    
    else:
        xk += 1
        yk -= 1
        pk += 2*xk - 2*yk + 1
    
    img.putpixel((xk + xc, -yk + yc),(255, 255, 255, 255))
    img.putpixel((yk + xc, yc - xk),(255, 255, 255, 255))
    img.putpixel((yk + xc, yc + xk),(255, 255, 255, 255))
    img.putpixel((-xk + xc, -yk + yc),(255, 255, 255, 255))
    img.putpixel((-yk + xc, yc + xk),(255, 255, 255, 255))
    img.putpixel((-yk + xc, yc - xk),(255, 255, 255, 255))
    img.putpixel((xk + xc, yk + yc),(255, 255, 255, 255))
    img.putpixel((-xk + xc, yk + yc),(255, 255, 255, 255))
  
img.show()