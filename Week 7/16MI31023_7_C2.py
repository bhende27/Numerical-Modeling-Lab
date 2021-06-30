from matplotlib import pyplot as plt 
mh = 3
sf = 0.0005
d = 423
sm = mh * (sf)
R = (0.1) * (d) #(taking so much time for large 'R' values, hence took small 'theta')
R = int(R)
ORx = [] #(x coordinates of Outer Rectangle)
ORy = [] #(y coordinates of Inner Rectangle)
for i in range(100 + 2*R):  #(instead of take 1m*1m boxes, I took 10m*10m boxes)
    for j in range(20 + 2*R):
        ORx.append(i)
        ORy.append(j)
IR = []
for i in range(R, 45+R):
    for j in range(R, 20+R):
        IR.append([i,j])
for i in range(55+R,100+R):
    for j in range(R, 20+R):
        IR.append([i,j])

k =  sm/(R**2)
a = ((2.718)**(-1*(3.1416)/(R**2)))

S = []
for i in range(len(ORx)):
    sum = 0
    for l in range(len(IR)):
        x = ((ORx[i] - IR[l][0])**2) + ((ORy[i] - IR[l][1])**2) + d**2
        s = (k)*(a**x)
        sum += s
    S.append(-sum)
fig = plt.figure()
ax = plt.axes(projection='3d')
zdata = S
xdata = ORx
ydata = ORy
ax.scatter3D(xdata, ydata, zdata)
plt.plot(xdata, ydata)