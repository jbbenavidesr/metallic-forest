import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('../data/difusion.csv')

info = data.groupby(['t']).aggregate(['std'])

info.plot(y=['x', 'y'])


plt.show()
