import tkinter as tk
from tkinter import ttk
from PIL import ImageTk, Image

import os
from menubar import Menubar

HEIGHT = 1080
WIDTH = 1920

class PhreeDFApp():
    
    def __init__(self, root):
        
        pathToAppIcon = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../icon/icon.png')
        img = Image.open(pathToAppIcon)
        icon = ImageTk.PhotoImage(img)
        root.tk.call('wm', 'iconphoto', root._w, icon)
        root.geometry( str(HEIGHT) + "x" + str(WIDTH) )

        root.title("PhreeDF")

        ribbon = ttk.Notebook(root)
        ribbon.place(relheight=1, relwidth=1)
        

        self.menuBar = Menubar(ribbon)
        ribbon.select(self.menuBar.homeFrame)

        root.bind('<Escape>', close)

    
def close(event):
    root.destroy()
    
if __name__ == "__main__":
    root = tk.Tk()
    PhreeDFApp(root)
    root.mainloop()