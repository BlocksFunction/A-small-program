#coding=utf-8
a = input("请输入要计算的算式：")
b = []
c = []
x = 0
j = 0
l = 0
for i in a:  #分词
    if i in "0123456789":
        x *= 10
        x += float(i)
    if i in "+-*/":
        b.append(x)
        b.append(i)
        x = 0
b.append(x)
for i in range(len(b)):   #处理二级运算
    if isinstance(b[i],str):
        if b[i] in '+-':
            if i == 1 and len(b)-1-i != 1:
                    c.append(b[i-1])
            elif i != 1 and len(b)-1-i == 1:
                if b[i-2] not in '*/':
                    c.append(b[i-1])
            else:
                if b[i-2] not in '*/' and b[i+2] not in '*/':
                    c.append(b[i-1])
            c.append(b[i])
        if b[i] in '*/':
            if b[i] == '*':
                if i != 1:
                    if b[i-2] in "*/":
                        c[len(c)-1] *= b[i+1]
                    else:
                        c.append(b[i-1]*b[i+1])
                else:
                    c.append(b[i-1]*b[i+1])
            else:
                if i != 1:
                    if b[i-2] in "*/":
                        c[len(c)-1] /= b[i+1]
                    else:
                        c.append(b[i-1]/b[i+1])
                else:
                    c.append(b[i-1]/b[i+1])
j = c[0]
for i in range(len(c)):                     #处理一级运算
    if isinstance(c[i],str):
        if c[i] in '+-':
            if c[i] == '+':
                j += c[i+1]
            else:
                j -= c[i+1]
print("结果为",j)
