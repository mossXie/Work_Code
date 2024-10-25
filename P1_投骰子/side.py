from plotly.graph_objs import Bar, Layout
from plotly import offline
import webbrowser

from die import Die

die = Die()
results = []
for roll_nums in range(60):
    result = die.roll()
    results.append(result)

frequencies = []
for value in range(1, die.num_sides + 1):
    frequency = results.count(value)
    frequencies.append(frequency)

print(frequencies)

x_values = list(range(1, die.num_sides + 1))
data = [Bar(x=x_values, y=frequencies)]

x_axis_config = {'title': '结果'}
y_axis_config = {'title': '结果的频率'}
my_layout = Layout(title='投掷1000次色子的结果', xaxis=x_axis_config, yaxis=y_axis_config)
offline.plot({'data': data, 'layout': my_layout}, filename='D6.html')

webbrowser.open('D6.html')
