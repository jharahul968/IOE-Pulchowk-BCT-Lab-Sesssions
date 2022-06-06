from PIL import Image as Img
img = Img.open(r'black.png')

print("Enter the center and the radii")
# xc =  int(input("Enter the x coordinate of the center"))
# yc =  int(input("Enter the y coordinate of the center"))
# rx = int (input ("Enter rx"))
# ry = int (input ("Enter ry"))
xc, yc, rx, ry = 90, 40, 40, 20
xk, yk, m = 0, ry, 0


img.putpixel((xc, yc), (255,255,255,255))
img.putpixel((rx + xc, yc), (255,255,255,255))
img.putpixel((-rx + xc, yc), (255,255,255,255))
img.putpixel((xc, ry+yc), (255,255,255,255))
img.putpixel((xc,yc-ry ), (255,255,255,255))

# for region 1
p1k = ry**2 - (rx**2)*ry + 0.25*(rx**2) 
while abs(m) <= 1:
    if p1k < 0:
        xk += 1
        # p1k += 2*(ry**2)*xk - 2*(rx**2)*yk + ry**2
        p1k += 2*(ry**2)*xk + ry**2
    else:
        xk+= 1
        yk=yk-1
        p1k+= 2*(ry**2)*xk - 2*(rx**2)*yk + ry**2
    
    img.putpixel((xk + xc, yc - yk), (255,255,255,255))
    img.putpixel((-xk + xc, yc - yk), (255,255,255,255))
    img.putpixel((-xk + xc, yc + yk), (255,255,255,255))
    img.putpixel((xk + xc, yc + yk), (255,255,255,255))
    m = -(2*(ry**2)*xk)/(2*(rx**2)*yk)

p2k = ry*ry*((xk+0.5)**2) + rx*rx*((yk - 1)**2) - (rx*ry)**2
count = 0
while xk <= (xc + rx) and yk > 0 :
    if p2k > 0:
        yk -=1
        p2k += rx**2 - 2*rx*rx*yk

    else:
        xk += 1
        yk -= 1
        p2k += 2*ry*ry*xk - 2*rx*rx*yk + rx**2 
    count+=1
    # print("count = ", count, "x = ",xk + xc, " y = ",yc - yk)
    img.putpixel((xk + xc, yc - yk), (255,255,255,255))
    img.putpixel((-xk + xc, yc - yk), (255,255,255,255))
    img.putpixel((-xk + xc, yc + yk), (255,255,255,255))
    img.putpixel((xk + xc, yc + yk), (255,255,255,255))


img.show()