import csv
import plotly.express as px
import pandas as pd


filename = 'F:\python_work\P2_SJ\world_fires_7_day.csv'
with open(filename) as fcsv:
    reader = csv.reader(fcsv)