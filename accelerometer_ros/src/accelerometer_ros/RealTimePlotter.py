import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

class RealTimePlotter:
    def __init__(self, threshold = 1000, pace = 200):
        self.threshold_ = threshold
        self.f = plt.figure()
        self.ax = plt.axes()
        self.ax.set_title('Simple plot')
        self.pace_ = pace
        print ("RealTimePlotter Constructor Initialized")

    def stop(self):
        plt.close("all")

    def update(self,seq,x,y):

        if seq % self.pace_ is 0:
            self.ax.plot(x,y)
            plt.draw()

        print (len(x))
        if len(x) is self.threshold_:
            x.pop(0)
            y.pop(0)
            self.ax.cla()
