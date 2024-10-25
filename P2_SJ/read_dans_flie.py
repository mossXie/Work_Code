import csv
import matplotlib.pyplot as plt
import matplotlib
from datetime import datetime

font1 = matplotlib.font_manager.FontProperties(fname="F:\python_work\SourceHanSerifSC-Light.otf")

filename = 'sitka_weather_07-2018_simple.csv'
with open(filename) as f:
    reader = csv.reader(f)
    header = next(reader)

    for index, column_header in enumerate(header):
        print(index, column_header)
    heights = []

    for row in reader:
        high = int(row[5])
        heights.append(high)
    print(heights)

    plt.style.use('seaborn')
    fig, ax = plt.subplots()
    ax.plot(heights, c='red')

    plt.title("菜鸟教程 - 测试", fontproperties=font1)
    plt.xlabel("x 轴", fontproperties=font1)
    plt.ylabel("y 轴", fontproperties=font1)
    ax.set_title('2018年7月每日最高气温', fontsize='24')
    ax.set_xlabel(' ', fontsize=16)
    ax.set_ylabel("温度（F）", fontsize=16, )
    ax.tick_params(axis='both', which='major', labelsize=16)

    plt.show()

