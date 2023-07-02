import numpy as np

import matplotlib.pyplot as plt
import random

print(random.randint(0, 20))
fontSerif = {'family': 'serif', 'color': 'blue', 'size': 20}
plt.rcParams['figure.figsize'] = [10, 14]


def generateRandomArray(minValue, maxValue, size):
    arr = []
    for i in range(0, size):
        arr.append(random.randint(minValue, maxValue))
    return arr


def generateSubSeqToBarDiagram(sizeSubSeq):
    arr = []
    for i in range(0, sizeSubSeq):
        arr.append(i)
    return arr


def generateDataToPieDiagram(sizeSubSeq):
    arr = []
    leftData = 100
    curSize = 0
    while leftData > 0 and curSize != sizeSubSeq - 1:
        curValue = random.randint(0, leftData)
        arr.append(curValue)
        leftData -= curValue
        curSize += 1
    if curSize != sizeSubSeq and leftData != 0:
        arr.append(leftData)
    return arr


# генерация простого графика
plt.subplot(3, 3, 1)
plt.plot(generateRandomArray(0, 40, 11))
plt.title('Default', fontdict=fontSerif)

# генерация простого графика в виде линий
plt.subplot(3, 3, 2)
plt.plot(generateRandomArray(0, 40, 11), linestyle='dashed')
plt.title('Line', fontdict=fontSerif)

# генерация простого графика в виде точек
plt.subplot(3, 3, 3)
plt.plot(generateRandomArray(0, 40, 11), linestyle='dotted')
plt.title('Dotted', fontdict=fontSerif)

# генерация точечной диаграмммы
x = np.array(generateRandomArray(0, 40, 11))
y = np.array(generateRandomArray(0, 40, 11))
plt.subplot(3, 3, 4)
plt.scatter(x, y)
plt.title('Scatter', fontdict=fontSerif)

# генерация стоблцовой диаграммы
size = 11
x = np.array(generateSubSeqToBarDiagram(size))
y = np.array(generateRandomArray(0, 40, size))
plt.subplot(3, 3, 5)
plt.bar(x, y)
plt.title('Bar', fontdict=fontSerif)

# генерация гистограммы
x = np.random.normal(300, 20, 400)
plt.subplot(3, 3, 6)
plt.hist(x)
plt.title('Histogram', fontdict=fontSerif)

# генерация кусочной диаграммы
x = np.array(generateDataToPieDiagram(10))
plt.subplot(3, 3, 7)
plt.pie(x)
plt.title('Pie', fontdict=fontSerif)

plt.show()
