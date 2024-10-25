import plotly.express as px
from All_DZ import *
import pandas as pd

data = pd.DataFrame(
    data=zip(lons, lats, titles, mags), columns=['经度', '纬度', '位置', '震级']
)

filename = 'F:\python_work\P2_SJ\eq_data_30_day_m1.json'
fig = px.scatter(
    data,
    x='经度',
    y='纬度',
    range_x=[-200, 200],
    range_y=[-90, 90],
    width=800,
    height=800,
    title='全球地震图',
    size='震级',
    size_max=10,
    color='震级',
    hover_name='位置'
)
px.colors.qualitative.Alphabet[::-1]
fig.write_html('global_earthquakes.html')
fig.show()
